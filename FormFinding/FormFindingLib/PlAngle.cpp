#include "fileLoader.h"

#include "PlAngle.h"


PlAngle::PlAngle(void)
{
}


PlAngle::~PlAngle(void)
{
}



void PlAngle::exportToStream(std::ostream& ofs){
	char stringOut[10000];
	sprintf_s(stringOut, "   PlAngle%19d%25.14E\n", ID, angle);
	ofs << stringOut;
}


void PlAngle::readFromFileLoader(fileLoader& fL){
	char* s;
	std::string subs;
		
	try{
		fL.getWord(&s);
		subs=s;
		this->ID= stol(subs);

		fL.getWord(&s);
		this->angle= atof(s);
	}
	catch(std::exception& e)
	{
		std::cout << " error Stage::readFromFileLoader  <" << subs  << "> " << e.what() << '\n';}

}

std::string PlAngle::toString()
{
	std::string s;
	char c[1000];
	sprintf_s(c, "PlAngle ID: %d  angle %g \n", ID, angle);
	s = c;
	return s;
}
