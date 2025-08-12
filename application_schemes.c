#include <stdio.h>
#include <string.h>
#include "menus.h"
#include "login.h"
#include "farmer.h"
#include "parcels.h"
#include "utils.h"
#include "application_schemes.h"

void subsidy_application(int id)
{

    FILE *fp;
    fp=fopen("SubsidyApplication.txt", "a");

    if(fp==NULL)
    {
        printf("Error! File not found!\n");
    }

    Subsidy s;

    s.farmerId=id;

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter your full name: ");
    fgets(s.farmerName, sizeof(s.farmerName), stdin);
    s.farmerName[strcspn(s.farmerName, "\n")] = '\0';


    printf("Enter your mobile number: ");
    fgets(s.mobile, sizeof(s.mobile), stdin);
    s.mobile[strcspn(s.mobile, "\n")] = '\0';


    printf("Enter the amount of subsidy required: ");
    scanf("%f", &s.subsidy_amount);
    while ((c = getchar()) != '\n' && c != EOF);


    printf("Enter the purpose of why you require the subsidy: ");
    fgets(s.subsidy_purpose, sizeof(s.subsidy_purpose), stdin);
    s.subsidy_purpose[strcspn(s.subsidy_purpose, "\n")] = '\0';


    printf("Enter the date of the application(YYYY-MM-DD): ");
    fgets(s.date_applied, sizeof(s.date_applied), stdin);
    s.date_applied[strcspn(s.date_applied, "\n")] = '\0';


    fprintf(fp,
        "%d|%s|%s|%.2f|%s|%s\n",
        s.farmerId,
        s.farmerName,
        s.mobile,
        s.subsidy_amount,
        s.subsidy_purpose,
        s.date_applied);

    fclose(fp);

    printf("Subsidy application submitted successfully!\n");
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

    l.farmerId=id;

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter your full name: ");
    fgets(l.farmerName, sizeof(l.farmerName), stdin);
    l.farmerName[strcspn(l.farmerName, "\n")] = '\0';

    printf("Enter your mobile number: ");
    fgets(l.mobile, sizeof(l.mobile), stdin);
    l.mobile[strcspn(l.mobile, "\n")] = '\0';

    printf("Enter the amount of loan required: ");
    scanf("%f", &l.loan_amount);
    while ((c = getchar()) != '\n' && c != EOF);


    printf("Enter the purpose of why you require the loan: ");
    fgets(l.loan_purpose, sizeof(l.loan_purpose), stdin);
    l.loan_purpose[strcspn(l.loan_purpose, "\n")] = '\0';


    printf("Enter the date of the application(YYYY-MM-DD): ");
    fgets(l.date_applied, sizeof(l.date_applied), stdin);
    l.date_applied[strcspn(l.date_applied, "\n")] = '\0';



    fprintf(fp,
        "%d|%s|%s|%.2f|%s|%s\n",
        l.farmerId,
        l.farmerName,
        l.mobile,
        l.loan_amount,
        l.loan_purpose,
        l.date_applied);

    fclose(fp);

    printf("Loan application submitted successfully!\n");
}
