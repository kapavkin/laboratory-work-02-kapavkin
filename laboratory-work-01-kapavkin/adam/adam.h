#ifndef ADAM_H
#define ADAM_H

#include <iostream>
#include <stdexcept>
#include <string>

#include "ADT.h"

#define MAX_ADAM_YEAR 7980
#define CHRIST_YEAR_DEVIATION 5508

class adam : public ADT {
private:
    int indict, sun, moon;

public:
    adam(int = 1);
    adam(int, int, int);
    adam(const adam&);
    ~adam();

    static adam from_adam_year(int = 1);
    static adam from_christ_year(int = 1);
    static adam from_cycle(int, int, int);
    static adam copy(const adam&);

    int to_adam_year() const;
    int to_christ_year() const;
    virtual std::string to_string() const override;

    int get_indict() const;
    int get_sun() const;
    int get_moon() const;

    void set_indict(int);
    void set_sun(int);
    void set_moon(int);

    adam operator+(const adam&) const;
    adam operator-(const adam&) const;

    adam operator+(int) const;
    adam operator-(int) const;

    friend adam operator+(int, const adam&);
    friend adam operator-(int, const adam&);

    adam& operator=(const adam&);
    adam& operator+=(const adam&);
    adam& operator-=(const adam&);

    adam& operator=(int);
    adam& operator+=(int);
    adam& operator-=(int);

    adam& operator++();
    adam operator++(int);
    adam& operator--();
    adam operator--(int);

    bool operator==(const adam&) const;
    bool operator!=(const adam&) const;
    bool operator<(const adam&) const;
    bool operator>(const adam&) const;
    bool operator<=(const adam&) const;
    bool operator>=(const adam&) const;

    bool operator==(int) const;
    bool operator!=(int) const;
    bool operator<(int) const;
    bool operator>(int) const;
    bool operator<=(int) const;
    bool operator>=(int) const;

    friend bool operator==(int, const adam&);
    friend bool operator!=(int, const adam&);
    friend bool operator<(int, const adam&);
    friend bool operator>(int, const adam&);
    friend bool operator<=(int, const adam&);
    friend bool operator>=(int, const adam&);

    friend std::istream& operator>>(std::istream&, adam&);
    friend std::ostream& operator<<(std::ostream&, const adam&);
};

#endif
