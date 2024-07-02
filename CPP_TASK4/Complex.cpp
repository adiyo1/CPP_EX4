// adi.yohanann@gmail.com

#include "Complex.hpp"

Complex Complex:: operator+(const Complex &other) const//overloading the + operator
{
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator*(const Complex &other) const//overloading the * operator
{
    return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
}

bool Complex::operator<(const Complex &other) const//overloading the < operator
{
    return std::sqrt(real * real + imag * imag) < std::sqrt(other.real * real + other.imag * other.imag);
}

bool Complex::operator>=(const Complex &other) const//overloading the >= operator
{
    return std::sqrt(real * real + imag * imag) >= std::sqrt(other.real * real + other.imag * other.imag);
}

std::ostream &operator<<(std::ostream &os, const Complex &c)//overloading the << operator
{
    os << c.real << " + " << c.imag << "i";
    return os;
}

std::string Complex::to_string() const//returning the string representation of the complex number
{
    return std::to_string(real) + " + " + std::to_string(imag) + "i";
}

double Complex::get_real() const { return real; }//returning the real part of the complex number

double Complex::get_imag() const { return imag; }//returning the imaginary part of the complex number
