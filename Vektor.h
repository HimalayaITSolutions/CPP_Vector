#pragma once
#include <iostream>

class Vektor
{
public:
    // Initialize
    // I1. Old style
    Vektor(int size);

    // I2. Initializer list
    Vektor(std::initializer_list<double> lst);
    virtual ~Vektor();

    double& operator[](int index);

    // I3. Pushback
    Vektor& pushback(double& d);

    // Simple return size
    int size() { return sz;}

private: 
    int sz;
    double *elem;
};

