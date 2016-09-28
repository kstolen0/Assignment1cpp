#include "stdafx.h"
#include "MiscWord.h"


MiscWord::MiscWord()
{
}

MiscWord::MiscWord(string w, string def, string t)
{
	word = w;
	definition = def;
	type = t;
}


MiscWord::~MiscWord()
{
}

int MiscWord::CalcScrabbleScore()
{
	return 0;
}

string MiscWord::GetDef()
{
	return "(misc.) " + definition;
}
