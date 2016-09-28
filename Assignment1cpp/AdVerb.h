#pragma once
#include "Word.h"
class AdVerb :
	public Word
{
public:
	AdVerb();
	AdVerb(string w, string def, string t);
	~AdVerb();
	string GetDef();

};

