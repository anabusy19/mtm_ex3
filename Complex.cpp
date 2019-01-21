//
// Created by samah on 12/30/2018.
//

#include <istream>
#include "Complex.h"
using namespace std;

namespace MtmMath {
    Complex::Complex(double r, double i) : re(r), im(i) {}

    Complex::Complex(const Complex& c) : re(c.re), im(c.im) {}

    Complex& Complex::operator=(const Complex &c) {
        this->re = c.re;
        this->im = c.im;
    }

    Complex Complex::operator-() const {
        return Complex(-re, -im);
    }

    Complex& Complex::operator+=(const Complex& c) {
        re += c.re;
        im += c.im;
        return *this;
    }

    Complex& Complex::operator-=(const Complex& c) {
        re -= c.re;
        im -= c.im;
        return *this;
    }

    Complex& Complex::operator*=(const Complex& c) {
        double tmpRe = re;
        re = re*c.re - im*c.im;
        im = im*c.re + tmpRe*c.im;
        return *this;
    }

    bool Complex::operator==(const Complex& c) const {
        return c.re == re && c.im == im;
    }

    bool Complex::operator!=(const Complex& c) const {
        return c.re != re || c.im != im;
    }
//    ostream& operator<<(ostream& os, const Complex& c) {
//        const char* sign = c.im < 0 ? "-" : "+";
//        return os << c.re << sign << c.im << "i";
//    }
//
//    istream& operator>>(istream& is, Complex& c) {
//        return is >> c.re >> c.im;
//    }

    Complex operator+(const Complex& a, const Complex& b) {
        return Complex(a) += b;
    }

    Complex operator-(const Complex& a, const Complex& b) {
        return Complex(a) -= b;
    }


    Complex operator*(const Complex& a, const Complex& b) {
        return Complex(a) *= b;
    }

}