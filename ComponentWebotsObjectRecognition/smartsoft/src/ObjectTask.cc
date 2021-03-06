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
#include "ObjectTask.hh"
#include "ComponentWebotsObjectRecognition.hh"

#include <iostream>

const std::unordered_map<std::string, CommObjectRecognitionObjects::
                                          SimpleObjects>
    ObjectTask::obj_str_enum = ObjectTask::createObjStrToEnumMap();

ObjectTask::ObjectTask(SmartACE::SmartComponent *comp)
    : ObjectTaskCore(comp)
{
  std::cout << "constructor ObjectTask\n";
}
ObjectTask::~ObjectTask()
{
  std::cout << "destructor ObjectTask\n";
}

int ObjectTask::on_entry()
{
  if (!COMP)
    return -1;

  object_bump_threshold_ = COMP->getParameters().getObject_properties().getObject_bump_threshold();
  //std::cout << "bump threshold: " << object_bump_threshold_ << std::endl;
  object_bump_type_ = COMP->getParameters().getObject_properties().getObject_bump_type();

  return 0;
}

int ObjectTask::on_execute()
{
  ObjectEnvironment objectsPushServiceInObject;
  BaseState baseStateServiceInObject;

  auto status_obj = objectsPushServiceInGetUpdate(objectsPushServiceInObject);
  auto status_base = baseStateServiceInGetUpdate(baseStateServiceInObject);

  if (status_obj == Smart::SMART_OK && status_base == Smart::SMART_OK){
    checkBump(objectsPushServiceInObject, baseStateServiceInObject);
    objectSimpleRecognition(objectsPushServiceInObject);
  }

  return 0;
}
int ObjectTask::on_exit()
{
  // use this method to clean-up resources which are initialized in on_entry() and needs to be freed before the on_execute() can be called again
  return 0;
}

void ObjectTask::checkBump(const ObjectEnvironment& objs, 
const BaseState& base) {
  BumpState bump;
  CommBasicObjects::SimpleBumpState simple_bump_state;
  simple_bump_state.setIs_valid(true);
  bump.setState(CommObjectRecognitionObjects::ObjectBumpState::NOT_BUMP);
  std::vector<unsigned int> ids;
  //std::cout << __LINE__ << " : " << __FILE__ << " " << object_bump_threshold_ << std::endl;
  //if(objs.get_size()==0) std::cout << "No hay objetos!!!" << std::endl;
  for(auto& obj : objs.getObjectsCopy()){
    if (object_bump_type_.empty() || object_bump_type_ == obj.getObject_type()){
      auto dist = sqrt(
        pow(obj.getPose().get_x(1) - base.getBasePose().get_x(1), 2) +
        pow(obj.getPose().get_y(1) - base.getBasePose().get_y(1), 2));
      if (dist < object_bump_threshold_) {
        simple_bump_state.setIs_bumped(true);
        ids.push_back(obj.getObject_id());
        bump.setState(CommObjectRecognitionObjects::ObjectBumpState::BUMP);
       // std::cout << "Object bump! Object is: " << obj.getObject_type() << "\n";
      }
    }
  }
  simpleObjectBumpPushServiceOutPut(simple_bump_state);
  bump.setObject_id(ids);
  objectEventBumpOutPut(bump);
}

std::unordered_map<std::string, CommObjectRecognitionObjects::SimpleObjects>
ObjectTask::createObjStrToEnumMap()
{

  std::unordered_map<std::string, CommObjectRecognitionObjects::SimpleObjects>
      map;

  map["portrait"] = CommObjectRecognitionObjects::SimpleObjects::PORTRAIT;
  map["bed"] = CommObjectRecognitionObjects::SimpleObjects::BED;
  map["can"] = CommObjectRecognitionObjects::SimpleObjects::CAN;
  map["apple"] = CommObjectRecognitionObjects::SimpleObjects::APPLE;
  map["gnome"] = CommObjectRecognitionObjects::SimpleObjects::GNOME;
  map["swing couch"] = CommObjectRecognitionObjects::SimpleObjects::SWINGCOUCH;
  map["watering can"] = CommObjectRecognitionObjects::SimpleObjects::WATERINGCAN;
  map["biscuit box"] = CommObjectRecognitionObjects::SimpleObjects::BISCUITBOX;
  map["jam jar"] = CommObjectRecognitionObjects::SimpleObjects::JAMJAR;
  map["atm"] = CommObjectRecognitionObjects::SimpleObjects::ATM;
  map["bench"] = CommObjectRecognitionObjects::SimpleObjects::BENCH;
  map["public bin"] = CommObjectRecognitionObjects::SimpleObjects::PUBLICBIN;
  map["simple bin"] = CommObjectRecognitionObjects::SimpleObjects::SIMPLEBENCH;
  map["snack stand"] = CommObjectRecognitionObjects::SimpleObjects::SNACKSTAND;
  map["trash bin"] = CommObjectRecognitionObjects::SimpleObjects::TRASHBIN;
  map["trash container"] = CommObjectRecognitionObjects::SimpleObjects::TRASHCONTAINER;
  map["pedestrian"] = CommObjectRecognitionObjects::SimpleObjects::PEDESTRIAN;
  return map;
}

void ObjectTask::objectSimpleRecognition(const ObjectEnvironment& objs) {
  SimpleRecognition rec_types;
  std::vector<SimpleObjects> simple_types; 
  for(auto& obj : objs.getObjectsCopy()){
    try {
      simple_types.push_back(obj_str_enum.at(obj.getObject_type()));
    }
    catch (...)
    {
      simple_types.push_back(CommObjectRecognitionObjects::SimpleObjects::UNKOWN);
    }
  }
  rec_types.setTypes(simple_types);
  objectsSimpleRecognitionPushServiceOutPut(rec_types);
}
