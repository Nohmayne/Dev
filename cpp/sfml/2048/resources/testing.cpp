#include <iostream>
#include <vector>

class Example
{
public:
    Example(int var) :
    m_var (var)
    {
    }

    int getVar()
    {
        return m_var;
    }
private:
    int m_var;
};

size_t findIndexOfExample(int var, std::vector<Example*>& examples)
{
    for (size_t i = 0; i < examples.size(); i++)
    {
        if (var == examples[i]->getVar())
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    std::vector<Example*> examples;
    
    for (size_t i = 0; i < 3; i++)
    {
        Example* newExample = new Example(i);
        examples.push_back(newExample);
    }

    //std::vector<Example&> exTest;

    for (Example* e : examples)
    {
        std::cout << e->getVar() << std::endl;
        //exTest.push_back(*e);
    }

    std::cout << "--------------" << std::endl;

    if (findIndexOfExample(2, examples) != -1)
        examples.erase(examples.begin() + findIndexOfExample(2, examples));

    for (Example* e : examples)
    {
        std::cout << e->getVar() << std::endl;
    }

    return 0;
}