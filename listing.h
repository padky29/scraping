typedef struct skin{
    char skinName[255];
    double marketPrice;
}Skin;

typedef struct list{
    Skin skin;
    double price;
}List;

List createList(Skin skin, double price);

void printList(List list);