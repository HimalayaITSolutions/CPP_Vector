#include "pch.h"
#include "Vektor.h"
#include <iostream>


Vektor::Vektor(int size)
    :sz{ size },  // member initialization list
    elem{ new double[size] }
{
    std::cout << "\n constructor (Vector) size\n";
    memset(elem, 0, sizeof(elem));                  // Init
}

Vektor::Vektor(std::initializer_list<double> lst)
    :sz{static_cast<int>(lst.size())}, // size_t to int, remember syntax. Remember syntac for templated things
    elem{new double[lst.size()]} 
{
    // copy elements in the list
    std::copy(lst.begin(), lst.end(), elem);
    std::cout << "\n constructor Vector (lst) \n";
}

Vektor::~Vektor()
{
    if (elem)
    {
        std::cout << "\n destructor (Vector) size \t" << sz << "\n";
        delete[] elem;
        elem = nullptr;
    }
    sz = 0;
}

double & Vektor::operator[](int index)
{
    return elem[index];
}

Vektor& Vektor::pushback(double & d)
{
    // Add to end
    int size = sz;
    double * arr = new double[sz++];
    delete[] arr;
    
    /*for (int i = 0; i < size; i++)
    {
        arr[i] = elem[i];
    }
    arr[size] = d;
    if (elem != nullptr)
    {
        if (sz == 1)
        {
            delete elem;
            
        }
        else
        {
            delete[] elem; // another error
        }
    }
    elem = new double[sz];

    for (int i = 0; i < sz; i++)
    {
        elem[i] = arr[i];
    }
    if (size == 0)
    {
        delete arr;
    }
    else
    {
        delete[] arr;
    }
    arr = nullptr;
    */
    return *this;
}
