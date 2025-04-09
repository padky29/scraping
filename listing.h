#ifndef LISTING_H
#define LISTING_H

typedef struct skin {
    char skinName[255];
    double marketPrice;
} Skin;

typedef struct list List; // Forward declaration to use in User

typedef struct {
    char name[255];
    Skin *skins;
    List *lists;
    int skinCount;
    int listCount;
    double balance;
} User;

typedef struct list {
    User user;
    Skin skin;
    double price;
} List;

List createList(User userL, Skin skinL, double price);

void printList(List listL);

void printLists(List listL[], int size);

User createUser(char name[], Skin skins[], List lists[], double balance);

#endif // LISTING_H