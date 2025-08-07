#include <stdio.h>
#include "utils.h"
#include "admin_utils.h"

void manage_farmers_profile()
{
    clear_screen();
    int chosenOption;

    printf("Manage farmer profiles.\n\n");

    printf("1: List of registered farmers\n");
    printf("2: Search farmer details by ID or name\n");
    printf("3: Delete farmer profile by ID\n");
    printf("4: Back\n\n");

    printf("Choose an option: ");
    scanf("%d", &chosenOption);


    switch(chosenOption)
    {
    case 1:
       list_farmers();
       break;
    case 2:
        search_farmer();
        break;
    case 3:
        delete_farmer();
        break;
    case 4:
        printf("Back\n");
        break;
    default:
        printf("Invalid Option chosen!\n");
        break;
    }
}

void manage_land_parcels()
{
    printf("Manage land parcels.\n");

}

void apply_for_loan_and_subsidy()
{
    printf("Apply for loan and subsidy.\n");

}

void configuration()
{
    printf("Configuration.\n");

}
