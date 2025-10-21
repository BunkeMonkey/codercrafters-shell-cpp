#include <iostream>
#include <ostream>
#include <string>
#include <queue>
#include "builtins.h"
int main() {
  // Flush after every std::cout / std:cerr
  bool alive = true;


  while (alive) {
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    std::cout << "$ ";

    std::string input;
    std::getline(std::cin, input);
    std::queue<std::string> input_tokens{};

    int index = 0;
    while (index != std::string::npos){
      auto space_index = input.find_first_of(" ",index);
       if (space_index == std::string::npos){
        input_tokens.push(input.substr(index,input.length()));
        break;
      }
      std::cout << "space index:" << space_index << std::endl << "start index" << index << std::endl;
      input_tokens.push(input.substr(index,space_index - index));
      std::cout << "extracted substring: " << input.substr(index,space_index - index) << std::endl;
      index = space_index + 1;

   }

    /*
    while(!input_tokens.empty()){
      std::cout << "tokens:" << input_tokens.front() << std::endl;
      input_tokens.pop();
    }
    */
    builtins.contains("test");
    auto command = input_tokens.front();
    input_tokens.pop(); 
    if (command == "exit"){
      break;
    }
    if (command == "echo"){
      while (!input_tokens.empty()){
        std::cout << input_tokens.front() << " ";
        input_tokens.pop();
      }
      std::cout << std::endl;
      continue;

    }


    std::cout << input << ": command not found hasud" << std::endl;
  }
  return 0;

}
