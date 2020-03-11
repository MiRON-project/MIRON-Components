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
#include "ComponentWebotsCameraRecognitionCore.hh"

// constructor
ComponentWebotsCameraRecognitionCore::ComponentWebotsCameraRecognitionCore()
{
	webotsRobot = NULL;

	std::ifstream file_input("configuration.json");
	if (!file_input.is_open())
	{
		std::cerr << "Can't open 'configuration.json' file." << std::endl;
		return;
	}

	Json::Reader reader;
	if (!reader.parse(file_input, mConfiguration))
	{
		std::cerr << "Invalid 'configuration.json' file." << std::endl;
		return;
	}

	// assign this controller to the correct robot in Webots
	char *robotName = std::getenv("WEBOTS_ROBOT_NAME");
	if (!robotName)
	{
		if (!mConfiguration.isMember("name") || !mConfiguration["name"].isString())
		{
			std::cerr << "Missing or invalid 'name' key in 'configuration.json' file." << std::endl;
			return;
		}
		char environment[256] = "WEBOTS_ROBOT_NAME=";
		putenv(strcat(environment, mConfiguration["name"].asCString()));
	}

	// create Robot instance
	webotsRobot = new webots::Robot();
}
