#include "pch.h"
#include <iostream>
using namespace std;

// Check impact of Reference assignment on associated Pointer
int ReferenceTest()
{
    int x = 2;
    int y = 3;
    int *p = &x;
    int *q = &y;
    cout << "\n Addresses \t" << p << "\t"  << &x;

    if (p == &x)
    {
        cout << "\n Equal x";
    }

    p = q;
    cout << "\n Adresses \t" << p << "\t" << &y;
    cout << "\n Values P and X \t" << *p << "\t" << x;

    if (p == &y)
    {
        cout << "\n Equal y";
    }

    p = &x;
    cout << "\n Values" << *p << "\t" << *q;

    int &r = x;
    int &s = y;

    cout << "\n Addresses" << &r << "\t" << &x;
    cout << "\n Adresses" << &s << "\t" << &y;

    r = s; // As r changes, Address of the pointer stays same but *p is modified as well. P stays same, know this!
    cout << "\n Addresses " << &r << "\t" << &s << "\t" << p << "\t" << q;
    cout << "\n Values \t" << r << s << "\t" << *p << "\t" <<*q;

    return 0;
}