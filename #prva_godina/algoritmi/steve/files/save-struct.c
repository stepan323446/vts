#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[16];
    int age;
};

int save(char *, struct Student *);
int load(char *);

int main() {
    char *filename = "save-struct.dat";
    struct Student student;

    int answer;
    printf("Choose 0 - load, 1 - save: ");
    scanf("%d", &answer);
    if(answer) {
        printf("Person name: ");
        scanf("%s", &student.name);
        printf("Person age: ");
        scanf("%d", &student.age);

        save(filename, &student);
    }
    else {
        load(filename);
    }
}

int save(char *filename, struct Student *person) {
    FILE *fp = fopen(filename, "wb");
    char *c;
    if(!fp) {
        printf("File not found\n");
        return 0;
    }

    int size = sizeof(struct Student);
    c = (char *)person;

    for (int i = 0; i < size; i++) {
        putc(*c++, fp);
    }
    
    printf("Data saved");
    fclose(fp);

    return 1;
}

int load(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if(!fp) {
        printf("File not found\n");
        return 0;
    }
    char *c;
    int size = sizeof(struct Student);
    struct Student *personPtr = (struct Student *)malloc(size);

    c = (char *)personPtr;
    int byte;
    while ((byte = getc(fp)) != EOF)
    {
        *c = byte;
        c++;
    }
    fclose(fp);

    printf("Name - %s, Age - %d", personPtr->name, personPtr->age);

    free(personPtr);

    return 1;
}