#include "../include/fileOptions.hpp"
#include <iostream>

void writeFile(std::string fileName, std::string content) {
    FILE* outputFile = fopen(fileName.c_str(), "w");
    if (outputFile != nullptr) {
        fprintf(outputFile, "%s", content.c_str());
        fclose(outputFile);
        std::cout << "Text written to " << fileName << " successfully!" << std::endl;
    } else {
        std::cerr << "Unable to open " << fileName << " for writing." << std::endl;
    }
}

std::string readFile(std::string fileName) {
    FILE* inputFile = fopen(fileName.c_str(), "r");
    if (inputFile != nullptr) {
        std::string fileContents;
        char currentChar = fgetc(inputFile);
        while (currentChar != EOF) {
            fileContents += currentChar;
            currentChar = fgetc(inputFile);
        }
        fclose(inputFile);
        return fileContents;
    } else {
        std::cerr << "Unable to open " << fileName << " for reading." << std::endl;
        return "";
    }
}