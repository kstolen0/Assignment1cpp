#pragma once
#include <iostream>
#include <string>
using namespace std;

class Word
{

public:
	Word();
	Word(string w, string def,string t);
	virtual ~Word();
	
	virtual string GetWord();
	virtual string GetDef();
	string GetType();
	
	void SetWord(string w,string def, string t);

	virtual int CalcScrabbleScore();
	bool IsHyphenated();
	bool IsPalindrome();
	virtual bool IsVerb();
	virtual bool IsNoun();

protected:
	string word;
	string definition;
	string type;
	
};


