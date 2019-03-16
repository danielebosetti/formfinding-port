
#include "PlateProperty.h"
#include "SharedVariables.h"
#include "fileLoader.h"
#include <iostream>
#include <string>

bool is_number(const std::string& s);

PlateProperty::PlateProperty(void)
{
	elastProperty = "";
	memThick = 0.0;
	density = 0.0;
	material_type = MATERIAL_UNKNOWN;
}


PlateProperty::~PlateProperty(void)
{
}



void PlateProperty::readFromFileLoader(fileLoader& fL){
	std::string subs;
	char *s;

	try{

		if (!is_number(fL.nextWord())){
			fL.getWord(&s);
			elastProperty = s;
		}

		fL.getWord(&s);
		ID=atol(s);

		fL.getWord(&s);
		color=atol(s);

		fL.getWord(&s);
		name = s;
		
		if (name=="")
			std::cout << "\n ERROR PlateProperty::readFromFileLoader : empty name? ";

		do {
			fL.getLine(&s);

			// salva la line
			if((*s)!=0)
				properties.push_back(s);


			fL.getWord(&s);

			// splitta ...
			subs=s;
			// NOTE! attenzione ai delimiters "
			if (subs=="MaterialName") {
				fL.getWord(&s);
				this->sMap["MaterialName"]=s;
				materialName = s;
			}
			else if (subs=="MemThick") {
				fL.getWord(&s);
				this->sMap["MemThick"]=s;
				memThick = atof(s);
			}
			else if (subs=="Density") {
				fL.getWord(&s);
				this->sMap["Density"]=s;
				density = atof(s);
			}
			else{
				std::string sKey = subs;
				fL.getWord(&s);
				this->sMap[sKey] = s;
			}
//		} while(fL.lineLength()>0);
		} while(!fL.emptyLine());

	}
	catch(std::exception& e)
	{
		std::cout << " error PlateProperty::readFromFileLoader  <" << subs  << "> " << e.what() << '\n';}

	//cout << "\n PlateProperty: Name: " << name << "\t MaterialName: " << sMap["MaterialName"].c_str() <<
	//		"\t MemThick: " << memThick << "\t Density:: " << density;

	
}

std::string PlateProperty::toString(){
	std::string s;
	std::string s2;
	char s1[1000];
	sprintf_s(s1,1000," ID: %d name: %s\n", this->ID , this->name.c_str());
	s = s1;

	// show content:
	for (std::map<std::string, std::string>::iterator it=sMap.begin(); it!=sMap.end(); ++it)
		if (it->second != "")
			s = s + it->first + " => " + it->second + "\n"  ;
	// show content:
	for (std::map<std::string,double>::iterator it=dMap.begin(); it!=dMap.end(); ++it){
		char s3[1000];
		sprintf_s(s3,1000,"%g", it->second);
		s = s + it->first + " => " + s3 + "\n" ;
	}
	s=s+"\n";
	return s;

}

void PlateProperty::exportToStream(std::ostream& ofs){
	char stringOut[10000];
	sprintf_s(stringOut, "   %s      %s %7d%12d   %s\n", type.c_str(), elastProperty.c_str(), ID, color, name.c_str()  );
	ofs << stringOut;


	unsigned long i;
	for(i=0; i< properties.size(); i++){
		sprintf_s(stringOut, "%s\n", properties[i] );
		ofs << stringOut;
	}

	// NOTE: export using the map is disabled, VECTOR is used instead.
	//for (map<string,string>::iterator it=sMap.begin(); it!=sMap.end(); ++it)
	//	if (it->second != ""){
	//		sprintf_s(stringOut, "     %-22s%s\n", it->first.c_str(), it->second.c_str() );
	//		ofs << stringOut;
	//	}

	ofs << std::endl;
//			s = s + it->first + " => " + it->second + "\n"  ;
}

