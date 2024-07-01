#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    Complex operator+(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

#endif // COMPLEX_HPP
