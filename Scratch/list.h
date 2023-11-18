#ifndef LIST_H
#define LIST_H

#define MAX_SIZE 100

// Definition of the ADT List for a static list of singers
struct StaticList {
    char items[MAX_SIZE][100];
    int size;
};

void createList(struct StaticList *list);
void insert(struct StaticList *list, const char *item);
int search(struct StaticList *list, const char *item);
void deleteItem(struct StaticList *list, const char *item);
void printList(struct StaticList *list);

#endif
