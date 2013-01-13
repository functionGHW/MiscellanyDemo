/************************************
** Edition:	Demo
** Author:	Kingsley Chen	
** Date:	2013/01/13
** Purpose:	algorithms implementation
************************************/

#include "stdafx.h"
#include <fstream>
#include "MarkovChain.h"
#include <ctime>
#include <cassert>
//#include <iostream>

using std::map;
using std::vector;

const string NOWORD = "\n";
enum {NUMOFPREFIX = 2, MAXGENWORDS = 10000};


inline void SetPrefixSential(Prefix& prefix)
{
	for (int i = 0; i < NUMOFPREFIX; ++i)
	{
		prefix.push_back(NOWORD);
	}
}


void BuildStateModel(Prefix& prefix, StateMap& stateTable, std::ifstream& in)
{
	// ensure that every word in content is in state table
	SetPrefixSential(prefix);

	string buf;
	while (in>>buf)
	{
		AddSuffix(prefix, stateTable, buf);
	}

	// add end-mark into state table
	AddSuffix(prefix, stateTable, NOWORD);
}


void AddSuffix(Prefix& prefix, StateMap& stateTable, const string& s)
{
	// alternative is to throw a logic_error exception
	assert(prefix.size() == NUMOFPREFIX);
	
	stateTable[prefix].push_back(s);
	prefix.pop_front();
	prefix.push_back(s);
}


void GenerateRandomText(const StateMap& stateTable, std::ofstream& out)
{
	Prefix prefix;
	SetPrefixSential(prefix);

	srand(static_cast<unsigned>(time(NULL)));	

	for (int i = 0; i < MAXGENWORDS; ++i)
	{
		const vector<string>& suffix = stateTable.at(prefix);
		//int rn = rand() % suffix.size();
		int rn = static_cast<int>(static_cast<double>(rand()) / RAND_MAX * suffix.size());
		//std::cout<<"size: "<<suffix.size()<<" rand-num: "<<rn<<std::endl;
		const string& word = suffix[rn];
		if (NOWORD == word)
		{
			break;
		}
		
		out<<word<<" ";
		prefix.pop_front();
		prefix.push_back(word);
	}
}