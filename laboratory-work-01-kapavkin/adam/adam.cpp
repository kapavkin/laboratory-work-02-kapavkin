#include "adam.h"

adam::adam(int other)
{
    if (other < 1 || other > MAX_ADAM_YEAR) {
        throw std::invalid_argument("year out of range");
    }

    indict = other % 15;
    sun = other % 28;
    moon = other % 19;
}

adam::adam(int indict, int sun, int moon)
{
    set_indict(indict);
    set_sun(sun);
    set_moon(moon);
}

adam::adam(const adam& other)
{
    indict = other.indict;
    sun = other.sun;
    moon = other.moon;
}

adam::~adam()
{
}

adam adam::from_adam_year(int other)
{
    adam adam(other);

    return adam;
}

adam adam::from_christ_year(int other)
{
    adam adam(other + CHRIST_YEAR_DEVIATION);

    return adam;
}

adam adam::from_cycle(int indict, int sun, int moon)
{
    adam adam(indict, sun, moon);

    return adam;
}

adam adam::copy(const adam& other)
{
    adam adam(other);

    return adam;
}

int adam::to_adam_year() const
{
    int m1 = MAX_ADAM_YEAR / 15, y1;
    int m2 = MAX_ADAM_YEAR / 28, y2;
    int m3 = MAX_ADAM_YEAR / 19, y3;

    for (int y = 0, m = m1 % 15; y < 15; y++)
        if ((m * y) % 15 == indict)
            y1 = y;
    for (int y = 0, m = m2 % 28; y < 28; y++)
        if ((m * y) % 28 == sun)
            y2 = y;
    for (int y = 0, m = m3 % 19; y < 19; y++)
        if ((m * y) % 19 == moon)
            y3 = y;

    return (m1 * y1 + m2 * y2 + m3 * y3) % MAX_ADAM_YEAR;
}

int adam::to_christ_year() const
{
    return to_adam_year() - CHRIST_YEAR_DEVIATION;
}

std::string adam::to_string() const
{
    return std::to_string(to_adam_year());
}

int adam::get_indict() const
{
    return indict + 1;
}

int adam::get_sun() const
{
    return sun + 1;
}

int adam::get_moon() const
{
    return moon + 1;
}

void adam::set_indict(int indict)
{
    if (indict < 1 || indict > 15) {
        throw std::invalid_argument("indict out of range");
    }

    this->indict = indict - 1;
}

void adam::set_sun(int sun)
{
    if (sun < 1 || sun > 28) {
        throw std::invalid_argument("sun out of range");
    }

    this->sun = sun - 1;
}

void adam::set_moon(int moon)
{
    if (moon < 1 || moon > 19) {
        throw std::invalid_argument("moon out of range");
    }

    this->moon = moon - 1;
}

adam adam::operator+(const adam& other) const
{
    int adam_year = to_adam_year() + other.to_adam_year();

    return from_adam_year(adam_year);
}

adam adam::operator-(const adam& other) const
{
    int adam_year = to_adam_year() - other.to_adam_year();

    return from_adam_year(adam_year);
}

adam adam::operator+(int other) const
{
    return *this + from_adam_year(other);
}

adam adam::operator-(int other) const
{
    return *this - from_adam_year(other);
}

adam operator+(int left, const adam& right)
{
    return adam::from_adam_year(left) + right;
}

adam operator-(int left, const adam& right)
{
    return adam::from_adam_year(left) - right;
}

adam& adam::operator=(const adam& other)
{
    indict = other.indict;
    sun = other.sun;
    moon = other.moon;

    return *this;
}

adam& adam::operator+=(const adam& other)
{
    return *this = *this + other;
}

adam& adam::operator-=(const adam& other)
{
    return *this = *this - other;
}

adam& adam::operator=(int other)
{
    return *this = from_adam_year(other);
}

adam& adam::operator+=(int other)
{
    return *this = *this + other;
}

adam& adam::operator-=(int other)
{
    return *this = *this - other;
}

adam& adam::operator++()
{
    return *this += 1;
}

adam adam::operator++(int)
{
    adam adam(*this);

    *this += 1;

    return adam;
}

adam& adam::operator--()
{
    return *this -= 1;
}

adam adam::operator--(int)
{
    adam adam(*this);

    *this -= 1;

    return adam;
}

bool adam::operator==(const adam& other) const
{
    return to_adam_year() == other.to_adam_year();
}

bool adam::operator!=(const adam& other) const
{
    return to_adam_year() != other.to_adam_year();
}

bool adam::operator<(const adam& other) const
{
    return to_adam_year() < other.to_adam_year();
}

bool adam::operator>(const adam& other) const
{
    return to_adam_year() > other.to_adam_year();
}

bool adam::operator<=(const adam& other) const
{
    return *this < other || *this == other;
}

bool adam::operator>=(const adam& other) const
{
    return *this > other || *this == other;
}

bool adam::operator==(int other) const
{
    return *this == adam::from_adam_year(other);
}

bool adam::operator!=(int other) const
{
    return *this != adam::from_adam_year(other);
}

bool adam::operator<(int other) const
{
    return *this < adam::from_adam_year(other);
}

bool adam::operator>(int other) const
{
    return *this > adam::from_adam_year(other);
}

bool adam::operator<=(int other) const
{
    return *this <= adam::from_adam_year(other);
}

bool adam::operator>=(int other) const
{
    return *this >= adam::from_adam_year(other);
}

bool operator==(int left, const adam& right)
{
    return adam::from_adam_year(left) == right;
}

bool operator!=(int left, const adam& right)
{
    return adam::from_adam_year(left) != right;
}

bool operator<(int left, const adam& right)
{
    return adam::from_adam_year(left) < right;
}

bool operator>(int left, const adam& right)
{
    return adam::from_adam_year(left) > right;
}

bool operator<=(int left, const adam& right)
{
    return adam::from_adam_year(left) <= right;
}

bool operator>=(int left, const adam& right)
{
    return adam::from_adam_year(left) >= right;
}

std::istream& operator>>(std::istream& stream, adam& adam)
{
    int adam_year;
    stream >> adam_year;

    adam = adam::from_adam_year(adam_year);

    return stream;
}

std::ostream& operator<<(std::ostream& stream, const adam& adam)
{
    return stream << adam.to_adam_year();
}
