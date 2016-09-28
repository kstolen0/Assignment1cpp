#include "stdafx.h"
#include "Noun.h"


Noun::Noun()
{
}

Noun::Noun(string w, string def, string t)
{
	word = w;
	definition = def;
	type = t;
}


Noun::~Noun()
{
}

bool Noun::IsNoun()
{
	return true;
}

string Noun::GetWord()
{
	return word;
}

string Noun::GetDef()
{
	return "(n.) " + definition;
}

