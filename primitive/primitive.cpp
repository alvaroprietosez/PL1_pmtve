//
// Created by ALVARO & MARCOS on 6/10/21.
//


#include "primitive.hpp"
#include <sstream>
#include <iomanip>

primitive::primitive(const primitive &m)
    : filas_{m.filas_},
      columnas_{m.columnas_},
      vec_{new double[filas_ * columnas_]} {
    std::copy_n(m.vec_, m.filas_ * m.columnas_, vec_);
}

primitive &primitive::operator=(const primitive &m) {
    if (this == &m)
        return *this;

    auto aux = new double[m.filas_ * m.columnas_];
    std::copy_n(m.vec_, m.filas_ * m.columnas_, aux);
    filas_ = m.filas_;
    columnas_ = m.columnas_;
    std::swap(vec_, aux);
    delete [] aux;
    return *this;
}

primitive::primitive(primitive &&m) noexcept
    : filas_{m.filas_},
      columnas_{m.columnas_},
      vec_{m.vec_} {
      //vec_{new double[m.filas_ * m.columnas_]} {
    m.filas_ = 0;
    m.columnas_ = 0;
    //std::swap(vec_, m.vec_);
    //delete [] m.vec_; si borras esto,
    m.vec_ = nullptr; // JD: Buena practica
}

primitive &primitive::operator=(primitive &&m) noexcept {
    filas_ = m.filas_;
    columnas_ = m.columnas_;
    delete [] vec_;
    vec_=m.vec_;
    /*delete[] vec_;
    vec_ = m.vec_;*/
    m.filas_ = 0;
    m.columnas_ = 0;
    m.vec_ = nullptr; // JD: Buena practica
    //Mala pinta --> codigo de arriba
    //primitive temp{std::move(m)};
    //delete [] vec_;*/
    return *this;

    //return (*this = temp); // esto está bien?
}

double primitive::operator()(int x, int  y) const {
    CONTRACT_PRE(x < filas_ && y < columnas_)
    return vec_[columnas_ * x + y];
}

double &primitive::operator()(int x, int y) {
    CONTRACT_PRE(x < filas_ && y < columnas_)
    return vec_[columnas_ * x + y];
}

bool primitive::operator==(const primitive &v) const noexcept {
    if (filas_ != v.filas_ || columnas_ != v.columnas_)
        return false;

    int index = 0;
    while (index < filas_ * columnas_) {
        if (vec_[index] != v.vec_[index])
            return false;
        ++index;
    }

    return true;
}

primitive &primitive::operator+=(const primitive &m) {
    CONTRACT_PRE(filas_ == m.filas_ && columnas_ == m.columnas_)
    for (int i = 0; i < filas_ * columnas_; ++i)
        vec_[i] += m.vec_[i];

    return *this;
}

primitive &primitive::operator-=(const primitive &m) {
    CONTRACT_PRE(filas_ == m.filas_ && columnas_ == m.columnas_)
    for (int i = 0; i < filas_ * columnas_; ++i)
        vec_[i] -= m.vec_[i];

    return *this;
}

primitive &primitive::operator*=(const primitive &m) {
    CONTRACT_PRE(columnas_==m.filas_)
    primitive temp{filas_, m.columnas_};

    for (int i = 0; i < temp.filas_; ++i)
        for (int j = 0; j < temp.columnas_; ++j) {
            double sum = 0;
            for (int k = 0; k < columnas_; ++k)
                sum += vec_[i * columnas_ + k] * m.vec_[k * m.columnas_ + j];
            temp.vec_[i * m.columnas_ + j] = sum;
        }
    std::swap(*this,temp);
    return *this;

}

primitive operator+(const primitive& m, const primitive& n) {
    primitive temp{m};
    return temp += n;
}

primitive operator-(const primitive& m, const primitive& n) {
    primitive temp{m};
    return temp -= n;
}

primitive operator*(const primitive& m, const primitive& n) {
    primitive temp{m};
    return temp *= n;
}

std::ostream &operator<<(std::ostream &os, primitive &m) {

    for (int i = 0; i < m.filas(); ++i) {
        for (int j = 0; j < m.columnas(); ++j) {
            os << "[" << i << "," << j << "] : " << std::setw(25) << m(i, j);// rellena con blancos
        }
        os << "\n";
    }
    return os;
}








