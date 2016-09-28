#include "stdafx.h"
#include "AuditLog.h"


AuditLog::AuditLog()
{
}


AuditLog::~AuditLog()
{
}

void AuditLog::LogWord(string word)
{
	string t = GetTimeStamp();
	word.append(" ");
	word.append(t);

	ofstream file;
	file.open("wordlog.txt", fstream::app);
	file << word << "\n";
	file.close();
}

string AuditLog::GetTimeStamp()
{
	time_t t = time(0);
	struct tm buff;
	string timestamp;
	char s[80];
	localtime_s(&buff, &t);
	strftime(s, sizeof(s), "%Y-%m-%d.%X", &buff);
	timestamp = s;
	return timestamp;
}
