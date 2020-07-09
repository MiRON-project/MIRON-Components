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
#ifndef _CAMERATASK_HH
#define _CAMERATASK_HH

#include "CameraTaskCore.hh"
#include <DomainVision/CommRGBDImage.hh>
#include <DomainVision/CommVideoImage.hh>
#include "CommObjectRecognitionObjects/CommObjectRecognitionObjectProperties.hh"
#include "CommObjectRecognitionObjects/CommObjectDominantColor.hh"
#include "CommObjectRecognitionObjects/CommObjectRecognitionEnvironment.hh"
#include <CommObjectRecognitionObjects/enumSimpleObjects.hh>

#include "Utils.hh"
#include <webots/Camera.hpp>

#include "Eigen/Geometry"

class CameraTask : public CameraTaskCore
{
private:
  webots::Camera *_camera;
  DomainVision::CommRGBDImage rgbd_image;
  DomainVision::CommVideoImage comm_video_image;
  unsigned long image_counter;
  Eigen::Affine3d _camera_pose; // Transform (sensor to robot)
  std::string object_bump_type_;
  double object_bump_threshold_;

  void getCameraPoseRobotFrame();
  void recognition();
  int computeCameraUpdate() const;

public:
  CameraTask(SmartACE::SmartComponent *comp);
  virtual ~CameraTask();

  virtual int on_entry();
  virtual int on_execute();
  virtual int on_exit();
};

#endif
