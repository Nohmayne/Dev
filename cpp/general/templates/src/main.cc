// Learning about templates
// Go to https://www.youtube.com/watch?v=I-hZkUa9mIs
// to learn more!
#include <iostream>
#include <string>

/* -- This is bad, don't do it
void Print(int value)
{
    std::cout << value << std::endl;
}

void Print(std::string value)
{
    std::cout << value << std::endl;
}

void Print(float value)
{
    std::cout << value << std::endl;
}
*/

// Only gets created when actually called
template<typename T>
void Print(T value)
{
    std::cout << value << std::endl;
}

int main()
{
    // This works to specify the type
    Print<int>(5);

    // Can also work with unspecified type
    // if the type can be determined at runtime
    Print("Hello");

    return 0;
}
