#include "stdafx.h"
#include "Dictionary.h"


Dictionary::Dictionary()
{

}


Dictionary::~Dictionary()
{
	// Get rid of the pointers
	for (vector<Word*>::iterator it = words.begin(); it != words.end(); it++)
	{
		delete(*it);
	}
	words.clear();
}


//	Function to return the size of the word list
int Dictionary::GetTotalNumberOfWords()
{
	return words.size();
}

//	Function to load words from a dictionary file 
void Dictionary::LoadDictionary()
{
	// Let user decide how many words will be loaded, easier for testing too 
	int size = 0;	
	cout << endl;
	//	Similar function to the GetInt function except also checks if the size is more than the dictionary size
	while (true)
	{
		cout << "\n\nPlease enter the size of the dictionary, \nbelow " << MAXWORDS << " (or enter 0 for the entire dictionary): ";
		string entry;
		getline(cin, entry);
		stringstream stream(entry);		
		if (stream >> size)
		{
			if (size == 0)
			{
				size = MAXWORDS;
				break;
			}
			else if (size < MAXWORDS && size > 0)
			{
				break;
			}
			system("cls");
			cout << "\nI'd make a suggestion, but you wouldn't listen. No one ever does.";
		}
		else
		{
			system("cls");
			cout << "\nI may be synthetic, but I'm not stupid.";
		}		
	}

	//	Notify user the dictionary is being loaded (could add functionality to suggest how long it will take
	cout << "\n\nLoading dictionary. . . ";

	ifstream file("dictionary.txt");	//	Get dictionary file


	for (int i = 0; i < size; i++)	//	Loop through the selected number of words
	{
		string data[4];	
		for (int l = 0; l < 3; l++)	// Get 3 lines of the dictionary
		{
			getline(file, data[l]);			
		}

		Word *word; 

		//	Find out what type of word it is and create a new object
		if (data[2] == "n")
		{
			word = new Noun(data[0], data[1], data[2]);
		}
		else if (data[2] == "adj")
		{
			word = new Adjective(data[0], data[1], data[2]);
		}
		else if (data[2] == "v")
		{
			word = new Verb(data[0], data[1], data[2]);
		}
		else if (data[2] == "misc")
		{
			word = new MiscWord(data[0], data[1], data[2]);
		}
		else if (data[2] == "adv")
		{
			word = new AdVerb(data[0], data[1], data[2]);
		}
		else if (data[2] == "pn")
		{
			word = new ProperNoun(data[0], data[1], data[2]);
		}
		else if (data[2] == "n_and_v")
		{
			word = new NounAndVerb(data[0], data[1], data[2]);
		}
		else if (data[2] == "prep")
		{
			word = new Preposition(data[0], data[1], data[2]);
		}
		else
		{
			continue;
		}
		
		//	Add new word to the list
		words.push_back(word);
		getline(file, data[3]);	//	Read the empty line of the dictionary
	}
	file.close();	//	Close the file after use

	

}


//	Function to find a given word in the dictionary list. Using a binary search tree
//		Have had some odd issues with '-'s

Word* Dictionary::FindWord(string word)
{
	int low = 0;
	int hi = GetTotalNumberOfWords()-1;
	int idx = 0;
	Word* found = NULL; 
	int dash = word.find("-", 0);	//	Check if this word contains a dash


	do
	{
		idx = (hi + low) / 2;
		Word *temp = words[idx];
		string tWord = temp->GetWord();	//	Get the word part of the indexed word

		if (dash < 0)	//	If the given word has no dash, get rid of the other word's dash (makes words like "livingroom" and "living-room" the same)
		{
			int pos = tWord.find("-", 0);
			if (pos > -1)
			{
				tWord.replace(pos, 1, "");
			}
		}

		for (int i = 0; i < word.size(); i++)	//	Change any capital letters to lowercase
		{
			if (word[i] < 91 && word[i] > 64)
			{
				word[i] += LUDIFF;
			}
		}
		
		if (word == tWord)	//	Compare the given word to the indexed word 
		{
			//	Set found to true and exit the loop 
			found = temp;	
			break;
		}
		else if (word < tWord)	//	If the given word is too low, reduce the upper boundary
		{
			hi = idx - 1;
		}
		else if(word > tWord)	//	If the given word is too high, increase the lower boundary
		{
			low = idx + 1;
		}
		
	} while (low <= hi);	//	Keep doing until low > hi

	//	If found, add the word to the log file
	if (found)
	{
		AuditLog log;
		log.LogWord(found->GetWord());
	}
	return found;
}


