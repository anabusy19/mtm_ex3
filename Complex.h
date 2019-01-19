#ifndef EX3_COMPLEX_H
#define EX3_COMPLEX_H

using namespace std;

namespace MtmMath {
    class Complex {
        double re,im;
    public:
        Complex(int r);
        Complex(double r=0, double i=0);
        Complex(const Complex& c) ;
        Complex& operator=(const Complex&);
        Complex& operator+=(const Complex& c) ;
        Complex& operator-=(const Complex& c) ;
        Complex& operator*=(const Complex& c) ;
        bool operator==(const Complex& c) const ;
        bool operator!=(const Complex& c) const ;
        Complex operator-() const ;
//        friend ostream& operator<<(ostream& os, const Complex& c);
//        friend istream& operator>>(istream& is, Complex& c);

    };
    Complex operator+(const Complex& a, const Complex& b) ;
    Complex operator-(const Complex& a, const Complex& b) ;
    Complex operator*(const Complex& a, const Complex& b)  ;
}
#endif //EX3_COMPLEX_H
