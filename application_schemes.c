#include <stdio.h>
#include <string.h>
#include "menus.h"
#include "login.h"
#include "farmer.h"
#include "parcels.h"
#include "utils.h"
#include "application_schemes.h"

void view_loanapplications(int id)
{
    FILE *fp = fopen("LoanApplication.txt", "r");

    if(fp==NULL)
    {
        printf("Error! File not found.\n");
        return;
    }

    Loan l;

    int id_matched=0;

    printf("\t\t APPLIED LOAN FORMS OF FARMER %d\n", id);

    while((fscanf(fp, "%d|%d|%99[^|]|%19[^|]|%f|%199[^|]|%14[^|]|%29[^\n]",
                  &l.id,
                  &l.farmerId,
                  l.farmerName,
                  l.mobile,
                  &l.loan_amount,
                  l.loan_purpose,
                  l.date_applied,
                  l.status) == EOF))
    {
        if(l.farmerId==id)
        {
            id_matched=1;
            printf("1.Loan Purpose:  %s\n", l.loan_purpose);
            printf("2.Loan Amount:  %.2f\n", l.loan_amount);
            printf("3.Date applied (YYYY-MM-DD):  %s\n", l.date_applied);
            printf("4.Status:  %s\n", l.status);
            printf("\n");
        }
    }

    fclose(fp);

    if(id_matched==0)
    {
        printf("No Loan Application Found for Farmer %d", id);

    }
    char back;
    printf("Enter \"B\" to go back: ");
    scanf("%c", &back);
    getchar();

    if(back=='b'|| back=='B')
    {
        clear_screen();
        application_schemes(id);
    }
}

void view_subsidyapplications(int id)
{
    FILE *fp2 = fopen("SubsidyApplication.txt", "r");

    if(fp2==NULL)
    {
        printf("Error! File not found.\n");
        return;
    }

    Subsidy s;

    int id_matched2=0;

    printf("\t\t APPLIED SUBSIDY FORMS OF FARMER %d\n", id);

    while((fscanf(fp2, "%d|%d|%99[^|]|%19[^|]|%f|%199[^|]|%14[^|]|%29[^\n]",
                  &s.id,
                  &s.farmerId,
                  s.farmerName,
                  s.mobile,
                  &s.subsidy_amount,
                  s.subsidy_purpose,
                  s.date_applied,
                  s.status) == EOF))
    {
        if(s.farmerId==id)
        {
            id_matched2=1;
            printf("1.Subsidy Purpose:  %s\n", s.subsidy_purpose);
            printf("2.Subsidy Amount:  %.2f\n", s.subsidy_amount);
            printf("3.Date applied (YYYY-MM-DD):  %s\n", s.date_applied);
            printf("4.Status:  %s\n", s.status);
            printf("\n");
        }
    }

    fclose(fp2);

    if(id_matched2==0)
    {
        printf("No Subsidy Application Found for Farmer %d", id);
    }
    char back;
    printf("Enter \"B\" to go back: ");
    scanf("%c", &back);
    getchar();

    if(back=='b'|| back=='B')
    {
        clear_screen();
        application_schemes(id);
    }


}

void view_appliedforms(int id)
{
    int selected_option;

    printf("\nChoose an option: \n");

    printf("1: Applied Loan Forms \n");
    printf("2: Applied Subsidy Forms \n");
    printf("3: Back \n");

    while (1)
    {

        printf("Enter your choice: ");
        scanf("%d", &selected_option);
        getchar();


        switch(selected_option)
        {
        case 1:
            view_loanapplications(id);
            break;
        case 2:
            view_subsidyapplications(id);
            break;
        case 3:
            clear_screen();
            application_schemes(id);
            break;
        default:
            printf("Error! Please enter a valid option!\n");
            continue;
        }
        break;
    }
}


