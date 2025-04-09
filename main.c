/**
 * @file main.c
 * @brief Main program to simulate env.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "listing.h"
#include "scrape.h"

#define NUMBER_OF_LISTING 100
#define TOTAL_SKINS 10

List bLists[500];
Skin bSkins[500];
char name[50] = "bot";

int main()
{

    printf("\nBot starts with: 200€\n\n");

    srand(time(NULL));

    // Skins que vamos usar para users e bots
    Skin skins[TOTAL_SKINS] = {
        {"AK-47 | Redline", 12.50},
        {"M4A1-S | Guardian", 8.75},
        {"AWP | Asiimov", 60.00},
        {"Glock-18 | Fade", 105.00},
        {"Desert Eagle | Blaze", 140.00},
        {"USP-S | Kill Confirmed", 55.30},
        {"P90 | Death by Kitty", 11.25},
        {"FAMAS | Roll Cage", 5.40},
        {"MP9 | Starlight Protector", 7.60},
        {"Nova | Hyper Beast", 4.20}};

    // Inicializar bot com cópia das skins
    for (int i = 0; i < TOTAL_SKINS; i++)
    {
        bSkins[i] = skins[i];
    }

    // Criar bot com 10 skins
    User bot = createBot(name, bSkins, bLists, 200.0);
    bot.skinCount = TOTAL_SKINS;
    for (int i = 0; i < TOTAL_SKINS; i++)
    {
        bot.skins[i] = bSkins[i];
    }

    List lists[NUMBER_OF_LISTING];

    for (int i = 0; i < NUMBER_OF_LISTING; i++)
        {
            int randomNumber = rand() % TOTAL_SKINS;
            double fluctuation = ((rand() % 1001) / 100.0) - 3.0;

            char userName[255];
            sprintf(userName, "User%d", i);

            Skin selectedSkin = skins[randomNumber];

            Skin dummySkins[20];  // ou qualquer número razoável
            List dummyLists[20];
            User user = createUser(userName, dummySkins, dummyLists, 10000);
            lists[i] = createList(user, selectedSkin, selectedSkin.marketPrice + fluctuation);

            updateB(lists[i], &bot);
/*
            printf("Created listing from %s: %s for %.2f€\n",
                   user.name, selectedSkin.skinName, selectedSkin.marketPrice + fluctuation);*/

            simulatePurchase(bot.lists, &bot);
        }

    // Simular listas de users normais
    

    printf("\n--- Bot starts listing its own skins ---\n");

    // Enquanto o bot tiver skins, ele lista-as
    while (bot.skinCount > 0)
    {
        listSkin(&bot, bot.skins[0]); // sempre lista a primeira
        printf("Bot listed a skin. Skins left: %d\n", bot.skinCount);
    }

    while (bot.listCount > 0)
    {   
        simulatePurchase(bot.lists, &bot);
    }

    printf("\nBot has no more skins to list.\n");

    return 0;
}
