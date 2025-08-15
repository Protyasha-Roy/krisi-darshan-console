#include <stdio.h>
#include "utils.h"
#include "farmer_utils.h"
#include "menus.h"
#include "login.h"
#include "agent_utils.h"
#include "land_parcel_utils.h"
#include "loan_subsidy_utils.h"

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

void manage_field_agents()
{
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
        break;
    default:
        printf("Invalid Option chosen!\n");
        break;
    }
}

void manage_land_parcels()
{
    clear_screen();
    int chosenOption;

    printf("Manage land parcels.\n\n");

    printf("1: View  assigned land parcels\n");
    printf("2: View  unassigned land parcels\n");
    printf("3: Assign field agent for a land parcel\n");
    printf("4: Delete assigned field agent for parcel\n");
    printf("5: Back\n\n");

    printf("Choose an option: ");
    scanf("%d", &chosenOption);

    switch(chosenOption)
    {
    case 1:
        list_assigned_land_parcels();
        break;
    case 2:
        list_unassigned_land_parcels();
        break;
    case 3:
        assign_field_agent();
        break;
    case 4:
        delete_field_agent();
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

void manage_loan_subsidy()
{
    clear_screen();
    int chosenOption;
    int id;

    printf("Manage loan and subsidy.\n\n");

    printf("1: Review loan applications\n");
    printf("2: Review subsidy applications\n");
    printf("3: Back\n\n");

    printf("Choose an option: ");
    scanf("%d", &chosenOption);

    switch(chosenOption)
    {
    case 1:
        list_loan_applications();
        break;
    case 2:
        list_subsidy_applications();
        break;
    case 3:
        clear_screen();
        adminMenu();
        break;
    default:
        printf("Invalid Option chosen!\n");
        break;
    }
}

void configuration()
{
    printf("Configuration.\n");

}
