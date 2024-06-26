#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

class AdressSort {
private:
    std::string city;
    std::string street;
    int house;
    int flat;

public:
    AdressSort() {}

    AdressSort(const std::string& city, const std::string& street, int houseNumber, int apartmentNumber)
        : city(city), street(street), house(houseNumber), flat(apartmentNumber) {}

    std::string get_output_address() const {
        return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(flat);
    }

    std::string getCity() const {
        return city;
    }

    static bool compare(const AdressSort& a, const AdressSort& b) {
        return a.getCity() < b.getCity();
    }
};

int main() {
    std::ifstream txtin("in.txt");
    std::ofstream txtout("out.txt");

    int N;
    txtin >> N;

    if (!txtin || !txtout) { // Проверка на открытие файла
        std::cerr << "Невозможно открыть файл.";
        return 1;
    }

    AdressSort* addresses = new AdressSort[N];

    for (int i = 0; i < N; ++i) {
        std::string city, street;
        int house, flat;
        txtin >> city >> street >> house >> flat;
        addresses[i] = AdressSort(city, street, house, flat);
    }

    std::sort(addresses, addresses + N, &AdressSort::compare);

    txtout << N << std::endl;
    for (int i = 0; i < N; ++i) {
        txtout << addresses[i].get_output_address() << std::endl;
    }

    txtin.close();
    txtout.close();

    delete[] addresses;

    return 0;
}