#ifndef RATIONAL_H
#define RATIONAL_H

#include <string>

namespace Turtle
{
    class Rational
    {
    private:
        int numerator;
        int denominator;
        
    public:
        Rational(int n, int d) : numerator{n}, denominator{d} {}
        Rational(const std::string& str);
        int getNumerator() const { return numerator; }
        int getDenominator() const { return denominator; }
        bool isNull();
        double toDouble();
        void simplify();

        friend Rational operator+(const Rational& r1, const Rational& r2);
        friend Rational operator-(const Rational& r1, const Rational& r2);
        friend Rational operator*(const Rational& r1, const Rational& r2);
        friend Rational operator/(const Rational& r1, const Rational& r2);
        friend bool operator<(const Rational& r1, const Rational& r2);
        friend bool operator==(const Rational& r1, const Rational& r2);
    };
}

#endif
