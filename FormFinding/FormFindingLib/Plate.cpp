#include "StdAfx.h"
#include "Plate.h"


Plate::Plate(void)
{
	node4=-1;
	pNode4 = NULL;
	sumStresses = 0.0;
	sumPressures = 0.0;
	material_type = MATERIAL_UNKNOWN;
}


Plate::~Plate(void)
{
}

void Plate::exportToStream(std::ostream& ofs){
	char stringOut[10000];

	if (this->type == "Tri3")
		sprintf_s(stringOut, "   Tri3%22d%8d%8d%8d%8d%8d%8d\n", ID, Gr2, group, Property, node1, node2, node3 );
	else
		sprintf_s(stringOut, "   Quad4%21d%8d%8d%8d%8d%8d%8d%8d\n", ID, Gr2, group, Property, node1, node2, node3, node4 );
	ofs << stringOut;

	/*if (this->type == "Tri3")
	{
		sprintf_s(c," ID: %d boh: %d group: %d property: %d node1: %d node2: %d node3: %d \n",  ID, boh, group, Property, node1, node2, node3);
	}else{
		sprintf_s(c," ID: %d boh: %d group: %d property: %d node1: %d node2: %d node3: %d node4: %d \n",  ID, boh, group, Property, node1, node2, node3, node4);		
	}
	s = "Plate type: "+type+c;*/


}


void Plate::readFromFileLoader(fileLoader& fL){
	char *s;
	std::string subs;
	try{
		
		fL.getWord(&s);
		subs=s;
		this->ID=stol(subs);
		
		fL.getWord(&s);
		subs=s;
		this->Gr2=stol(subs);
		
		fL.getWord(&s);
		subs=s;
		this->group=stol(subs);
		
		fL.getWord(&s);
		subs=s;
		this->Property=stol(subs);
		
		fL.getWord(&s);
		subs=s;
		this->node1=stol(subs);
		
		fL.getWord(&s);
		subs=s;
		this->node2=stol(subs);
		
		fL.getWord(&s);
		subs=s;
		this->node3=stol(subs);

		if(this->type == "Quad4")
		{
			fL.getWord(&s);
			subs=s;
			this->node4=stol(subs);	
			if (node4 == -1){
				std::cout << " \n\nERROR, Node ID for node4 shouldn't be -1 !!\nexit now." ;
				system("PAUSE");
				exit(0);
			}


		}

	}
	catch(std::exception& e)
	{
		std::cout << " error Plate::readFromFileLoader  <" << subs  << "> " << e.what() << '\n';}

}

std::string Plate::toString(){
	char c[1000];
	std::string s;
	if (this->type == "Tri3")
	{
		sprintf_s(c," ID: %d boh: %d group: %d property: %d node1: %d node2: %d node3: %d \n",  ID, boh, group, Property, node1, node2, node3);
	}else{
		sprintf_s(c," ID: %d boh: %d group: %d property: %d node1: %d node2: %d node3: %d node4: %d \n",  ID, boh, group, Property, node1, node2, node3, node4);		
	}
	s = "Plate type: "+type+c;
	return s;
}