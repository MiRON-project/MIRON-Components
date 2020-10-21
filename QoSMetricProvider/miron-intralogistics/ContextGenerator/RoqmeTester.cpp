#include "RoqmeTester.h"


int RoqmeTester::publicarInt()
{
	int valor;

	preguntarNombre();
	preguntarValor(valor);	

	intCtx.name(nombre);
	intCtx.value().clear();
	intCtx.value().push_back(valor);
	intWr.write(intCtx);

	return 0;
}

int RoqmeTester::publicarUInt()
{
	unsigned int valor;

	preguntarNombre();
	preguntarValor(valor);	

	uintCtx.name(nombre);
	uintCtx.value().clear();
	uintCtx.value().push_back(valor);
	uintWr.write(uintCtx);	

	return 0;
}

int RoqmeTester::publicarDouble()
{
	double valor;

	preguntarNombre();
	preguntarValor(valor);	

	doubleCtx.name(nombre);
	doubleCtx.value().clear();
	doubleCtx.value().push_back(valor);
	doubleWr.write(doubleCtx);

	return 0;	

}

int RoqmeTester::publicarBool()
{
	bool valor;

	preguntarNombre();
	preguntarValor(valor);	

	/*if(valor)
		valor = true;
	else
		valor = false;
*/
	boolCtx.name(nombre);
	boolCtx.value().clear();
	boolCtx.value().push_back(valor);
	boolWr.write(boolCtx);

	return 0;
}

int RoqmeTester::publicarEnum()
{
	std::string valor;

	preguntarNombre();
	preguntarValor(valor);	

	enumCtx.name(nombre);
	enumCtx.value().clear();
	enumCtx.value().push_back(valor);
	enumWr.write(enumCtx);

	return 0;
}

int RoqmeTester::publicarEvent()
{
	std::string valor;

	preguntarNombre();
	preguntarValor(valor);		

	eventCtx.name(nombre);
	eventCtx.value().clear();
	eventCtx.value().push_back(valor);
	eventWr.write(eventCtx);

	return 0;
}

int RoqmeTester::publicarObservacion()
{
	preguntarNombre();

	observation.name(nombre);
	observationWr.write(observation);

	return 0;
}

int RoqmeTester::publicarEstimacion()
{
	double valor;

	preguntarNombre();	
	preguntarValor(valor);		

	estimate.name(nombre);
	estimate.value(valor);
	estimateWr.write(estimate);	

	return 0;
}

/**
* Funciones miembro auxiliares
*/ 

void RoqmeTester::showOptions(char& op)
{
	std::cout << std::endl << "*************************************" << std::endl;
	std::cout << "1: Publicar un contexto de tipo Int" << std::endl;
	std::cout << "2: Publicar un contexto de tipo UInt" << std::endl;
	std::cout << "3: Publicar un contexto de tipo Double" << std::endl;
	std::cout << "4: Publicar un contexto de tipo Bool" << std::endl;
	std::cout << "5: Publicar un contexto de tipo Event" << std::endl;
	std::cout << "6: Publicar un contexto de tipo Enum" << std::endl;
	std::cout << "7: Publicar una observación" << std::endl;
	std::cout << "8: Publicar una estimación" << std::endl;	
	std::cout << "0: Salir" << std::endl;	
	std::cout << "**************************************" << std::endl;
	std::cout << "Elige una opcion: " << std::flush;
	std::cin >> op;
}

int RoqmeTester::preguntarNombre()
{
	std::cout << "Introduce el nombre del topico: " << std::flush;
	std::cin >> nombre;
	return 0;
}

int RoqmeTester::mostrarIntroduceValor()
{
	std::cout << "Introduce el valor: " << std::flush;
	return 0;
}

int RoqmeTester::preguntarValor(int & valor)
{
	mostrarIntroduceValor();
	std::cin >> valor;
	return 0;
}

int RoqmeTester::preguntarValor(unsigned int & valor)
{
	mostrarIntroduceValor();
	std::cin >> valor;
	return 0;
}

int RoqmeTester::preguntarValor(bool & valor)
{
	mostrarIntroduceValor();
	std::cin >> valor;
	return 0;
}

int RoqmeTester::preguntarValor(std::string & valor)
{
	mostrarIntroduceValor();
	std::cin >> valor;
	return 0;
}

int RoqmeTester::preguntarValor(double & valor)
{
	mostrarIntroduceValor();
	std::cin >> valor;
	return 0;
}


