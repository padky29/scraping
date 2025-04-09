/**
 * @file main.c
 * @brief Main program to simulate env.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listing.h"

int main() {

    Skin skins[] = {
        {"AK-47 | Redline", 12.50},
        {"M4A1-S | Guardian", 8.75},
        {"AWP | Asiimov", 60.00},
        {"Glock-18 | Fade", 105.00},
        {"Desert Eagle | Blaze", 140.00},
        {"USP-S | Kill Confirmed", 55.30},
        {"P90 | Death by Kitty", 11.25},
        {"FAMAS | Roll Cage", 5.40},
        {"MP9 | Starlight Protector", 7.60},
        {"Nova | Hyper Beast", 4.20}
    };
    
    srand(time(NULL));

    //Simulate listing
    for(int i = 0; i <= 10; i++){
        int randomNumber = rand() % 10;
        double fluctuation = ((rand() % 1001) / 100.0) - 3.0;
        List l = createList(skins[randomNumber], skins[randomNumber].marketPrice + fluctuation);
        printList(l);
    }
    return 0;
}
