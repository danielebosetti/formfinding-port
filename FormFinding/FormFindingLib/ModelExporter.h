#pragma once

#include <string>
#include <iostream>

class Model;

class ModelExporter
{
public:
	Model *originalModel;
	Model *workingModel;

	std::string outBasePath;

	ModelExporter(void);
	~ModelExporter(void);

//	void exportModel();
//	void exportToSingleFile(string fileName);
	//void exportToSingleFile_Compose(string fileName);
	void exportToSingleFile_ComposeFinal(std::string fileName);

	//void exportToSingleFile2(string fileName);
};

