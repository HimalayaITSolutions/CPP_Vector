#include "pch.h"
#include "Vektor.h"


Vektor::Vektor(int size)
    :sz{ size },  // member initialization list
    elem{ new double[size] }
{
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

