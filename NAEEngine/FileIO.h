#ifndef FILEIO_H
#define FILEIO_H

#include <vector>

class FileIO
{
public:
	static std::vector<char> ReadFile(const std::string& fileName);
};
#endif
