#include <stdio.h>
#include "login.h"
#include "admin.h"
#include "utils.h"

void adminMenu()
{
    int chosenOption;

    printf("1: Manage farmer's profiles.\n");
    printf("2: Manage land parcels.\n");
    printf("3: Apply for loans and subsidy.\n");
    printf("4: Configuration.\n");
    printf("5: Back.\n\n");

    printf("Choose an option: ");
    scanf("%d", &chosenOption);


    switch(chosenOption)
    {
    case 1:
       manage_farmers_profile();
       break;
    case 2:
        manage_land_parcels();
        break;
    case 3:
        apply_for_loan_and_subsidy();
        break;
    case 4:
        configuration();
        break;
    case 5:
        printf("Back\n");
        break;
    default:
        printf("Invalid Option chosen!\n");
        break;
    }

}

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
        registration();
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
