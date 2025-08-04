#include <stdio.h>
#include "login.h"

void loginMenu() {
    int chosenOption;

    printf("1: Login as a farmer\n");
    printf("2: Login as a field agent.\n");
    printf("3: Login as an admin.\n");
    printf("4: Register as a farmer.\n");
    printf("5: Get information.\n");
    printf("6: Exit.\n\n");

    printf("Choose an option: ");
    scanf("%d", &chosenOption);

    switch(chosenOption) {
    case 1:
        loginForm('F');
        break;
    case 2:
        loginForm('t');
        break;
    case 3:
        loginForm('a');
        break;
    case 4:
        loginForm('r');
        break;
    case 5:
        loginForm('i');
        break;
    case 6:
        loginForm('e');
        break;
    default:
        printf("Please enter a valid option(1-6).");
        break;
    }
}
