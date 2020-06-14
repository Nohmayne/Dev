#include <iostream>
#include <vector> // Contiguous memory allocation
#include <list> // Doubly linked list
#include <algorithm> // Algorithms (duh)

int main()
{
    // sequence containers
    // VECTOR
    // Essentially ArrayList<> from Java
    // Can store any type at any length
    std::vector<int> v; 

    // LIST
    // Essentially a vector, but doubly linked
    // std::list<int> l;

    // Storing values uses the push_back() func
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);

    // Built-in sorting algorithm using Random Access Iterators
    // NOTE: List is bidirectional iterator
    std::sort(v.begin(), v.end());

    // Accessed via iterators (very similar to pointers)
    auto itr = v.begin();
    for (; itr != v.end(); itr++)
    {
	std::cout << "Value: " << *itr << std::endl;
    }

    std::cout << std::endl;

    // Vector size can be accessed through size()
    std::cout << "Size before clear: " << v.size() << std::endl;

    // Can be cleared via clear()
    v.clear();
    std::cout << "Size after clear:  " << v.size() << std::endl;

    return 0;
}
