#include <iostream>
#include <fstream>
#include <string>

class AdressSort {
    private:
    std::string city;
    std::string street;
    int house;
    int flat;
    

    public:
    std::string get_output_address(){
        return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(flat);
    };

    AdressSort(){}

    AdressSort(const std::string city, const std::string street, int houseNumber, int apartmentNumber)
        : city(city), street(street), house(houseNumber), flat(apartmentNumber) {}
};

int main(int argc, char **argv){
    int N;
    std::ifstream txtin ("in.txt");
    std::ofstream txtout ("out.txt");
    txtin >> N;

    AdressSort adress (std::string city, std::string street, int house, int flat);

    if (!txtin||!txtout) { // Проверка на открытие файла
        std::cerr << "Невозможно открыть файл.";
        return 1;
    }
    AdressSort* adresses = new AdressSort[N];
    AdressSort* adresses2 = new AdressSort[N];

       for (int i = 0; i < N; ++i) {
        std::string city, street;
        int house, flat;
        txtin >> city >> street >> house >> flat;
        adresses[i] = AdressSort(city, street, house, flat);
    }

    txtout << N << std::endl;
    for (int i = N - 1; i >= 0; --i) {
        txtout << adresses[i].get_output_address() << std::endl;
    }

    txtin.close();
    txtout.close();
    delete[] adresses;
};