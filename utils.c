#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "utils.h"

int checkIdDuplication(FILE *fp2, int farmerId) {
    int id;
    while(fscanf(fp2, "%d", &id) != EOF) {
        if(id != farmerId) {
            return 0;
        }
        else {
            return 1;
        }
    }
}


void clear_screen() {
    printf("\033[2J\033[H");
    fflush(stdout);
}

int generateId(int lower, int upper) {
    srand(time(NULL));

    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

char *lowercased_str(char str[]) {
    for(int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
    str[strlen(str)] = '\0';

    return str;
}
