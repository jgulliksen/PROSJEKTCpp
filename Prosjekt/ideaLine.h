#include <string>
#include <vector>
#include <AnimationWindow.h>
#include "widgets/Button.h"

class ideaLine {
    public:
        int linjeNummer;
        std::vector<int> størrelse = {50,50};

    ideaLine(int linjeNummer) {
        this->linjeNummer = linjeNummer;
    }

    std::vector<int> getPosisjon(int linjeNummer);
    std::string getTekst(int linjeNummer);

};

void callbackFunction();

class removeButtonClass : public TDT4102::AnimationWindow {
    public:
        removeButtonClass();
        void removeButtonFunc();


    private:
        TDT4102::Button removeButton;
};