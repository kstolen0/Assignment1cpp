#include "stdafx.h"
#include "Preposition.h"


Preposition::Preposition()
{
}

Preposition::Preposition(string w, string def, string t)
{
	word = w;
	definition = def;
	type = t;
}


Preposition::~Preposition()
{
}

string Preposition::GetDef()
{
	return "(prep.) " + definition;
}
