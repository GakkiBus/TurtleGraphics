#include "rationals.h"

#include <string>
#include <numeric>

using namespace Turtle;

Rational::Rational(const std::string& str)
{
    auto search{str.find('%')};
    if (search == std::string::npos) {
        numerator = str.length() > 0 ? std::stoi(str) : 1;
        denominator = 1;
    } else {
        std::string n{str.substr(0, search)};
        numerator = n.length() > 0 ? std::stoi(n) : 1;
        std::string d{str.substr(search+1)};
	    denominator = d.length() > 0 ? std::stoi(d) : 1;
    }
}

bool Rational::isNull()
{
    return numerator == 0;
}

double Rational::toDouble()
{
    return static_cast<double>(numerator) / static_cast<double>(denominator);
}

void Rational::simplify()
{
    int gcd{std::gcd(numerator, denominator)};
    numerator /= gcd;
    denominator /= gcd;
}

Rational operator+(const Rational& r1, const Rational& r2)
{
    Rational sum{r1.getNumerator() * r2.getDenominator() + r1.getDenominator() * r2.getNumerator(), 
                r1.getDenominator() * r2.getDenominator()};
    sum.simplify();
    return sum;
}

Rational operator-(const Rational& r1, const Rational& r2)
{
    Rational sum{r1.getNumerator() * r2.getDenominator() - r1.getDenominator() * r2.getNumerator(),
                r1.getDenominator() * r2.getDenominator()};
    sum.simplify();
    return sum;
}

Rational operator*(const Rational& r1, const Rational& r2)
{
    Rational sum{r1.getNumerator() * r2.getNumerator(), r1.getDenominator() * r2.getDenominator()};
    sum.simplify();
    return sum;
}

Rational operator/(const Rational& r1, const Rational& r2)
{
    Rational sum{r1.getNumerator() * r2.getDenominator(), r1.getDenominator() * r2.getNumerator()};
    sum.simplify();
    return sum;
}
