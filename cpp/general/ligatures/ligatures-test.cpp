#include <iostream>
#include <unordered_map>

class Widget
{
public:
    void setVariable(int set) { m_var = set; }
    int getVariable() { return m_var; }
private:
    int m_var = 0;
};

int main()
{
    int x = 1;
    int y = 2;

    if (y >= x)
    {
        std::cout << y << std::endl;
    }
    else if (x == 1 && y == 2)
    {
        std::cout << "CASE MET" << std::endl;
    }
    else
    {
        std::cout << x << std::endl;
    }

    Widget* w = new Widget;

    int sum = x;
    sum += y;
    w->setVariable(sum);

    std::cout << w->getVariable() << std::endl;

    if (w->getVariable() == 3)
    {
        std::cout << "It's 3!" << std::endl;
    }
    else if (w->getVariable() != 3)
    {
        std::cout << "It ain't 3!" << std::endl;
    }

    const char* hw = "Hello, world!";
    std::cout << hw << std::endl;

    std::unordered_map<std::string, int> hashmap;

    hashmap.insert(std::make_pair("Hello", 1));
    hashmap.insert(std::make_pair("World", 2));

    for (auto itr = hashmap.begin(); itr != hashmap.end(); itr++)
    {
        std::cout << itr->second << ": " << itr->first << std::endl;
    }

    return 0;
}
