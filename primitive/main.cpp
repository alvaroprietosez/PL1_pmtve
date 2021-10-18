#include <iostream>
#include <random>
#include "primitive.hpp"
#include <chrono>
#include <string>

int ask_user_for_numbers();

void set_values_for_matrix(primitive &first_matrix, primitive &second_matrix);

int main() {

    std::vector<int> dimensions{100, 200, 500, 1000, 2000};
    std::vector<std::string> methods{"Suma", "IJK", "IKJ"};
    int method = 0;

    for (int dim: dimensions) {

        //int n = ask_user_for_numbers();
        int n = dim;

        primitive first_matrix{n, n};
        primitive second_matrix{n, n};

        set_values_for_matrix(first_matrix, second_matrix);

        // Sum both matrix
        first_matrix += second_matrix;

        while (method < 3) {

            long duration = 0L;

            for (int i = 0; i < 25; ++i) {

                std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

                primitive temp_matrix{first_matrix};
                temp_matrix *= temp_matrix;

                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

                duration += std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

            }

            primitive::next_method();

            std::cout << "Time average for method " << methods[method++] <<
                      " and " << dim << " squared dimensions = " << (duration / 25L) << "[us]" << std::endl;

        }

        method = 0;
    }

    // std::cout << first_matrix << "\n";

    // Print square's diagonal
    /*
    std::cout << "Starting from two square matrix of " << n << " squared dimensions... \n"
        << "After sum them into a third one and  squaring it... \n"
        << "The result of adding their diagonal elements is: "
        << first_matrix.diagonal() << "\n";
    */
    return 0;
}

int ask_user_for_numbers() {

    std::cout << "Welcome to squared matrix programme" << "\n";
    int number = -1;
    do {
        std::cout << "Please introduce a positive number corresponding to the square matrix dimensions" << "\n";
        std::cin >> number;
    } while (number < 0);

    return number;
}

void set_values_for_matrix(primitive &first_matrix, primitive &second_matrix) {

    std::random_device rd;
    std::mt19937_64 gen(rd()); // Create and seed the generator
    std::normal_distribution<> d(100, 2.5); // Create distribution

    for (int i = 0; i < first_matrix.filas(); ++i)
        for (int j = 0; j < first_matrix.columnas(); ++j) {
            first_matrix(i, j) = d(gen);
            second_matrix(i, j) = d(gen);
        }

}
