#include "list.h"
#include <stdio.h>

int main() {
    struct StaticList singerList;
    createList(&singerList);

    insert(&singerList, "Penyanyi A");
    insert(&singerList, "Penyanyi B");
    insert(&singerList, "Penyanyi C");

    printList(&singerList);

    deleteItem(&singerList, "Penyanyi B");

    printList(&singerList);

    insert(&singerList, "Afgan");
    deleteItem(&singerList,"Penyanyi A");
    printList(&singerList);
    return 0;
}
