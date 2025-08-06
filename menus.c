#include <stdio.h>
#include "login.h"
#include "farmer.h"
#include "agents.h"

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

void FarmerMenu(int id)
{
    int selected_option;

    printf("1: View my personal details\n");
    printf("2: View Land Parcels\n");
    printf("3: Apply for Loan or Subsidy\n");
    printf("4: Talk to our ChatBot\n");
    printf("5: Track my crop cycle\n");
    printf("6: Go back\n\n");

    printf("Choose an option: ");
    scanf("%d", &selected_option);

    switch(selected_option)
    {
    case 1:
        personal_details(id);
        break;
    case 2:
        land_parcels(id);
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
        printf("BACK");
        break;
    default:
        printf("Please enter a valid option(1-6).");
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
        printf("BACK");
        break;
    default:
        printf("Please enter a valid option(1-5).");
        break;
    }
}



