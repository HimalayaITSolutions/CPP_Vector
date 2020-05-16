#include "pch.h"


// Variadic templates
// 3 stage tail...
// Typename... Tail
// define Tail.... 
// then recursion(tail..)

// 1
template<typename Ty, typename... Tail>
void print(Ty val, Tail... tail)
{
    std::cout << val << "\t";
    //print(tail...);

    // check size of tail
    if constexpr (sizeof...(tail) > 0)  // check constexpr use
        print(tail...);
    else
        std::cout << std::endl;
}

// 2

template<typename... Ty>
void printfold(Ty&&... vals)
{
   (std::cout <<  ... << vals ); // autocorrect.. braces are key   
}


// 3
template<typename... Ty>
void sum(Ty&&... vals)     // has ro be RValue operator
{
    // left fold
    int leftsum = ((-10) + ... + vals);
    auto rightsum = (vals + ... + (-20));
    std::cout << "\n" << leftsum << "\t" << rightsum << "\n"; // autocorrect
}


// 4
/* Understand the paramter here... this "T" is just the template for types like
va_list or va_arg in C

Type of vector need to be specified like in 1;
2 and 3 assume arithmetic Concepts behind the type

template<typename... T>
std::vector<T> toVectorfold(T&&... args)
{
    std::vector<T> v;
    (v.push_back(args...));
    return v;
}
*/

// 5
// Define a type for vector


template<typename Vec, typename... T>
std::vector<Vec> toVectorfold(T&&... args)
{
    std::vector<Vec> v;
    // (v.push_back(args...));  see the error
    (v.push_back(args),...);  // Commma is the key
    return v;
}


void chap7()
{
    //1
    print(1, 2, 3, 4);

    // 2
    printfold(2, 3, 4, 5);

    //3
    sum(10,20,30);

    // 5
    
    std::vector<int> v = toVectorfold<int>(3, 5, 7, 9);
    std::cout << "\t" << v[0] << v[2] << "\n";
    
}