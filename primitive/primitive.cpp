//
// Created by ALVARO & MARCOS on 6/10/21.
//

#include "primitive.hpp"
#include <iomanip>
#include <cstring>

primitive::primitive(int filas, int columnas)
    : filas_{filas},
      columnas_{columnas},
      vec_{new double[filas_ * columnas_]} {
    CONTRACT_PRE(filas >= 0 && columnas >= 0)

    std::memset(vec_, 0, sizeof *vec_ * (filas_ * columnas_));
}

primitive::primitive(const primitive &m)
    : filas_{m.filas_},
      columnas_{m.columnas_},
      vec_{new double[filas_ * columnas_]} {
    std::copy_n(m.vec_, m.filas_ * m.columnas_, vec_);
}

primitive &primitive::operator=(const primitive &m) {
    if (this == &m)
        return *this;

    auto temp = new double[m.filas_ * m.columnas_];
    std::copy_n(m.vec_, m.filas_ * m.columnas_, temp);
    filas_ = m.filas_;
    columnas_ = m.columnas_;
    vec_ = temp;
    // delete [] temp; ¿Hace falta esto o pasa igual que en la línea 45?
    // temp = nullptr; ¿O lo correcto es esto, que se hace solo?
    return *this;
}

primitive::primitive(primitive &&m) noexcept
: filas_{m.filas_},
columnas_{m.columnas_},
vec_{m.vec_} {
    m.filas_ = 0;
    m.columnas_ = 0;
    //std::swap(vec_, m.vec_);
    //delete [] m.vec_; si borras esto, te cargas a lo que está apuntando ahora vec_ (construido por copia)
    m.vec_ = nullptr;
}

primitive &primitive::operator=(primitive &&m) noexcept {
    if (this == &m)
        return *this;

    filas_ = m.filas_;
    columnas_ = m.columnas_;

    delete [] vec_;
    vec_= nullptr;
    vec_ = m.vec_;

    m.filas_ = 0;
    m.columnas_ = 0;
    m.vec_ = nullptr;

    return *this;
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

    int index = -1;
    while (++index < filas_ * columnas_)
        if (vec_[index] != v.vec_[index])
            return false;
        
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
    *this = std::move(temp);

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
        for (int j = 0; j < m.columnas(); ++j)
            os << "[" << i << "," << j << "] : " << std::setw(10) << m(i, j);
        os << "\n";
    }
    return os;
}
