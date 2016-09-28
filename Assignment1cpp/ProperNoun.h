#pragma once
#include "Noun.h"

class ProperNoun :
	public Noun
{
public:
	ProperNoun();
	ProperNoun(string w, string def, string t);
	~ProperNoun();
	string GetWord();
	string GetDef();
	int CalcScrabbleScore();
};

