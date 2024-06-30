#include <iostream>
#include <string>

class Figure {
    protected:
    int sides_count;
    std::string name;

    public:
    Figure() : sides_count(0), name("Фигура") {}
    
    int get_sides_count() const { return (sides_count); }
    std::string get_name() const { return (name); }
};

class Triangle: public Figure {
    public:
        Triangle() {sides_count = 3, name = "Треугольник";}
};

class Quadrangle: public Figure {
    public:
        Quadrangle() {sides_count = 4, name = "Четырехугольник";}
};

int main(){
    Figure f;
    Triangle t;
    Quadrangle q;

    std::cout << "Количество сторон:\n" << f.get_name() << " " << f.get_sides_count() << "\n" << t.get_name() << " " << t.get_sides_count() << "\n" << q.get_name() << " " << q.get_sides_count();

}