#include "stdafx.h"
#include "TriGame.h"


TriGame::TriGame()
{
	fileLoaded = false;
}


TriGame::~TriGame()
{
}

void TriGame::LoadFile()
{
	// Only load the file the first time function is called
	if (!fileLoaded)
	{
		
		bool exists = false;
		ifstream file("ex11File.txt");
		string data, pair,line;

		while (!(file.eof()))
		{
			getline(file, line);
			replace(line.begin(), line.end(), '.', '_');	// Replace all "," and " " with "_"
			replace(line.begin(), line.end(), ' ', '_');
			data.append(line);
		}
		file.close();


		// Loop through string
		for (int i = 0; i < data.size() - 3; i++)
		{
			int asciiChars[127] = { 0 };	//Array to count number of instances of each ascii character
			pair = "";
			pair.append(1, data[i]);
			pair.append(1, data[i + 1]);

			// Convert to lowercase
			for (int j = 0; j < 2; j++)
			{
				if (pair[j] < 91 && pair[j] > 64)
				{
					pair[j] += LUDIFF;
				}
			}

			// Check if pair has already been added
			for (int j = 0; j < pairs.size(); j++)
			{
				if (pair == pairs[j].GetPair())
				{
					exists = true;
					break;
				}
			}
			// If so, move to next pair
			if (exists)
			{
				exists = false;
				continue;
			}

			
			asciiChars[int(data[i + 2])]++;	// increment first instance

			// Search string for matching pairs
			for (int j = i + 1; j < data.size() - 3; j++)
			{
				string tPair = "";
				tPair.append(1, data[j]);
				tPair.append(1, data[j + 1]);

				// convert tPair to lowercase
				for (int k = 0; k < 2; k++)
				{
					if (tPair[k] < 91 && tPair[k] > 64)
					{
						tPair[k] += LUDIFF;
					}
				}

				// If match found, increment instance
				if (tPair == pair)
				{
					asciiChars[int(data[j + 2])]++;
				}
			}

			// Find three most occuring characters
			int topThree[3][2] = { 0 };	//Array to keep track of character and index of character
			for (int j = 0; j < 127; j++)
			{
				if (asciiChars[j] >= topThree[0][0])
				{
					topThree[0][0] = asciiChars[j];
					topThree[0][1] = j;
				}
				else if (asciiChars[j] >= topThree[1][0])
				{
					topThree[1][0] = asciiChars[j];
					topThree[1][1] = j;
				}
				else if (asciiChars[j] >= topThree[2][0])
				{
					topThree[2][0] = asciiChars[j];
					topThree[2][1] = j;
				}
			}

			// If some of the top three were not found, convert to "_"
			for (int j = 0; j < 3; j++)
			{
				if (topThree[j][0] == 0)
				{
					topThree[j][1] = 95;
				}
			}

			//Add new TriGram to list
			TriPair newPair(pair, topThree[0][1], topThree[1][1], topThree[2][1]);
			pairs.push_back(newPair);
		}
		//Set to true so next time the wait isn't so long 
		fileLoaded = true;
	}
}


void TriGame::FindTopThree(string p)
{
	bool found = false; 

	// Loop through pairs to find matching character pair
	for (vector<TriPair>::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if (p == it->GetPair())
		{
			cout << "Most likely following character:\t" << it->GetFirst() << endl;
			cout << "Second most likely following character:\t" << it->GetSecond() << endl;
			cout << "Third most likely following character:\t" << it->GetThird() << endl;
			found = true;
			break;
		}		
	}

	// Notify user no data exists for that pair
	if (!found)
	{
		cout << "No matching pairs in document. Not enough data." << endl;
	}
}

void TriGame::ListWords(Dictionary* words)
{

	int syllable = 0,idx = 0,ltr = 0;
	// Loop to make ten words
	for (int i = 0; i < 10; i++)
	{
		string fWord;
		char x;
		int val = 0;
		syllable = rand() % 4 + 2;	//Set random syllable size

		do
		{
			fWord = "";
			// For each syllable, add a triGram
			for (int j = 0; j < syllable; j++)
			{
				idx = rand() % (pairs.size() - 1);	// Select a random index from the list
				fWord.append(pairs[idx].GetPair());
				ltr = rand() % 2;	// Select a random third character
				switch (ltr)
				{
				case 0:
					x = pairs[idx].GetFirst();
					break;
				case 1:
					x = pairs[idx].GetSecond();
					break;
				case 2:
					x = pairs[idx].GetThird();
					break;
				}

				fWord.append(1, x);
			}
			val = fWord.find('_');	// check for no spaces

		} while (val > -1 || words->FindWord(fWord) != NULL);	// Keep trying until a new word with no spaces is made

		cout << fWord << endl;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////



/*	Zipfy stuff

for (int i = 0; i < data.size(); i++)
{
asciiChars[int(data[i])]++;
}


//Sort it out
for (int i = 0; i < 127; i++)
{
for (int n = i + 1; n < 127; n++)
{
if (asciiChars[n] < asciiChars[i])
{
temp = asciiChars[i];
asciiChars[i] = asciiChars[n];
asciiChars[n] = temp;
}
}
}

//	Print it out
for (int i = 0; i < 127; i++)
{
cout << i << ") " << asciiChars[i] << endl;
}
*/
