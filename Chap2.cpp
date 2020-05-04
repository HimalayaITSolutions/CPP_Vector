#include "pch.h"
#include <iostream>
#include <variant>
using namespace std;

// First we write naked union, then Tagged union and then a Variant
// https://en.cppreference.com/w/cpp/utility/variant


enum Type { num, decimal };

struct Entry{
    string name;
    Type t;
    int a;
    float b;
};

// Optimized
struct Entry2{
    string name;
    Type t;
    union {
        int a;
        float b;
    };
};

/*
struct Entry3 {
    string name;
    variant<int, float> v;
};*/

int simpleStructFunc(Entry2 e)
{
    if (e.t == num)
    {
        cout << "\n Num =" << e.a ;
    }

    if (e.t == decimal)
    {
        cout << "\n Float =" << e.b;
    }
    return 0;
}

class TaggedUnion
{

public:
    int getNumber();
    float getFloat();
    void set(Entry2 in) { e = in; }
private:
    Entry2 e;

};

float TaggedUnion::getFloat()
{
    if (e.t == decimal)
    {
        cout << "\n float =" << e.b;
        return e.b;
    }
    return  0;
}

int TaggedUnion::getNumber()
{
    if (e.t == num)
    {
        cout << "\n Num =" << e.a;
        return e.a;
    }
    return  -1;
}

int testVariant()
{
    // Variant
    variant<int, double> v;
    v = 15.5;

    if (holds_alternative<int>(v))
    {
        cout << "\n Val = " <<  get<int> (v);
    }
    else
        cout << "error";

    if (holds_alternative<double>(v))
    {
        cout << "\n Val = " << get<double> (v);
    }
    return 0;
}


int enumtests()
{
    // Global scope
    enum Color { red, green, blue };
    int a = red;

    // Class scope. "r" does not exist aside of Colour::
    enum class Colour { r, g, b };
    enum class Traffic {g, b, r};

    // Error
    // a = Colour::r;

    Traffic t{ 0 }; // This works
    // Error cant print it like this
   //  cout << t;  

    // errors
    //t = Colour(Colour::r);
    //t = red;

    Colour thisColor = Colour::b;

    // We can add Operator overloading as any type
    // page 27
    return 0;
}

int NakedUnion()
{
    // First we write naked union, then Tagged union and then a Variant
    Entry2 e2;
    e2.name = "simpleStructFunc";
    e2.t = decimal;
    e2.b = 15.5;

    // naked union... erronoeus
    simpleStructFunc(e2);

    // Tagged union
    TaggedUnion* tu = new TaggedUnion();
    tu->set(e2);
    tu->getNumber();

    delete tu;

    testVariant();

    enumtests();
    return 0;
}
