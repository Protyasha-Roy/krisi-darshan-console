#include <stdio.h>
#include "application_schemes.h"
#include "admin.h"
#include "utils.h"
#include <string.h>
#include <stdlib.h>

void update_loan_status()
{
    FILE *fp = fopen("LoanApplication.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    Loan loan;

    int id;
    char status[30];

    printf("Enter application id: ");
    scanf("%d", &id);

    getchar();
    printf("Enter status: ");
    fgets(status, 30, stdin);

    while((fscanf(fp, "%d|%d|%99[^|]|%19[^|]|%f|%199[^|]|%14[^|]|%29[^\n]",
                  &loan.id,
                  &loan.farmerId,
                  loan.farmerName,
                  loan.mobile,
                  &loan.loan_amount,
                  loan.loan_purpose,
                  loan.date_applied,
                  loan.status) == EOF))
    {
        if(id != loan.id)
        {
            fprintf(temp, "%d|%d|%s|%s|%f|%s|%s|%s\n",
                    loan.id,
                    loan.farmerId,
                    loan.farmerName,
                    loan.mobile,
                    loan.loan_amount,
                    loan.loan_purpose,
                    loan.date_applied,
                    loan.status
                   );
        }
        else {
            strcpy(loan.status, status);

            fprintf(temp, "%d|%d|%s|%s|%f|%s|%s|%s\n",
                    loan.id,
                    loan.farmerId,
                    loan.farmerName,
                    loan.mobile,
                    loan.loan_amount,
                    loan.loan_purpose,
                    loan.date_applied,
                    loan.status
                    );
        }
    }

    fclose(fp);
    fclose(temp);

    remove("LoanApplication.txt");
    rename("temp.txt", "LoanApplication.txt");

    printf("Status updated successfully!");
}

void list_loan_applications()
{
    FILE *fp = fopen("LoanApplication.txt", "r");

    if(fp==NULL)
    {
        printf("Error! File not found.\n");
        return;
    }

    Loan loan;

    printf("\t\t APPLIED LOAN FORMS OF FARMER: %s\n", loan.farmerName);

    while((fscanf(fp, "%d|%d|%99[^|]|%19[^|]|%f|%199[^|]|%14[^|]|%29[^\n]",
                  &loan.id,
                  &loan.farmerId,
                  loan.farmerName,
                  loan.mobile,
                  &loan.loan_amount,
                  loan.loan_purpose,
                  loan.date_applied,
                  loan.status) == EOF))
    {
        printf("Application's ID:             %d\n", loan.id);
        printf("Farmer ID:                    %d\n", loan.farmerId);
        printf("Farmer name:                  %s\n", loan.farmerName);
        printf("Farmer's mobile:              %s\n", loan.mobile);
        printf("Loan Amount:                  %.2f\n", loan.loan_amount);
        printf("Loan Purpose:                 %s\n", loan.loan_purpose);
        printf("Date applied (YYYY-MM-DD):    %s\n", loan.date_applied);
        printf("Status:                       %s\n", loan.status);
        printf("\n");
    }


    fclose(fp);

    char chosenOption;

    ("OPTIONS:");
    printf("1. Update status of a loan application\n");
    printf("2. Back\n");
    printf("3. Exit\n");

    printf("Choose an option: ");
    scanf("%c", &chosenOption);

    switch(chosenOption)
    {
    case 1:
        update_loan_status();
        break;
    case 2:
        manage_loan_subsidy();
        break;
    case 3:
        exit(1);
        break;
    default:
        printf("Invalid option chosen. Please select a valid option.");
        break;
    }
}

void update_subsidy_status() {
    FILE *fp = fopen("SubsidyApplication.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    Subsidy subsidy;

    int id;
    char status[30];

    printf("Enter application id: ");
    scanf("%d", &id);

    getchar();
    printf("Enter status: ");
    fgets(status, 30, stdin);

    while((fscanf(fp, "%d|%d|%99[^|]|%19[^|]|%f|%199[^|]|%14[^|]|%29[^\n]",
                  &subsidy.id,
                  &subsidy.farmerId,
                  subsidy.farmerName,
                  subsidy.mobile,
                  &subsidy.subsidy_amount,
                  subsidy.subsidy_purpose,
                  subsidy.date_applied,
                  subsidy.status) == EOF))
    {
        if(id != subsidy.id)
        {
            fprintf(temp, "%d|%d|%s|%s|%f|%s|%s|%s\n",
                    subsidy.id,
                    subsidy.farmerId,
                    subsidy.farmerName,
                    subsidy.mobile,
                    subsidy.subsidy_amount,
                    subsidy.subsidy_purpose,
                    subsidy.date_applied,
                    subsidy.status
                   );
        }
        else {
            strcpy(subsidy.status, status);

            fprintf(temp, "%d|%d|%s|%s|%f|%s|%s|%s\n",
                    subsidy.id,
                    subsidy.farmerId,
                    subsidy.farmerName,
                    subsidy.mobile,
                    subsidy.subsidy_amount,
                    subsidy.subsidy_purpose,
                    subsidy.date_applied,
                    subsidy.status
                    );
        }
    }

    fclose(fp);
    fclose(temp);

    remove("SubsidyApplication.txt");
    rename("temp.txt", "SubsidyApplication.txt");

    printf("Status updated successfully!");
}

void list_subsidy_applications()
{
    FILE *fp = fopen("SubsidyApplication.txt", "r");

    if(fp==NULL)
    {
        printf("Error! File not found.\n");
        return;
    }

    Subsidy subsidy;

    printf("\t\t APPLIED SUBSIDY FORMS OF FARMER: %s\n", subsidy.farmerName);

    while((fscanf(fp, "%d|%d|%99[^|]|%19[^|]|%f|%199[^|]|%14[^|]|%29[^\n]",
                  &subsidy.id,
                  &subsidy.farmerId,
                  subsidy.farmerName,
                  subsidy.mobile,
                  &subsidy.subsidy_amount,
                  subsidy.subsidy_purpose,
                  subsidy.date_applied,
                  subsidy.status) == EOF))
    {
        printf("Application's ID:             %d\n", subsidy.id);
        printf("Farmer ID:                    %d\n", subsidy.farmerId);
        printf("Farmer name:                  %s\n", subsidy.farmerName);
        printf("Subsidy Purpose:                 %s\n", subsidy.mobile);
        printf("Subsidy Amount:                  %.2f\n", subsidy.subsidy_amount);
        printf("Subsidy purpose:              %s\n", subsidy.subsidy_purpose);
        printf("Date applied (YYYY-MM-DD):    %s\n", subsidy.date_applied);
        printf("Status:                       %s\n", subsidy.status);
        printf("\n");
    }


    fclose(fp);

    char chosenOption;

    ("OPTIONS:");
    printf("1. Update status of a subsidy application\n");
    printf("2. Back\n");
    printf("3. Exit\n");

    printf("Choose an option: ");
    scanf("%c", &chosenOption);

    switch(chosenOption)
    {
    case 1:
        update_subsidy_status();
        break;
    case 2:
        manage_loan_subsidy();
        break;
    case 3:
        exit(1);
        break;
    default:
        printf("Invalid option chosen. Please select a valid option.");
        break;
    }
}
