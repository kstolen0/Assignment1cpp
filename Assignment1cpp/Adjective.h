#pragma once
#include "Word.h"
class Adjective :
	public Word
{
public:
	Adjective();
	Adjective(string w, string def, string t);
	~Adjective();
	string GetDef();

};

