#include "stdafx.h"

#include "ModelLoader_Reduced.h"
#include "Straus_Constants.h"
#include "Model_Reduced.h"

ModelLoader_Reduced::ModelLoader_Reduced()
{
}

ModelLoader_Reduced::~ModelLoader_Reduced()
{
}

void ModelLoader_Reduced::loadModel()
{
	std::ifstream ifs;
	ifs.open(fileName, std::ifstream::in);

	//check file open, altrimenti d� errore e esce
	if (!ifs) {
		std::cout << " ERROR : file not found: " << fileName << "\n";
		system("PAUSE");
		exit(0);
	}
	ifs.close();

	char  *s2;

	std::cout << "\nFile open " << fileName;
	fL.fileName = fileName;
	fL.initFileLoader();

	std::cout << "\n\nLoading File..\n";
	fL.loadFile();
	fL.splitAllFile();
	std::cout << "End loading file.\n";

	int i = 0;

	std::string line, subs;

	std::cout << "\nCreating objects..";
	std::cout << "\n100k > ";
	long count100k = 0;
	char *line1;


	//LOOP over file
	while (fL.getLine(&line1))
	{
		count100k = count100k + 1;
		if ((count100k % 100000) == 0) std::cout << ".";

		fL.getWord(&s2);
		subs = s2;

		// legge un NODE
		if (strcmp(s2, str_Node) == 0) {
			Node *n;
			n = new Node();
			n->readFromFileLoader(fL);
			model->nodes[n->ID] = n;
			i++;
		}
		else if (strcmp(s2, str_Beam) == 0) {
			Beam *b;
			b = new Beam();
			b->readFromFileLoader(fL);
			model->beams[b->ID] = b;
			i++;
			//cout << "\nbeam " << b->ID;
		}
		else if (strcmp(s2, str_Tri3) == 0) {
			//		/ PLATE ELEMENTS
			Plate *plate;
			plate = new Plate();
			plate->type = "Tri3";
			plate->readFromFileLoader(fL);
			model->plates[plate->ID] = plate;
			i++;
		}
		else if (strcmp(s2, str_Quad4) == 0) {
			//		/ PLATE ELEMENTS
			Plate *plate;
			plate = new Plate();
			plate->type = "Quad4";
			plate->readFromFileLoader(fL);
			model->plates[plate->ID] = plate;
			i++;
		}
		else if (strcmp(s2, str_NdFreedom) == 0) {
			Restraint *rest;
			rest = new Restraint();
			rest->readFromFileLoader(fL);
			model->restraints.push_back(rest);
		}
		else if (strcmp(s2, str_BAR) == 0) {
			// str_BAR =  str_/
			//		COMMENteD LINE? insert COMMENT >>
			fL.pushComment();
		}
		else {
			//		COMMENteD LINE? insert COMMENT >>
			fL.pushComment();
			//printf( " unknown line?  <%s>   line size: %d", &(fL.buffer[fL.iniLine]), fL.lineLength() );
		}
	}

	std::cout << "\nObjects created.\n";
	// COPY COMMENTED SECTIONS TO MODEL
	model->linesToCopy = fL.linesToCopy;
	model->sectionFirstLine = fL.sectionFirstLine;
	model->sectionLinesCount = fL.sectionLinesCount;
	model->sectionsCount = fL.sectionsCount;

	std::cout << "Found: " << i << " elements\n";
	std::cout << "Number of lines in input file: " << fL.fileLinesCount << "\n";
	std::cout << "Number of Comments/Unknown sections found: " << model->sectionsCount << "\n";
}
