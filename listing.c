#include "listing.h"
#include <stdio.h>

List createList(Skin skin, double price){
    List list = {skin, price};
    return list;
}

void printList(List list){
    printf("Listing - Name: %s \t\t price: %2f\n", list.skin.skinName, list.price);
}