#include <stdio.h>
#include <stdlib.h>

struct game {
    char *title;
    int year;
    int popularity;

    struct game *next;
};

void printGame(struct game *g) {
    printf("Game:\t\t %s\n", g->title);
    printf("Year:\t\t %d\n", g->year);
    printf("Popularity:\t %d\n", g->popularity);
}

int main() {
    struct game genshin = {.title="Genshin Impact", .year=2016, .popularity=9};
    struct game honkai = {.title="Honkai Star Rail", .year=2020, .popularity=7};
    struct game strongold = {.title="Strongold Crusader", .year=2003, .popularity=2};

    genshin.next = &honkai;
    honkai.next = &strongold;

    struct game *pointer = &genshin;
    while (pointer != NULL)
    {
        printGame(pointer);
        printf("=======\n");

        pointer = pointer->next;
    }
    
    
    return 0;
}