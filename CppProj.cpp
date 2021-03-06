// CppProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Vektor.h"
#include <iostream>
#include <vector>
#include "Smiley.h"

using namespace std;


/*
directcallsfrommain()
{
    //ReferenceTest();
        // NakedUnion();
        //Complex c;
    Complex a{ 1,2.3 };
    Complex b = { 2, 4.6 };
    //c = a;
    Complex d{ 2 * a }; // Does not work unless I specify single Argument Constructor
    std::cout << "\n Equal = " << (d != a) << (d == b); // Remove braces and this will choose operators in a weird way
}

direct2()
{
    //Vektor t1{ 1,1,1 };
    //Vektor t2{ 2,2,2 };
    Vektor *t1 = new Vektor{ 1,1,1 };
    Vektor *t2 = new Vektor{ 2,2,2 };
    Vektor *t3 = new Vektor{ 3,3,3 }; // Leak memory
    // //unique pointers help in solving memory leaks but
    // then every Vektor* needs to move to unique_ptr<>

    //std::unique_ptr<Vektor> t1 = new Vektor{ 1,1,1 };
    //std::unique_ptr<Vektor> t2= new Vektor{ 2,2,2 };
    //std::unique_ptr<Vektor> t3= new Vektor{ 3,3,3 }; 

    Vektor c{ 1,2,1 };

    Circle c1{ c,5 };
    //Triangle t{ *t1,*t2,*t3 };
    //Triangle t{ { 1,1,1 } ,{ 2,2,2 },{ 3,3,3 }};
    Vektor *arr[] = { t1, t2,t3 };
    Triangle t(arr, 3);
    Smiley s{ c1, t };

    // C1 is deleted and then you try to delete the object in a different class.

    Vektor m{ 2,2,2 };
    sh.push_back(&c1);
    sh.push_back(&t);
    sh.push_back(&s);

    for (auto s: sh)
    {
        s->draw();
        s->move(m);
        s->rotate(45);
    }

    delete t1;
    delete t2;
    delete t3;
}


void callHierarchy()
{
    vector<unique_ptr<Shape>> shape;

    unique_ptr<Vektor<double>> t1 = (unique_ptr<Vektor<double>>)new Vektor<double>{ 1,1,1 };

    int a = 0;
    // get the objects built
        while (cin >> a) {
            shape.push_back(read_shape(a));
    }

    //Run operations
        Vektor<double> m{ 2,2,2 };
        // unique pointers cant be deleted.
        // so use reference
        for (auto &s : shape)
        {
            s->draw();
            s->move(m);
            s->rotate(45);
        }
}*/

// The templated Draw:
template<typename Sequence, typename Predicate>
void forAllShapes(Sequence& Seq, Predicate P)
{
    for (auto &a : Seq)
        P(a);               // Predicate is not called but it as object, whose operator() method is called. Pass the Sequence as input
}

int main()
{
    cout << "Hello World!\n";    
   
    vector<unique_ptr<Shape>> shape;

    unique_ptr<Vektor<double>> t1 = (unique_ptr<Vektor<double>>)new Vektor<double>{ 1,1,1 };

    Vektor t2 { 2.2, 2.3 };
    int a = 0;
    // get the objects built
    while (cin >> a) {
        shape.push_back(read_shape(a));
    }

    forAllShapes(shape, [&](unique_ptr<Shape> &s) {s->draw(); });
    forAllShapes(shape, [&](auto &s) {s->rotate(45); s->centre(t2); });// does this capture t2... yep, ,supposedly in entire scope aa reference

    

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
