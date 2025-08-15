#include <stdio.h>
#include "login.h"
#include "utils.h"

void view_analytics(void)
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

    printf("ANALYTICS\n");
    printf(" _________________________\n");
    printf("| Total Users:         %d |\n", total_admins + total_agents + total_farmers);
    printf(" _________________________\n");
    printf("| Total Farmers:       %d |\n", total_farmers);
    printf(" _________________________\n");
    printf("| Total Admins:        %d |\n", total_admins);
    printf(" _________________________\n");
    printf("| Total Field agents:  %d |\n", total_agents);
    printf(" _________________________\n");
    printf("| Total land parcels:  %d |\n", total_parcels);
    printf("--------------------------\n\n");

    printf("APPLICATIONS\n");
    printf(" __________________________________\n");
    printf("| Total loan applications:      %d |\n", total_loan_applications);
    printf("-----------------------------------\n");
    printf("| Total subsidy applications:   %d |\n", total_subsidy_applications);
    printf("-----------------------------------\n");
}
