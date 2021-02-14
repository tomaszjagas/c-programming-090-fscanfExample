#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

int main() {
    FILE *fp = NULL;
    char buff[100];
    char words[MAX];

    char *str = "Tomasz Jagas 36";
    char name[10], surname [10];
    int age = 0, ret = 0;

    ret = sscanf(str, "%s %s %d", name, surname, &age);

    printf("Name: %s\n", name);
    printf("Surname: %s\n", surname);
    printf("Age: %d\n", age);

    fp = fopen("testFile.txt", "r");

    while (fscanf(fp, "%s", buff) != EOF) {
        printf("%s ", buff);
    }

    fclose(fp);

    if ((fp = fopen("testFile.txt", "a+")) == NULL) {
        fprintf(stdout, "Can't open file.\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(fp, "%s", buff) != EOF) {
        printf("%s ", buff);
    }

    puts("\nEnter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");

    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#')) {
        fprintf(fp, "%s\n", words);
    }

    puts("File contents:");
    rewind(fp); // go back to beginning of the file
    while (fscanf(fp, "%s", words) == 1) {
        puts(words);
    } 

    puts("Done!");

    if (fclose(fp) != 0) {
        fprintf(stderr, "Error closing file\n");
    }

    return 0;
}