# ComponentWebotsHRI

This Component provides human-robot interaction: skills for the robot to query something to a person or to the environment. It communicates to the ComponentWebotsRobot to change the environment.
![ComponentWebotsRobots](model/ComponentWebotsHRIComponentDefinition.jpg)

## Service Ports

| Inputs  | outputs |
| ------- | ------- |
| | **ObjectPlacementPushServiceOut**: HRI to query an object placement on it |
| | **ObjectPlacementQueryServiceAnsw**: It is possible to send Lisp commands to query object placement |
| | **ObjectDropPushServiceOut**: HRI to query an object drop |
| | **ObjectDropQueryServiceAnsw**: It is possible to send Lisp commands to query object drop |
