#include <stdio.h>
#include <string.h>

int change(char* dir, char* token) {
    FILE *fptr;
    fptr = fopen(dir, "w");

    if(fptr == NULL) {
        printf("File not found!");
        return -1;
    }

    fprintf(fptr, token);
    fclose(fptr);
    return 0;
}

void help() {
    printf("-c change token\n");
}


int main(int argc, char *argv[]) {
    char dir[100];
    strcpy(dir, "/home/petko/Dev/envs/");
    char target[] = "token";
    strcat(dir, target);

    if(argc > 1) {
        for(int i = 1; i < argc; i++) {
            if(strcmp("-c", argv[i]) == 0) {
                i+=1;
                change(dir, argv[i]);
            }

            if (strcmp("-h", argv[i]) == 0) help();
        }
        return 0;
    }
    printf("%s\n\n", dir);
    FILE *fptr;
    fptr = fopen(dir, "r");

    if(fptr == NULL) {
        printf("File not found!\n");
        return -1;
    }

    char content[41];
    fgets(content, 41, fptr);
    printf("Token: %s\n", content);
    fclose(fptr);
    return 0;
}