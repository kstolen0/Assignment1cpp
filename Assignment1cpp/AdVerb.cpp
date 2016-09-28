#include "stdafx.h"
#include "AdVerb.h"


AdVerb::AdVerb()
{
}

AdVerb::AdVerb(string w, string def, string t)
{
	word = w;
	definition = def;
	type = t;
}


AdVerb::~AdVerb()
{
}

string AdVerb::GetDef()
{
	return "(adv.) " + definition;
}
