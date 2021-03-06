// stdafx.cpp : source file that includes just the standard includes
// OOP_uzduotis_5.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "Header.h"
#include "stdafx.h"

void RemovePunctuation()
{
	std::string str;
	std::ifstream fd("text.txt");
	if (!fd)
	{
		std::cerr << "failas text.txt neegzistuoja" << std::endl;
		return;
	}
	std::ofstream fr("text2.txt");
	while (!fd.eof()) {
		getline(fd, str);
		for (size_t i = 0; i < str.size(); ++i)
		{
			if (ispunct(str[i]) && str[i]!= '\'') 
			{
				str.erase(i, 1);
				--i;
			}
			else if (isupper(str[i])) 
			{
				str[i] = tolower(str[i]);
				
			}
		}
		fr << str << std::endl;
	}
	fd.close();
	fr.close();
}

void isvedimas(std::map<std::string, values> wmap)
{
	std::map<std::string, values>::iterator it;
	for (it = wmap.begin(); it != wmap.end(); ++it)
	{
		if (it->second.count > 1)
		{
			std::cout << std::setw(12)<< std::left << it->first << " kartojasi " << it->second.count;
			if (it->second.count % 10 == 0 || it->second.count % 100 <= 19 && it->second.count % 100 >= 11) {
				std::cout << " kartu ";
			}
			else if (it->second.count % 10 == 1) {
				std::cout << " karta ";
			}
			else std::cout << " kartus ";
			std::cout << "eilutese: ";
			for (size_t i = 0; i < it->second.count; ++i)
				std::cout << it->second.line[i] << ",";
			std::cout << std::endl << std::endl;
		}
	}
}
// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
