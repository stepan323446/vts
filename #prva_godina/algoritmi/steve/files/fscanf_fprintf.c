#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[50];
    int age;
};
int main() {
    char *filename = "fscanf_fprintf.txt";
    struct Person david = { "David", 19 };

    FILE *fp = fopen(filename, "w");
    fprintf(fp, "%s %d", david.name, david.age);
    fclose(fp);

    FILE *fp2 = fopen(filename, "r");
    char name[50];
    int age;
    fscanf(fp, "%s %d", name, &age);
    printf("name: %s, age: %d\n", name, age);

    return 0;
}