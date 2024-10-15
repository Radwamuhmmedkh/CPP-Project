#include <iostream>
#include <math.h>
using namespace std;


# define pi 3.14
class shape
{
    public:
    virtual float Area() = 0;
    virtual float perimeter() = 0;
};

class Rectangle: public shape
{
private:
    float length;
    float width;
public:
    // Constructors
    Rectangle(float length = 0, float width = 0)
    {
        setLength(length);
        setWidth(width);
    }

    // Mutators

    void setLength(float x)
    {
        if (x > 0)
            length = x;
        else
        {
            cout<<"invalid value, length is set to ZERO"<<endl;
            length = 0;
        }
    }
    void setWidth(float x)
    {
        if (x > 0)
            width = x;
        else
        {
            cout<<"invalid value, Width is set to ZERO"<<endl;
            width = 0;
        }
    }
// Accessors
    float getLength() { return length; }

    float getWidth() { return width; }

    float Area() { return length * width; }

    float perimeter() { return 2 * (length + width); }
};

class Circle : public shape
{
private:
    float raduis;
public:
    Circle(float raduis  = 0) {setRaduis(raduis);}
    void setRaduis(float raduis)
    {
        if (raduis > 0)
            this->raduis = raduis;
        else
        {
            cout<<"invalid value, raduis is set to ZERO"<<endl;
            this->raduis = 0;
        }
    }
    float getRaduis() { return raduis; }
    float Area() { return pi * pow( raduis, 2); }
    float perimeter() { return 2 * pi * raduis; }
};

int main()
{

    shape *ptr = new Rectangle(0.7, 5.2);
    shape *p = new Circle(5);

    cout<<"Area of Rectangle = "<< ptr->Area() << " Perimeter of Rectangle = " << ptr->perimeter() <<endl;
      cout<<"Area of Circle = "<< p->Area() << " Perimeter of Circle = " << p->perimeter() <<endl;
    return 0;
}
