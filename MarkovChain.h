/************************************
** Edition:	Demo
** Author:	Kingsley Chen	
** Date:	2013/01/13
** Purpose:	declaration
************************************/

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef _MARKOVE_CHAIN_4C0F590A_8C80_44C6_BD5C_18A624536A97
#define _MARKOVE_CHAIN_4C0F590A_8C80_44C6_BD5C_18A624536A97

#include <map>
#include <list>
#include <vector>

using std::string;

typedef std::list<string> Prefix;
typedef std::map<Prefix, std::vector<string>> StateMap;

void AddSuffix(Prefix& prefix, StateMap& stateTable, const string& s);
void BuildStateModel(Prefix& prefix, StateMap& stateTable, std::ifstream& in);
void GenerateRandomText(const StateMap& stateTable, std::ofstream& out);

#endif