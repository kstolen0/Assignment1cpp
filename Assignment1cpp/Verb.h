#pragma once
#include "Word.h"
class Verb :
	public virtual Word
{
public:
	Verb();
	Verb(string w, string def, string t);
	virtual ~Verb();
	bool IsVerb();
	string GetDef();
};

