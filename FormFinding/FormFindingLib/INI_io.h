#pragma once
class INI_io
{
public:
	INI_io(void);
	~INI_io(void);

	static void writeToIni(const char* paramName, double value);
	static void writeToIni(const char* paramName, long value);
	static void getFromIni(const char* paramName, const char* defaultValue, long& outValue);
	static void getFromIni(const char* paramName, const char* defaultValue, double& outValue);
	static void getFromIni(const char* paramName, const char* defaultValue, char* outValue);
	static void getFromIni(const char* paramName, const char* defaultValue, std::string& outValue);
	static void getFromIni(const char* paramName, const char* defaultValue, bool& outValue);
};

