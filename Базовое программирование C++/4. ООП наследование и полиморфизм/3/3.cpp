#include <iostream>

class Figure {
public:
    virtual void print_info() const = 0;
};

class Triangle : public Figure {
protected:
    double a, b, c;
    double A, B, C;

public:
    Triangle(double a, double b, double c, double A, double B, double C)
        : a(a), b(b), c(c), A(A), B(B), C(C) {}

    bool is_valid() const {
        return a > 0 && b > 0 && c > 0 && A > 0 && B > 0 && C > 0 && A + B + C == 180.0;
    }

    void print_info() const override {
        std::cout << "Треугольник:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n";
        if (is_valid()) {
            std::cout << "Правильная\n";
        } else {
            std::cout << "Неправильная\n";
        }
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b, double c)
        : Triangle(a, b, c, 90.0, 0.0, 0.0) {}

    void print_info() const override {
        std::cout << "Прямоугольный треугольник:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n";
        if (is_valid()) {
            std::cout << "Правильная\n";
        } else {
            std::cout << "Неправильная\n";
        }
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double c, double A)
        : Triangle(a, a, c, A, A, 180.0 - 2 * A) {}
    void print_info() const override {
        std::cout << "Равнобедренный треугольник:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n";
        if (is_valid()) {
            std::cout << "Правильная\n";
        } else {
            std::cout << "Неправильная\n";
        }
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double a)
        : Triangle(a, a, a, 60.0, 60.0, 60.0) {}
    void print_info() const override {
        std::cout << "Равносторонний треугольник:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n";
        if (is_valid()) {
            std::cout << "Правильная\n";
        } else {
            std::cout << "Неправильная\n";
        }
    }
};

class Quadrilateral : public Figure {
protected:
    double a, b, c, d;
    double A, B, C, D;

public:
    Quadrilateral(double a, double b, double c, double d,
                  double A, double B, double C, double D)
        : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

    bool is_valid() const {
        return a > 0 && b > 0 && c > 0 && d > 0 && A > 0 && B > 0 && C > 0 && D > 0 && A + B + C + D == 360.0;
    }

    void print_info() const override {
        std::cout << "Четырёхугольник:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
        if (is_valid()) {
            std::cout << "Правильная\n";
        } else {
            std::cout << "Неправильная\n";
        }
    }
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(double a, double b)
        : Quadrilateral(a, b, a, b, 90.0, 90.0, 90.0, 90.0) {}

    void print_info() const override {
        std::cout << "Прямоугольник:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
        if (is_valid()) {
            std::cout << "Правильная\n";
        } else {
            std::cout << "Неправильная\n";
        }
    }
};

class Square : public Rectangle {
public:
    Square(double a)
        : Rectangle(a, a) {}

    void print_info() const override {
        std::cout << "Квадрат:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
        if (is_valid()) {
            std::cout << "Правильная\n";
        } else {
            std::cout << "Неправильная\n";
        }
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(double a, double b, double A)
        : Quadrilateral(a, b, a, b, A, 180.0 - A, A, 180.0 - A) {}

    void print_info() const override {
        std::cout << "Параллелограмм:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
        if (is_valid()) {
            std::cout << "Правильная\n";
        } else {
            std::cout << "Неправильная\n";
        }
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(double a, double A)
        : Parallelogram(a, a, A) {}

    void print_info() const override {
        std::cout << "Ромб:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
        if (is_valid()) {
            std::cout << "Правильная\n";
        } else {
            std::cout << "Неправильная\n";
        }
    }
};

void print_info(const Figure* fig) { // пока гуглил нашел что вот так можно сделать
    fig->print_info();
    std::cout << "\n";
}

int main() {
    Triangle triangle(10.0, 20.0, 30.0, 50.0, 60.0, 70.0);
    print_info(&triangle);

    RightTriangle right_triangle(10.0, 20.0, 30.0);
    print_info(&right_triangle);

    IsoscelesTriangle isosceles_triangle(10.0, 30.0, 50.0);
    print_info(&isosceles_triangle);

    EquilateralTriangle equilateral_triangle(30.0);
    print_info(&equilateral_triangle);

    Quadrilateral quadrilateral(10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0);
    print_info(&quadrilateral);

    Rectangle rectangle(10.0, 20.0);
    print_info(&rectangle);

    Square square(20.0);
    print_info(&square);

    Parallelogram parallelogram(20.0, 30.0, 30.0);
    print_info(&parallelogram);

    Rhombus rhombus(30.0, 40.0);
    print_info(&rhombus);

    return 0;
}