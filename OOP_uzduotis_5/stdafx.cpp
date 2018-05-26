// stdafx.cpp : source file that includes just the standard includes
// OOP_uzduotis_5.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "Header.h"
#include "stdafx.h"

void RemovePunctuation()
{
	std::string str;
	char test;
	std::ifstream fd("text.txt");
	std::ofstream fr("text2.txt");
	while (!fd.eof()) { // Use std::ifstream::good()
		getline(fd, str);
		//std::istringstream is(str);// Use std::getline()
		for (size_t i = 0; i < str.size(); ++i)
		{
			if (ispunct(str[i])) { // Use ispunct()
				str.erase(i, 1);
				--i;
			}
		}
		fr << str << std::endl;
	}
	fd.close();
	fr.close();
}
// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
