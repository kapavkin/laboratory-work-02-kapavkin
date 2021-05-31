#ifndef NUMBER_H
#define NUMBER_H

#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>

#include "ADT.h"

#define DEFAULT_CAPACITY 8 * sizeof(int)

class number : public ADT {
private:
    size_t capacity;
    bool* binary;

    void resize(size_t);

    static number copy(const number&, size_t);
    static number shift(const number&, int);
    static number divide(const number&, const number&, number&);

    static std::string divide(const std::string&, number&);
    static std::string add(const std::string&, const std::string&);

public:
    number(int = 0);
    number(const number&);
    ~number();

    static number from_int(int);
    static number copy(const number&);

    int to_int() const;
    virtual std::string to_string() const override;

    size_t get_capacity() const;

    number operator-() const;
    number operator~() const;
    number operator+(const number&) const;
    number operator-(const number&) const;
    number operator*(const number&) const;
    number operator/(const number&) const;
    number operator%(const number&) const;
    number operator&(const number&) const;
    number operator|(const number&) const;
    number operator^(const number&) const;
    number operator<<(const number&) const;
    number operator>>(const number&) const;

    number operator+(int) const;
    number operator-(int) const;
    number operator*(int) const;
    number operator/(int) const;
    number operator%(int) const;
    number operator&(int) const;
    number operator|(int) const;
    number operator^(int) const;
    number operator<<(int) const;
    number operator>>(int) const;

    friend number operator+(int, const number&);
    friend number operator-(int, const number&);
    friend number operator*(int, const number&);
    friend number operator/(int, const number&);
    friend number operator%(int, const number&);
    friend number operator&(int, const number&);
    friend number operator|(int, const number&);
    friend number operator^(int, const number&);
    friend number operator<<(int, const number&);
    friend number operator>>(int, const number&);

    number& operator=(const number&);
    number& operator+=(const number&);
    number& operator-=(const number&);
    number& operator*=(const number&);
    number& operator/=(const number&);
    number& operator%=(const number&);
    number& operator&=(const number&);
    number& operator|=(const number&);
    number& operator^=(const number&);
    number& operator<<=(const number&);
    number& operator>>=(const number&);

    number& operator=(int);
    number& operator+=(int);
    number& operator-=(int);
    number& operator*=(int);
    number& operator/=(int);
    number& operator%=(int);
    number& operator&=(int);
    number& operator|=(int);
    number& operator^=(int);
    number& operator<<=(int);
    number& operator>>=(int);

    number& operator++();
    number operator++(int);
    number& operator--();
    number operator--(int);

    bool operator!() const;
    bool operator&&(const number&) const;
    bool operator||(const number&) const;
    bool operator==(const number&) const;
    bool operator!=(const number&) const;
    bool operator<(const number&) const;
    bool operator>(const number&) const;
    bool operator<=(const number&) const;
    bool operator>=(const number&) const;

    bool operator&&(int) const;
    bool operator||(int) const;
    bool operator==(int) const;
    bool operator!=(int) const;
    bool operator<(int) const;
    bool operator>(int) const;
    bool operator<=(int) const;
    bool operator>=(int) const;

    friend bool operator&&(int, const number&);
    friend bool operator||(int, const number&);
    friend bool operator==(int, const number&);
    friend bool operator!=(int, const number&);
    friend bool operator<(int, const number&);
    friend bool operator>(int, const number&);
    friend bool operator<=(int, const number&);
    friend bool operator>=(int, const number&);

    friend std::istream& operator>>(std::istream&, number&);
    friend std::ostream& operator<<(std::ostream&, const number&);
};

#endif
