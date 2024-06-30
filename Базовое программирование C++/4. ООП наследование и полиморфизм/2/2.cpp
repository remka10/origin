#include <iostream>
#include <string>
#include <cmath>

class Figure {
protected:
    std::string name;
public:
    Figure(const std::string& figure_name) : name(figure_name) {}

    std::string get_name() const { return name; }
};

class Triangle : public Figure {
protected:
    double a, b, c;
    double A, B, C;
public:
    Triangle(double a, double b, double c, double A, double B, double C)
        : Figure("Треугольник"), a(a), b(b), c(c), A(A), B(B), C(C) {}

    double get_a() const { return a; }
    double get_b() const { return b; }
    double get_c() const { return c; }
    double get_A() const { return A; }
    double get_B() const { return B; }
    double get_C() const { return C; }
};

class RectangleTriangle : public Triangle {
public:
    RectangleTriangle(double a, double b, double A, double B)
        : Triangle(a, b, std::sqrt(a*a + b*b), A, B, 90) {name = "Прямоугольный треугольник";}
};

class IsoscelesTriangle : public Triangle {
public: 
    IsoscelesTriangle(double a, double b, double A, double B)
        : Triangle(a, b, a, A, B, A) {name = "Равнобедренный треугольник";}
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double a)
        : Triangle(a, a, a, 60, 60, 60) {name = "Равносторонний треугольник";}
};

class Quadrilateral : public Figure {
protected:
    double a, b, c, d;
    double A, B, C, D;
public:
    Quadrilateral(double a, double b, double c, double d, double A, double B, double C, double D)
        : Figure("Четырёхугольник"), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

    double get_a() const { return a; }
    double get_b() const { return b; }
    double get_c() const { return c; }
    double get_d() const { return d; }
    double get_A() const { return A; }
    double get_B() const { return B; }
    double get_C() const { return C; }
    double get_D() const { return D; }
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(double a, double b)
        : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {name = "Прямоугольник";}
};

class Square : public Quadrilateral {
public:
    Square(double a)
        : Quadrilateral(a, a, a, a, 90, 90, 90, 90) {name = "Квадрат";}
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(double a, double b, double A, double B)
        : Quadrilateral(a, b, a, b, A, B, A, B) {name = "Параллелограмм";}
};

class Rhombus : public Quadrilateral {
public:
    Rhombus(double a, double A, double B)
        : Quadrilateral(a, a, a, a, A, B, A, B) {name = "Ромб";}
};

int main() {
    Triangle tri(10, 20, 30, 50, 60, 70);
    RectangleTriangle rect_tri(10, 20, 30, 60);
    IsoscelesTriangle isosceles_tri(10, 20, 50, 60);
    EquilateralTriangle equilateral_tri(30);
    Quadrilateral quad(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rect(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30, 30, 40);

    std::cout << tri.get_name() << ":\n"
              << "Стороны: a=" << tri.get_a() << " b=" << tri.get_b() << " c=" << tri.get_c() << "\n"
              << "Углы: A=" << tri.get_A() << " B=" << tri.get_B() << " C=" << tri.get_C() << "\n\n";

    std::cout << rect_tri.get_name() << ":\n"
              << "Стороны: a=" << rect_tri.get_a() << " b=" << rect_tri.get_b() << " c=" << rect_tri.get_c() << "\n"
              << "Углы: A=" << rect_tri.get_A() << " B=" << rect_tri.get_B() << " C=" << rect_tri.get_C() << "\n\n";

    std::cout << isosceles_tri.get_name() << ":\n"
              << "Стороны: a=" << isosceles_tri.get_a() << " b=" << isosceles_tri.get_b() << " c=" << isosceles_tri.get_c() << "\n"
              << "Углы: A=" << isosceles_tri.get_A() << " B=" << isosceles_tri.get_B() << " C=" << isosceles_tri.get_C() << "\n\n";

    std::cout << equilateral_tri.get_name() << ":\n"
              << "Стороны: a=" << equilateral_tri.get_a() << " b=" << equilateral_tri.get_b() << " c=" << equilateral_tri.get_c() << "\n"
              << "Углы: A=" << equilateral_tri.get_A() << " B=" << equilateral_tri.get_B() << " C=" << equilateral_tri.get_C() << "\n\n";

    std::cout << quad.get_name() << ":\n"
              << "Стороны: a=" << quad.get_a() << " b=" << quad.get_b() << " c=" << quad.get_c() << " d=" << quad.get_d() << "\n"
              << "Углы: A=" << quad.get_A() << " B=" << quad.get_B() << " C=" << quad.get_C() << " D=" << quad.get_D() << "\n\n";

    std::cout << rect.get_name() << ":\n"
              << "Стороны: a=" << rect.get_a() << " b=" << rect.get_b() << " c=" << rect.get_c() << " d=" << rect.get_d() << "\n"
              << "Углы: A=" << rect.get_A() << " B=" << rect.get_B() << " C=" << rect.get_C() << " D=" << rect.get_D() << "\n\n";

    std::cout << square.get_name() << ":\n"
              << "Стороны: a=" << square.get_a() << " b=" << square.get_b() << " c=" << square.get_c() << " d=" << square.get_d() << "\n"
              << "Углы: A=" << square.get_A() << " B=" << square.get_B() << " C=" << square.get_C() << " D=" << square.get_D() << "\n\n";

    std::cout << parallelogram.get_name() << ":\n"
              << "Стороны: a=" << parallelogram.get_a() << " b=" << parallelogram.get_b() << " c=" << parallelogram.get_c() << " d=" << parallelogram.get_d() << "\n"
              << "Углы: A=" << parallelogram.get_A() << " B=" << parallelogram.get_B() << " C=" << parallelogram.get_C() << " D=" << parallelogram.get_D() << "\n\n";

    std::cout << rhombus.get_name() << ":\n"
              << "Стороны: a=" << rhombus.get_a() << " b=" << rhombus.get_b() << " c=" << rhombus.get_c() << " d=" << rhombus.get_d() << "\n"
              << "Углы: A=" << rhombus.get_A() << " B=" << rhombus.get_B() << " C=" << rhombus.get_C() << " D=" << rhombus.get_D() << "\n\n";

    return 0;
    }