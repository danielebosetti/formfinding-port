// stdafx.h : file di inclusione per file di inclusione di sistema standard
// o file di inclusione specifici del progetto utilizzati di frequente, ma
// modificati raramente
//

#pragma once
#pragma warning (disable:4244)
#pragma warning (disable:4267)
//#pragma warning (disable:4018)

#include "targetver.h"
#include "SharedVariables.h"

#include <iostream>
#include <fstream>

#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <windows.h>
#include <cmath>
#include <ctime>

#include <stdio.h>
#include <tchar.h>
#include <ctype.h>

#include <Eigen/Dense>

#include "appSettings.h"
#include "utilCode.h"
#include "ModelItemsDeclare.h"
#include "GraphSplit.h"
#include "MapTypesDef.h"
#include "LoadCaseCombinationItem.h"
#include "ModelRenderer.h"
#include "LoadCaseCombination.h"
#include "FormFindingDataSet.h"
#include "Model.h"
#include "ModelLoader.h"
#include "WorkModel.h"
#include "ModelExporter.h"
#include "MainWindow.h"
#include "Application.h"

void coutVector(std::string label, Eigen::Vector3d& v, std::ostream& os);
