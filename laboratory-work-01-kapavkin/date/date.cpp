#include "date.h"

int date::leap_years_until(int year)
{
    return year / 4 - year / 100 + year / 400;
}

int date::leap_years_between(int start, int end)
{
    return leap_years_until(end) - leap_years_until(start - 1);
}

bool date::is_leap_year(int year)
{
    return leap_years_between(year, year) == 1;
}

int date::number_of_days(int month, int year)
{
    int number_of_days = 30;

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        number_of_days = 31;
    }

    if (month == 2) {
        if (is_leap_year(year)) {
            number_of_days = 29;
        } else {
            number_of_days = 28;
        }
    }

    return number_of_days;
}

date::date(uint64_t other)
{
    uint64_t years_since_epoch = other / 31557600;

    year = 1970 + years_since_epoch;

    if (year > 9999) {
        throw std::invalid_argument("year out of range");
    }

    uint64_t days_since_year = (other - years_since_epoch * 31536000 - leap_years_between(1970, year - 1) * 86400) / 86400;

    for (int m = 1; m <= 12; m++) {
        if (days_since_year > number_of_days(m, year)) {
            days_since_year -= number_of_days(m, year);
        } else {
            month = m;
            day = days_since_year + 1;
            break;
        }
    }

    uint64_t seconds_since_day = other % 86400;

    hour = seconds_since_day / 3600;

    seconds_since_day -= hour * 3600;

    minute = seconds_since_day / 60;

    seconds_since_day -= minute * 60;

    second = seconds_since_day;
}

date::date(const date& other)
{
    year = other.year;
    month = other.month;
    day = other.day;
    hour = other.hour;
    minute = other.minute;
    second = other.second;
}

date::~date()
{
}

date date::from_unix_time(uint64_t other)
{
    date date(other);

    return date;
}

date date::from_file_time(uint64_t other)
{
    other /= 10000000;

    date date;

    uint64_t years_since_epoch = other / 31557600;

    date.year = 1601 + years_since_epoch;

    if (date.year > 9999) {
        throw std::invalid_argument("year out of range");
    }

    uint64_t days_since_year = (other - years_since_epoch * 31536000 - leap_years_between(1601, date.year - 1) * 86400) / 86400;

    for (int m = 1; m <= 12; m++) {
        if (days_since_year > number_of_days(m, date.year)) {
            days_since_year -= number_of_days(m, date.year);
        } else {
            date.month = m;
            date.day = days_since_year + 1;
            break;
        }
    }

    uint64_t seconds_since_day = other % 86400;

    date.hour = seconds_since_day / 3600;

    seconds_since_day -= date.hour * 3600;

    date.minute = seconds_since_day / 60;

    seconds_since_day -= date.minute * 60;

    date.second = seconds_since_day;

    return date;
}

date date::copy(const date& other)
{
    date date(other);

    return date;
}

uint64_t date::to_unix_time() const
{
    if (year < 1970) {
        return 0;
    }

    uint64_t unix_time = (year - 1970) * 31536000 + leap_years_between(1970, year - 1) * 86400;

    for (int m = 1; m < month; m++) {
        unix_time += number_of_days(m, year) * 86400;
    }

    unix_time += (day - 1) * 86400;
    unix_time += hour * 3600;
    unix_time += minute * 60;
    unix_time += second;

    return unix_time;
}

uint64_t date::to_file_time() const
{
    if (year < 1601) {
        return 0;
    }

    uint64_t file_time = ((uint64_t)year - 1601) * 31536000 + leap_years_between(1601, year - 1) * 86400;

    for (int m = 1; m < month; m++) {
        file_time += number_of_days(m, year) * 86400;
    }

    file_time += (day - 1) * 86400;
    file_time += hour * 3600;
    file_time += minute * 60;
    file_time += second;

    return file_time * 10000000;
}

std::string date::to_string() const
{
    std::string string, temp;

    temp = std::to_string(year);
    string.append(4 - temp.length(), '0');
    string += temp;

    string += "-";

    temp = std::to_string(month);
    string.append(2 - temp.length(), '0');
    string += temp;

    string += "-";

    temp = std::to_string(day);
    string.append(2 - temp.length(), '0');
    string += temp;

    string += "T";

    temp = std::to_string(hour);
    string.append(2 - temp.length(), '0');
    string += temp;

    string += ":";

    temp = std::to_string(minute);
    string.append(2 - temp.length(), '0');
    string += temp;

    string += ":";

    temp = std::to_string(second);
    string.append(2 - temp.length(), '0');
    string += temp;

    return string;
}

int date::get_year() const
{
    return year;
}

int date::get_month() const
{
    return month;
}

int date::get_day() const
{
    return day;
}

int date::get_hour() const
{
    return hour;
}

int date::get_minute() const
{
    return minute;
}

