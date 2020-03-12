//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain
// The SmartSoft Toolchain has been developed by:
//  
// Service Robotics Research Center
// University of Applied Sciences Ulm
// Prittwitzstr. 10
// 89075 Ulm (Germany)
//
// Information about the SmartSoft MDSD Toolchain is available at:
// www.servicerobotik-ulm.de
//
// This file is generated once. Modify this file to your needs. 
// If you want the toolchain to re-generate this file, please 
// delete it before running the code generator.
//--------------------------------------------------------------------------
#include "CameraRecognitionTask.hh"
#include "ComponentWebotsCameraRecognition.hh"
#include "CommObjectRecognitionObjects/CommObjectRecognitionObjectProperties.hh"
#include "CommBasicObjects/CommPose3d.hh"

#include <iostream>

#include <webots/Device.hpp>
#include <webots/Node.hpp>

using namespace CommObjectRecognitionObjects;

CameraRecognitionTask::CameraRecognitionTask(SmartACE::SmartComponent *comp):
	CameraRecognitionTaskCore(comp),
	_thread(),
	_threadRunning(false),
	_wbShouldQuit(false),
	imageCounter(0)
{
	std::cout << "constructor CameraRecognitionTask\n";
}

CameraRecognitionTask::~CameraRecognitionTask() 
{
	std::cout << "destructor CameraRecognitionTask\n";
}

int CameraRecognitionTask::on_entry()
{
	// do initialization procedures here, which are called once, each time the task is started
	// it is possible to return != 0 (e.g. when initialization fails) then the task is not executed further
	
	if (!COMP->webotsRobot)
		return -1;

	// acquisition
	COMP->mutex.acquire();

	// get timestep from the world and match the one in SmartMDSD component
	webotsTimeStep = COMP->webotsRobot->getBasicTimeStep();
	int coeff = S_TO_MS / (webotsTimeStep * COMP->connections.cameraRecognitionTask.periodicActFreq);
	webotsTimeStep *= coeff;

	// connect to the sensor from Webots
	wbcamera = NULL;
	for (int i = 0; i < COMP->webotsRobot->getNumberOfDevices(); i++)
	{
		webots::Device *webotsDevice = COMP->webotsRobot->getDeviceByIndex(i);

		if (webotsDevice->getNodeType() == webots::Node::CAMERA)
		{
			std::string cameraName = webotsDevice->getName();
			wbcamera = COMP->webotsRobot->getCamera(cameraName);
			wbcamera->enable(webotsTimeStep);
			wbcamera->recognitionEnable(webotsTimeStep);
			std::cout << "Device #" << i << " called " << cameraName << 
				" is a camera. Sampling time is: " << webotsTimeStep << 
				std::endl;
			break;
		}
	}

	// release
	COMP->mutex.release();

	if (!wbcamera)
	{
		std::cout << "No camera found, no data is sent." << std::endl;
		return -1;
	}

	return 0;
	
}
int CameraRecognitionTask::on_execute()
{
	// this method is called from an outside loop,
	// hence, NEVER use an infinite loop (like "while(1)") here inside!!!
	// also do not use blocking calls which do not result from smartsoft kernel
	
	if (_wbShouldQuit)
		return -1;

	if (_threadRunning || !COMP->webotsRobot)
		return 0;

	double basePosX = 0.0;
	double basePosY = 0.0;
	double basePosZ = 0.0;
	double basePosAzim = 0.0;
	double basePosElev = 0.0;
	double basePosRoll = 0.0;

	// acquisition
	COMP->mutex.acquire();

	// get base state from port
	Smart::StatusCode baseStatus = COMP->baseStateServiceIn->getUpdate(baseState);

	// check if the transmission worked
	if (baseStatus != Smart::SMART_OK)
		std::cerr << "Error: receiving BaseState: " << baseStatus << std::endl;
	else
		std::cout << "BaseState received" << std::endl;

	basePosX = baseState.get_base_position().get_x(1.0);
	basePosY = baseState.get_base_position().get_y(1.0);
	basePosZ = baseState.get_base_position().get_z(1.0);
	basePosAzim = baseState.get_base_position().get_base_azimuth();
	basePosElev = baseState.get_base_position().get_base_elevation();
	basePosRoll = baseState.get_base_position().get_base_roll();

	DomainVision::CommRGBDImage current_rgbd_image;

	auto image = wbcamera->getImage();
	if (wbcamera && image)
	{
		DomainVision::CommVideoImage comm_video_image;
		unsigned int cols = wbcamera->getWidth();
		unsigned int rows = wbcamera->getHeight();
		++imageCounter;

		comm_video_image.setSeq_count(imageCounter);
		comm_video_image.set_parameters(cols, rows, 
			DomainVision::FormatType::RGB32);
		comm_video_image.set_data(image);
		comm_video_image.setIs_valid(true);
		current_rgbd_image.setColor_image(comm_video_image);
		current_rgbd_image.setSeq_count(imageCounter);
		current_rgbd_image.setIs_valid(true);
		current_rgbd_image.setBase_state(baseState);
		recognition();
	}

	else
		current_rgbd_image.setIs_valid(false);

	// send out image through port
	COMP->rGBImagePushServiceOut->put(current_rgbd_image.getColor_image());

	// start robot step thread
	_threadRunning = true;
	if (_thread.joinable())
	_thread.join();
	_thread = std::thread(&CameraRecognitionTask::runStep, this, COMP->webotsRobot);

	// release
	COMP->mutex.release();

	// it is possible to return != 0 (e.g. when the task detects errors), then the outer loop breaks and the task stops
	return 0;
}
int CameraRecognitionTask::on_exit()
{
	// use this method to clean-up resources which are initialized in on_entry() and needs to be freed before the on_execute() can be called again
	delete COMP->webotsRobot;
	return 0;
}

