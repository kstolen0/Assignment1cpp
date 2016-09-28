#pragma once
#include "Word.h"
#include "Adjective.h"
#include "AdVerb.h"
#include "AuditLog.h"
#include "MiscWord.h"
#include "Noun.h"
#include "NounAndVerb.h"
#include "Preposition.h"
#include "ProperNoun.h"
#include "Verb.h"

#include <vector>
#include <fstream>
#include <string>

class Dictionary
{
public:
	Dictionary();
	~Dictionary();

	//	Basic tasks
	int GetTotalNumberOfWords();
	void LoadDictionary();
	Word* FindWord(string word);
	void ListZs();
	void ListQs();
	void ListNounVerbs();
	void ListPalidromes();
	void HighestScores();

	//	Intermediate tasks
	void AnagramHigh(string word);
	void ListRhymes(string word);
	void ListAnagrams(string word);

	//	Advanced tasks

	//	Alt tasks
	void AltListNV();

protected:
	vector<Word*> words;
};

