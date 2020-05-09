#include "pch.h"
#include "Circle.h"
#include <iostream>

Circle::~Circle()
{
}

void Circle::draw()
{
    std::cout << "\n inside Circle::draw \n ";
}

void Circle::move(Vektor<double> &)
{
    std::cout << "\n inside Circle::move \n ";
}

void Circle::rotate(int angle)
{
    std::cout << "\n inside Circle::rotate \n ";
}


void Circle::centre(Vektor<double> &)
{
    std::cout << "\n inside Circle::centre \n ";
}
