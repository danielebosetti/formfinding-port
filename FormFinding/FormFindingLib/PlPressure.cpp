#include "StdAfx.h"
#include "PlPressure.h"


PlPressure::PlPressure(void)
{
}


PlPressure::~PlPressure(void)
{
}

void PlPressure::readFromFileLoader(fileLoader& fL)
{
	char *s;
	std::string subs;

	try{
		fL.getWord(&s);
		subs=s;
		this->loadPatternID=stol(subs);

		fL.getWord(&s);
		subs=s;
		this->plateID=stol(subs);

		fL.getWord(&s);
		subs=s;
		this->plPressureValue=stod(subs);
	}
	catch(std::exception& e)
	{
		std::cout << " error PlPressure::readFromFileLoader  <" << subs  << "> " << e.what() << '\n';}

}

std::string PlPressure::toString(){
	std::string s;
	char c[1000];
	sprintf_s(c,"loadPatternID: %d plateID: %d plPressureValue: %g\n", loadPatternID, plateID, plPressureValue);
	s=c;
	return s;
}

void PlPressure::exportToStream(std::ostream& ofs){
	char stringOut[10000];
	sprintf_s(stringOut, "   PlPressure %15d%8d%25.14E\n" ,  loadPatternID, plateID, plPressureValue  );
	ofs << stringOut;
}

