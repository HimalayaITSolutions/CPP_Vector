#include "pch.h"
#include "Vektor.h"
#include <iostream>

template<typename T>
int Vektor<T>::key = 0;

template<typename T>
Vektor<T>::Vektor(int size)
    :sz{ size },  // member initialization list
    elem{ new T[size] }
{
    memset(elem, 0, sizeof(elem));                  // Init
    val = Vektor::key++;
    val = Vektor::key++;
    std::cout << "\n constructor Vector (size) \t" << val << "\n";
}

template<typename T>
Vektor<T>::Vektor(std::initializer_list<T> lst)
    :sz{static_cast<int>(lst.size())}, // size_t to int, remember syntax. Remember syntax for templated things
    elem{new T[lst.size()]} 
{
    // copy elements in the list
    std::copy(lst.begin(), lst.end(), elem);
    val = Vektor::key++;
    std::cout << "\n constructor Vector (lst) \t" << val << "\n";

}

template<typename T>
Vektor<T>::~Vektor()
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

template<typename T>
T& Vektor<T>::operator[](int index) const
{
    return elem[index];
}

template<typename T>
T& Vektor<T>::operator[](int index)
{
    return elem[index];
}

template<typename T>
Vektor<T>& Vektor<T>::pushback(T & d)
{
    // Add to end
    int size = sz;
    T * arr = new T[sz++];
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

template<typename T>
Vektor<T>::Vektor(const Vektor<T>& a)
{
    // error check and exception later
    sz = a.size();
    elem = new T[sz];

    for (int i = 0; i < sz; i++)
    {
        // no pointer magic here
        // just data copy
        elem[i] = a[i];
    }
    val = Vektor::key++;
    std::cout << "\nCopy constructor\t" << val << "\n";
}

template<typename T>
Vektor<T>& Vektor<T>::operator=(const Vektor<T> & a)
{
    // Free whatever data we had;
    // Ideally have a resource free function
    if (elem)
    {
        delete[] elem;
    }

    sz = a.size();
    elem = new T[sz];

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

template<typename T>
Vektor<T>::Vektor(Vektor<T> && a)
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

template<typename T>
Vektor<T> & Vektor<T>::operator=(Vektor<T> && a)
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


// Crazy Template WAR
// https://isocpp.org/wiki/faq/templates#separate-template-fn-defn-from-decl
template class Vektor<double>;