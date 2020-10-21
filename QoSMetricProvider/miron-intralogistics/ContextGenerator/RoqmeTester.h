#include <RoqmeWriterImpl.h>
#include <RoqmeDDSException.h>
#include <iostream>

class RoqmeTester 
{
public:
	int publicarInt();
	int publicarUInt();
	int publicarDouble();
	int publicarBool();
	int publicarEnum();
	int publicarEvent();
	int publicarObservacion();
	int publicarEstimacion();
	void showOptions(char& op);
private:
	int preguntarNombre();
	int mostrarIntroduceValor();
	int preguntarValor(int & valor);
	int preguntarValor(unsigned int & valor);
	int preguntarValor(bool & valor);
	int preguntarValor(std::string & valor);
	int preguntarValor(double & valor);

private:
	std::string nombre;

	Roqme::RoqmeIntWriter intWr;
	Roqme::RoqmeUIntWriter uintWr;
	Roqme::RoqmeDoubleWriter doubleWr;
	Roqme::RoqmeBoolWriter boolWr;
	Roqme::RoqmeEventWriter eventWr;
	Roqme::RoqmeEnumWriter enumWr;
	Roqme::RoqmeObservationWriter observationWr;
	Roqme::RoqmeEstimateWriter estimateWr;

	RoqmeDDSTopics::RoqmeIntContext	intCtx;		
	RoqmeDDSTopics::RoqmeUIntContext uintCtx;
	RoqmeDDSTopics::RoqmeBoolContext boolCtx;
	RoqmeDDSTopics::RoqmeDoubleContext doubleCtx;
	RoqmeDDSTopics::RoqmeEventContext eventCtx;
	RoqmeDDSTopics::RoqmeEnumContext enumCtx;		
	RoqmeDDSTopics::RoqmeObservation observation;
	RoqmeDDSTopics::RoqmeEstimate estimate;
};
