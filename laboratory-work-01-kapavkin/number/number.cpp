#include "number.h"

void number::resize(size_t capacity)
{
    bool* new_binary = new bool[capacity];

    size_t min = std::min(this->capacity, capacity);

    for (size_t i = 0; i < min - 1; i++) {
        new_binary[i] = binary[i];
    }

    for (size_t i = min - 1; i < capacity; i++) {
        new_binary[i] = binary[this->capacity - 1];
    }

    this->capacity = capacity;

    binary = new bool[capacity];
    for (size_t i = 0; i < capacity; i++) {
        binary[i] = new_binary[i];
    }

    delete[] new_binary;
}

number number::copy(const number& other, size_t capacity)
{
    number number(other);
    number.resize(capacity);

    return number;
}

number number::shift(const number& left, int right)
{
    number number(left);

    for (size_t i = 0; i + right < left.capacity; i++) {
        number.binary[i] = left.binary[i + right];
    }

    for (size_t i = left.capacity - right; i < left.capacity; i++) {
        number.binary[i] = 0;
    }

    return number;
}

number number::divide(const number& left, const number& right, number& remainder)
{
    if (right == 0) {
        throw std::invalid_argument("cannot divide by zero");
    }

    if (left.capacity < right.capacity) {
        return divide(copy(left, right.capacity), right, remainder);
    }

    if (left.capacity > right.capacity) {
        return divide(left, copy(right, left.capacity), remainder);
    }

    number quotient(left);
    for (size_t i = 0; i < left.capacity; i++) {
        quotient.binary[i] = 0;
    }

    number dividend = left < 0 ? -left : left;
    number divisor = right < 0 ? -right : right;

    if (dividend < divisor) {
        return 0;
    }

    size_t divisor_bit = 0;
    for (size_t i = divisor.capacity - 1; i > 0; i--) {
        if (divisor.binary[i]) {
            divisor_bit = i;
            break;
        }
    }

    size_t space = left.capacity - divisor_bit - 2;
    divisor <<= space;

    for (size_t i = 0; i <= space; i++, divisor = shift(divisor, 1)) {
        if (divisor <= dividend) {
            quotient.binary[space - i] = 1;
            dividend -= divisor;
        }
    }

    remainder = dividend;

    if ((left < 0) != (right < 0)) {
        return -quotient;
    }

    return quotient;
}

number::number(int other)
{
    capacity = DEFAULT_CAPACITY;

    binary = new bool[capacity];
    for (size_t i = 0; i < capacity; i++) {
        binary[i] = other & (1 << i);
    }
}

std::string number::divide(const std::string& left, number& remainder)
{
    size_t carry = 0;
    std::string string = left;

    if (left[0] == '1') {
        carry = 1;
        string.assign(left, 1, left.length() - 1);
    }

    for (size_t i = 0; i < string.length(); i++) {
        size_t n = ((string[i] - '0') + (10 * carry));
        string[i] = n / 2 + '0';
        carry = n % 2;
    }

    remainder = carry > 0;

    return string;
}

number::number(const number& other)
{
    capacity = other.capacity;

    binary = new bool[capacity];
    for (size_t i = 0; i < capacity; i++) {
        binary[i] = other.binary[i];
    }
}

number::~number()
{
    delete[] binary;
}

number number::from_int(int other)
{
    number number(other);

    return number;
}

number number::copy(const number& other)
{
    number number(other);

    return number;
}

int number::to_int() const
{
    int integer = 0;

    number narrowed = copy(*this, DEFAULT_CAPACITY);

    for (size_t i = 0; i < DEFAULT_CAPACITY; i++) {
        integer |= narrowed.binary[i] << i;
    }

    return integer;
}

std::string number::add(const std::string& left, const std::string& right)
{
    if (left.length() < right.length()) {
        return add(right, left);
    }

    if (left.length() > right.length()) {
        std::string resized = right;
        resized.append(left.length() - right.length(), '0');
        return add(left, resized);
    }

    std::string string(left.length(), '0');

    size_t carry = 0;
    for (size_t i = 0; i < left.length(); i++) {
        size_t n = (left[i] - '0') + (right[i] - '0') + (carry > 0);
        string[i] = n % 10 + '0';

        if (n / 10) {
            carry += carry == 0;
        } else {
            carry -= carry > 0;
        }
    }

    if (carry > 0) {
        string += "1";
    }

    return string;
}

std::string number::to_string() const
{
    number number = *this < 0 ? -*this : *this;

    std::string string = "0", power = "1";
    for (size_t i = 0; i < capacity - 1; i++) {
        if (number.binary[i]) {
            string = add(string, power);
        }

        power = add(power, power);
    }

    if (*this < 0) {
        string += "-";
    }

    std::reverse(string.begin(), string.end());

    return string;
}

size_t number::get_capacity() const
{
    return capacity;
}

number number::operator-() const
{
    return ~copy(*this) + 1;
}

number number::operator~() const
{
    number number(*this);

    for (size_t i = 0; i < capacity; i++) {
        number.binary[i] = !binary[i];
    }

    return number;
}

