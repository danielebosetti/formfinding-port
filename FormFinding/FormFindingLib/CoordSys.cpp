#include "StdAfx.h"
#include "CoordSys.h"


CoordSys::CoordSys(void)
{
}


CoordSys::~CoordSys(void)
{
}

void CoordSys::exportToStream(std::ostream& ofs){
	char stringOut[10000];
	sprintf_s(stringOut, "   CoordSys  %d   %s   %s\n", this->ID, this->name.c_str(), this->type.c_str() );
	ofs << stringOut;

	for (unsigned int i=0; i<this->otherProperties.size(); i++)
		ofs << otherProperties[i] << std::endl;
}

void CoordSys::readFromFileLoader(fileLoader& fL){
	std::string subs;
	char *s;

	try{
		fL.getWord(&s);
		this->ID=atol(s);

		fL.getWord(&s);
		this->name = s;

		fL.getWord(&s);
		this->type = s;
		
		do {
			fL.getLine(&s);

			fL.getWord(&s);

			otherProperties.push_back(fL.lines[fL.currentLineIndex]);

		} while(!fL.emptyLine());

	}
	catch(std::exception& e)
	{
		std::cout << " error CoordSys::readFromFileLoader  <" << subs  << "> " << e.what() << '\n';}


}

std::string CoordSys::toString(){
	std::string s;
	char s1[1000];
	sprintf_s(s1,1000," ID: %d name: %s type: %s\n", this->ID , this->name.c_str(), this->type.c_str());
	s = s1;
	return s;
}

