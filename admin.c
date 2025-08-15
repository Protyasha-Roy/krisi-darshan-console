#include <stdio.h>
#include "utils.h"
#include "farmer_utils.h"
#include "menus.h"
#include "login.h"
#include "agent_utils.h"

void manage_farmers_profile()
{
    clear_screen();
    int chosenOption;

    printf("Manage farmer profiles.\n\n");

    printf("1: List of registered farmers\n");
    printf("2: Search farmer details by ID or name\n");
    printf("3: Delete farmer profile by ID\n");
    printf("4: Add new farmer\n");
    printf("5: Back\n\n");

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
        registration();
        break;
    case 5:
        clear_screen();
        adminMenu();
        break;
    default:
        printf("Invalid Option chosen!\n");
        break;
    }
}

void manage_field_agents() {
    clear_screen();
    int chosenOption;

    printf("Manage field agents.\n\n");

    printf("1: View field agents\n");
    printf("2: Search field agents\n");
    printf("3: Add new field agent\n");
    printf("4: Update field agent\n");
    printf("5: Delete field agent\n");
    printf("6: Back\n\n");

    printf("Choose an option: ");
    scanf("%d", &chosenOption);

    switch(chosenOption)
    {
    case 1:
       list_agents();
       break;
    case 2:
        search_agent();
        break;
    case 3:
        add_agent();
        break;
    case 4:
        update_agent();
        break;
    case 5:
        delete_agent();
        break;
    case 6:
        clear_screen();
        adminMenu();
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
