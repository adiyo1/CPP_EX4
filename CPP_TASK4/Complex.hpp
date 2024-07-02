// adi.yohanann@gmail.com

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <string>
#include <cmath>

class Complex
{
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    Complex operator+(const Complex &other) const;

    Complex operator*(const Complex &other) const;
    
    bool operator<(const Complex &other) const;
    
    bool operator>=(const Complex &other) const;
    
    friend std::ostream &operator<<(std::ostream &os, const Complex &c);
    
    std::string to_string() const;
    
    double get_real() const;

    double get_imag() const;
};

#endif // COMPLEX_HPP
