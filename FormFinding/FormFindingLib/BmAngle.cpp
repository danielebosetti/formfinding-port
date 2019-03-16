#include "StdAfx.h"
#include "BmAngle.h"


BmAngle::BmAngle(void)
{
}


BmAngle::~BmAngle(void)
{
}

void BmAngle::exportToStream(std::ostream& ofs){
	char stringOut[10000];
	sprintf_s(stringOut, "   BmAngle%19d%24.15E\n", ID, this->angle);
	ofs << stringOut;
}


void BmAngle::readFromFileLoader(fileLoader& fL){
	char* s;
	std::string subs;
		
	try{
		fL.getWord(&s);
		subs=s;
		this->ID= stol(subs);

		fL.getWord(&s);
		subs=s;
		this->angle= stod(subs);

	}
	catch(std::exception& e)
	{
		std::cout << " error BmAngle::readFromFileLoader  <" << subs  << "> " << e.what() << '\n';}

}

std::string BmAngle::toString()
{
	std::string s;
	char c[1000];
	sprintf_s(c,"BmAngle ID: %d Angle: %g \n", ID, this->angle);
	s = c;
	return s;
}