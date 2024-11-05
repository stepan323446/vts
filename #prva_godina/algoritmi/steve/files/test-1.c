#include <stdio.h>
#include <stdlib.h>

int main() {
    char message[] = "При чтении из файла и записи в него одного символа указатель текущей позиции в потоке увеличивается, обеспечивая тем самым продвижение по файлу.";
    FILE *fp = fopen("test-1.txt", "w");
    if(!fp) {
        printf("File not found\n");
        return -1;
    }
    int n = sizeof(message) / sizeof(message[0]);

    for (int i = 0; i < n; i++) {
        fputc(message[i], fp);
    }
    printf("File was written\n");
    fclose(fp);

    FILE *fp2 = fopen("data.txt", "r");
    char c;
    while ((c = fgetc(fp2)) != EOF) {
        printf("%c", c);
    }
    
    fclose(fp2);

    return 0;
}