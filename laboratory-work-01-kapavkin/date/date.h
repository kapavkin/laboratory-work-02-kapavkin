#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <stdexcept>
#include <string>

#include "ADT.h"

class date : public ADT {
private:
    int year, month, day;
    int hour, minute, second;

    static int leap_years_until(int);
    static int leap_years_between(int, int);
    static bool is_leap_year(int);

    static int number_of_days(int, int);

public:
    date(uint64_t = 0);
    date(const date&);
    ~date();

    static date from_unix_time(uint64_t);
    static date from_file_time(uint64_t);
    static date copy(const date&);

    uint64_t to_unix_time() const;
    uint64_t to_file_time() const;
    virtual std::string to_string() const override;

    int get_year() const;
    int get_month() const;
    int get_day() const;
    int get_hour() const;
    int get_minute() const;
    int get_second() const;

    void set_year(int);
    void set_month(int);
    void set_day(int);
    void set_hour(int);
    void set_minute(int);
    void set_second(int);

    date operator+(const date&) const;
    date operator-(const date&) const;

    date operator+(uint64_t) const;
    date operator-(uint64_t) const;

    friend date operator+(uint64_t, const date&);
    friend date operator-(uint64_t, const date&);

    date& operator=(const date&);
    date& operator+=(const date&);
    date& operator-=(const date&);

    date& operator=(uint64_t);
    date& operator+=(uint64_t);
    date& operator-=(uint64_t);

    date& operator++();
    date operator++(int);
    date& operator--();
    date operator--(int);

    bool operator==(const date&) const;
    bool operator!=(const date&) const;
    bool operator<(const date&) const;
    bool operator>(const date&) const;
    bool operator<=(const date&) const;
    bool operator>=(const date&) const;

    bool operator==(uint64_t) const;
    bool operator!=(uint64_t) const;
    bool operator<(uint64_t) const;
    bool operator>(uint64_t) const;
    bool operator<=(uint64_t) const;
    bool operator>=(uint64_t) const;

    friend bool operator==(uint64_t, const date&);
    friend bool operator!=(uint64_t, const date&);
    friend bool operator<(uint64_t, const date&);
    friend bool operator>(uint64_t, const date&);
    friend bool operator<=(uint64_t, const date&);
    friend bool operator>=(uint64_t, const date&);

    friend std::istream& operator>>(std::istream&, date&);
    friend std::ostream& operator<<(std::ostream&, const date&);
};

#endif