int date::get_second() const
{
    return second;
}

void date::set_year(int year)
{
    if (year < 1 || year > 9999) {
        throw std::invalid_argument("year out of range");
    }

    if (day > number_of_days(month, year)) {
        throw std::invalid_argument("day out of range");
    }

    this->year = year;
}

void date::set_month(int month)
{
    if (month < 1 || month > 12) {
        throw std::invalid_argument("month out of range");
    }

    if (day > number_of_days(month, year)) {
        throw std::invalid_argument("day out of range");
    }

    this->month = month;
}

void date::set_day(int day)
{
    if (day < 1 || day > number_of_days(month, year)) {
        throw std::invalid_argument("day out of range");
    }

    this->day = day;
}

void date::set_hour(int hour)
{
    if (hour < 0 || hour > 23) {
        throw std::invalid_argument("hour out of range");
    }

    this->hour = hour;
}

void date::set_minute(int minute)
{
    if (minute < 0 || minute > 59) {
        throw std::invalid_argument("minute out of range");
    }

    this->minute = minute;
}

void date::set_second(int second)
{
    if (second < 0 || second > 59) {
        throw std::invalid_argument("second out of range");
    }

    this->second = second;
}

date date::operator+(const date& other) const
{
    uint64_t unix_time = to_unix_time() + other.to_unix_time();

    return from_unix_time(unix_time);
}

date date::operator-(const date& other) const
{
    uint64_t unix_time = to_unix_time() - other.to_unix_time();

    return from_unix_time(unix_time);
}

date date::operator+(uint64_t other) const
{
    return *this + from_unix_time(other);
}

date date::operator-(uint64_t other) const
{
    return *this - from_unix_time(other);
}

date operator+(uint64_t left, const date& right)
{
    return date::from_unix_time(left) + right;
}

date operator-(uint64_t left, const date& right)
{
    return date::from_unix_time(left) - right;
}

date& date::operator=(const date& other)
{
    year = other.year;
    month = other.month;
    day = other.day;
    hour = other.hour;
    minute = other.minute;
    second = other.second;

    return *this;
}

date& date::operator+=(const date& other)
{
    return *this = *this + other;
}

date& date::operator-=(const date& other)
{
    return *this = *this - other;
}

date& date::operator=(uint64_t other)
{
    return *this = from_unix_time(other);
}

date& date::operator+=(uint64_t other)
{
    return *this = *this + other;
}

date& date::operator-=(uint64_t other)
{
    return *this = *this - other;
}

date& date::operator++()
{
    return *this += 1;
}

date date::operator++(int)
{
    date date(*this);

    *this += 1;

    return date;
}

date& date::operator--()
{
    return *this -= 1;
}

date date::operator--(int)
{
    date date(*this);

    *this -= 1;

    return date;
}

bool date::operator==(const date& other) const
{
    return to_unix_time() == other.to_unix_time();
}

bool date::operator!=(const date& other) const
{
    return to_unix_time() != other.to_unix_time();
}

bool date::operator<(const date& other) const
{
    return to_unix_time() < other.to_unix_time();
}

bool date::operator>(const date& other) const
{
    return to_unix_time() > other.to_unix_time();
}

bool date::operator<=(const date& other) const
{
    return *this < other || *this == other;
}

bool date::operator>=(const date& other) const
{
    return *this > other || *this == other;
}

bool date::operator==(uint64_t other) const
{
    return *this == date::from_unix_time(other);
}

bool date::operator!=(uint64_t other) const
{
    return *this != date::from_unix_time(other);
}

bool date::operator<(uint64_t other) const
{
    return *this < date::from_unix_time(other);
}

bool date::operator>(uint64_t other) const
{
    return *this > date::from_unix_time(other);
}

bool date::operator<=(uint64_t other) const
{
    return *this <= date::from_unix_time(other);
}

bool date::operator>=(uint64_t other) const
{
    return *this >= date::from_unix_time(other);
}

bool operator==(uint64_t left, const date& right)
{
    return date::from_unix_time(left) == right;
}

bool operator!=(uint64_t left, const date& right)
{
    return date::from_unix_time(left) != right;
}

bool operator<(uint64_t left, const date& right)
{
    return date::from_unix_time(left) < right;
}

bool operator>(uint64_t left, const date& right)
{
    return date::from_unix_time(left) > right;
}

bool operator<=(uint64_t left, const date& right)
{
    return date::from_unix_time(left) <= right;
}

bool operator>=(uint64_t left, const date& right)
{
    return date::from_unix_time(left) >= right;
}

std::istream& operator>>(std::istream& stream, date& date)
{
    uint64_t unix_time;
    stream >> unix_time;

    date = date::from_unix_time(unix_time);

    return stream;
}

std::ostream& operator<<(std::ostream& stream, const date& date)
{
    return stream << date.to_unix_time();
}
