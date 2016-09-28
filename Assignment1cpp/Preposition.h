#pragma once
#include "MiscWord.h"
class Preposition :
	public MiscWord
{
public:
	Preposition();
	Preposition(string w, string def, string t);
	~Preposition();
	string GetDef();
};

