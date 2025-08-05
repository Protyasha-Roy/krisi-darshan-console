#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear_screen() {
    printf("\033[2J\033[H");
    fflush(stdout);
}

int generateId(int lower, int upper) {
    srand(time(NULL));

    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}
