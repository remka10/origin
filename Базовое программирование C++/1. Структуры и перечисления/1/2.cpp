#include <iostream>
using namespace std;

struct bank {
    long int numbers;
    string name;
    long int balance;
};

void structchange(bank b1, long int newbalance) {
    b1.balance = newbalance;
    std::cout << "\nВаш счёт: " << b1.numbers << ", " << b1.name << ", " << b1.balance << " рублей.\n";
}
  
int main() {
  long int x, z, newbalance = 0;
  std::string y;
  std::cout << "Введите номер счёта: ";
  std::cin >> x;
  std::cout << "\nВведите имя владельца: ";
  std::cin >> y;
  std::cout << "\nВведите баланс: ";
  std::cin >> z;
  std::cout << "\nВведите новый баланс: ";
  std::cin >> newbalance;
  bank b1 = {x, y, z};
  structchange(b1, newbalance);
}