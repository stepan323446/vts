#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[20];
    int age;
    int index;

    struct Person *next;
};

int main() {
    struct Person person;
    int createPerson;
    do
    {
        printf("Need create new person? (1/0)");
        scanf("%d", &createPerson);

        if(!createPerson)
            break;

        printf("Name: ");
        scanf("%s", &person.name);
        printf("Age: ");
        scanf("%s", &person.age);
        printf("Index: ");
        scanf("%s", &person.index);
    } while (1);
    

    return 0;
}