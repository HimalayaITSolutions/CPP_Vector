#include "pch.h"
#include <vector>
#include <string>

// Literals need nameapace as well
using namespace std;

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
template <typename T>
class Less_than
{
    using Value_type = T;
private:
    const Value_type x;
public:
    Less_than(const Value_type& n) { x = n; }

    bool operator()(const Value_type& in){return in < x;}
};

// More predicates
template <typename T>
class More_than
{
    using Value_type = T;
private:
    const Value_type x;
public:
    More_than(const Value_type& n) { x = n; }

    bool operator()(const Value_type& in) { return in > x; }
};

template <typename T>
class Zeroes
{
    using Value_type = T;
public:
    bool operator()(const Value_type& in) { return in == 0; }
};


// now comes the real deal,, count
// This can take multiple predicates. And, run on same sequence
// We dont need to create many counts, just one count and multiple internal algo'es telling how to count.

template <typename Seq, typename Predicate>
int count3(Seq s, Predicate P)
{
    int i = 0;
    for (auto &a : s)
    {
        if (P(a)) i++;
    }
}

void testTemplateFuncs()
{
    std::vector<int> v1{ 5,6,7,8 };
    std::vector<double> v2{ 5.5,6.6,7.7,8.7 };
    int c1 = count<std::vector<int>, 6>(v1);
    // int c1 = count<6>(v1); // incorrect instantiation
    int c2 = count2(v1, 6); // Type deduced automatically

    Less_than lti{ 5 };
    Less_than ltd{10.0};
    Less_than lts{"5"s};
    std::cout << "int 1 = " << lti(1);

    // See how simple and intuitive code is now
    // Decouple data, algorithm and loop

    // Called Policy objects as well
    int c3 = count3(v1, Less_than{ 6 });  // Should give same answer to c2.
    int c3 = count3(v2, More_than{ 7.3}); // but we need a new count than count 2 for this function. Here count stays same.



}



