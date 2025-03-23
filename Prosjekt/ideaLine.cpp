#include "ideaLine.h"
#include <vector>
#include <AnimationWindow.h>
#include <iostream>
#include <fstream>
#include "widgets/Button.h"
#include "hFiler/fileReader.h"

std::vector<int> ideaLine::getPosisjon(int linjeNummer) {
    std::vector<int> posisjon;

    posisjon.push_back(50);
    posisjon.push_back(50 + (linjeNummer * 50));

    return posisjon;
}

std::string ideaLine::getTekst(int linjeNummer) {
    return "Dette er en test";
}

void callbackFunction() {
    std::string verdi;

    std::ifstream inputFile("tekstFolder/antallLinjer");
    std::getline(inputFile, verdi);
    inputFile.close();

    int antallLinjer = std::stoi(verdi);
    antallLinjer++;
    std::ofstream outputFile("tekstFolder/antallLinjer");
    outputFile << antallLinjer << std::endl;
    outputFile.close();
}

void removeButtonClass::removeButtonFunc() {
    std::cout << "Fjern" << std::endl;
}


removeButtonClass::removeButtonClass() : AnimationWindow(), removeButton({0, 0}, 100, 30, "Fjern") {
    removeButton.setCallback(std::bind(&removeButtonClass::removeButtonFunc, this));
    add(removeButton);
    
}