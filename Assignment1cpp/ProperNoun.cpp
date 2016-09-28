#include "stdafx.h"
#include "ProperNoun.h"


ProperNoun::ProperNoun()
{
}

ProperNoun::ProperNoun(string w, string def, string t)
{
	word = w;
	definition = def;
	type = t;
}


ProperNoun::~ProperNoun()
{
}

string ProperNoun::GetWord()
{
	string temp = word;
	temp[0] -= LUDIFF;
	return temp;
}

string ProperNoun::GetDef()
{
	return "(pn.) " + definition;
}

int ProperNoun::CalcScrabbleScore()
{
	return 0;
}
