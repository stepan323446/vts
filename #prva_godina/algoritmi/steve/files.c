// Online C compiler to run C program online
#include <stdio.h>

struct row {
    char character;
    struct row *next;
}

/*
Read file, formatting row and print characters
*/
int main() {
    struct row *nowRow, *startRow, *endRow;
    
    // Open file
    fp = fopen("data.txt", "r");
    if(!fp) {
        printf("Error. Cannot read file data.txt");
        return -1;
    }
    
    // WTF
    char ch;
    int flag = 1;
    while((ch = fgetc(fp)) != EOF) {
        if(flag) {
            nowRow = (struct row *) malloc(sizeof (struct row));
            startRow = endRow = nowRow;
            nowRow->character = ch;
            nowRow->next = NULL;
            
            flag = 0;
        }
        else {
            nowRow = (struct row *) malloc(sizeof (struct row));
            nowRow->character = ch;
            endRow->next = nowRow;
            nowRow->next = NULL;
            endRow->nowRow;
            
        }
    }
    fclose(fp);
    
    nowRow = startRow;
    while(nowRow != NULL) {
        printf("%c", nowRow->character);
        nowRow = nowRow->next;
    }
    
    nowRow = startRow->next;
    while(nowRow != NULL) {
        printf("Deleted: %c\n", startRow->character);
        startRow = nowRow;
        nowRow = nowRow->next;
    }
    
    
    return 0;
}
