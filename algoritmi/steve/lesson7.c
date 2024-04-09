#include <stdio.h>
#include <stdlib.h>

void rProgramTxt();
void wProgramTxt();
void setStudentTodb(int);
void getStudentsFromDb();

int main() {
    /*
    int numStudents;
    printf("Student nums: ");
    scanf("%d", &numStudents);
    setStudentTodb(numStudents);
    */

   getStudentsFromDb();

    return 0;
}
void getStudentsFromDb() {
    FILE *fptr;
    char ch;
    int numStudents = 0;
    fptr = fopen("grades.txt", "r");

    ch = fgetc(fptr);
    printf("Content database: \n");
    while (ch != EOF)
    {
        if(ch == '\n')
            numStudents++;

        printf("%c", ch);
        ch = fgetc(fptr);
    }
    printf("\n=========\n");
    printf("Num students: %d\n", numStudents - 1);
    
}
void setStudentTodb(int numStudents) {
    char name[numStudents][30];
    char subject[numStudents][15];
    int grade[numStudents];
    int index[numStudents];

    FILE *fptr;
    fptr = fopen("grades.txt", "w");
    if(fptr == NULL) {
        printf("Greska!");
        exit(1);
    }

    for(int i = 0; i < numStudents; i++) {
        printf("------------\n");
        printf("Enter your index: ");
        scanf("%d", &index[i]);
        printf("Enter grade: ");
        scanf("%d", &grade[i]);
        printf("Enter name: ");
        scanf("%s", &name[i]);
        printf("Enter subject: ");
        scanf("%s", &subject[i]);
    }
    fprintf(fptr, "Name \t | \t Index \t\t | \t Subj \t\t | \t grade \t | \t\n");
    for(int i = 0; i < numStudents; i++) {
        fprintf(fptr, "%s \t | \t %d \t | \t %s \t | \t %d\n", name[i], index[i], subject[i], grade[i]);
    }
    fclose(fptr);
}

void rProgramTxt() {
    int num;
    FILE *fptr;
    fptr = fopen("program.txt", "r");
    if(fptr == NULL) {
        printf("Greska!");
        exit(1);
    }
    fscanf(fptr, "%d", &num);
    printf("%d", num);
    fclose(fptr);
}
void wProgramTxt() {
    FILE *fptr;
    int number;

    fptr = fopen("program.txt", "w");
    if(fptr == NULL) {
        printf("Greska!");
        exit(1);
    }
    printf("Enter one num: ");
    scanf("%d", &number);

    fprintf(fptr, "%d", number);
    fclose(fptr);
}