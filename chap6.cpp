#include "pch.h"
#include <vector>
#include <string>
//using namespace std;

// Templated Function.
// N is a value argument
// Array is template argument
template <typename Array, int N>
int count(Array Seq)
{
    int i = 0;

    for (auto a: Seq)
    {
        if (a < N) i++;
    }
    return i;
}


// Only template arguments
template <typename Array, typename Val>
int count2(Array &Seq, Val N)  // Get by reference
{
    int i = 0;

    for (auto a : Seq)
    {
        if (a < N) i++;
    }
    return i;
}

// Function objects
// Implement Less than function in count for 
// special types.
// Pass it around as an object.
template <typename typed>
class Less_than
{
private:
    typed x;
public:
    Less_than(typed n) { x = n; }

    bool operator()(typed in){return in < x;}
};


void testTemplateFuncs()
{
    std::vector<double> v1{ 5,6,7,8 };
    int c1 = count<std::vector<double>, 6>(v1);
    // int c1 = count<6>(v1); // incorrect instantiation
    int c2 = count2(v1, 6); // Type deduced automatically

    Less_than lti{ 5 };
    Less_than ltd{10.0};
   // Less_than lts{"5"s};
    std::cout << "int 1 = " << lti(1);
}



