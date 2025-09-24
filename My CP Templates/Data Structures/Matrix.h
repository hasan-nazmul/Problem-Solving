#pragma once

#include <vector>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <numeric>
#include <iomanip>
#include <initializer_list>

template <typename T>
class Matrix {
private:
    // Forward declaration of the proxy class for element access
    class ElementProxy;

    size_t rows_, cols_;
    std::vector<T> data_;
    
    // For O(1) sum lookups
    std::vector<T> row_sums_;
    std::vector<T> col_sums_;

    // Helper to validate coordinates
    void check_bounds(size_t r, size_t c) const {
        if (r >= rows_ || c >= cols_) {
            throw std::out_of_range("Matrix indices are out of range.");
        }
    }

public:
    // --- Constructors ---

    // Default constructor: 0x0 matrix
    Matrix() : rows_(0), cols_(0) {}

    // Constructor with dimensions, filled with default value (e.g., 0 for numbers)
    Matrix(size_t rows, size_t cols)
        : rows_(rows), cols_(cols), 
          data_(rows * cols, T{}), 
          row_sums_(rows, T{}), 
          col_sums_(cols, T{}) {}

    // Constructor with dimensions and a fill value
    Matrix(size_t rows, size_t cols, const T& value)
        : rows_(rows), cols_(cols), 
          data_(rows * cols, value),
          row_sums_(rows, static_cast<T>(cols) * value),
          col_sums_(cols, static_cast<T>(rows) * value) {}

    // NumPy-like constructor from initializer list
    Matrix(std::initializer_list<std::initializer_list<T>> il) {
        rows_ = il.size();
        if (rows_ == 0) {
            cols_ = 0;
            return;
        }
        cols_ = il.begin()->size();

        data_.reserve(rows_ * cols_);
        row_sums_.assign(rows_, T{});
        col_sums_.assign(cols_, T{});

        size_t r = 0;
        for (const auto& row_list : il) {
            if (row_list.size() != cols_) {
                throw std::invalid_argument("All rows in initializer list must have the same size.");
            }
            for (const auto& val : row_list) {
                data_.push_back(val);
                row_sums_[r] += val;
            }
            r++;
        }

        // Calculate column sums after data is populated
        for (size_t i = 0; i < rows_; ++i) {
            for (size_t j = 0; j < cols_; ++j) {
                col_sums_[j] += data_[i * cols_ + j];
            }
        }
    }

    // --- Accessors ---

    // Get dimensions as a pair
    std::pair<size_t, size_t> dimensions() const noexcept {
        return {rows_, cols_};
    }

    size_t rows() const noexcept { return rows_; }
    size_t cols() const noexcept { return cols_; }

    // Const element access
    const T& operator()(size_t r, size_t c) const {
        check_bounds(r, c);
        return data_[r * cols_ + c];
    }

    // Non-const element access returns a proxy to handle updates
    ElementProxy operator()(size_t r, size_t c) {
        check_bounds(r, c);
        return ElementProxy(*this, r, c);
    }

    // --- O(1) Sum Methods ---

    T row_sum(size_t r) const {
        if (r >= rows_) throw std::out_of_range("Row index is out of range.");
        return row_sums_[r];
    }

    T col_sum(size_t c) const {
        if (c >= cols_) throw std::out_of_range("Column index is out of range.");
        return col_sums_[c];
    }

    // --- Matrix Operations ---

    Matrix<T> transpose() const {
        Matrix<T> result(cols_, rows_);
        for (size_t i = 0; i < rows_; ++i) {
            for (size_t j = 0; j < cols_; ++j) {
                // Using the proxy here is fine, but direct access is faster
                // since the new matrix calculates its own sums on creation.
                 result.data_[j * rows_ + i] = (*this)(i, j);
            }
        }
        // Re-calculate sums for the new transposed matrix
        result.recalculate_sums();
        return result;
    }

