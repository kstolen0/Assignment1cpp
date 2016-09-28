#pragma once
#include <iostream>
#include <vector>
using namespace std;

class TriPair
{
public:
	TriPair();
	TriPair(string pair, char f, char s, char t);
	~TriPair();

	string GetPair();
	char GetFirst();
	char GetSecond();
	char GetThird();


	void SetTopThree(char f,char s, char t);
	void SetPair(string p);

private:
	string lPair;
	char first,second,third;
};

