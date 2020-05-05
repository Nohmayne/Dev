#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(void)
{
    enum Type
    {
	NONE = -1, ONE = 0, TWO = 1
    };

    Type t = Type::NONE;

    const char* source1 = "";
    const char* source2 = "";
    
    std::string ssource1 = "";
    std::string ssource2 = "";

    const char* filepath = "res/file.txt";

    std::string currentLine = "";

    std::ifstream file(filepath);
    if (file.is_open())
    {
	while (getline(file, currentLine))
	{
	    if (currentLine.find("#type") != std::string::npos)
	    {
		if (currentLine.find("1") != std::string::npos)
		    t = Type::ONE;
		if (currentLine.find("2") != std::string::npos)
		    t = Type::TWO;
	    }
	    else
	    {
		if (t == Type::ONE)
		    ssource1 += currentLine + '\n';
		else if (t == Type::TWO)
		    ssource2 += currentLine + '\n';
	    }
	}
    }

    source1 = ssource1.c_str();
    source2 = ssource2.c_str();

    std::cout << "FIRST SOURCE" << std::endl;
    std::cout << source1 << std::endl;
    // std::cout << "SECOND SOURCE" << std::endl;
    // std::cout << source2 << std::endl;

    return 0;
}
