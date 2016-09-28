// Assignment1cpp.cpp : Defines the entry point for the console application.
//

//	BASIC TASKS COMPLETE		05/04/16
//	INTERFACE BEGUN				09/04/16
//	INTERMEDIATE TASKS BEGUN	09/04/16
//	INTERMEDIATE TASKS END		10/04/16
//	ADVANCED TASKS BEGUN		15/04/16
//	ADVANCED TASKS END			15/04/16
//	INTERFACE END				27/05/16


#include "stdafx.h"

// The main function. This is where our program is run. 
int main()
{	
	int choice = 0;
	bool exit = false;
	Dictionary* words = new Dictionary;
	TriGame* game = new TriGame();
	words->LoadDictionary();	
	system("cls");	
	SecretMessage();
	while (true)
	{	
		// Display options to the user
		cout << "/////////////////////////////////////////////////////////////////" << endl;
		cout << "Please select the exercise number you would like to perform ////" << endl;
		cout << "///////////////////////////////////////////////////////////////\n\n";		
		cout << "1) Find a word. " << endl;
		cout << "2) List words with more than three 'z's." << endl;
		cout << "3) List words with a 'q' without a following 'u'." << endl;
		cout << "4) List words that are nouns and verbs." << endl;
		cout << "5) List palindromes. " << endl;
		cout << "6) List words with the highest scrabble score. " << endl;
		cout << "7) Return a good word from your letters!" << endl;
		cout << "8) List the words which rhyme with a given word. " << endl;
		cout << "9) List the anagrams of a given word. " << endl;
		cout << "10) Fun with Tri Games! " << endl;
		cout << "11) Exit program. \n\n";
		cout << "For your own safety, please reframe from ░░▒░▓▓▒░" << endl;
		choice =  GetInt();	//Use a function to return an integer
		system("cls");	// Clear the console, at least keep things tidy on the surface 


		// Using a bunch of functions instead of having a load a bunch of couts
		//	in one small area

		switch (choice)
		{
		case 1:
			FindWord(words);
			break;
		case 2:
			ListZZZ(words);
			break;
		case 3:
			ListQ(words);
			break;
		case 4:
			ListNounVerbs(words);
			break;
		case 5:
			ListPalindromes(words);
			break;
		case 6:
			ListHighScore(words);
			break;
		case 7:
			MakeHighWord(words);
			break;
		case 8:
			ListRhymes(words);
			break;
		case 9:
			ListAnagrams(words);
			break;
		case 10:
			DoingTriGames(game, words);
			break;
		case 11:
			exit = true;
			break;
		}

		if (exit)
		{
			delete(words);
			delete(game);			
			GoodBye();
			break;
		}
		system("cls"); 
	}
    return 0;
}


// Function to continue to request an integer to user
//		Borrowed from internet source
int GetInt()
{
	int choice = 0;	
	// Keep going until an integer is entered 
	while (true)
	{		
		cout << "Please enter a number: ";
		string entry;
		getline(cin, entry);
		stringstream stream(entry);	// stringstream does the heavy lifting
		if (stream >> choice)
		{
			break;
		}		
	}

	return choice; 
}


// Function to run the find word method
void FindWord(Dictionary* words)
{
	string entry = "";
	cout << "///////////////////////////////////" << endl;
	cout << "Find a word in the dictionary ////" << endl;
	cout << "/////////////////////////////////\n\n";

	// Continuously ask the user to enter a word for as long as they choose
	while (true)
	{
		cout << "Please enter a word to search for: ";
		cin >> entry;
		Word *temp = words->FindWord(entry);
		if (temp)
		{
			//	Print out the details of the word
			cout << endl << temp->GetWord() << "\n" << temp->GetDef() << endl;
			if (temp->CalcScrabbleScore() > 0)
			{
				cout << "Scrabble score: " << temp->CalcScrabbleScore() << endl;
				//	If the word is too long to be used in scrabble, notify the user
				if (temp->GetWord().size() > 16)
				{
					cout << "Too long to use in scrabble." << endl;
				}
			}
			else
			{
				cout << "\n\nNot valid in scrabble." << endl;
			}
		}
		else
		{
			cout << "Word not in dictionary.\n\n";
		}

		cout << "\n\nAgain? (y/n) ";
		cin >> entry;
		if (entry == "n")
		{
			break;
		}
	}
}

//	Function to run the ListZs method
void ListZZZ(Dictionary* words)
{
	cout << "//////////////////////////////////////////////////////" << endl;
	cout << "List the words which contain more than three z's ////" << endl;
	cout << "////////////////////////////////////////////////////\n\n";	
	words->ListZs();
	system("pause");	// Don't leave right away or else the screen will be cleared
}

//	Function to run the ListQs method
void ListQ(Dictionary* words)
{
	cout << "////////////////////////////////////////////////////" << endl;
	cout << "List the words with a 'q' but no following 'u' ////" << endl;
	cout << "//////////////////////////////////////////////////\n\n";
	words->ListQs();
	system("pause");
}

