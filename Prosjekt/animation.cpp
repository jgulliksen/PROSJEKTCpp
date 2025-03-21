#include "std_lib_facilities.h"
#include <AnimationWindow.h>
#include "ideaLine.h"
#include "hFiler/fileReader.h"
#include "widgets/Button.h"



//Konstanter for vinduet
int windowWidth = 1200;
int windowHight = 600;
int windowX = 90;
int windowY = 80;
std::string name = "Huskeliste";


//Funksjonen som lager vinduet
void animation(){


    const TDT4102::Point buttonPosition {windowWidth/2, windowHight/5};
    TDT4102::Button button {buttonPosition, 100, 30, "Legg til"};
    button.setCallback(callbackFunction);





    AnimationWindow window(windowX, windowY, windowWidth, windowHight, name);
    window.add(button);
    while(!window.should_close()){


        int antallLinjer = std::stoi(readFromFile(1, "antallLinjer"));

        for (int i = 1; i <= antallLinjer; i++) {
            antallLinjer = std::stoi(readFromFile(1, "antallLinjer"));
            ideaLine line(i);
            TDT4102::Point p1 = TDT4102::Point(line.getPosisjon(i)[0], line.getPosisjon(i)[1]);
            window.draw_rectangle(p1, line.størrelse[0], line.størrelse[1], TDT4102::Color::white, TDT4102::Color::black);
        }


        window.next_frame();
    }
}