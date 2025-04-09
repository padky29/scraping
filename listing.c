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
    return user;
}