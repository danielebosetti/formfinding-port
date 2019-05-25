#pragma once

#pragma warning (disable:4244)
#pragma warning (disable:4267)
//#pragma warning (disable:4018)


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

using namespace std;


#include <Eigen/Dense>
using namespace Eigen;

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

#include "Model_Reduced.h"
#include "ModelLoader_Reduced.h"
#include "ModelExporter_Reduced.h"




// TODO: fare riferimento qui alle intestazioni aggiuntive richieste dal programma

void coutVector(string label, Vector3d& v, ostream& os);


// TODO: reference additional headers your program requires here
