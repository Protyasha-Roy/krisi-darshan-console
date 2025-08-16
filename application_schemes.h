#ifndef APPLICATION_SCHEMES_H_INCLUDED
#define APPLICATION_SCHEMES_H_INCLUDED

typedef struct
{
    int id;
    int parcelId;
    int farmerId;
    char farmerName[100];
    char mobile[20];
    float loan_amount;
    char loan_purpose[200];
    char date_applied[15];
    char status[30];
}Loan;

typedef struct
{
    int id;
    int parcelId;
    int farmerId;
    char farmerName[100];
    char mobile[20];
    float subsidy_amount;
    char subsidy_purpose[200];
    char date_applied[15];
    char status[30];
}Subsidy;

void loan_application(int id);
void subsidy_application(int id);
void view_appliedforms(int id);
void view_loanapplications(int id);
void view_subsidyapplications(int id);



#endif // APPLICATION_SCHEMES_H_INCLUDED
