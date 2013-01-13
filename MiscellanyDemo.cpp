
#include "stdafx.h"
#include <conio.h>
#include <fstream>
#include "MarkovChain.h"


using std::ifstream;
using std::ofstream;

int _tmain(int argc, _TCHAR* argv[])
{
	Prefix prx;
	StateMap state;
	ifstream in("test.txt");
	ofstream out("genout.txt");
	BuildStateModel(prx, state, in);
	GenerateRandomText(state, out);
	in.close();
	out.close();

	_getch();
	return 0;
}

