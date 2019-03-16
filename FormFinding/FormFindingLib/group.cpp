#include "StdAfx.h"
#include "group.h"


group::group(void)
{
}


group::~group(void)
{
}

void group::exportToStream(std::ostream& ofs){
	char stringOut[10000];
	sprintf_s(stringOut, "   Group%21d%12d   %s\n", this->ID, this->color, this->name.c_str());
	ofs << stringOut;
}


void group::readFromFileLoader(fileLoader& fL){
	std::string subs;
	char *s;

	try{
		fL.getWord(&s);
		this->ID=atol(s);

		fL.getWord(&s);
		this->color=atol(s);

		//fL.getWordDelimited(&s);
		fL.getWord(&s);
		this->name=s;
	}
	catch(std::exception& e)
	{
		std::cout << " error group::readFromFileLoader  <" << subs  << "> " << e.what() << '\n';}

	
}

std::string group::toString(){
	std::string s;
	char c[1000];
	sprintf_s(c,"Group ID: %d Color: %d Name: <%s> \n", ID, color, name.c_str() );
	s = c;
	return s;
}

