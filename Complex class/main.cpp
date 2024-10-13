#include <iostream>
#include <math.h>
using namespace std;

class complex
{
private:
    float real;
    float imag;
public:
    complex(float, float);
    complex(complex &c);

    float getReal(){return real;}

    float getImag(){return imag;}

    /*
    void display()
    {
        cout<< real << " " << "+ " <<imag<< "i"<<endl;
    }
*/
    void display_MagAngle()
    {
        float c_mag = sqrt(pow(real,2) + pow(imag,2));

        float c_angle = atan(imag / real);

        cout<<c_mag<<" "<<"<"<<c_angle<<endl;
    }

    complex operator+(complex c);
    complex operator-(complex c);
    complex operator/(complex c);
    complex operator*(complex c);
    friend ostream & operator<<(ostream &O, complex &c);

};


complex::complex(float real = 0, float imag = 0)
    {
        this->real = real;
        this->imag = imag;
    }

complex::complex(complex &comp)
    {
        real = comp.real;
        imag = comp.imag;

    }
complex complex::operator+(complex c)
    {
        complex temp(0,0);
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
complex complex::operator-(complex c)
    {
        complex temp(0,0);
        temp.real = real - c.real;
        temp.imag = imag - c.imag;
        return temp;
    }
complex complex::operator/(complex c)
    {
        complex temp(0,0);
        float c1_mag = sqrt(pow(real,2) + pow(imag,2));
        float c_mag = sqrt(pow(c.real,2) + pow(c.imag,2));

        float c1_angle = atan(imag / real);
        float c_angle = atan(c.imag / c.real);

        float temp_mag = c1_mag / c_mag;
        float temp_ang = c1_angle - c_angle;

        temp.real = temp_mag * cos(temp_ang);
        temp.imag = temp_mag * sin(temp_ang);

        return temp;
    }
complex complex::operator*(complex c)
    {
        complex temp(0,0);
        float c1_mag = sqrt(pow(real,2) + pow(imag,2));
        float c_mag = sqrt(pow(c.real,2) + pow(c.imag,2));

        float c1_angle = atan(imag / real);
        float c_angle = atan(c.imag / c.real);

        float temp_mag = c1_mag * c_mag;
        float temp_ang = c1_angle + c_angle;

        temp.real = temp_mag * cos(temp_ang);
        temp.imag = temp_mag * sin(temp_ang);

        return temp;
    }
ostream & operator<<(ostream &O, complex &c)
{
    O << c.real << " " << "+ " <<c.imag<< "i";
    return O;
}
int main()
{
    complex c1(5, 9) , c2(4,2);
    complex c3 = c1 / c2;
    cout<<c3<<endl;
    c3.display_MagAngle();

    return 0;
}
