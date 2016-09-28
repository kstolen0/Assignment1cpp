#pragma once
#include "Word.h"
class Noun :
	public virtual Word
{
public:
	Noun();
	Noun(string w, string def, string t);
	virtual ~Noun();
	bool IsNoun();
	virtual string GetWord();
	virtual string GetDef();

};



