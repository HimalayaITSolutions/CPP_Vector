#include "pch.h"
#include "Triangle.h"
#include <iostream>

int Triangle::keyT = 0;

Triangle::Triangle(std::initializer_list<Vektor> lst)
// bad code
    : point {new Vektor*[3]} // bad code
{
    if (lst.size() != 3)
    {
        std::cout << "\nerror size\n";
        //throw std::length_error("Incorrect Size of Triangle"); // throw correct exception
    }
    val = Triangle::keyT++;
    std::cout << "\n Triangle Constructor Lst initialize\t" << val <<"\t";
    //std::copy(lst.begin(), lst.end(), point);
/*    for (int i = 0; i < size; i++)
    {
        point[i] = lst.be
    }*/
    /*int i = 0;
    for ((std::initializer_list<Vektor*>::iterator lstit = lst.begin(); lstit != lst.end(); lstit++))
        point[i++] = lstit;
    */
}

Triangle::Triangle(Vektor **v, int num)
// bad code
    : point{ new Vektor*[num] }
{
    if (num != 3)
    {
        std::cout << "\nerror size\n";
        //throw std::length_error("Incorrect Size of Triangle"); // throw correct exception
    }
    val = Triangle::keyT++;
    std::cout << "\n Triangle Constructor pointer\t" << val << "\t";

    for (int i = 0; i < num; i++)
    {
        //for (int j = 0; j < v[i]->size(); j++)
        {
            point[i] = new Vektor(*v[i]);
            //*point[i] =  *v[i] ;
         }
    }
       /*for (int i = 0; i < num; i++)
        {
           point[i] = new Vektor(v[i]->size());
           for (int j = 0; j < v[i]->size(); j++)
           {
               point[i][j] = v[i][j] ;
           }
        }*/
}


Triangle::~Triangle()
{
    std::cout << "\n Triangle destructor\t" << val <<"\t";
    if (point!= nullptr)
    {
        //std::cout << "\n Size point \t" << sizeof(point);
        for (int i = 0; i < 3; i++)
        {
            if (point[i]!= nullptr)
            {
                delete point[i];
                point[i] = nullptr;
            }

        }
        delete[] point;
        point = nullptr;
    }
}

void Triangle::draw()
{
    std::cout << "\n inside Triangle::draw \n ";
}

void Triangle::move(Vektor & v)
{
    std::cout << "\n inside Triangle::move \n ";
}

void Triangle::rotate(int angle)
{
    std::cout << "\n inside Triangle::rotate \n ";
}

void Triangle::centre(Vektor &)
{
    std::cout << "\n inside Triangle::centre \n ";
}
