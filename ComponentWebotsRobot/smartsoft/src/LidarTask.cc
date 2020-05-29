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
#include "LidarTask.hh"
#include "ComponentWebotsRobot.hh"

#include <iostream>

LidarTask::LidarTask(SmartACE::SmartComponent *comp) 
:	LidarTaskCore(comp),
	scanCount(0),
	_lidar(NULL),
  bumper_type_(CommBasicObjects::BumperEventType::BUMPER_UNKNOWN)
{
	std::cout << "constructor LidarTask\n";
}
LidarTask::~LidarTask() 
{
	delete _lidar;
	std::cout << "destructor LidarTask\n";
}

int LidarTask::on_entry()
{
	if (!COMP->_supervisor || 
		!COMP->getGlobalState().getLidar_properties().getEnable())
    	return -1;
	
	COMP->mRobotMutex.acquire();

	for (int i = 0; i < COMP->_supervisor->getNumberOfDevices(); i++)
	{
		auto webotsDevice = COMP->_supervisor->getDeviceByIndex(i);
		if (webotsDevice->getNodeType() == webots::Node::LIDAR)
		{
			_lidar = dynamic_cast<webots::Lidar*>(webotsDevice);
			_lidar->enable(computeLidarUpdate());
			break;
		}
	}
	if (_lidar == NULL)
	{
		std::cerr << "You enable a Lidar, but robot has not such device!" 
		<< std::endl;
		COMP->mRobotMutex.release();
		return -1;
	}

	_lidar->enablePointCloud();
	horizontalResolution = _lidar->getHorizontalResolution();
	field_of_view = _lidar->getFov();
	numberValidPoints = _lidar->getNumberOfPoints();

	scan.set_scan_size(numberValidPoints);
	scan.set_scan_update_count(scanCount);
	scan.set_scan_double_field_of_view(- 180 * field_of_view / (2 * M_PI), 
		field_of_view * 180 / (horizontalResolution * M_PI));
	scan.set_max_distance((int)
		std::min(65535.0, _lidar->getMaxRange() * 1000.0));
	scan.set_min_distance(_lidar->getMinRange() * 1000.0);
	scan.set_scan_length_unit(1);

	bumper_threshold_ = COMP->getParameters().getLidar_properties().
		getBumper_threshold();
	
	COMP->mRobotMutex.release();

	return 0;
}
int LidarTask::on_execute()
{
	if (!COMP->_supervisor || !_lidar)
		return -1;

	COMP->mRobotMutex.acquire();

	// From left to right
	double min_dist = bumper_threshold_ + .1;
	auto rangeImageVector = _lidar->getRangeImage();
	if (rangeImageVector)
	{
		++scanCount;
		timeval _receiveTime;
		::gettimeofday(&_receiveTime, 0);
		scan.set_scan_time_stamp(CommBasicObjects::CommTimeStamp(_receiveTime));
		scan.set_scan_update_count(scanCount);
		for (unsigned int i = 0; i < numberValidPoints; ++i)
		{
			// From right to left
      double ddist = rangeImageVector[numberValidPoints - 1 - i];
			min_dist = (ddist < min_dist) ? ddist : min_dist; 

			unsigned int dist = (unsigned int) (ddist * 1000.0);
			scan.set_scan_index(i, i);
			scan.set_scan_integer_distance(i, dist);
		}
		scan.set_base_state(*COMP->_pose.get());
		scan.set_scanner_x(COMP->_pose->get_base_position().get_x());
		scan.set_scanner_y(COMP->_pose->get_base_position().get_y());
		scan.set_scanner_z(COMP->_pose->get_base_position().get_z());
		scan.set_scanner_azimuth(COMP->_pose->get_base_position().get_base_azimuth());
		scan.set_scanner_roll(COMP->_pose->get_base_position().get_base_roll());
		scan.set_scanner_elevation(COMP->_pose->get_base_position().get_base_elevation());
		//TODO: This should translate to the sensor real pose
		// scan.set_sensor_pose(...);
		scan.set_scan_valid(true);
    
    CommBasicObjects::BumperEventType current_bumper_type = 
      (min_dist < bumper_threshold_) ? CommBasicObjects::BumperEventType::
      BUMPER_PRESSED : CommBasicObjects::BumperEventType::BUMPER_NOT_PRESSED;
    if (bumper_type_ != current_bumper_type){
      CommBasicObjects::CommBumperEventState state;
      state.setNewState(current_bumper_type);
      bumperEventServiceOutPut(state);
      bumper_type_ = current_bumper_type;
    }
	}
	else
		scan.set_scan_valid(false);

	laserServiceOutPut(scan);
	
	COMP->mRobotMutex.release();
	
	return 0;
}
int LidarTask::on_exit()
{
	return 0;
}

int LidarTask::computeLidarUpdate() const
{
	double simulation_step = COMP->_supervisor->getBasicTimeStep();
	double lidar_step = 1000.0 / 
		COMP->connections.lidarTask.periodicActFreq;
	int duration = (int) (
		ceil(lidar_step / simulation_step) * simulation_step);
	std::cout << "Lidar duration is: " <<  duration << "\n";
	return duration;
}
