#ifndef MATRIX_H
#define MATRIX_H

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

#include "ADT.h"

class matrix : public ADT {
private:
    size_t rows, columns;
    std::map<size_t, double>* adjacency;

public:
    matrix(size_t = 0, size_t = 0);
    matrix(const matrix&);
    ~matrix();

    static matrix identity(size_t);
    static matrix copy(const matrix&);
    static matrix copy(const matrix&, size_t, size_t);

    virtual std::string to_string() const override;

    size_t get_rows() const;
    size_t get_columns() const;

    double get(size_t, size_t) const;

    void set(size_t, size_t, double);

    double determinant() const;

    matrix transpose() const;
    matrix inverse() const;

    matrix operator-() const;
    matrix operator+(const matrix&) const;
    matrix operator-(const matrix&) const;
    matrix operator*(const matrix&) const;

    matrix operator*(double) const;

    friend matrix operator*(double, const matrix&);

    matrix& operator=(const matrix&);
    matrix& operator+=(const matrix&);
    matrix& operator-=(const matrix&);
    matrix& operator*=(const matrix&);

    matrix& operator*=(double);

    bool operator==(const matrix&) const;
    bool operator!=(const matrix&) const;

    friend std::istream& operator>>(std::istream&, matrix&);
    friend std::ostream& operator<<(std::ostream&, const matrix&);
};

#endif
