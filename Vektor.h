#pragma once
#include <iostream>

class Vektor
{
public:
    static int key;

    // Initialize
    // I0: default
    Vektor()
    { 
        /*
        sz = 0;
        elem = nullptr;*/
        val = Vektor::key++;
    };
    // I1. Old style
    // This can lead to stupid compiler initializations like
    // Vektor v = 7; to create a 7 array of vektor.. !!!
    // explicit for single arguement always!
    explicit Vektor(int size);

    // I2. Initializer list
    Vektor(std::initializer_list<double> lst);
    virtual ~Vektor();

    // Returns individual Elements
    // Need 2 definitions for const and non-const cases
    // Undersatnd why we need 2 declaration and 2 definitions

    // Alternatively just reuse the variable directly as it is constructor
    double& operator[](int index) const;
    double& operator[](int index);

    // I3. Pushback
    Vektor& pushback(double& d);

    // Simple return size
    int size() const { return sz;}
    int size()       { return sz; }

    // Copy Constructor
    // Input is Const. We do not want to Move.
    // Onus is on this function to decide how to create a copy
    // Copying pointers is a no-no
    // Only const functions can be used for Const objects
    Vektor(const Vektor& a);

    // Copy assignment
    // Similar to Constructor but it returns back the object it created
    // And this is not a CONSTRUCTOR but an overloaded operator "="
    Vektor& operator=(const Vektor& a);


    // Move Constructors
    // We are going to destroy input object so no Const
    // See &&. This is for return.
    Vektor(Vektor&& a);

    // Move Assignment
    // Used as the proper assignment code.
    Vektor& operator=(Vektor&& a);



private: 
    // Member Initialization
    int sz = 0;
    int val = 0;
    double *elem = nullptr;
};


