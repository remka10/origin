#include <iostream>
using namespace std;

struct adress {
    string city;
    string street;
    int housenumber;
    int apartmentnumber;
    int index;
};

void structname(struct adress x) {
    std::cout << "Город: " << x.city << std::endl << "Улица: " << x.street << std::endl << "Номер дома: " << x.housenumber << std::endl << "Номер квартиры: " << x.apartmentnumber << std::endl << "Индекс: " << x.index << std::endl << std::endl;
}

int main() {
    struct adress x = {"Москва", "Арбат", 12, 8, 123456};
    struct adress y = {"Мухосранск", "Ленина", 1, 1, 111111};
    structname(x);
    structname(y);
}