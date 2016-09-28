#pragma once
#include <fstream>
#include <time.h>

class AuditLog
{
public:
	AuditLog();
	~AuditLog();

	void LogWord(string word);
	string GetTimeStamp();

};

