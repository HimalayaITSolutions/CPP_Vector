#include "pch.h"
#include <vector>
#include <string>

// Literals need namespace as well
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
// Implement "Less than function" in count for 
// special types.
// Pass it around as an object.
template <typename T>
class Less_than
{
    using Value_type = T;
private:
    const Value_type x;
public:
    Less_than(const Value_type n) 
        :x{ n }                                     // Const can be added only in initializer list. cant do as in commented code
    {
        // x = n;
    }

    bool operator()(const Value_type in){return in < x;}
};

// More predicates
template <typename T>
class More_than
{
    using Value_type = T;
private:
    Value_type x;
public:
    More_than(Value_type n)
        :x{ n }
    {}

    bool operator()(Value_type in) { return in > x; }
};

// This is still weird
template <typename T>
class Zeroes
{
    using Value_type = T;
   // T a = 0;
public:
    //Zeroes(T a1) { a = a1; }
    Zeroes() {}
    bool operator()( Value_type in) { return (in == 0); }
};


// now comes the real deal,, count
// This can take multiple predicates. And, run on same sequence
// We dont need to create many counts, just one count and multiple internal algo'es telling how to count.

template <typename Seq, typename Predicate>
int count3(const Seq s, Predicate* P)
{
    int i = 0;
    Predicate b = *P;
    for (const auto &a : s)
    {
        //if (b(a)) i++;
        //if ((*P)(a)) i++;
        if (P->operator()(a)) i++;
         
    }
    return i;
}


// Template mechanisms

template <class T>
    //using value_type = T;    // cant use 2 lines
    constexpr T variable = 4 * sizeof(T);


template <typename T>
void dump(T a)
{
    //cout << typename T::value_type << "\n" << a << "\n"; // cant dump the value. compile time
    cout << a;
}


template <typename T>
    //bool func = dump(T& a);  // only try constexpr or functions which operate on traits or types
constexpr bool func = is_pod<T>::value;


void VariableTemplates()
{
    cout << func<int> << "\n";
    constexpr auto a1 = variable<int>;
    dump(a1);

    // simple not compile time but auto errors
    auto a2 = int{ };
    //a2 = double{ 6.8 }; // compile and see error
    cout << "\n" << a2;
}

//////////////////////////////////////////////////////////////////////////

template <typename A, typename B>
class map
{
    
public:
    using value_type = B;
    A key;
    B value;

    map(A inKey, B inValue)
        :key{inKey},
        value{inValue}
    {

    }

    void print() { cout << key << value; }
};


// Play with types only
template <typename A>
using StringMap = map<string, A>;

// Define Value type for 1
template <typename T>
using Value_type = typename T::value_type;

/*
template>typename A, typename B>
void aliasTemplate(map<A,B> &m)  // No idea of templated functions yet */

template <typename T>
void aliasTemplate(T &m)
{
    // Method 1
    vector <Value_type<T>> val;   // remember how this works. play with types
    
    // Method 2, gets value of variable. not the best pbe, prefer #1
    //using mytype = decltype(m.value);
    
    // Method 3
    //using mytype = typename T::value_type;
    // vector<mytype> val;

    val.push_back(m.value);
    cout << val[0]; // Illegal use as expression << Value_type<T>;

}

void createAlias()
{
    map m1(2, 4.5);
    map m2("first"s, 1);
    aliasTemplate(m1);
    aliasTemplate(m2);

    StringMap<int> m("2"s, 2); // this is of type String int.
    m = m2;     
}


void testTemplateFuncs()
{
    std::vector<int> v1{ 5,6,7,8 };
    std::vector<double> v2{ 5.5,6.6,7.7,8.7 };
    std::vector<int> v3{ 1, 0, 5, 7 };

    // Specific instantiation
    int c1 = count<std::vector<int>, 6>(v1);


    // int c1 = count<6>(v1); // incorrect instantiation
    int c2 = count2(v1, 6); // Type deduced automatically

    Less_than lti{ 5 };
    Less_than ltd{10.0};
    Less_than lts{"5"s};
    std::cout << "int 1 = " << lti(1);

    // See how simple and intuitive code is now
    // Decouple data, algorithm and loop

    // Try instantitate without Template argument
    // unless type is explicitly specified 
   // Zeroes Z(1);
    Zeroes<int> Z;

    // Called Policy objects as well
    int c3 = count3(v1, &Less_than{ 6 });  // Should give same answer to c2.
    int c4 = count3(v2, &More_than{ 7.3}); // but we need a new func than count2 for " > case" function. Here, count stays same.
    int cz = count3(v3, new Zeroes<int>);

    // The craziest, crappiest, lambda in c++
    // Expands to function object above
    // use only if simple
    int x = 6;
    int c5 = count3(v1, &[&](int a) {return (a < x); });  // Capture locals by ref, capture X.
    int c6 = count3(v2, &[=](double a) {return (a < 7.5); }); // capture and reuse locals by value
    int c7 = count3(v3, &[](int a) {return (a == 0); }); // Corresponds to zeroes, no capture
}



