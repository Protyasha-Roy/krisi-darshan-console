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

    printf("Manage farmer profiles.\n\n");

    printf("1: List of registered farmers\n");
    printf("2: Search farmer details by ID or name\n");
    printf("3: Delete farmer profile by ID\n");
    printf("4: Add new farmer\n");
    printf("5: Back\n");
    printf("6. Exit\n\n");

    printf("Choose an option: ");
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
        printf("Invalid Option chosen!\n");
        break;
    }
}

void manage_field_agents(int adminId)
{
    clear_screen();
    int chosenOption;

    printf("Manage field agents.\n\n");

    printf("1: View field agents\n");
    printf("2: Search field agents\n");
    printf("3: Add new field agent\n");
    printf("4: Update field agent\n");
    printf("5: Delete field agent\n");
    printf("6: Back\n");
    printf("7. Exit\n\n");

    printf("Choose an option: ");
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
        printf("Invalid Option chosen!\n");
        break;
    }
}

void manage_land_parcels(int adminId)
{
    clear_screen();
    int chosenOption;

    printf("Manage land parcels.\n\n");

    printf("1: View  assigned land parcels\n");
    printf("2: View  unassigned land parcels\n");
    printf("3: Assign field agent for a land parcel\n");
    printf("4: Delete assigned field agent for parcel\n");
    printf("5: Back\n");
    printf("6. Exit\n\n");

    printf("Choose an option: ");
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
        printf("Invalid Option chosen!\n");
        break;
    }
}

void manage_loan_subsidy(int adminId)
{
    clear_screen();
    int chosenOption;

    printf("Manage loan and subsidy.\n\n");

    printf("1: Review loan applications\n");
    printf("2: Review subsidy applications\n");
    printf("3: Back\n");
    printf("4. Exit\n");

    while(1)
    {
        printf("Choose an option: ");
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
            printf("Error! Please enter a valid option!\n");
            continue;
        }
        break;
    }
}

void configuration(int adminId)
{
    clear_screen();

    int chosenOption;

    printf("CONFIGURATION AND ANALYTICS\n");
    printf("1. View analytics\n");
    printf("2. Change your password\n");
    printf("3. Back\n");
    printf("4. Exit\n\n");

    getchar();
    printf("Choose an option: ");
    scanf("%d", &chosenOption);

    switch(chosenOption)
    {
    case 1:
        view_analytics(adminId);
        break;
    case 2:
        changePass(adminId);

            while (1)
            {
                int back_exit;
                printf("\nChoose an option: \n");
                printf("1. 'B' - Go back\n2. 'E' - Exit: \n");
                printf("Enter you choice: ");
                scanf("%d", &back_exit);
                getchar();

                switch(back_exit)
                {
                case 1:
                    clear_screen();
                    adminMenu(adminId);
                    break;
                case 2:
                    exit(1);
                    break;
                default:
                    printf("Error! Please enter a valid option!");
                    continue;
                }
                break;
            }
        break;
    case 3:
        clear_screen();
        adminMenu(adminId);
        break;
    case 4:
        exit(1);
        break;
    default:
        printf("Invalid option chosen.\n");
        break;
    }

}
