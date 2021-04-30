#pragma once
#include <iostream>

struct FileInfo {
	std::string fileName;
	std::string crTime, modTime;
	bool readonly = false;
	unsigned long size = 0;
};