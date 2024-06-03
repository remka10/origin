#include <iostream>

class Calculator {
public:
  double num1, num2;

  double add() { return (num1 + num2); }
  double multiply() { return (num1 * num2); }
  double substract_1_2() { return (num1 - num2); }
  double substract_2_1() { return (num2 - num1); }
  double divide_1_2() { return (num1 / num2); }
  double divide_2_1() { return (num2 / num1); }

  bool set_num1(double num1) {
    if (num1 != 0) {
      this->num1 = num1;
      return true;
    }
    return false;
  }
  bool set_num2(double num2) {
    if (num2 != 0) {
      this->num2 = num2;
      return true;
    }
    return false;
  }

  Calculator(double num1, double num2) {
    this->num1 = num1;
    this->num2 = num2;
  }
};
int main() {
  while (true){
  std::cout << "Введите два числа: ";
  double num1, num2;
  std::cin >> num1;
  std::cout << "   ";
  std::cin >> num2;
  Calculator calc(num1, num2);
  if ((num1 || num2) == 0) { std::cout << "Wrong imput." << std::endl;}
  else {
  std::cout << "Add 1 to 2: " << calc.add() << std::endl;
  std::cout << "Multiply 1*2: " << calc.multiply() << std::endl;
  std::cout << "Substract 1 - 2: " << calc.substract_1_2() << std::endl;
  std::cout << "Substract 2 - 1: " << calc.substract_2_1() << std::endl;
  std::cout << "Divide 1 / 2: " << calc.divide_1_2() << std::endl;
  std::cout << "Divide 2 / 1: " << calc.divide_2_1() << std::endl;
  }
  }
}