# MIRON-Components

The QoSMetricProvider for MiRoN states.
![QoSMetricProvider](model/QoSMetricProviderComponentDefinition.jpg)

## Service Ports

| Inputs  | outputs |
| ------- | ------- |
| **SimplePeopleBumpPushServiceInPersonBump**: It periodically receives inputs if someone (or a desired person in parameters) is too close to the robot (true or false) | **EstimateServiceOut**: Estimation of Non-fuctional properties update to the reasoner |
| **SimpleWantedPeoplePushServiceInWantedPersonFound**: It periodically receives inputs if desired person (parameter) is in robot sight (true or false) | |
| **SimplePeoplePushServiceInPeopleInRoom**: It periodically receives inputs if a person is in robot's sight (true or false) | |
| **SimpleObjectBumpPushServiceInObjectBump**: It periodically receives inputs of objects that are too close to the robot or just when the desired type of object is close (true or false) | |
| **SimpleBumperServiceInRobotBump**: It periodically receives info about robot state of "bump" (too close or far from objects/people) | |
| **BatteryPushServiceInBatteryCharging**: It is an input about battery charging (or not) | |
| **BatteryPushServiceInBatteryLevel**: It is an input about battery level | |