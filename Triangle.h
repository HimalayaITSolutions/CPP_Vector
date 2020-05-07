#pragma once
#include "Shape.h"
#include <iostream>
#include <vector>
#include "Vektor.h"

class Triangle :
    public Shape
{
public:
    static int keyT;
    Triangle(std::initializer_list<Vektor> lst);
    Triangle()
        :  point{nullptr}
    {
        std::cout << "\n Triangle Constructor void\n";
    };

    Triangle(Vektor *v[], int num);
    virtual ~Triangle();


    // Constructor move and copy
    Triangle(const Triangle& t);
    Triangle(Triangle&& t);

    // Assigment copy and move
    Triangle & operator=(const Triangle& t);
    Triangle & operator=(Triangle&& t);


    void draw();

    void move(Vektor&);
    void rotate(int angle);
    void centre(Vektor&);

//private:
    Vektor** point;
    int size{ 3 };
    int val = 0;

};

