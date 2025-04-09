#include "listing.h"
#include "scrape.h"
#include <stdio.h>

List createList(User userL, Skin skinL, double price){
    List listL = {userL, skinL, price};
    return listL;
}

void printList(List listL){
    printf("Listing - Name: %s \t\t price: %2f\n", listL.skin.skinName, listL.price);
}

void printLists(List lists[], int size){
    for(int i = 0; i < size; i++){
        printList(lists[i]);
    }
}

User createUser(char name[], Skin skins[], List lists[], double balance) {
    User user;
    strcpy(user.name, name);
    user.skins = skins;
    user.lists = lists;
    user.balance = balance;
    user.skinCount = 0;
    user.listCount = 0;  // <- AQUI
    return user;
}


void simulatePurchase(List *botListings, User *bot) {
    if (bot->listCount == 0) {
        printf("lista vazia");
        return; // Proteção contra lista vazia
    }

    int index = rand() % bot->listCount;
    List *botListing = &botListings[index];

    int chance = rand() % 100;
    if (chance < 30) {
        printf("[BUY EVENT] %s foi comprada por um user por %.2f€!\n", 
               botListing->skin.skinName, botListing->price);
        bot->balance += botListing->price;
        printf("BOT BALANCE AFTER SALE: %.2f€\n", bot->balance);

        // Remover skin vendida do inventário do bot
        int indexToRemove = -1;
        for (int i = 0; i < bot->skinCount; i++) {
            if (strcmp(bot->skins[i].skinName, botListing->skin.skinName) == 0) {
                indexToRemove = i;
                break;
            }
        }
        if (indexToRemove != -1) {
            for (int i = indexToRemove; i < bot->skinCount - 1; i++) {
                bot->skins[i] = bot->skins[i + 1];
            }
            bot->skinCount--;
        }

        // Também podes querer remover a list vendida do array de listas
        for (int i = 0; i < bot->listCount; i++) {
            if (strcmp(bot->lists[i].skin.skinName, botListing->skin.skinName) == 0) {
                for (int j = i; j < bot->listCount - 1; j++) {
                    bot->lists[j] = bot->lists[j + 1];
                }
                bot->listCount--;
                break;
            }
        }
    } else {
        //printf("[NO SALE] Ninguém comprou hoje.\n", botListing->skin.skinName);
    }
}

