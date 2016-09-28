#include "stdafx.h"
#include "Adjective.h"


Adjective::Adjective()
{
}

Adjective::Adjective(string w, string def, string t)
{
	word = w;
	definition = def;
	type = t;
}


Adjective::~Adjective()
{
}

string Adjective::GetDef()
{
	return "(adj.) " + definition;
}
