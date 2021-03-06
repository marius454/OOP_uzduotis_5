// OOP_uzduotis_5.cpp : Defines the entry point for the console application.
//

#include "Header.h"
#include "stdafx.h"
#include <gtest/gtest.h>

TEST(values, structure_count_test)
{
	std::map<std::string, values> test;
	test["test key"].count = 10;

	EXPECT_EQ(10, test["test key"].count);
}

TEST(values, stucture_line_test)
{
	std::map<std::string, values> test;
	test["test key"].line.push_back(10);

	EXPECT_EQ(10, test["test key"].line[0]);
}

int main(int argc, char* argv[])
{
	RemovePunctuation();
	static const char text[] = "text2.txt";
	std::ifstream fd(text);
	if (!fd)
	{
		std::cerr << "failas text2.txt neegzistuoja" << std::endl;
		return 0;
	}
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

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	return 0;
}


