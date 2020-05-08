#include "pch.h"

using namespace std;

unique_ptr<Shape> read_shape(int a)
{
    //Shape *s = nullptr;
    //cin >> a;
    //while (a)
    {
        switch (a)
        {
        case 1: // Circle
            {
                cout << "Enter Centre and Radius";
                double x, y, r;
                cin >> x >> y >> r;
                Vektor c{ x,y,0 };

                // Cant return local variable 
                // Circle c1{ c,5 };
                // return c1;
                return (unique_ptr<Circle>)new Circle(c, 5);
            }
            break;
        case 2: // Triangle
            {
                cout << "Enter six  points for vertices";
                double x1, x2, x3, y1, y2, y3;
                cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
                Vektor v1{ x1,y1,0 };
                Vektor v2{ x2,y2,0 };
                Vektor v3{ x3,y3,0 };
                Vektor *arr[] = { &v1, &v2,&v3 };
                //Triangle t(arr, 3);
                return (unique_ptr<Triangle>) new Triangle(arr, 3);
            }

            break;
        case 3: //Smiley
            {
                cout << "Enter Centre and Radius";
                double x, y, r;
                cin >> x >> y >> r;
                Vektor c{ x,y,0 };
                Circle c1{ c,5 };

                cout << "Enter six  points for vertices";
                double x1, x2, x3, y1, y2, y3;
                cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
                Vektor v1{ x1,y1,0 };
                Vektor v2{ x2,y2,0 };
                Vektor v3{ x3,y3,0 };
                Vektor *arr[] = { &v1, &v2,&v3 };
                Triangle t(arr, 3);

                //Smiley s{ c1, t };
                return (unique_ptr<Smiley>)new Smiley(c1, t);
            }
            break;
        }
    }
    return nullptr;
}