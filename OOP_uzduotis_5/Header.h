#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <string>
#include <vector>
#include <sstream>

struct values {
	size_t count = 0;
	std::vector<size_t> line;
};
void RemovePunctuation();
void isvedimas(std::map<std::string, values> wmap);