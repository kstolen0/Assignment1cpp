#pragma once
#include "Dictionary.h"
#include "TriPair.h"
#include <stdlib.h>

class TriGame
{
public:
	TriGame();
	~TriGame();
	void LoadFile();
	void FindTopThree(string p);
	void ListWords(Dictionary* words);

private:
	vector<TriPair> pairs;
	bool fileLoaded;
};