//	Function to list all the words with more than 3 zs
void Dictionary::ListZs()
{
	bool found = false;

	for (vector<Word*>::iterator it = words.begin(); it != words.end(); it++)
	{
		string word = (*it)->GetWord();
		int zs = 0;
		
		// Search through the word to find the zs
		for (int i = 0; i < word.size(); i++)
		{
			if (word[i] == 'z')
			{
				zs++;
				if (zs > 3)
				{
					//	If the word has at least 4 zs, set found to true and move to the next word
					cout << word << endl;
					found = true;
					break;
				}
			}
		}
	}

	//	If not found, notify the user no words have more than 3 zs
	if (!found)
	{
		cout << "\n\nNo words in the dictionary contain more than 3 z's. \n\n";
	}
}

//	Function to list words with a q with not following u
void Dictionary::ListQs()
{
	bool found = false;

	for (vector<Word*>::iterator it = words.begin(); it != words.end(); it++)
	{
		string word = (*it)->GetWord();

		//	Search through the word, ending with the second last word
		for (int i = 0; i < word.size()-1; i++)
		{
			if (word[i] == 'q')
			{
				if (word[i + 1] != 'u')
				{
					cout << word << endl;
					found = true;
				}
			}
		}

		//	Check the last letter
		if (word[word.size() - 1] == 'q')
		{
			cout << word << endl;
			found = true;
		}
	}

	//	If not found, notify the user no words have a q without a following u
	if (!found)
	{
		cout << "\n\nNo words in the dictionary contain a 'q' without a following 'u'. \n\n";
	}
}

//	Function to list all the words which are nouns and verbs
void Dictionary::ListNounVerbs()
{
	//	Search through list and do a dynamic cast (ever so slightly faster than checking isNoun and isVerb)
	for (vector<Word*>::iterator it = words.begin(); it != words.end(); it++)
	{
		NounAndVerb *word = dynamic_cast<NounAndVerb*>((*it));

		if (word)	//	If word is not null, print it
		{
			cout << word->GetWord() << endl;
		}
	}
}

//	Function to list all the words which are palindromes
void Dictionary::ListPalidromes()
{
	for (vector<Word*>::iterator it = words.begin(); it != words.end(); it++)
	{
		if ((*it)->IsPalindrome())
		{
			cout << (*it)->GetWord() << endl;
		}
	}
}

// Function to display highest scrabble scores for possible and impossible words. 
//	An impossible word is a word that can not fit on a scrabble board (greater than 16 characters long)
void Dictionary::HighestScores()
{
	int hi = 0;
	int pHi = 0;
	vector<string> hWord;
	vector<string> pHword;
	
	for (vector<Word*>::iterator it = words.begin(); it != words.end(); it++)
	{
		string word = (*it)->GetWord();
		int score = (*it)->CalcScrabbleScore();		
		
		// If the word can fit on a scrabble board, compare and add to the possible word list
		if (word.size() <= 16)
		{
			if (score == pHi)
			{
				pHword.push_back(word);
			}
			else if (score > pHi)
			{
				pHi = score;
				pHword.clear();
				pHword.push_back(word);
			}
		}
		else  // Otherwise compare and add to the impossible word list
		{
			if (score == hi)
			{
				hWord.push_back(word);
			}
			else if (score > hi)
			{
				hi = score;
				hWord.clear();
				hWord.push_back(word);
			}
		}
	}
	
	// List possible words
	cout << "Highest Possible score: " << pHi << endl;
	for (vector<string>::iterator it = pHword.begin(); it != pHword.end(); it++)
	{		
		cout << (*it) << "\t" << (*it).size() << " characters long" << endl;
	}

	// List impossible words
	cout << endl << "Highest Impossible score: " << hi << endl;
	for (vector<string>::iterator it = hWord.begin(); it != hWord.end(); it++)
	{
		cout << (*it) << "\t" << (*it).size() << " characters long" << endl;
	}
}