    // Helper to recalculate sums if needed (e.g., after transpose)
    void recalculate_sums() {
        row_sums_.assign(rows_, T{});
        col_sums_.assign(cols_, T{});
        for (size_t i = 0; i < rows_; ++i) {
            for (size_t j = 0; j < cols_; ++j) {
                const T& val = data_[i * cols_ + j];
                row_sums_[i] += val;
                col_sums_[j] += val;
            }
        }
    }

    // --- Iterators ---
    // Provides simple row-major iteration over elements
    using iterator = typename std::vector<T>::iterator;
    using const_iterator = typename std::vector<T>::const_iterator;

    iterator begin() { return data_.begin(); }
    iterator end() { return data_.end(); }
    const_iterator begin() const { return data_.cbegin(); }
    const_iterator end() const { return data_.cend(); }
    const_iterator cbegin() const { return data_.cbegin(); }
    const_iterator cend() const { return data_.cend(); }


private:
    // --- Proxy Class for Element Access ---
    // This is the key to achieving O(1) sums on update.
    class ElementProxy {
    private:
        Matrix<T>& matrix_;
        size_t row_;
        size_t col_;

    public:
        ElementProxy(Matrix<T>& matrix, size_t r, size_t c)
            : matrix_(matrix), row_(r), col_(c) {}

        // Called when you read: T val = mat(r, c);
        operator T() const {
            return matrix_.data_[row_ * matrix_.cols_ + col_];
        }

        // Called when you write: mat(r, c) = new_value;
        ElementProxy& operator=(const T& new_value) {
            T& old_value = matrix_.data_[row_ * matrix_.cols_ + col_];
            T delta = new_value - old_value;
            
            // Update the sums with the change
            matrix_.row_sums_[row_] += delta;
            matrix_.col_sums_[col_] += delta;

            // Finally, update the actual value
            old_value = new_value;
            
            return *this;
        }
    };
};

// --- Operator Overloads (Free Functions) ---

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& mat) {
    os << "Matrix (" << mat.rows() << "x" << mat.cols() << "):\n";
    if (mat.rows() == 0) return os;
    
    for (size_t i = 0; i < mat.rows(); ++i) {
        os << "[ ";
        for (size_t j = 0; j < mat.cols(); ++j) {
            os << std::setw(8) << std::left << mat(i, j) << " ";
        }
        os << "]\n";
    }
    return os;
}

template<typename T>
Matrix<T> operator+(const Matrix<T>& lhs, const Matrix<T>& rhs) {
    if (lhs.dimensions() != rhs.dimensions()) {
        throw std::invalid_argument("Matrix dimensions must match for addition.");
    }
    Matrix<T> result(lhs.rows(), lhs.cols());
    for (size_t i = 0; i < lhs.rows(); ++i) {
        for (size_t j = 0; j < lhs.cols(); ++j) {
            result(i, j) = lhs(i, j) + rhs(i, j); // Uses proxy to set value and update sums
        }
    }
    return result;
}

template<typename T>
Matrix<T> operator*(const T& scalar, const Matrix<T>& mat) {
    Matrix<T> result(mat.rows(), mat.cols());
    for (size_t i = 0; i < mat.rows(); ++i) {
        for (size_t j = 0; j < mat.cols(); ++j) {
            result(i, j) = scalar * mat(i, j);
        }
    }
    return result;
}

template<typename T>
Matrix<T> operator*(const Matrix<T>& mat, const T& scalar) {
    return scalar * mat; // Reuse the above operator
}

template<typename T>
Matrix<T> operator*(const Matrix<T>& lhs, const Matrix<T>& rhs) {
    if (lhs.cols() != rhs.rows()) {
        throw std::invalid_argument("Matrix dimensions are not compatible for multiplication.");
    }
    Matrix<T> result(lhs.rows(), rhs.cols());
    for (size_t i = 0; i < lhs.rows(); ++i) {
        for (size_t j = 0; j < rhs.cols(); ++j) {
            T sum = T{};
            for (size_t k = 0; k < lhs.cols(); ++k) {
                sum += lhs(i, k) * rhs(k, j);
            }
            result(i, j) = sum; // Proxy handles sum updates
        }
    }
    return result;
}