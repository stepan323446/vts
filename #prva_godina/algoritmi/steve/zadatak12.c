#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATABASE_NAME "db.txt"

struct game
{
    char *name;
    int year;
    int popularity;
    char *company;
    char *description;
};
struct dataStruct {
    struct game games[100];
    int count;
} data;

void getData() {
    data.count = 0;
    FILE *database = fopen(DATABASE_NAME, "r");
    if(database == NULL)
        return;

    char str[100];
    while(fgets(str, sizeof(str), database) != 0) {
        int len = strlen(str);

        if(len>0 && str[len-1] == '\n'){
            str[len-1]='\0';
        }
        printf("%s", str);
    }
}
void readData() {
    int answer;
    printf("=========== Your data ===========n\n");
    for (int i = 0; i < data.count; i++)
    {
        printf("%d - %s\n", i, data.games[i].name);
    }
    if(data.count == 0){ 
        printf("Nothing to show. Click any number...\n");
        scanf("%d", &answer);
    }
    
}
int main()
{
    getData();

    while (1)
    {
        int answer;
        int is_exit = 0;

        printf("\n\n=========== MENU ===========\n");
        printf("Choose option: \n");
        printf("1 - Read data\n");
        printf("2 - Write new data\n");
        printf("3 - Edit data\n");
        printf("4 - Remove data\n");
        printf("0 - Exit\n");
        printf("...\n");
        printf("Your answer: \n");

        scanf("%d", &answer);

        switch (answer) {
            case 1:
                readData();
                break;
            case 2:
                /* code */
                break;
            case 3:

                break;
            case 0:
                is_exit = 1;
                break;

            default:
                printf("Uncorrect answer!\n");
                break;
        }

        if (is_exit)
            break;
    }
    return 0;
}