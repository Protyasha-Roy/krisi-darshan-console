#include <stdio.h>
#include "login.h"

void loginMenu()
{
    int chosenOption;

    printf("1: Login as a farmer\n");
    printf("2: Login as a field agent.\n");
    printf("3: Login as an admin.\n");
    printf("4: Register as a farmer.\n");
    printf("5: Get information.\n");
    printf("6: Exit.\n\n");

    printf("Choose an option: ");
    scanf("%d", &chosenOption);

    if((chosenOption >= 1) && (chosenOption <= 3))
    {
        loginForm(chosenOption);
    }
    else if(chosenOption == 4) {
        printf("Register");
    }
    else if(chosenOption == 5)
    {
        printf("Get information");
    }
    else if(chosenOption == 6)
    {
        printf("Exit");
    }
    else
    {
        printf("Please enter a valid option(1-6).");
    }
}
