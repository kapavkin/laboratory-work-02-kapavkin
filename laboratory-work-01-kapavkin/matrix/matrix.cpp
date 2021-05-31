#include "matrix.h"

matrix::matrix(size_t rows, size_t columns)
{
    this->rows = rows;
    this->columns = columns;

    adjacency = new std::map<size_t, double>[rows];
}

matrix::matrix(const matrix& other)
{
    rows = other.rows;
    columns = other.columns;

    adjacency = new std::map<size_t, double>[rows];
    for (size_t r = 0; r < rows; r++) {
        adjacency[r] = other.adjacency[r];
    }
}

matrix::~matrix()
{
    delete[] adjacency;
}

matrix matrix::identity(size_t size)
{
    matrix matrix(size, size);

    for (size_t i = 0; i < size; i++) {
        matrix.set(i, i, 1.);
    }

    return matrix;
}

matrix matrix::copy(const matrix& other)
{
    matrix matrix(other);

    return matrix;
}

matrix matrix::copy(const matrix& other, size_t row, size_t column)
{
    if (row >= other.rows) {
        throw std::invalid_argument("row out of range");
    }

    if (column >= other.columns) {
        throw std::invalid_argument("column out of range");
    }

    matrix matrix(other.rows - 1, other.columns - 1);

    for (size_t r = 0; r < row; r++) {
        for (std::pair<size_t, double> e : other.adjacency[r]) {
            if (e.first != column) {
                matrix.set(r, e.first - (e.first > column), e.second);
            }
        }
    }

    for (size_t r = row + 1; r < other.rows; r++) {
        for (std::pair<size_t, double> e : other.adjacency[r]) {
            if (e.first != column) {
                matrix.set(r - 1, e.first - (e.first > column), e.second);
            }
        }
    }

    return matrix;
}

std::string matrix::to_string() const
{
    std::string string = std::to_string(rows) + " " + std::to_string(columns);

    for (size_t r = 0; r < rows; r++) {
        string += "\n";
        for (size_t c = 0; c < columns; c++) {
            string += std::to_string(get(r, c)) + " ";
        }
    }

    return string;
}

size_t matrix::get_rows() const
{
    return rows;
}

size_t matrix::get_columns() const
{
    return columns;
}

double matrix::get(size_t row, size_t column) const
{
    if (row >= rows) {
        throw std::invalid_argument("row out of range");
    }

    if (column >= columns) {
        throw std::invalid_argument("column out of range");
    }

    if (adjacency[row].count(column)) {
        return adjacency[row][column];
    }

    return .0;
}

void matrix::set(size_t row, size_t column, double value)
{
    if (row >= rows) {
        throw std::invalid_argument("row out of range");
    }

    if (column >= columns) {
        throw std::invalid_argument("column out of range");
    }

    if (value != .0) {
        adjacency[row][column] = value;
    } else if (adjacency[row].count(column)) {
        adjacency[row].erase(column);
    }
}

double matrix::determinant() const
{
    if (rows != columns) {
        throw std::logic_error("rows are not equal to columns");
    }

    if (rows == 1) {
        return get(0, 0);
    }

    double det = .0;
    for (std::pair<size_t, double> e : adjacency[0]) {
        double minor = copy(*this, 0, e.first).determinant();
        det += e.second * (e.first % 2 ? -minor : minor);
    }

    return det;
}

matrix matrix::transpose() const
{
    matrix matrix(columns, rows);

    for (size_t r = 0; r < rows; r++) {
        for (std::pair<size_t, double> e : adjacency[r]) {
            matrix.set(e.first, r, e.second);
        }
    }

    return matrix;
}

matrix matrix::inverse() const
{
    double det = determinant();

    if (det == .0) {
        throw std::logic_error("inverse matrix does not exist");
    }

    matrix matrix(rows, columns);

    for (size_t r = 0; r < rows; r++) {
        for (std::pair<size_t, double> e : adjacency[r]) {
            double minor = copy(*this, r, e.first).determinant();
            matrix.set(r, e.first, (r + e.first) % 2 ? -minor : minor);
        }
    }

    return 1. / det * matrix.transpose();
}

