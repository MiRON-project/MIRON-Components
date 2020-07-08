#include "EstimateListener.hh"
#include "QoSMetricProvider.hh"
#include "EstimateActivity.hh"

EstimateListener::EstimateListener(EstimateActivity* activity)
{
	this->activity = activity;
}

void EstimateListener::dataAvailable(const RoqmeDDSTopics::RoqmeEstimate& data, const dds::sub::SampleInfo& sampleInfo)
{
	/*
	std::cout << "ESTIMATE sample available:" << std::endl;
	std::cout << "\t name: " << data.name() << std::endl;
	std::cout << "\t value: " << data.value() << std::endl;
	*/

	CommRoqmeEstimate::RoqmeEstimate estimate;
	estimate.setName(data.name());
	estimate.setValue(data.value());

	//std::cout << "Publishing data" << std::endl;
	Smart::StatusCode status = COMP->estimateServiceOut->put(estimate);
	if(status!= Smart::SMART_OK)
	{
		std::cout << "Error pushing estimate data: " << Smart::StatusCodeConversion(status) << std::endl;
	}

}