void subsidy_application(int id)
{

    FILE *fp;
    fp=fopen("SubsidyApplication.txt", "a");

    if(fp==NULL)
    {
        printf("Error! File not found!\n");
    }

    Subsidy s;

    do
    {
        s.id = generateId(0, 2147483640);
    }
    while(checkIdDuplication(fp, s.id) == 1);
    s.farmerId=id;

    FILE *fp2;
    fp2=fopen("Farmers.txt", "r");

    if(fp2==NULL)
    {
        printf("Error! File not found!\n");
    }

    Farmer f;

    while((fscanf(fp, "%d|%99[^|]|%14[^|]|%c|%19[^|]|%99[^|]|%19[^|]|%49[^|]|%299[^|]|%d|%f|%f|%d|%99[^|]|%c|%29[^|]|%49[^|]|%d|%19[^\n]\n",
                  &f.id,
                  f.fullName,
                  f.dob,
                  &f.gender,
                  f.nid,
                  f.literacy,
                  f.mobile,
                  f.email,
                  f.address,
                  &f.postal_code,
                  &f.farming_experience,
                  &f.area,
                  &f.land_parcels,
                  f.crops,
                  &f.ownership,
                  f.bank_number,
                  f.bank_name,
                  &f.branch_code,
                  f.linked_number
                 ) != EOF))
    {
        if(f.id==id)
        {
            strcpy(s.farmerName, f.fullName);
            strcpy(s.mobile, f.mobile);
            break;
        }
    }
    fclose(fp2);

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter the amount of subsidy required: ");
    scanf("%f", &s.subsidy_amount);
    while ((c = getchar()) != '\n' && c != EOF);


    printf("Enter the purpose of why you require the subsidy: ");
    fgets(s.subsidy_purpose, sizeof(s.subsidy_purpose), stdin);
    s.subsidy_purpose[strcspn(s.subsidy_purpose, "\n")] = '\0';


    printf("Enter the date of the application(YYYY-MM-DD): ");
    fgets(s.date_applied, sizeof(s.date_applied), stdin);
    s.date_applied[strcspn(s.date_applied, "\n")] = '\0';

    strcpy(s.status, "Pending");


    fprintf(fp,
            "%d|%d|%s|%s|%.2f|%s|%s|%s\n",
            s.id,
            s.farmerId,
            s.farmerName,
            s.mobile,
            s.subsidy_amount,
            s.subsidy_purpose,
            s.date_applied,
            s.status);

    fclose(fp);

    printf("Subsidy application submitted successfully!\n");

    char back;
    printf("Enter \"B\" to go back: ");
    scanf("%c", &back);
    getchar();

    if(back=='b'|| back=='B')
    {
        clear_screen();
        application_schemes(id);
    }
}

void loan_application(int id)
{
    FILE *fp;
    fp=fopen("LoanApplication.txt", "a");

    if(fp==NULL)
    {
        printf("Error! File not found!\n");
    }

    Loan l;

    do
    {
        l.id = generateId(0, 2147483640);
    }
    while(checkIdDuplication(fp, l.id) == 1);

    l.farmerId=id;

    FILE *fp2;
    fp2=fopen("Farmers.txt", "r");

    if(fp2==NULL)
    {
        printf("Error! File not found!\n");
    }

    Farmer f;

    while((fscanf(fp2, "%d|%99[^|]|%14[^|]|%c|%19[^|]|%99[^|]|%19[^|]|%49[^|]|%299[^|]|%d|%f|%f|%d|%99[^|]|%c|%29[^|]|%49[^|]|%d|%19[^\n]\n",
                  &f.id,
                  f.fullName,
                  f.dob,
                  &f.gender,
                  f.nid,
                  f.literacy,
                  f.mobile,
                  f.email,
                  f.address,
                  &f.postal_code,
                  &f.farming_experience,
                  &f.area,
                  &f.land_parcels,
                  f.crops,
                  &f.ownership,
                  f.bank_number,
                  f.bank_name,
                  &f.branch_code,
                  f.linked_number
                 ) != EOF))
    {
        if(f.id==id)
        {
            strcpy(l.farmerName, f.fullName);
            strcpy(l.mobile, f.mobile);
            break;
        }
    }
    fclose(fp2);


    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter the amount of loan required: ");
    scanf("%f", &l.loan_amount);
    while ((c = getchar()) != '\n' && c != EOF);


    printf("Enter the purpose of why you require the loan: ");
    fgets(l.loan_purpose, sizeof(l.loan_purpose), stdin);
    l.loan_purpose[strcspn(l.loan_purpose, "\n")] = '\0';


    printf("Enter the date of the application(YYYY-MM-DD): ");
    fgets(l.date_applied, sizeof(l.date_applied), stdin);
    l.date_applied[strcspn(l.date_applied, "\n")] = '\0';

    strcpy(l.status, "Pending");


    fprintf(fp,
            "%d|%d|%s|%s|%.2f|%s|%s|%s\n",
            l.id,
            l.farmerId,
            l.farmerName,
            l.mobile,
            l.loan_amount,
            l.loan_purpose,
            l.date_applied,
            l.status);

    fclose(fp);

    printf("Loan application submitted successfully!\n");

    char back;
    printf("Enter \"B\" to go back: ");
    scanf("%c", &back);
    getchar();

    if(back=='b'|| back=='B')
    {
        clear_screen();
        application_schemes(id);
    }
}