matrix matrix::operator-() const
{
    matrix matrix(*this);

    for (size_t r = 0; r < rows; r++) {
        for (std::pair<size_t, double> e : adjacency[r]) {
            matrix.set(r, e.first, -e.second);
        }
    }

    return matrix;
}

matrix matrix::operator+(const matrix& other) const
{
    if (rows != other.rows) {
        throw std::invalid_argument("rows are not equal");
    }

    if (columns != other.columns) {
        throw std::invalid_argument("columns are not equal");
    }

    matrix matrix(*this);

    for (size_t r = 0; r < rows; r++) {
        for (std::pair<size_t, double> e : other.adjacency[r]) {
            matrix.set(r, e.first, get(r, e.first) + e.second);
        }
    }

    return matrix;
}

matrix matrix::operator-(const matrix& other) const
{
    if (rows != other.rows) {
        throw std::invalid_argument("rows are not equal");
    }

    if (columns != other.columns) {
        throw std::invalid_argument("columns are not equal");
    }

    matrix matrix(*this);

    for (size_t r = 0; r < rows; r++) {
        for (std::pair<size_t, double> e : other.adjacency[r]) {
            matrix.set(r, e.first, get(r, e.first) - e.second);
        }
    }

    return matrix;
}

matrix matrix::operator*(const matrix& other) const
{
    if (columns != other.rows) {
        throw std::invalid_argument("columns are not equal to rows");
    }

    matrix matrix(rows, other.columns);

    for (size_t r = 0; r < rows; r++) {
        for (size_t c = 0; c < other.columns; c++) {
            double product = .0;
            for (size_t i = 0; i < columns; i++) {
                product += get(r, i) * other.get(i, c);
            }

            matrix.set(r, c, product);
        }
    }

    return matrix;
}

matrix matrix::operator*(double other) const
{
    matrix matrix(rows, columns);

    for (size_t r = 0; r < rows; r++) {
        for (std::pair<size_t, double> e : adjacency[r]) {
            matrix.set(r, e.first, e.second * other);
        }
    }

    return matrix;
}

matrix operator*(double left, const matrix& right)
{
    return right * left;
}

matrix& matrix::operator=(const matrix& other)
{
    rows = other.rows;
    columns = other.columns;

    adjacency = new std::map<size_t, double>[rows];
    for (size_t r = 0; r < rows; r++) {
        adjacency[r] = other.adjacency[r];
    }

    return *this;
}

matrix& matrix::operator+=(const matrix& other)
{
    return *this = *this + other;
}

matrix& matrix::operator-=(const matrix& other)
{
    return *this = *this - other;
}

matrix& matrix::operator*=(const matrix& other)
{
    return *this = *this * other;
}

matrix& matrix::operator*=(double other)
{
    return *this = *this * other;
}

bool matrix::operator==(const matrix& other) const
{
    if (rows != other.rows) {
        return false;
    }

    if (columns != other.columns) {
        return false;
    }

    for (size_t r = 0; r < rows; r++) {
        for (std::pair<size_t, double> e : adjacency[r]) {
            if (std::abs(e.second - other.get(r, e.first)) > 1e-6) {
                return false;
            }
        }

        for (std::pair<size_t, double> e : other.adjacency[r]) {
            if (std::abs(e.second - get(r, e.first)) > 1e-6) {
                return false;
            }
        }
    }

    return true;
}

bool matrix::operator!=(const matrix& other) const
{
    return !(*this == other);
}

std::istream& operator>>(std::istream& stream, matrix& matrix)
{
    stream >> matrix.rows;
    stream >> matrix.columns;

    matrix.adjacency = new std::map<size_t, double>[matrix.rows];
    for (size_t r = 0; r < matrix.rows; r++) {
        for (size_t c = 0; c < matrix.columns; c++) {
            double value;
            stream >> value;
            matrix.set(r, c, value);
        }
    }

    return stream;
}

std::ostream& operator<<(std::ostream& stream, const matrix& matrix)
{
    return stream << matrix.to_string();
}
