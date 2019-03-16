#include "stdafx.h"
#include "ModelExporter_Reduced.h"

#include "SharedFunctions.h"
#include "Model_Reduced.h"

ModelExporter_Reduced::ModelExporter_Reduced()
{
}

ModelExporter_Reduced::~ModelExporter_Reduced()
{
}

void ModelExporter_Reduced::exportModel(std::string fileName)
{
	std::ofstream ofs;
	ofs.open(fileName, std::ofstream::out);
	if (!ofs.is_open()) {
		std::cout << "\n\nError, unable to open file [" << fileName << "] , exit now..";
		exit(0);
	}

	// export the first comments/misc section
	model->exportSectionToStream(1, ofs);

	ofs << std::endl;

	// export ALL NODES from MODEL
	ofs << "/ ______________________________________________________________________________" << std::endl;
	ofs << "/ ALL MODEL NODES" << std::endl;
//	for (map<long, Node*>::iterator it = model->nodes.begin(); it != model->nodes.end(); ++it)
	for (auto& item : model->nodes)
		if (item.second)
			item.second->exportToStream(ofs);

	ofs << std::endl;

	ofs << std::endl;

	ofs << "/ ______________________________________________________________________________" << std::endl;
	ofs << "/ ALL MODEL BEAMS" << std::endl;

	writeAllMapToStream<Beam>(model->beams, ofs);
	ofs << std::endl;

	ofs << "/ ______________________________________________________________________________" << std::endl;
	ofs << "/ ALL MODEL PLATES" << std::endl;
	writeAllMapToStream<Plate>(model->plates, ofs);
	ofs << std::endl;

	ofs << "/ ______________________________________________________________________________" << std::endl;
	ofs << "/ ALL MODEL RESTRAINTS" << std::endl;

	writeAllVectorToStream<Restraint>(model->restraints, ofs);
	ofs << std::endl;



	// export all the remaining sections
	for (int i = 2; i<=model->sectionsCount; i++)
		model->exportSectionToStream(i, ofs);

	ofs.close();

}
