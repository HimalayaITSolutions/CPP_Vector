#include "pch.h"
#include "Vektor.h"
#include <iostream>


Vektor::Vektor(int size)
    :sz{ size },  // member initialization list
    elem{ new double[size] }
{
}


Vektor::Vektor(std::initializer_list<double> lst)
    :sz{static_cast<int>(lst.size())}, // size_t to int, remember syntax. Remember syntac for templated things
    elem{new double[lst.size()]} 
{
    // copy elements in the list
    std::copy(lst.begin(), lst.end(), elem);
}

Vektor::~Vektor()
{
    delete[]  elem;
    elem = nullptr;
}

double & Vektor::operator[](int index)
{
    return elem[index];
}

Vektor& Vektor::pushback(double & d)
{
    // Add to end
    return *this;
}

