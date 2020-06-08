
#ifndef _ROQMEESTIMATELISTENER_HH
#define _ROQMEESTIMATELISTENER_HH

#include <RoqmeReaderImpl.h>

class EstimateActivity;

class EstimateListener: public Roqme::RoqmeDDSListener<RoqmeDDSTopics::RoqmeEstimate>
{
public:
	EstimateListener(EstimateActivity* activity);
	void dataAvailable(const RoqmeDDSTopics::RoqmeEstimate& data, const dds::sub::SampleInfo& sampleInfo);

private:
	EstimateActivity* activity;
};

#endif