number number::operator+(const number& other) const
{
    if (capacity < other.capacity) {
        return copy(*this, other.capacity) + other;
    }

    if (capacity > other.capacity) {
        return *this + copy(other, capacity);
    }

    number sum(*this);

    bool carry = 0;
    for (size_t i = 0; i < capacity; i++) {
        sum.binary[i] = (binary[i] != other.binary[i]) != carry;
        carry = ((binary[i] || other.binary[i]) && carry) || (binary[i] && other.binary[i]);
    }

    return sum;
}

number number::operator-(const number& other) const
{
    return *this + -other;
}

number number::operator*(const number& other) const
{
    if (capacity < other.capacity) {
        return copy(*this, other.capacity) * other;
    }

    if (capacity > other.capacity) {
        return *this * copy(other, capacity);
    }

    number product(*this);
    for (size_t i = 0; i < capacity; i++) {
        product.binary[i] = 0;
    }

    for (size_t i = 0; i < capacity; i++) {
        if (other.binary[i]) {
            product += *this << i;
        }
    }

    return product;
}

number number::operator/(const number& other) const
{
    number remainder;

    return divide(*this, other, remainder);
}

number number::operator%(const number& other) const
{
    number remainder;

    divide(*this, other, remainder);

    return remainder;
}

number number::operator&(const number& other) const
{
    if (capacity < other.capacity) {
        return copy(*this, other.capacity) & other;
    }

    if (capacity > other.capacity) {
        return *this & copy(other, capacity);
    }

    number number(*this);

    for (size_t i = 0; i < capacity; i++) {
        number.binary[i] = binary[i] && other.binary[i];
    }

    return number;
}

number number::operator|(const number& other) const
{
    if (capacity < other.capacity) {
        return copy(*this, other.capacity) | other;
    }

    if (capacity > other.capacity) {
        return *this | copy(other, capacity);
    }

    number number(*this);

    for (size_t i = 0; i < capacity; i++) {
        number.binary[i] = binary[i] || other.binary[i];
    }

    return number;
}

number number::operator^(const number& other) const
{
    if (capacity < other.capacity) {
        return copy(*this, other.capacity) ^ other;
    }

    if (capacity > other.capacity) {
        return *this ^ copy(other, capacity);
    }

    number number(*this);

    for (size_t i = 0; i < capacity; i++) {
        number.binary[i] = binary[i] != other.binary[i];
    }

    return number;
}

number number::operator<<(const number& other) const
{
    return *this << other.to_int();
}

number number::operator>>(const number& other) const
{
    return *this >> other.to_int();
}

number number::operator+(int other) const
{
    return *this + from_int(other);
}

number number::operator-(int other) const
{
    return *this - from_int(other);
}

number number::operator*(int other) const
{
    return *this * from_int(other);
}

number number::operator/(int other) const
{
    return *this / from_int(other);
}

number number::operator%(int other) const
{
    return *this % from_int(other);
}

number number::operator&(int other) const
{
    return *this & from_int(other);
}

number number::operator|(int other) const
{
    return *this | from_int(other);
}

number number::operator^(int other) const
{
    return *this ^ from_int(other);
}

number number::operator<<(int other) const
{
    number number(*this);

    for (size_t i = 0; i < other; i++) {
        number.binary[i] = 0;
    }

    for (size_t i = other; i < capacity; i++) {
        number.binary[i] = binary[i - other];
    }

    return number;
}

number number::operator>>(int other) const
{
    number number(*this);

    for (size_t i = 0; i + other < capacity; i++) {
        number.binary[i] = binary[i + other];
    }

    for (size_t i = capacity - other; i < capacity; i++) {
        number.binary[i] = binary[capacity - 1];
    }

    return number;
}

number operator+(int left, const number& right)
{
    return number::from_int(left) + right;
}

number operator-(int left, const number& right)
{
    return number::from_int(left) - right;
}

number operator*(int left, const number& right)
{
    return number::from_int(left) * right;
}

number operator/(int left, const number& right)
{
    return number::from_int(left) / right;
}

number operator%(int left, const number& right)
{
    return number::from_int(left) % right;
}

number operator&(int left, const number& right)
{
    return number::from_int(left) & right;
}

number operator|(int left, const number& right)
{
    return number::from_int(left) | right;
}

number operator^(int left, const number& right)
{
    return number::from_int(left) ^ right;
}

number operator<<(int left, const number& right)
{
    return number::from_int(left) << right;
}

number operator>>(int left, const number& right)
{
    return number::from_int(left) >> right;
}

number& number::operator=(const number& other)
{
    capacity = other.capacity;

    binary = new bool[capacity];
    for (size_t i = 0; i < capacity; i++) {
        binary[i] = other.binary[i];
    }

    return *this;
}

number& number::operator+=(const number& other)
{
    return *this = *this + other;
}

number& number::operator-=(const number& other)
{
    return *this = *this - other;
}

number& number::operator*=(const number& other)
{
    return *this = *this * other;
}

number& number::operator/=(const number& other)
{
    return *this = *this / other;
}

number& number::operator%=(const number& other)
{
    return *this = *this % other;
}

