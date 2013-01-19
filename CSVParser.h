/************************************
** Edition:	Demo
** Author:	Kingsley Chen	
** Date:	2013/01/19
** Purpose:	class declaration
************************************/

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef _CSVPARSER_53B3DF25_CEB2_4433_A900_943796CD0519_
#define _CSVPARSER_53B3DF25_CEB2_4433_A900_943796CD0519_

#include <iosfwd>
#include <vector>

using std::istream;
using std::vector;
using std::string;

class CSVParser
{
	public:
		CSVParser(istream& in, const string& delim = ",");
		~CSVParser();

	private:
		CSVParser(const CSVParser& csv);
		CSVParser& operator =(const CSVParser& rhs);

	public:
		int GetLineContent(string& line);
		string GetField(int index) const;
		string operator [](int index) const;
		int GetNumOfField() const;
		int TestDrive();

	private:
		int Split();
		int ExtractFromQuote(const string& line, string& field, int begPos) const;
		int ExtractFromPlain(const string& line, string& field, int begPos) const;

	private:
		istream&		_inStream;
		string			_line;
		vector<string>	_field;
		int				_numField;
		string			_delim;
};

#endif

