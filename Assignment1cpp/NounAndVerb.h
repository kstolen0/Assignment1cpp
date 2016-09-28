#pragma once
#include "Noun.h"
#include "Verb.h"
class NounAndVerb :
	public Noun, public Verb
{
public:
	NounAndVerb();
	NounAndVerb(string w, string def, string t);
	~NounAndVerb();
	bool IsNoun();
	bool IsVerb();
	string GetDef();
};
