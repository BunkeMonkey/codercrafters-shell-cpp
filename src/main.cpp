#include <iostream>
#include <ostream>
#include <string>

int main() {
  // Flush after every std::cout / std:cerr
  while (true) {
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    std::cout << "$ ";

    std::string input;
    std::getline(std::cin, input);

    std::cout << input << ": command not found" << std::endl;
  }
}