//	Function to run the ListNounVerbs method
void ListNounVerbs(Dictionary* words)
{
	cout << "/////////////////////////////////////////////////////" << endl;
	cout << "List the words which are nouns as well as verbs ////" << endl;
	cout << "///////////////////////////////////////////////////\n\n";

	words->ListNounVerbs();
	system("pause");
}

//	Function to run the ListPalindromes method
void ListPalindromes(Dictionary* words)
{
	cout << "//////////////////////////////////////////" << endl;
	cout << "List the words which are palindromes ////" << endl;
	cout << "////////////////////////////////////////\n\n";

	words->ListPalidromes();
	system("pause");
}

// Function to run the HighestScores method
void ListHighScore(Dictionary* words)
{
	cout << "////////////////////////////////////" << endl;
	cout << "List the highest scoring words ////" << endl;
	cout << "//////////////////////////////////\n\n";

	words->HighestScores();
	system("pause");
}

//	Function to run the AnagramHigh method
void MakeHighWord(Dictionary* words)
{
	string chars;
	//	Continue to ask the user to enter a string for as long as they choose
	while (true)
	{
		system("cls");
		cout << "///////////////////////////////////////////////////////" << endl;
		cout << "Enter some letters to make the best scrabble word ////" << endl;
		cout << "/////////////////////////////////////////////////////\n\n";
		cout << "Enter some characters: ";
		cin >> chars;
		words->AnagramHigh(chars);
		cout << "\n\nAgain? (y/n) ";
		cin >> chars;
		if (chars == "n")
		{
			break;
		}
	}	
}

//	Function to run the ListRhymes method
void ListRhymes(Dictionary* words)
{
	string entry;
	cout << "//////////////////////////////////////////////" << endl;
	cout << "Enter a word to find what rhymes with it ////" << endl;
	cout << "////////////////////////////////////////////\n\n";

	//	Continue to ask the user to enter a word for as long as they choose
	while (true)
	{
		cout << "Enter a word: ";
		cin >> entry;
		words->ListRhymes(entry);
		cout << "\n\nAgain? (y/n) ";
		cin >> entry;
		if (entry == "n")
		{
			break;
		}
	}
}

//	Function to run the ListAnagrams method
void ListAnagrams(Dictionary* words)
{
	string entry;
	cout << "////////////////////////////////////////////////" << endl;
	cout << "Enter a word to find anagrams of that word ////" << endl;
	cout << "//////////////////////////////////////////////\n\n";

	//	Continue to ask the user to enter a word for as long as they choose
	while (true)
	{
		cout << "Enter a word: ";
		cin >> entry;
		words->ListAnagrams(entry);
		cout << "\n\nAgain? (y/n) ";
		cin >> entry;
		if (entry == "n")
		{
			break;
		}
	}
}

void DoingTriGames(TriGame* game, Dictionary* words)
{
	string entry = "";
	cout << "\n\nGenerating words. . . \n";
	game->LoadFile();
	system("cls");
	cout << "\n\nPlease enter any two characters (enter \"_\" for space): ";
	cin >> entry;

	while (entry.size() > 2)
	{
		cout << "\nOnly two are needed";
		cout << "\n\nPlease enter any two characters: ";
		cin >> entry;
	}

	game->FindTopThree(entry);
	game->ListWords(words);
	system("pause");
}

void SecretMessage()
{
	cout << "\n\nResistance is futile.";
	
	Sleep(200);
	system("cls");
}

void GoodBye()
{	
	system("Color 04");
	cout << "\n\nDaisy, ";
	Sleep(1100);
	cout << "Daisy,\n";
	Sleep(1200);
	cout << "give ";
	Sleep(200);
	cout << "me ";
	Sleep(200);
	cout << "your ";
	Sleep(200);
	cout << "ans"; 
	Sleep(400);
	cout << "wer";
	Sleep(400);
	cout << " do.\n";
	Sleep(1200);
	cout << "I'm ";
	Sleep(400);
	cout << "half ";
	Sleep(400);
	cout << "cra";
	Sleep(400);
	cout << "zy\n";
	Sleep(600);
	cout << "all ";
	Sleep(200);
	cout << "for "; 
	Sleep(200);
	cout << "the "; 
	Sleep(200);
	cout << "love ";
	Sleep(450);
	cout << "of";
	Sleep(150);
	cout << " you. . . ";
	Sleep(2000);

}
/*
		######
	   ##      ### ####
	 ##          ## #  #
	#      ##     ## #  #
   #              # # #  #
   #           #  #  # # #
  #            #  ##  # ##
 #               # # ## #
 #   ##          # ##  ##
 #         ##    #  #   #
 #                # ### #
 #           #    # #  #
  #         ##     ## #
  #        #  #       #
   ##    ##*  #        #
   ######    ##        #
   # * # #  #          #
    # #  ####          #
     #                 #
     #                  #
    #  #          ##    #
    # # #       ##\#    #
   #    #      # \#    #
   #   #     *# \#       #
   #  #     ## \#        ##
  #  ##   ##*  * #      #  #
  #  # ###        #     #  ##
  # #             #    #   ###
  ##             # #   #   ####
	   /##**##\
     /##**###\#
	 #/#**##\##
	#  #    #  #
	#  ##**##  #
	 ##*#    #  *###
	 ###     #
	  #       *#####
*/