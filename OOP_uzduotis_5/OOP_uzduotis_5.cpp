// OOP_uzduotis_5.cpp : Defines the entry point for the console application.
//

#include "Header.h"
#include "stdafx.h"

int main()
{
	RemovePunctuation();
	static const char text[] = "text2.txt";
	std::ifstream fd(text);
	std::map<std::string, values> wmap;
	std::string w;
	size_t line = 0;
	std::string str;
	while (!fd.eof()) {
		line++;
		getline(fd, str);
		std::istringstream is(str);
		while (is >> w)
		{
			if (wmap.find(w) != wmap.end())
			{
				wmap[w].count++;
				wmap[w].line.push_back(line);
			}
			else
			{
				wmap[w].count = 1;
				wmap[w].line.push_back(line);
			}
		}
	}
	std::map<std::string, values>::iterator it;
	for (it = wmap.begin(); it != wmap.end(); ++it)
	{
		if (it->second.count > 1)
		{
			std::cout << "Zodis \"" << it->first << "\" kartojasi " << it->second.count;
			if (it->second.count % 10 == 0) {
				std::cout << " kartu ";
			}
			else if (it->second.count % 100 <= 19 && it->second.count % 100 >= 11) {
				std::cout << " kartu ";
			}
			else if (it->second.count % 10 == 1) {
				std::cout << " karta ";
			}
			else std::cout << " kartus ";
			std::cout << " ir yra randamas eilutese: ";
			for (size_t i = 0; i < it->second.count; ++i)
			std::cout << it->second.line[i] << ",";
			std::cout << std::endl << std::endl;
		}
	}

	return 0;
}

