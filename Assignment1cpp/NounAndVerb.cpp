#include "stdafx.h"
#include "NounAndVerb.h"


NounAndVerb::NounAndVerb()
{
}

NounAndVerb::NounAndVerb(string w, string def, string t)
{
	word = w;
	definition = def;
	type = t;
}


NounAndVerb::~NounAndVerb()
{
}

bool NounAndVerb::IsNoun()
{
	return true;
}

bool NounAndVerb::IsVerb()
{
	return true;
}

string NounAndVerb::GetDef()
{
	return "(n.v.) " + definition;
}