//	Function to find the highest scoring word which can be made from a given string
void Dictionary::AnagramHigh(string word)
{
	vector<Word*> matches;	//	Store matching words in a vector
	string hiWord;
	int topScore = 0, cScore = 0;

	//	Loop through dictionary
	for (vector<Word*>::iterator it = words.begin(); it != words.end(); it++)	
	{
		string temp = (*it)->GetWord();
		if (temp.size() <= word.size())	//	Check if the dictionary word is larger than the entered string before looping
		{
			for (int i = 0; i < word.size(); i++)
			{
				//	Check if a character in the given word exists in the dictionary word
				for (int n = 0; n < temp.size(); n++)
				{
					//	If it does, remove the character from the dictionary word
					if (word[i] == temp[n])
					{
						temp.replace(n, 1, "");
						break;
					}
				}
				//	Check if the dictionary word is empty before moving to the next given word character
				if (temp.size() == 0)
				{
					//	If it's empty, add to matches and move to the next dictionary word
					matches.push_back(*it);
					break;
				}
			}
		}
		
	}
	//	If any words were found, find the word with the highest scrabble score, otherwise, notify the user no words were found
	if (matches.size() > 0)
	{
		for (vector<Word*>::iterator it = matches.begin(); it != matches.end(); it++)
		{
			cScore = (*it)->CalcScrabbleScore();
			if (cScore > topScore)
			{
				hiWord = (*it)->GetWord();
				topScore = cScore;
			}
		}

		cout << hiWord << "\tscore: " << topScore << endl;
	}
	else
	{
		cout << "No matches found. . . \n";
	}
	
}

//	Function to list all the words which rhyme with a given word
void Dictionary::ListRhymes(string word)
{
	//	A word rhymes with another word if the last 3 characters are the same so both words must be at least 3 characters long
	if (word.size() > 2)
	{
		bool found = false;
		string wEnd;
		wEnd.append(word.begin() + (word.size() - 3), word.end());	//	Get the last three characters of the given word

		//	Loop through the dictionary
		for (vector<Word*>::iterator it = words.begin(); it != words.end(); it++)
		{
			string temp = (*it)->GetWord();

			if (temp.size() > 2)
			{
				string tEnd;
				tEnd.append(temp.begin() + (temp.size() - 3), temp.end());	//	Get the last three characters of the dictionary word

				//	If they match, print the word
				if (tEnd == wEnd)	
				{
					cout << temp << endl;
					found = true;
				}
			}
		}

		//	If no words rhymed with the given word, notify the user
		if (!found)
		{
			cout << "No words rhyme with the given word. " << endl;
		}
	}
	else
	{
		cout << "Entry must be at least 3 characters long. " << endl;
	}
}

//	Function to list all the anagrams of a given word
//	Similar to Anagram high except both words must be the same length and anagram must be different to the given word (e.g. "hello" is not an anagram of "hello")
void Dictionary::ListAnagrams(string word)
{
	bool found = false;
	//	Loop through the dictionary
	for (vector<Word*>::iterator it = words.begin(); it != words.end(); it++)
	{
		string temp = (*it)->GetWord();
		//	Check if both words are the same size and not the same word
		if ((temp.size() == word.size()) && word != temp)
		{
			for (int i = 0; i < word.size(); i++)
			{
				//	Check if a character in the given word exists in the dictionary word
				for (int n = 0; n < temp.size(); n++)
				{
					//	If so, remove the character from the dictionary word
					if (word[i] == temp[n])
					{
						temp.replace(n, 1, "");
						break;
					}
				}				
			}
			//	If the dictionary word is empty, print the word
			if (temp.size() == 0)
			{
				found = true;
				cout << (*it)->GetWord() << endl;
			}
		}

	}
	//	If there were no matches, notify the user there are no anagrams
	if (!found)
	{
		cout << "No anagrams found for that word. " << endl;
	}
}

//	Alternative function to list nouns and verbs in case Martin really wants it this way (ever so slightly slower than the other function)
void Dictionary::AltListNV()
{
	for (vector<Word*>::iterator it = words.begin(); it != words.end(); it++)
	{
		if ((*it)->IsNoun() && (*it)->IsVerb())
		{
			cout << (*it)->GetWord() << endl;
		}
	}
}
