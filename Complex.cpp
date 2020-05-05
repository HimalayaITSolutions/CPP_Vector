#include "pch.h"
#include "Complex.h"
#include <iostream>


    Complex::Complex(double r, double i)
        :re(r),
        img(i)
    {
    }

    Complex::Complex(double r)
        : re{r},
        img(r)
    {

    }

    Complex::~Complex()
    {
        re = img = 0.0f;
    }
 


Complex operator+(Complex a, Complex b)
{
    // TODO: insert return statement here
    return a += b;
}

Complex operator-(Complex a, Complex b)
{
    // TODO: insert return statement here
    return a -= b;
}

Complex& Complex::operator+=(Complex & b)
{
    // TODO: insert return statement here
    re += b.re;
    img += b.img;
    return *this;
}

Complex & Complex::operator-=(Complex & b)
{
    // TODO: insert return statement here
    re -= b.re;
    img -= b.img;
    return *this;
}

Complex & Complex::operator*=(Complex & b)
{
    // TODO: insert return statement here
    re *= b.re;
    img *= b.img;
    return *this;
}


Complex operator*(Complex a, Complex b)
{
    // TODO: insert return statement here
    return a *= b;
}

bool operator!=(Complex & a, Complex & b)
{
    return !(a==b);
}

bool Complex::operator==(Complex & b)
{
    // TODO: insert return statement here
    return (getReal() == b.getReal() &&
            getImg() == b.getImg());
}