void CameraRecognitionTask::runStep(webots::Robot *robot)
{
  _wbShouldQuit = robot->step(webotsTimeStep) == -1.0;
  _threadRunning = false;
}

void CameraRecognitionTask::recognition()
{
	CommObjectRecognitionObjectProperties obj_properties;
	int number_of_objects = wbcamera->getRecognitionNumberOfObjects();
	printf("\nRecognized %d objects.\n", number_of_objects);

	auto objects = wbcamera->getRecognitionObjects();
	for (int i = 0; i < number_of_objects; ++i) 
	{
		printf("Model of object %d: %s\n", i, objects[i].model);
		obj_properties.setObject_type(objects[i].model);

		printf("Id of object %d: %d\n", i, objects[i].id);
		obj_properties.setObject_id(objects[i].id);

		printf("Relative position of object %d: %lf %lf %lf\n", i, 
			objects[i].position[0], objects[i].position[1], 
			objects[i].position[2]);
		printf("Relative orientation of object %d: %lf %lf %lf %lf\n", i, 
			objects[i].orientation[0], objects[i].orientation[1],
			objects[i].orientation[2], objects[i].orientation[3]);
		Quaternion quat(objects[i].orientation[0], objects[i].orientation[1],
			objects[i].orientation[2], objects[i].orientation[3]);
		auto euler_angles = ToEulerAngles(quat);
		CommBasicObjects::CommPose3d obj_pose(objects[i].position[0],
			objects[i].position[1], objects[i].position[2], euler_angles.yaw, 
			euler_angles.pitch, euler_angles.roll);
		obj_properties.setPose(obj_pose);
		
		printf("Size of object %d: %lf %lf\n", i, objects[i].size[0], 
			objects[i].size[1]);
		obj_properties.set_dimension(objects[i].size[0], objects[i].size[1], 
			0);
		
		printf("Position of the object %d on the camera image: %d %d\n", i, 
			objects[i].position_on_image[0], objects[i].position_on_image[1]);
		printf("Size of the object %d on the camera image: %d %d\n", i, 
			objects[i].size_on_image[0], objects[i].size_on_image[1]);
		for (int j = 0; j < objects[i].number_of_colors; ++j)
			printf("- Color %d/%d: %lf %lf %lf\n", j + 1, 
				objects[i].number_of_colors, objects[i].colors[3 * j],
				objects[i].colors[3 * j + 1], objects[i].colors[3 * j + 2]);
		obj_properties.setIs_valid(true);
		COMP->objectPushServiceOut->put(obj_properties);
	}
}
