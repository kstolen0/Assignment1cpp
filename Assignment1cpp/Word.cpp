#include "stdafx.h"
#include "Word.h"


// Constructor can create an empty word and definition or accept
//		a word and definition on creation
Word::Word()
{
	word = "";
	definition = "";
	type = "";
}

Word::Word(string w, string def, string t)
{
	word = w;
	definition = def;
	type = t;
}


Word::~Word()
{
}

//Returns word associated with object
string Word::GetWord()
{
	return word;
}

//Returns definition associated with object
string Word::GetDef()
{
	return "(?) " + definition;
}

string Word::GetType()
{
	return type;
}

//Populate the word object
void Word::SetWord(string w,string def,string t)
{
	word = w;
	definition = def;
	type = t; 
}

// Calculates the scrabble score of a valid word
int Word::CalcScrabbleScore()	//Accepts an array containing the value of each letter
{
	int arr[26] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };
	if (!IsHyphenated())	//Check if valid word
	{
		int score = 0;

		for (int i = 0; i < word.size(); i++)
		{
			score += arr[tolower(word[i]) - 'a'];	//add score for each letter
		}

		return score;	// return scrabble score
	}
	return 0;	//If not valid return 0
	
}

// Checks if word contains a '-'
bool Word::IsHyphenated()
{

	//Loops through each letter of the word
	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] == '-')
		{
			return true; //Once '-' is found exit function
		}
	}

	return false;	//Return false if no '-' is found
}

// Checks if word is a palindrome
bool Word::IsPalindrome()
{
	string temp = "";
	string rWord = "";

	// Convert each letter to lowercase and store in temp string
	for (int i = 0; i < word.size(); i++)
	{
		temp += tolower(word[i]);
	}
	
	// Loop backwards through temp and append each character to rWord
	for (int i = temp.size() - 1; i >= 0; i--)
	{
		rWord.append(temp, i, 1);
	}

	// If rWord is equal to temp, the word is a palindrome, return true
	if (rWord == temp)
	{
		return true;
	}
	return false;	// If not a palindrome return false
}

// Check if word is a verb
bool Word::IsVerb()
{
	return false;
}

// Check if word is a noun
bool Word::IsNoun()
{
	return false;
}
