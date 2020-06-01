# ComponentWebotsObjectRecognition

This Component provides Object Recognition events and types.
![ComponentWebotsObjectRecognition](model/ComponentWebotsObjectRecognitionComponentDefinition.jpg)

## Service Ports

| Inputs  | outputs |
| ------- | ------- |
| **BaseStateServiceOut**: state of the robot base (position and orientation) | **ObjectEventBumpOut**: Event triggered when any object is found or wanted one |
| **ObjectPushServiceOut**: recognized objects and properties | **ObjectsSimpleRecognitionPushServiceOut**: Vector of simple objects types in database |

Known datatypes are: UNKOWN; SOFA; CHAIR; PORTRAIT; TABLE; BED; CAN; APPLE; GNOME; SWINGCOUCH; WATERINGCAN; BISCUITBOX; JAMJAR; ATM; BENCH; PUBLICBIN; SIMPLEBENCH; SNACKSTAND; TRASHBIN; TRASHCONTAINER; PEDESTRIAN.

## InternalParameter Settings

### Object Properties

| Attribute Name | Attribute Type | Description |
|----------------|----------------|-------------|
| **object_bump_threshold** | Double | The distance to trigger the event (object is considered too close in this threshold) |
| **object_bump_type** | String | The wanted type: event will only trigger for that type. If empty, it triggers for all types |
