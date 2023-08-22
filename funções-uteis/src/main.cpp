#include "../include/fileOptions.hpp"
#include <iostream>

int main() {
    /* std::string userInput;

    std::cout << "Enter text: ";
    std::getline(std::cin, userInput);

    writeFile("output.txt", userInput);
    */

    std::cout << readFile("output.txt") << std::endl;
    return 0;
}
