#include "stdafx.h"
#include "Verb.h"


Verb::Verb()
{
}

Verb::Verb(string w, string def, string t)
{
	word = w;
	definition = def;
	type = t;
}


Verb::~Verb()
{
}

bool Verb::IsVerb()
{
	return true;
}

string Verb::GetDef()
{
	return "(v.) " + definition;
}
