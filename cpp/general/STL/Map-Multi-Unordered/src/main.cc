#include <iostream>
#include <map>
#include <unordered_map>

int main()
{
    // Pairs are 2 values
    std::pair<int, int> p = std::make_pair(1,2);
    std::cout << "First: " << p.first << std::endl;
    std::cout << "Second: " << p.second << std::endl;
    std::cout << std::endl;

    // Maps are key-value pairs
    // Ordered maps always sort by the key
    std::map<std::string, int> mp;
    mp["Hello"] = 100;
    mp["World"] = 200;

    mp.insert(std::make_pair("Test", 3));
    // Cannot overwrite with insert()
    // mp.insert(std::make_pair("Test", 3));

    mp["Hello"] = 4;

    // Iterate
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
    {
	std::cout << "First: " << itr->first << std::endl;
	std::cout << "Second: " << itr->second << std::endl;
    }
    std::cout << std::endl;

    // Multimaps are key-value pairs
    // where there can be multiple values
    // to one key
    std::multimap<std::string, int> mmp;
    mmp.insert(std::make_pair("Hello", 100));
    mmp.insert(std::make_pair("World", 200));
    mmp.insert(std::make_pair("Hello", 4));
    mmp.insert(std::make_pair("Test", 3));

    // Iterate
    for (auto itr = mmp.begin(); itr != mmp.end(); itr++)
    {
	std::cout << "First: " << itr->first << std::endl;
	std::cout << "Second: " << itr->second << std::endl;
    }
    std::cout << std::endl;

    // Unordered maps are self-descriptive
    // There are also unordered multimaps
    std::unordered_map<std::string, int> ump;
    ump["Hello"] = 100;
    ump["World"] = 200;
    ump["Test"] = 4;

    // Iterate
    for (auto itr = ump.begin(); itr != ump.end(); itr++)
    {
	std::cout << "First: " << itr->first << std::endl;
	std::cout << "Second: " << itr->second << std::endl;
    }

    return 0;
}
