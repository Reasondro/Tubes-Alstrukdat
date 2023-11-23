#include "list.h"
#include <string.h>
#include <stdio.h>

// Fungsi untuk membuat list kosong
void createList(struct StaticList *list) {
    list->size = 0;
}

// Fungsi untuk menambahkan penyanyi ke dalam list
void insert(struct StaticList *list, const char *item) {
    if (list->size < MAX_SIZE) {
        strcpy(list->items[list->size], item);
        list->size++;
        printf("Penyanyi '%s' ditambahkan ke dalam list.\n", item);
    } else {
        printf("List penuh. Penyanyi tidak dapat ditambahkan.\n");
    }
}

// Fungsi untuk mencari penyanyi dalam list
int search(struct StaticList *list, const char *item) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->items[i], item) == 0) {
            return i; // Penyanyi ditemukan, mengembalikan indeksnya
        }
    }
    return -1; // Penyanyi tidak ditemukan
}

// Fungsi untuk menghapus penyanyi dari list
void deleteItem(struct StaticList *list, const char *item) {
    int index = search(list, item);
    if (index != -1) {
        for (int i = index; i < list->size - 1; i++) {
            strcpy(list->items[i], list->items[i + 1]);
        }
        list->size--;
        printf("Penyanyi '%s' dihapus dari list.\n", item);
    } else {
        printf("Penyanyi '%s' tidak ditemukan dalam list.\n", item);
    }
}

// Fungsi untuk menampilkan seluruh daftar penyanyi
void printList(struct StaticList *list) {
    if (list->size == 0) {
        printf("List kosong.\n");
    } else {
        printf("Daftar Penyanyi:\n");
        for (int i = 0; i < list->size; i++) {
            printf("%d. %s\n", i + 1, list->items[i]);
        }
    }
}
