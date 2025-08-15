#include <stdio.h>
#include "parcels.h"
#include "crops_details.h"
#include "login.h"
#include "farmer.h"
#include "agents.h"
#include "admin.h"
#include "utils.h"
#include "info.h"
#include "menus.h"
#include <stdlib.h>


void adminMenu()
{
    int chosenOption;

    printf("1: Manage farmer's profiles\n");
    printf("2: Manage land parcels\n");
    printf("3: Apply for loans and subsidy\n");
    printf("4: Manage field agents\n");
    printf("5: Configuration and analytics\n");
    printf("6: Back.\n\n");

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
        manage_field_agents();
        break;
    case 5:
        configuration();
        break;
    case 6:
        clear_screen();
        loginMenu();
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
    else if(chosenOption == 4)
    {
        registration();
    }
    else if(chosenOption == 5)
    {
        get_info();
    }
    else if(chosenOption == 6)
    {
        exit(0);
    }
    else
    {
        printf("Please enter a valid option(1-6).\n");
        loginMenu();
    }
}

void FarmerMenu(int id)
{
    int selected_option;

    printf("1: View my personal details\n");
    printf("2: View Land Parcels\n");
    printf("3: Apply for Loan or Subsidy\n");
    printf("4: Talk to our ChatBot\n");
    printf("5: Track my crop cycle\n");
    printf("6: Change my password\n");
    printf("7: Go back\n\n");

    while (1)
    {

        printf("Choose an option: ");
        scanf("%d", &selected_option);

        switch(selected_option)
        {
        case 1:
            personal_details(id);
            break;
        case 2:
            farmer_land_parcels(id);
            break;
        case 3:
            application_schemes(id);
            break;
        case 4:
            chatbot();
            break;
        case 5:
            track_cropcycle(id);
            break;
        case 6:
            change_password(id);
            break;
        case 7:
            clear_screen();
            loginMenu();
            break;
        default:
            printf("Error! Please enter a valid option!\n");
            continue;
        }
        break;
    }
}

void AgentMenu(int id)
{
    int selected_option;

    printf("1: View assigned parcels\n");
    printf("2: Upload land parcel report\n");
    printf("3: Mange Report\n");
    printf("4: Manage schedules\n");
    printf("5: Go back\n\n");

    while (1)
    {

        printf("Choose an option: ");
        scanf("%d", &selected_option);

        switch(selected_option)
        {
        case 1:
            assigned_parcels(id);
            break;
        case 2:
            upload_report(id);
            break;
        case 3:
            manage_report(id);
            break;
        case 4:
            manage_schedules(id);
            break;
        case 5:
            clear_screen();
            loginMenu();
            break;
        default:
            printf("Error! Please enter a valid option!\n");
            continue;
        }
        break;
    }
}

void parcel_AddEditDeleteMenu(int id)
{
    int selected_option;

    printf("Choose an option: \n");

    printf("1: Add new Parcel \n");
    printf("2: Edit Parcel\n");
    printf("3: Delete Parcel\n");
    printf("4: Go back\n\n");

    while (1)
    {

        printf("Choose an option: ");
        scanf("%d", &selected_option);


        switch(selected_option)
        {
        case 1:
            clear_screen();
            add_landparcels(id);
            break;
        case 2:
            edit_landparcels(id);
            break;
        case 3:
            delete_landparcels(id);
            break;
        case 4:
            clear_screen();
            FarmerMenu(id);
            break;
        default:
            printf("Error! Please enter a valid option!\n");
            continue;
        }
        break;
    }
}

void crop_AddEditDeleteMenu(int id)
{
    int selected_option;

    printf("Choose an option: \n");

    printf("1: Add new crop details: \n");
    printf("2: Edit existing crop details: \n");
    printf("3: Delete existing crop details: \n");
    printf("4: Go back\n\n");

    while (1)
    {

        printf("Choose an option: ");
        scanf("%d", &selected_option);


        switch(selected_option)
        {
        case 1:
            clear_screen();
            add_cropdetails(id);
            break;
        case 2:
            edit_cropdetails(id);
            break;
        case 3:
            delete_cropdetails(id);
            break;
        case 4:
            clear_screen();
            FarmerMenu(id);
            break;
        default:
            printf("Error! Please enter a valid option!\n");
            continue;
        }
        break;
    }
}

void farmer_editmenu(int id)
{
    printf("\nChoose an option: \n");
    printf("1.Edit personal details: \n");
    printf("2.Go Back \n");
    printf("Enter your choice: ");

    Farmer f;

    while(1)
    {
        int selected_option;
        scanf("%d", &selected_option);
        getchar();

        switch(selected_option)
        {
        case 1:
            edit_personaldetails(f, id);
            break;
        case 2:
            clear_screen();
            FarmerMenu(id);
            break;
        default:
            printf("Error! Please enter a valid input!\n");
            continue;
        }
        break;
    }
}






