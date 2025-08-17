#include <stdio.h>
#include <stdlib.h>
#include "admin.h"
#include "menus.h"
#include "login.h"
#include "utils.h"

void view_analytics(int adminId)
{
    clear_screen();

    FILE *usersFile = fopen("Users.txt", "r");
    FILE *loanFile  = fopen("LoanApplication.txt", "r");
    FILE *subFile   = fopen("SubsidyApplication.txt", "r");
    FILE *parcFile  = fopen("Parcels.txt", "r");

    if (!usersFile)
    {
        fprintf(stderr, "Cannot open Users.txt\n");
    }
    if (!loanFile)
    {
        fprintf(stderr, "Cannot open LoanApplication.txt\n");
    }
    if (!subFile)
    {
        fprintf(stderr, "Cannot open SubsidyApplication.txt\n");
    }
    if (!parcFile)
    {
        fprintf(stderr, "Cannot open Parcels.txt\n");
    }

    int total_farmers = 0, total_admins = 0, total_agents = 0;
    int total_loan_applications = 0, total_subsidy_applications = 0, total_parcels = 0;

    User user;
    if (usersFile)
    {
        while (fscanf(usersFile, "%d %s %c", &user.id, user.password, &user.type) != EOF)
        {
            if (user.type == 'f') total_farmers++;
            else if (user.type == 'a') total_admins++;
            else if (user.type == 't') total_agents++;
        }
        fclose(usersFile);
    }

    else
    {
        fprintf(stderr, "Cannot open Users.txt\n");
    }

    if (loanFile)
    {
        int ch;
        while ((ch = fgetc(loanFile)) != EOF) if (ch == '\n') total_loan_applications++;
        fclose(loanFile);
    }
    if (subFile)
    {
        int ch;
        while ((ch = fgetc(subFile)) != EOF) if (ch == '\n') total_subsidy_applications++;
        fclose(subFile);
    }
    if (parcFile)
    {
        int ch;
        while ((ch = fgetc(parcFile)) != EOF) if (ch == '\n') total_parcels++;
        fclose(parcFile);
    }

    printf("\tANALYTICS\n");
    printf("\t _________________________\n");
    printf("\t| Total Users:         %d |\n", total_admins + total_agents + total_farmers);
    printf("\t _________________________\n");
    printf("\t| Total Farmers:       %d |\n", total_farmers);
    printf("\t _________________________\n");
    printf("\t| Total Admins:        %d |\n", total_admins);
    printf("\t _________________________\n");
    printf("\t| Total Field agents:  %d |\n", total_agents);
    printf("\t _________________________\n");
    printf("\t| Total land parcels:  %d |\n", total_parcels);
    printf("\t--------------------------\n\n");

    printf("\tAPPLICATIONS\n");
    printf("\t __________________________________\n");
    printf("\t| Total loan applications:      %d |\n", total_loan_applications);
    printf("\t-----------------------------------\n");
    printf("\t| Total subsidy applications:   %d |\n", total_subsidy_applications);
    printf("\t-----------------------------------\n");

    while (1)
    {
        int back_exit;
        printf("\t--------------------------------\n");
        printf("\t1. Go Back \n");
        printf("\t2. Exit \n");
        printf("\t--------------------------------\n\n");
        printf("\t-> Choose an option: ");
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
            printf("\n\tError! Please enter a valid input!\n\n");
            continue;
        }
        break;
    }
}
