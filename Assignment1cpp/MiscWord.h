#pragma once
#include "Word.h"
class MiscWord :
	public Word
{
public:
	MiscWord();
	MiscWord(string w, string def, string t);
	virtual ~MiscWord();

	int CalcScrabbleScore();
	virtual string GetDef();
};

