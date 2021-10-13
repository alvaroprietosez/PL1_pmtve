//
// Created by ALVARO & MARCOS on 6/10/21.
//

// https://www.jetbrains.com/help/clion/code-coverage-clion.html#run-coverage
#include "primitive.hpp"
#include <gtest/gtest.h>

TEST(test_primitive, constructor_defecto) {

    primitive a;
    ASSERT_TRUE(a.filas() == 0 && a.columnas() == 0);
}

TEST(test_primitive, constructor_parametros) {

    //Matriz con enteros naturales
    primitive a{2,2};
    ASSERT_TRUE(a.filas() == 2 && a.columnas() == 2);
}

TEST(test_primitive, constructor_copia) {

    primitive a{2,2};
    a(1,1) = 78;
    a(1,0) = 37;
    primitive b(a);
    b(1,1) = 22;
    ASSERT_TRUE(b.filas() == a.filas());
    ASSERT_TRUE(a(1,1) == 78 && a(1,0) == 37 && b(1,1) == 22 && b(1,0) == 37);
}

TEST(test_primitive, asignacion_copia) {

    primitive a{2,2};
    a(1,1) = 78;
    a(1,0) = 37;
    primitive b;
    b = a;
    // b = b; // Needed to get 100% code coverage, but not compiling
    b(1,1) = 22;
    ASSERT_TRUE(b.filas() == a.filas());
    ASSERT_TRUE(a(1,1) == 78 && a(1,0) == 37 && b(1,1) == 22 && b(1,0) == 37);
}

TEST(test_primitive, constructor_movimiento) {

    primitive a{2,2};
    a(1,1) = 78;
    a(1,0) = 37;
    primitive b{std::move(a)};
    ASSERT_TRUE(a.filas() == 0 && a.columnas() == 0);
    b(1,1) = 22;
    ASSERT_TRUE(b.filas() == 2 && b.columnas() == 2);
    ASSERT_TRUE(b(1,1) == 22 && b(1,0) == 37);
}

TEST(test_primitive, asignacion_movimiento) {

    primitive a{2,2};
    a(1,1) = 78;
    a(1,0) = 37;
    primitive b;
    b = std::move(a);
    // b = std::move(b); // Needed to get 100% code coverage, but not compiling
    ASSERT_TRUE(a.filas() == 0 && a.columnas() == 0);
    b(1,1) = 22;
    ASSERT_TRUE(b.filas() == 2 && b.columnas() == 2);
    ASSERT_TRUE(b(1,1) == 22 && b(1,0) == 37);
}

TEST(test_primitive, acceso){

    primitive const a{2,4};
    ASSERT_TRUE(a(1,3) == 0);
}

TEST(test_primitive, diagonal) {

    primitive a{2, 2};
    a(0,0) = 55;
    a(1,1) = 20;
    EXPECT_DOUBLE_EQ(a.diagonal(), 75);
}

TEST(test_primitive, suma) {

    primitive a{2,2};
    primitive b{2,2};
    a(0,0) = 3.1;
    b(0,0) = 5.1;
    a(1,1) = 25.45;
    b(1,1) = 24.55;
    a += b;
    ASSERT_TRUE(a(0,0) == 8.2 && a(1,1) == 50);
    primitive c = a + b;
    EXPECT_DOUBLE_EQ( c(0,0) , 13.3);
}

TEST(test_primitive, resta){

    primitive a{2,2};
    primitive b{2,2};
    a(0,0) = 3.1;
    b(0,0) = 5.1;
    a(1,1) = 25.45;
    b(1,1) = 24.55;
    a -= b;
    EXPECT_NEAR(a(1,1), 0.9, 0.00001);
    EXPECT_NEAR(a(0,0), -2.0, 0.00001);
    primitive c = a - b;
    EXPECT_DOUBLE_EQ( c(0,0) , -7.1);
}

TEST(test_primitive, multiplicacion) {

    primitive a{2,1};
    a(0,0) = 3;
    a(1,0) = 4;
    primitive b{1,2};
    b(0,0) = 2;
    b(0,1) = 2;
    std::cout << a << b;
    a *= b;
    std::cout << a << b;
    ASSERT_TRUE(a.filas() == 2 && a.columnas() == 2);
    ASSERT_TRUE(a(0,0) == 6 && a(1,1) == 8);
    primitive c{2,2};
    c(0,0) = -2123.234;
    c(1,1) = 45.22;
    std::cout << a << c;
    primitive d = a * c;
    std::cout << d;
    EXPECT_NEAR(d(0,0),-12739.404, 0.001);
}

TEST(test_primitive, impresion) {

    primitive a{2,2};
    a(0,0) = 37.2111;
    a(0,1) = 0.01;
    a(1,0) = 99999;
    a(1,1) = 37.21;
    std::ostringstream str_s;// Ineficiente, generando cadena e imprimiendo
    str_s << a;
    std::string expected = "[0,0] :    37.2111[0,1] :       0.01\n[1,0] :      99999[1,1] :      37.21\n";
    EXPECT_EQ(expected, str_s.str());
}
