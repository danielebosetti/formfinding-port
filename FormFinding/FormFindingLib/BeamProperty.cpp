#include "StdAfx.h"
#include "BeamProperty.h"


BeamProperty::BeamProperty(void)
{
	material_type = MATERIAL_UNKNOWN;
	isRigidLink = false;
	isElastic = false;
	density=1.;
	area=0.;
	modulus=1.;
}


BeamProperty::~BeamProperty(void)
{
}




void BeamProperty::readFromFileLoader(fileLoader& fL){
	std::string subs;
	char *s;

	try{
		fL.getWord(&s);
		this->ID=atol(s);

		fL.getWord(&s);
		this->color=atol(s);

		fL.getWord(&s);
		this->name=s;
		
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
				//fL.getWordDelimited(&s);
				fL.getWord(&s);
				this->sMap["MaterialName"]=s;
				materialName = s;
			}
			else if (subs=="Density") {
				//fL.getWordDelimited(&s);
				fL.getWord(&s);
				this->sMap["Density"]=s;
				density = atof(s);
			}
			else if (subs=="Area") {
				//fL.getWordDelimited(&s);
				fL.getWord(&s);
				this->sMap["Area"]=s;
				area = atof(s);
			}
			else if (subs=="Modulus") {
				//fL.getWordDelimited(&s);
				fL.getWord(&s);
				this->sMap["Modulus"]=s;
				modulus = atof(s);
			}
			else{
				std::string sKey = subs;
				fL.getWord(&s);
				this->sMap[sKey] = s;
			}
		} while(!fL.emptyLine());
			
	}
	catch(std::exception& e)
	{
		std::cout << " error BeamProperty::readFromFileLoader  <" << subs  << "> " << e.what() << '\n';}
	
}

std::string BeamProperty::toString(){
	std::string s;
	std::string s2;
	char s1[1000];
	sprintf_s(s1,1000," type: %s  ID: %d name: %s\n", type.c_str(), ID , this->name.c_str());
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

void BeamProperty::exportToStream(std::ostream& ofs){
	char stringOut[10000];
	sprintf_s(stringOut, "   %s%20d%12d   %s\n", type.c_str(), ID, color, name.c_str() );
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
}


