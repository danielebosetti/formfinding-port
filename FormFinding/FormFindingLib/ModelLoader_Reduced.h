#pragma once

class Model_Reduced;

class ModelLoader_Reduced
{
public:
	ModelLoader_Reduced();
	~ModelLoader_Reduced();

	std::string fileName;
	Model_Reduced *model;
	fileLoader fL;
	void loadModel();
};

