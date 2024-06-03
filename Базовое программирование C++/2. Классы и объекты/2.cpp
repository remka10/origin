#include <iostream>
class Counter {
private:
  int value;

public:
  Counter() : value(1) {}
  Counter(int initialValue) : value(initialValue) {}
  void increment() { value++; }
  void decrement() { value--; }
  int getValue() const { return value; }
};
int main() {
  std::cout
      << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
  std::string answer;
  std::cin >> answer;
  Counter counter;
  if (answer == "да") {
    std::cout << "Введите начальное значение счётчика: ";
    int initialValue;
    std::cin >> initialValue;
    counter = Counter(initialValue);
  }

  char command;
  do {
    std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
    std::cin >> command;
    switch (command) {
    case '+':
      counter.increment();
      break;
    case '-':
      counter.decrement();
      break;
    case '=':
      std::cout << "Текущее значение счётчика: " << counter.getValue()
                << std::endl;
      break;
    case 'x':
      std::cout << "До свидания!" << std::endl;
      break;
    default:
      std::cout << "Неверная команда. Попробуйте ещё раз." << std::endl;
      break;
    }
  } while (command != 'x');
}