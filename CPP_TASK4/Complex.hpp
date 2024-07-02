// #ifndef COMPLEX_HPP
// #define COMPLEX_HPP

// #include <iostream>

// class Complex {
// private:
//     double real;
//     double imag;

// public:
//     Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
//     Complex operator+(const Complex& other) const;
//     Complex operator*(const Complex& other) const;
//     friend std::ostream& operator<<(std::ostream& os, const Complex& c);
// };

// #endif // COMPLEX_HPP

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

    Complex operator+(const Complex &other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator*(const Complex &other) const
    {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }
    bool operator<(const Complex &other) const
    {
        return std::sqrt(real * real + imag * imag) < std::sqrt(other.real * real + other.imag * other.imag);
    }
    bool operator>(const Complex &other) const
    {
        return std::sqrt(real * real + imag * imag) > std::sqrt(other.real * real + other.imag * other.imag);
    }
    friend std::ostream &operator<<(std::ostream &os, const Complex &c)
    {
        os << c.real << " + " << c.imag << "i";
        return os;
    }

    std::string to_string() const
    {
        return std::to_string(real) + " + " + std::to_string(imag) + "i";
    }

    double get_real() const { return real; }
    double get_imag() const { return imag; }
};

#endif // COMPLEX_HPP
