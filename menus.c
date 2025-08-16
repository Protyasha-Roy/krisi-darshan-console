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


void adminMenu(int id)
{
    int chosenOption;

    printf("\n\t-------------------------------------\n");
    printf("\t1: Manage farmer's profiles\n");
    printf("\t2: Manage land parcels\n");
    printf("\t3: Manage loan and subsidy\n");
    printf("\t4: Manage field agents\n");
    printf("\t5: Configuration and analytics\n");
    printf("\t6: Back.\n");
    printf("\t7. Exit\n");
    printf("\t---------------------------------------\n\n");

    printf("\t-> Choose an option: ");
    scanf("%d", &chosenOption);

    switch(chosenOption)
    {
    case 1:
        clear_screen();
        manage_farmers_profile(id);
        break;
    case 2:
        clear_screen();
        manage_land_parcels(id);
        break;
    case 3:
        clear_screen();
        manage_loan_subsidy(id);
        break;
    case 4:
        clear_screen();
        manage_field_agents(id);
        break;
    case 5:
        clear_screen();
        configuration(id);
        break;
    case 6:
        clear_screen();
        loginMenu();
        break;
    case 7:
        exit(1);
        break;
    default:
        printf("\n\tInvalid Option chosen!\n\n");
        break;
    }

}

void loginMenu()
{
    int chosenOption;

    printf("\t_________________________________________\n");
    printf("\t|\t1: Login as a farmer\t\t|\n");
    printf("\t|\t2: Login as a field agent\t|\n");
    printf("\t|\t3: Login as an admin\t\t|\n");
    printf("\t|\t4: Register as a farmer\t\t|\n");
    printf("\t|\t5: Get information\t\t|\n");
    printf("\t|\t6: Exit\t\t\t\t|\n");
    printf("\t-----------------------------------------\n\n");

    printf("\t\t-> Choose an option: ");
    scanf("%d", &chosenOption);

    if((chosenOption >= 1) && (chosenOption <= 3))
    {
        clear_screen();
        loginForm(chosenOption);
    }
    else if(chosenOption == 4)
    {
        clear_screen();
        registration();
    }
    else if(chosenOption == 5)
    {
        clear_screen();
        get_info();
    }
    else if(chosenOption == 6)
    {
        exit(0);
    }
    else
    {
        printf("\n\tPlease enter a valid option(1-6).\n\n");
        loginMenu();
    }
}

void FarmerMenu(int id)
{
    int selected_option;

    printf("\t---------------------------------\n");
    printf("\t| 1: View my personal details\t|\n");
    printf("\t| 2: View Land Parcels\t\t|\n");
    printf("\t| 3: Apply for Loan or Subsidy\t|\n");
    printf("\t| 4: Talk to our ChatBot\t|\n");
    printf("\t| 5: Track my crop cycle\t|\n");
    printf("\t| 6: Change my password\t\t|\n");
    printf("\t| 7: Go back\t\t\t|\n");
    printf("\t| 8. Exit\t\t\t|\n");
    printf("\t---------------------------------\n\n");

    while (1)
    {

        printf("\t-> Choose an option: ");
        scanf("%d", &selected_option);

        switch(selected_option)
        {
        case 1:
            clear_screen();
            personal_details(id);
            break;
        case 2:
            clear_screen();
            farmer_land_parcels(id);
            break;
        case 3:
            clear_screen();
            application_schemes(id);
            break;
        case 4:
            clear_screen();
            chatbot(id);
            break;
        case 5:
            clear_screen();
            track_cropcycle(id);
            break;
        case 6:
            clear_screen();
            changePass(id);

            while (1)
            {
                int back_exit;
                printf("\nChoose an option: \n");
                printf("1. Go back\n2. Exit: \n");
                printf("Enter you choice: ");
                scanf("%d", &back_exit);
                getchar();

                switch(back_exit)
                {
                case 1:
                    clear_screen();
                    FarmerMenu(id);
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
        case 7:
            clear_screen();
            loginMenu();
            break;
        case 8:
            exit(1);
            break;
        default:
            printf("\n\tError! Please enter a valid option!\n\n");
            continue;
        }
        break;
    }
}


void AgentMenu(int id)
{
    int selected_option;


    printf("\t---------------------------------------\n");
    printf("\t1: View assigned parcels\n");
    printf("\t2: Upload land parcel report\n");
    printf("\t3: Mange Report\n");
    printf("\t4: Manage schedules\n");
    printf("\t5: Go back\n");
    printf("\t6. Exit\n");
    printf("\t---------------------------------------\n\n");

    while (1)
    {

        printf("\t-> Choose an option: ");
        scanf("%d", &selected_option);

        switch(selected_option)
        {
        case 1:
            clear_screen();
            assigned_parcels(id);
            break;
        case 2:
            clear_screen();
            upload_report(id);
            break;
        case 3:
            clear_screen();
            manage_report(id);
            break;
        case 4:
            clear_screen();
            manage_schedules(id);
            break;
        case 5:
            clear_screen();
            loginMenu();
            break;
        case 6:
            exit(1);
            break;
        default:
            printf("\n\tError! Please enter a valid option!\n\n");
            continue;
        }
        break;
    }
}

void parcel_AddEditDeleteMenu(int id)
{
    int selected_option;

    printf("\t---------------------------\n");
    printf("\t1: Add new Parcel \n");
    printf("\t2: Edit Parcel\n");
    printf("\t3: Delete Parcel\n");
    printf("\t4: Go back\n");
    printf("\t5. Exit\n");
    printf("\t---------------------------\n\n");

    while (1)
    {

        printf("\t-> Choose an option: ");
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
        case 5:
            exit(1);
            break;
        default:
            printf("\n\tError! Please enter a valid option!\n\n");
            continue;
        }
        break;
    }
}

void crop_AddEditDeleteMenu(int id)
{
    int selected_option;

    printf("\t--------------------------------------------\n");
    printf("\t1: Add new crop details: \n");
    printf("\t2: Edit existing crop details: \n");
    printf("\t3: Delete existing crop details: \n");
    printf("\t4: Go back\n");
    printf("\t5. Exit\n");
    printf("\t--------------------------------------------\n\n");


    while (1)
    {

        printf("\t-> Choose an option: ");
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
        case 5:
            exit(1);
            break;
        default:
            printf("\n\tError! Please enter a valid option!\n\n");
            continue;
        }
        break;
    }
}

void farmer_editmenu(int id)
{
    printf("\t--------------------------------\n");
    printf("\t1. Edit personal details: \n");
    printf("\t2. Go Back \n");
    printf("\t3. Exit \n");
    printf("\t--------------------------------\n\n");

    printf("\t-> Enter your choice: ");

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
        case 3:
            exit(1);
            break;
        default:
            printf("\n\tError! Please enter a valid input!\n\n");
            continue;
        }
        break;
    }
}






