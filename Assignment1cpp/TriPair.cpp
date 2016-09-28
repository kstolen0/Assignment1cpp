#include "stdafx.h"
#include "TriPair.h"


TriPair::TriPair()
{
}

TriPair::TriPair(string pair, char f, char s, char t)
{
	lPair = pair;
	first = f;
	second = s;
	third = t;
}


TriPair::~TriPair()
{
}

string TriPair::GetPair()
{
	return lPair;
}

char TriPair::GetFirst()
{
	return first;
}

char TriPair::GetSecond()
{
	return second;
}

char TriPair::GetThird()
{
	return third;
}




void TriPair::SetTopThree(char f, char s, char t)
{
	first = f;
	second = s;
	third = t;
}

void TriPair::SetPair(string p)
{
	lPair = p;
}
