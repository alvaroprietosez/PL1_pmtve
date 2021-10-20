//
// Created by ALVARO & MARCOS  on 6/10/21.
//

#ifndef PRIMITIVE_PRIMITIVE_HPP
#define PRIMITIVE_PRIMITIVE_HPP

#include "mincontracts/mincontracts.hpp"

class primitive {

    private:

        int filas_;
        int columnas_;
        double* vec_;

    public:

        primitive(): filas_{0}, columnas_{0}, vec_{nullptr} {}
        primitive(int filas, int columnas);

        primitive(const primitive &m);
        primitive &operator=(const primitive &m);
        primitive(primitive &&m) noexcept;
        primitive &operator=(primitive &&m) noexcept;

        ~primitive() { delete [] vec_; }

        [[nodiscard]] int filas() const noexcept { return filas_; }
        [[nodiscard]] int columnas() const noexcept { return columnas_; }
        [[nodiscard]] double diagonal() const noexcept;

        double operator()(int x, int y) const;
        double &operator()(int x, int y);

        primitive &operator+=(const primitive &m);
        primitive &operator-=(const primitive &m);
        primitive &operator*=(const primitive &m);

        //static void next_method();
};

primitive operator+(const primitive& m, const primitive& n);
primitive operator-(const primitive& m, const primitive& n);
primitive operator*(const primitive& m, const primitive& n);

std::ostream &operator<<(std::ostream &os, primitive &m);

#endif //PRIMITIVE_PRIMITIVE_HPP
