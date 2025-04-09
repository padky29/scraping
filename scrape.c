#include "listing.h"
#include "scrape.h"
#include <stdio.h>

#define TRESHOLD 1
#define MAX_TRANSACTIONS 200

User createBot(char name[], Skin bSkins[], List bLists[], double balance){
    User bot = createUser(name, bSkins, bLists, balance);
    return bot;
}

void buySkinBot(User *bot, List listToBuy) {
    if (bot->balance >= listToBuy.price) {
        bot->skins[bot->skinCount++] = listToBuy.skin;
        bot->balance -= listToBuy.price;
        printf("BOT BOUGHT: %s for %.2f€. New balance: %.2f€\n",
               listToBuy.skin.skinName, listToBuy.price, bot->balance);
        listSkin(bot, listToBuy.skin);
    } else {
        printf("BOT CANNOT AFFORD: %s (%.2f€). Balance: %.2f€\n",
               listToBuy.skin.skinName, listToBuy.price, bot->balance);
    }
}

void listSkin(User *userB, Skin skinB) {
    if (userB->skinCount > 0) {
        // Ensure createList expects a pointer if necessary.
        List newList = createList(*userB, skinB, skinB.marketPrice + 5);

        // Add the new listing to the user's list
        userB->lists[userB->listCount++] = newList;

        printf("SKIN LISTED: %s for %.2f€\n", skinB.skinName, newList.price);

        // Remove the skin from the skins array
        int indexToRemove = -1;
        for (int i = 0; i < userB->skinCount; i++) {
            if (strcmp(userB->skins[i].skinName, skinB.skinName) == 0) {
                indexToRemove = i;
                break;
            }
        }
        if (indexToRemove != -1) {
            for (int i = indexToRemove; i < userB->skinCount - 1; i++) {
                userB->skins[i] = userB->skins[i + 1];
            }
            userB->skinCount--;
        }
    } else {
        printf("No more skins to list.\n");
    }
}

void updateB(List listB, User *user){
    if(listB.price > listB.skin.marketPrice + TRESHOLD){
        buySkinBot(user, listB);
    }
}