number& number::operator&=(const number& other)
{
    return *this = *this & other;
}

number& number::operator|=(const number& other)
{
    return *this = *this | other;
}

number& number::operator^=(const number& other)
{
    return *this = *this ^ other;
}

number& number::operator<<=(const number& other)
{
    return *this = *this << other;
}

number& number::operator>>=(const number& other)
{
    return *this = *this >> other;
}

number& number::operator=(int other)
{
    return *this = from_int(other);
}

number& number::operator+=(int other)
{
    return *this = *this + other;
}

number& number::operator-=(int other)
{
    return *this = *this - other;
}

number& number::operator*=(int other)
{
    return *this = *this * other;
}

number& number::operator/=(int other)
{
    return *this = *this / other;
}

number& number::operator%=(int other)
{
    return *this = *this % other;
}

number& number::operator&=(int other)
{
    return *this = *this & other;
}

number& number::operator|=(int other)
{
    return *this = *this | other;
}

number& number::operator^=(int other)
{
    return *this = *this ^ other;
}

number& number::operator<<=(int other)
{
    return *this = *this << other;
}

number& number::operator>>=(int other)
{
    return *this = *this >> other;
}

number& number::operator++()
{
    return *this += 1;
}

number number::operator++(int)
{
    number number(*this);

    *this += 1;

    return number;
}

number& number::operator--()
{
    return *this -= 1;
}

number number::operator--(int)
{
    number number(*this);

    *this -= 1;

    return number;
}

bool number::operator!() const
{
    return *this == 0;
}

bool number::operator&&(const number& other) const
{
    return *this != 0 && other != 0;
}

bool number::operator||(const number& other) const
{
    return *this != 0 || other != 0;
}

bool number::operator==(const number& other) const
{
    if (capacity < other.capacity) {
        return copy(*this, other.capacity) == other;
    }

    if (capacity > other.capacity) {
        return *this == copy(other, capacity);
    }

    for (size_t i = 0; i < capacity; i++) {
        if (binary[i] != other.binary[i]) {
            return false;
        }
    }

    return true;
}

bool number::operator!=(const number& other) const
{
    return !(*this == other);
}

bool number::operator<(const number& other) const
{
    if (capacity < other.capacity) {
        return copy(*this, other.capacity) < other;
    }

    if (capacity > other.capacity) {
        return *this < copy(other, capacity);
    }

    if (binary[capacity - 1] && !other.binary[other.capacity - 1]) {
        return true;
    }

    if (other.binary[other.capacity - 1] && !binary[capacity - 1]) {
        return false;
    }

    for (size_t i = 0; i < capacity; i++) {
        if (binary[capacity - i - 1] < other.binary[capacity - i - 1]) {
            return true;
        }

        if (binary[capacity - i - 1] > other.binary[capacity - i - 1]) {
            return false;
        }
    }

    return false;
}

bool number::operator>(const number& other) const
{
    return other < *this;
}

bool number::operator<=(const number& other) const
{
    return *this < other || *this == other;
}

bool number::operator>=(const number& other) const
{
    return *this > other || *this == other;
}

bool number::operator&&(int other) const
{
    return *this && number::from_int(other);
}

bool number::operator||(int other) const
{
    return *this || number::from_int(other);
}

bool number::operator==(int other) const
{
    return *this == number::from_int(other);
}

bool number::operator!=(int other) const
{
    return *this != number::from_int(other);
}

bool number::operator<(int other) const
{
    return *this < number::from_int(other);
}

bool number::operator>(int other) const
{
    return *this > number::from_int(other);
}

bool number::operator<=(int other) const
{
    return *this <= number::from_int(other);
}

bool number::operator>=(int other) const
{
    return *this >= number::from_int(other);
}

bool operator&&(int left, const number& right)
{
    return number::from_int(left) && right;
}

bool operator||(int left, const number& right)
{
    return number::from_int(left) || right;
}

bool operator==(int left, const number& right)
{
    return number::from_int(left) == right;
}

bool operator!=(int left, const number& right)
{
    return number::from_int(left) != right;
}

bool operator<(int left, const number& right)
{
    return number::from_int(left) < right;
}

bool operator>(int left, const number& right)
{
    return number::from_int(left) > right;
}

bool operator<=(int left, const number& right)
{
    return number::from_int(left) <= right;
}

bool operator>=(int left, const number& right)
{
    return number::from_int(left) >= right;
}

std::istream& operator>>(std::istream& stream, number& num)
{
    std::string string;
    stream >> string;

    num = number::from_int(0);

    std::string temp = string;

    if (string[0] == '-') {
        temp.assign(string, 1, string.length() - 1);
    }

    number remainder;
    for (size_t i = 0; !temp.empty(); i++) {
        if (i == num.capacity - 1) {
            num.resize(2 * num.capacity);
        }

        temp = number::divide(temp, remainder);

        num.binary[i] = remainder == 1;
    }

    if (string[0] == '-') {
        num = -num;
    }

    return stream;
}

std::ostream& operator<<(std::ostream& stream, const number& num)
{
    return stream << num.to_string();
}
