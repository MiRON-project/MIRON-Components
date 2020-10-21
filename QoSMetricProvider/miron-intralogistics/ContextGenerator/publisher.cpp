#include "RoqmeTester.h"


int main (int argc, char *argv[])
{
	try
	{
		RoqmeTester roqmeTester;

		char op;
		do 
		{
			roqmeTester.showOptions(op);
			switch(op) 
			{
				case '1' : roqmeTester.publicarInt();
					break;
				case '2' : roqmeTester.publicarUInt();
					break;
				case '3' : roqmeTester.publicarDouble();
					break;
				case '4' : roqmeTester.publicarBool();
					break;
				case '5' : roqmeTester.publicarEvent();
					break;
				case '6' : roqmeTester.publicarEnum();
					break;
				case '7' : roqmeTester.publicarObservacion();
					break;
				case '8' : roqmeTester.publicarEstimacion();
					break;

			}
		} while(op!='0');		
	}
	catch(Roqme::RoqmeDDSException& e)
	{
		std::cerr << e.what() << std::endl;
	}	

	return 0;
}



