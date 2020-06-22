# ComponentWebotsPersonRecognition

This Component provides the recognized person information (name, id, other data), compairing characteristics in a "people.json" file with the object information got by the robot's camera.
![ComponentWebotsPersonRecognition](model/ComponentWebotsPersonRecognitionComponentDefinition.jpg)

## Service Ports

| Inputs  | outputs |
| ------- | ------- |
| **ObjectPushServiceIn**: recognized objects and properties | **PeoplePushServiceOut**: Person data |
| **RGBImagePushServiceOut**: Camera image | **WantedPersonServiceOut**: It is an event that triggers if desired person (parameter) is found |
| **BaseStateServiceIn**: Robot's base state information (robot pose) | **PeopleEventServiceOut**: It is an event that triggers if a person is in the robot's sight |
| | **PeopleEventBumpServiceOut**: Is is an event that triggers if someone (or a desired person in parameters) is too close to the robot |
| | **SimplePeopleBumpPushServiceOut**: It periodically outputs if someone (or a desired person in parameters) is too close to the robot |
| | **SimpleWantedPeoplePushServiceOut**: It periodically outputs if desired person (parameter) is in robot sight |
| | **SimplePeoplePushServiceOut**: It periodically outputs if a person is in robot's sight |
| | **PersonQueryServiceAnsw**: Lisp commands can query if a specific person is or previously was in robot's sight |


## InternalParameter Settings

### Recognition Properties

| Attribute Name | Attribute Type | Description |
|----------------|----------------|-------------|
| **color_base** | Boolean | true if one want to use person recognition by json file comparison |
| **people_bump_threshold** | Double | Threshold for person bump event in meters [m]: it is useful if one wants to get close to a person, or one does not |
| **person_bump_name** | String | If string has a specific name, the event occurs only for that name |
| **wanted_person_name** | String | The person to be found |