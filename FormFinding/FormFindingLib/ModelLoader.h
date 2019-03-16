#pragma once

#include "fileLoader.h"
#include <string>

class fileLoader;
class Model;

class ModelLoader
{
public:
	std::string fileName;
	Model *model;

	fileLoader fL;

	ModelLoader(void);
	~ModelLoader(void);

	void loadModel();
};

