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
	isvedimas(wmap);

	return 0;
}

