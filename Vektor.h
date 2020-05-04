#pragma once
class Vektor
{
public:
    Vektor(int size);
    virtual ~Vektor();

    double& operator[](int index);

    // Simple return size
    int size() { return sz;}

private: 
    int sz;
    double *elem;
};

