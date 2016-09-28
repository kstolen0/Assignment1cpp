// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

// TODO: reference additional headers your program requires here

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include <algorithm>
#include "Dictionary.h"
#include "TriGame.h"
using namespace std;

#define MAXWORDS 106184
#define LUDIFF 32; //difference between lowercase and uppercase letters in ascii 

int GetInt();

// Exercise functions

void FindWord(Dictionary* words);
void ListZZZ(Dictionary* words);
void ListQ(Dictionary* words);
void ListNounVerbs(Dictionary* words);
void ListPalindromes(Dictionary* words);
void ListHighScore(Dictionary* words);
void MakeHighWord(Dictionary* words);
void ListRhymes(Dictionary* words);
void ListAnagrams(Dictionary* words);
void DoingTriGames(TriGame* game, Dictionary* words);

//	Other functions

void SecretMessage();
void GoodBye();