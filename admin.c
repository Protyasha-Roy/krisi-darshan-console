#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "farmer_utils.h"
#include "menus.h"
#include "login.h"
#include "agent_utils.h"
#include "land_parcel_utils.h"
#include "loan_subsidy_utils.h"
#include "config_utils.h"

void manage_farmers_profile(int adminId)
{
    clear_screen();
    int chosenOption;

    printf("\t\t-MANAGE FARMER PROFILES-\n\n");
    printf("\t---------------------------------------------\n");
    printf("\t1: List of registered farmers\n");
    printf("\t2: Search farmer details by ID or name\n");
    printf("\t3: Delete farmer profile by ID\n");
    printf("\t4: Add new farmer\n");
    printf("\t5: Back\n");
    printf("\t6. Exit\n\n");
    printf("\t----------------------------------------------\n");

    printf("\t-> Choose an option: ");
    scanf("%d", &chosenOption);


    switch(chosenOption)
    {
    case 1:
        list_farmers(adminId);
        break;
    case 2:
        search_farmer(adminId);
        break;
    case 3:
        delete_farmer(adminId);
        break;
    case 4:
        registration();
        break;
    case 5:
        clear_screen();
        adminMenu(adminId);
        break;
    case 6:
        exit(1);
        break;
    default:
        printf("\n\tInvalid Option chosen!\n\n");
        break;
    }
}

void manage_field_agents(int adminId)
{
    clear_screen();
    int chosenOption;

    printf("\tMANAGE FIELD AGENTS\n\n");

    printf("\t---------------------------------\n");
    printf("\t1: View field agents\n");
    printf("\t2: Search field agents\n");
    printf("\t3: Add new field agent\n");
    printf("\t4: Update field agent\n");
    printf("\t5: Delete field agent\n");
    printf("\t6: Back\n");
    printf("\t7. Exit\n");
    printf("\t---------------------------------\n\n");

    printf("\t-> Choose an option: ");
    scanf("%d", &chosenOption);

    switch(chosenOption)
    {
    case 1:
        list_agents(adminId);
        break;
    case 2:
        search_agent(adminId);
        break;
    case 3:
        add_agent(adminId);
        break;
    case 4:
        update_agent(adminId);
        break;
    case 5:
        delete_agent(adminId);
        break;
    case 6:
        clear_screen();
        adminMenu(adminId);
        break;
    case 7:
        exit(1);
        break;
    default:
        printf("\n\tInvalid Option chosen!\n\n");
        break;
    }
}

void manage_land_parcels(int adminId)
{
    clear_screen();
    int chosenOption;

    printf("\tMANAGE LAND PARCELS\n\n");

    printf("\t--------------------------------------------n");
    printf("\t1: View  assigned land parcels\n");
    printf("\t2: View  unassigned land parcels\n");
    printf("\t3: Assign field agent for a land parcel\n");
    printf("\t4: Delete assigned field agent for parcel\n");
    printf("\t5: Back\n");
    printf("\t6. Exit\n");
    printf("\t--------------------------------------------n");

    printf("\t-> Choose an option: ");
    scanf("%d", &chosenOption);

    switch(chosenOption)
    {
    case 1:
        list_assigned_land_parcels(adminId);
        break;
    case 2:
        list_unassigned_land_parcels(adminId);
        break;
    case 3:
        assign_field_agent(adminId);
        break;
    case 4:
        delete_field_agent(adminId);
        break;
    case 5:
        clear_screen();
        adminMenu(adminId);
        break;
    case 6:
        exit(1);
        break;
    default:
        printf("\n\tInvalid Option chosen!\n\n");
        break;
    }
}

void manage_loan_subsidy(int adminId)
{
    clear_screen();
    int chosenOption;

    printf("\tMANAGE LOAN AND SUBSIDY\n\n");

    printf("\t-----------------------------------\n");
    printf("\t1: Review loan applications\n");
    printf("\t2: Review subsidy applications\n");
    printf("\t3: Back\n");
    printf("\t4. Exit\n");
    printf("\t-----------------------------------\n");

    while(1)
    {
        printf("\t-> Choose an option: ");
        scanf("%d", &chosenOption);
        getchar();

        switch(chosenOption)
        {
        case 1:
            list_loan_applications(adminId);
            break;
        case 2:
            list_subsidy_applications(adminId);
            break;
        case 3:
            clear_screen();
            adminMenu(adminId);
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("\n\tError! Please enter a valid option!\n\n");
            continue;
        }
        break;
    }
}

void configuration(int adminId)
{
    clear_screen();

    int chosenOption;

    printf("\tCONFIGURATION AND ANALYTICS\n");

    printf("\t------------------------------\n");
    printf("\t1. View analytics\n");
    printf("\t2. Change your password\n");
    printf("\t3. Back\n");
    printf("\t4. Exit\n");
    printf("\t------------------------------\n");

    getchar();
    printf("\t-> Choose an option: ");
    scanf("%d", &chosenOption);

    switch(chosenOption)
    {
    case 1:
        view_analytics(adminId);
        break;
    case 2:
        changePass(adminId);
        break;
    case 3:
        clear_screen();
        adminMenu(adminId);
        break;
    case 4:
        exit(1);
        break;
    default:
        printf("\n\tInvalid option chosen.\n\n");
        break;
    }

}
