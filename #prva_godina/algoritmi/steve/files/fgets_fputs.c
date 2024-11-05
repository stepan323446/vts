#include <stdio.h>
#include <stdlib.h>

int main() {
    char *text = "Первый параметр функции - записываемая строка, а второй - указатель на файловый поток. В качестве результата функция возвращает неотрицательное целое число. При ошибках в процессе записи возвращается значение EOF.";
    FILE *fp = fopen("fgets_fputs.txt", "w");
    if(!fp) {
        printf("File not found\n");
        return -1;
    }
    fputs(text, fp);
    fclose(fp);

    FILE *fp2 = fopen("fgets_fputs.txt", "r");
    char buffer[256];
    while (fgets(buffer, 256, fp2)) {
        printf("%s", buffer);
    }
    printf("\nEnd\n");


    return 0;
}