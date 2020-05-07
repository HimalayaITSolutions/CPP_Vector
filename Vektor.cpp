#include "pch.h"
#include "Vektor.h"
#include <iostream>

int Vektor::key = 0;

Vektor::Vektor(int size)
    :sz{ size },  // member initialization list
    elem{ new double[size] }
{
    memset(elem, 0, sizeof(elem));                  // Init
    val = Vektor::key++;
    val = Vektor::key++;
    std::cout << "\n constructor Vector (size) \t" << val << "\n";
}

Vektor::Vektor(std::initializer_list<double> lst)
    :sz{static_cast<int>(lst.size())}, // size_t to int, remember syntax. Remember syntac for templated things
    elem{new double[lst.size()]} 
{
    // copy elements in the list
    std::copy(lst.begin(), lst.end(), elem);
    val = Vektor::key++;
    std::cout << "\n constructor Vector (lst) \t" << val << "\n";

}

Vektor::~Vektor()
{
    if (elem)
    {
        std::cout << "\n destructor (Vector) key \t" << val << "\n";
        delete[] elem;
        elem = nullptr;
    }
    sz = 0;
    val = 0;
}

double & Vektor::operator[](int index) const
{
    return elem[index];
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

Vektor::Vektor(const Vektor& a)
{
    // error check and exception later
    sz = a.size();
    elem = new double[sz];

    for (int i = 0; i < sz; i++)
    {
        // no pointer magic here
        // just data copy
        elem[i] = a[i];
    }
    val = Vektor::key++;
    std::cout << "\nCopy constructor\t" << val << "\n";
}

Vektor & Vektor::operator=(const Vektor & a)
{
    // Free whatever data we had;
    // Ideally have a resource free function
    if (elem)
    {
        delete[] elem;
    }

    sz = a.size();
    elem = new double[sz];

    for (int i = 0; i < sz; i++)
    {
        // no pointer magic here
        // just data copy
        elem[i] = a[i];
    }
    val = Vektor::key++;
    std::cout << "\nCopy assignment\t" << val << "\n";

    return *this;
}

Vektor::Vektor(Vektor && a)
    :sz{a.size()},
    elem{a.elem}
{
    // Copied the pointer
    // So delete a's copy
    //delete a;
    a.elem = nullptr;
    a.sz = 0;
    a.val = 0;

    val = Vektor::key++;
    std::cout << "\n Move constructor\t" << val << "\n";
}

Vektor & Vektor::operator=(Vektor && a)
{
    sz = a.size();
    elem = a.elem;

    // Copied the pointer
    // So delete a's copy
    // delete [] a.elem;

    // DO NOT FREE. It will spoil this->elem
    a.elem = nullptr;
    a.sz = 0;

    val = Vektor::key++;
    std::cout << "\n Move assignment\t" << val << "\n";
    return *this;
}
