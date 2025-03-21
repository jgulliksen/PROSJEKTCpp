#include <fstream>
#include "hFiler/fileReader.h"
#include <vector>


std::string folder = "tekstFolder";


// addToFile legger til en linje i en fil
void addToFile(std::string tekst, std::string fil) {
    std::ofstream outputFile(folder + "/" +  fil, std::ios::app);

    outputFile << tekst << std::endl;

    outputFile.close();
}


// readFromFile leser av en spesefikk linje i en fil
std::string readFromFile(int linjenummer, std::string fil) {
    std::string tekst;
    int currentLine = 1;

    std::ifstream inputFile(folder + "/" +fil);

    while (std::getline(inputFile, tekst)) {
        if (currentLine == linjenummer) {
            inputFile.close();
            return tekst;
        }
    }
    return tekst;
}

// removeFromFile fjerner en spesefikk linje i en fil
void removeFromFile(int linjenummer, std::string fil) {
    std::ifstream inputFile(folder + "/" + fil);

    std::vector<std::string> tekstVektor;
    std::string line;
    while (std::getline(inputFile, line)) {
        tekstVektor.push_back(line);
    }
    inputFile.close();


    tekstVektor.erase(tekstVektor.begin() + linjenummer - 1);

    std::ofstream outputFile(folder + "/" + fil);
    for (std::string l : tekstVektor) {
        outputFile << l << std::endl;
    }
    outputFile.close();



}