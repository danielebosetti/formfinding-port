#include "StdAfx.h"
#include "INI_io.h"


INI_io::INI_io(void)
{
}


INI_io::~INI_io(void)
{
}


// writes a double value to the settings.ini file
void INI_io::writeToIni(const char* paramName, double value) {
	char strBuffer[1000];
	sprintf_s(strBuffer, 999, "%.14g", value);
	WritePrivateProfileStringA("default-settings", paramName, strBuffer, (appSettings::settingsDir + "settings.ini").c_str() );
}

// writes a long value to the settings.ini file
void INI_io::writeToIni(const char* paramName, long value) {
	char strBuffer[1000];
	sprintf_s(strBuffer, 999, "%d", value);
	WritePrivateProfileStringA("default-settings", paramName, strBuffer, (appSettings::settingsDir + "settings.ini").c_str() );
}


// reads a value from the INI file
void INI_io::getFromIni(const char* paramName, const char* defaultValue, long& outValue) {
	char strBuffer[1000];

	GetPrivateProfileStringA("default-settings", paramName, defaultValue, 
		strBuffer, sizeof(strBuffer), (appSettings::settingsDir + "settings.ini").c_str()  );
	outValue = atol(strBuffer);

	//cout << endl << "Read from INI file: " << paramName  << "=" << outValue;
}

// reads a value from the INI file
void INI_io::getFromIni(const char* paramName, const char* defaultValue, double& outValue) {
	char strBuffer[1000];

	GetPrivateProfileStringA("default-settings", paramName, defaultValue, 
		strBuffer, sizeof(strBuffer), (appSettings::settingsDir + "settings.ini").c_str()  );
	outValue = atof(strBuffer);
	//cout << endl << "Read from INI file: " << paramName  << "=" << outValue;
}

// reads a value from the INI file
void INI_io::getFromIni(const char* paramName, const char* defaultValue, char* outValue) {
	GetPrivateProfileStringA("default-settings", paramName, defaultValue, 
		outValue, 1000, (appSettings::settingsDir + "settings.ini").c_str()  );
//	outValue = atof(strBuffer);
	//cout << endl << "Read from INI file: " << paramName  << "=" << outValue;
}

// reads a value from the INI file
void INI_io::getFromIni(const char* paramName, const char* defaultValue, std::string& outValue) {
	char strBuffer[1000];

	GetPrivateProfileStringA("default-settings", paramName, defaultValue, 
		strBuffer, sizeof(strBuffer), (appSettings::settingsDir + "settings.ini").c_str()  );
	outValue = strBuffer;
	//cout << endl << "Read from INI file: " << paramName  << "=" << outValue;
}

// reads a boolan value from the INI file
void INI_io::getFromIni(const char* paramName, const char* defaultValue, bool& outValue) {
	std::string s;
	getFromIni(paramName, defaultValue, s);
	if ((s == "ON") || (s == "on")) 
		outValue = true;
	else if ((s == "OFF") || (s == "off")) 
		outValue = false;
	else {
		std::cout << "\nWARNING, check " << paramName << " in settings.ini ! <" << s << ">\n";
		system("PAUSE");
	}
}