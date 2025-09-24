#include "Matrix.h" // Your header file
#include <iostream>

int main() {
    try {
        // --- Construction ---
        std::cout << "--- Construction Examples ---" << std::endl;
        Matrix<int> m1(3, 4, 5); // 3x4 matrix filled with 5s
        std::cout << "m1 (filled with 5s):\n" << m1 << std::endl;
        
        Matrix<double> m2 = {{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}}; // From initializer list
        std::cout << "m2 (from initializer list):\n" << m2 << std::endl;

        // --- Element Access and O(1) Sums ---
        std::cout << "--- O(1) Sums and Element Modification ---" << std::endl;
        std::cout << "Initial row 0 sum of m2: " << m2.row_sum(0) << std::endl;
        std::cout << "Initial col 1 sum of m2: " << m2.col_sum(1) << std::endl;

        std::cout << "\nSetting m2(0, 1) = 10.0...\n" << std::endl;
        m2(0, 1) = 10.0; // The proxy updates the sums automatically here

        std::cout << "Modified m2:\n" << m2 << std::endl;
        std::cout << "New row 0 sum of m2: " << m2.row_sum(0) << " (O(1) lookup)" << std::endl;
        std::cout << "New col 1 sum of m2: " << m2.col_sum(1) << " (O(1) lookup)" << std::endl;

        // --- Iteration ---
        std::cout << "\n--- Iteration Example ---" << std::endl;
        double total_sum = 0;
        for (const auto& val : m2) {
            total_sum += val;
        }
        std::cout << "Sum of all elements in m2 via iterator: " << total_sum << std::endl;

        // --- Operations ---
        std::cout << "\n--- Matrix Operations ---" << std::endl;
        Matrix<double> m3 = {{1, 2}, {3, 4}};
        Matrix<double> m4 = {{5, 6}, {7, 8}};

        std::cout << "m3:\n" << m3 << std::endl;
        std::cout << "m4:\n" << m4 << std::endl;

        Matrix<double> m_add = m3 + m4;
        std::cout << "m3 + m4:\n" << m_add << std::endl;

        Matrix<double> m_scalar = m3 * 3.0;
        std::cout << "m3 * 3.0:\n" << m_scalar << std::endl;
        
        Matrix<double> m_mult = m3 * m2;
        std::cout << "m3 * m2:\n" << m_mult << std::endl;
        
        Matrix<double> m_transposed = m2.transpose();
        std::cout << "m2 transposed:\n" << m_transposed << std::endl;
        std::cout << "Row 0 sum of transposed matrix: " << m_transposed.row_sum(0) << std::endl;
        std::cout << "Col 0 sum of transposed matrix: " << m_transposed.col_sum(0) << std::endl;

        // --- Error Handling ---
        std::cout << "\n--- Error Handling ---" << std::endl;
        try {
            Matrix<int> error_mat = m1 + Matrix<int>(2,2);
        } catch (const std::invalid_argument& e) {
            std::cout << "Caught expected exception: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
    }

    return 0;
}