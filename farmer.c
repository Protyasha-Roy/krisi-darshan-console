#include <stdio.h>
#include <string.h>
#include "application_schemes.h"
#include "farmer_utils.h"
#include "menus.h"
#include "login.h"
#include "farmer.h"
#include "parcels.h"
#include "utils.h"


void personal_details(int id)
{
    FILE *fp = fopen("Farmers.txt", "r");

    if(fp==NULL)
    {
        printf("Error! File not found.\n");
        return;
    }

    Farmer f;

    int id_matched=0;

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
            id_matched=1;

            printf("\t\t PERSONAL DETAILS OF FARMER %d\n", id);
            printf("1.Full name:  %s\n", f.fullName);
            printf("2.Date of birth:  %s\n", f.dob);
            printf("3.Gender:  %c\n", f.gender);
            printf("4.NID:  %s\n", f.nid);
            printf("5.Literacy level:  %s\n", f.literacy);
            printf("6.Mobile Number:  %s\n", f.mobile);
            printf("7.Email address:  %s\n", f.email);
            printf("8.Address:  %s\n", f.address);
            printf("9.Postal Code:  %d\n", f.postal_code);
            printf("10.Farming Experience:  %.2f\n", f.farming_experience);
            printf("11.Area of Land Parcels:  %.2f\n", f.area);
            printf("12.Number of Land Parcels:  %d\n", f.land_parcels);
            printf("13,Types of crops:  %s\n", f.crops);
            printf("14.Ownership Type:  %c\n", f.ownership);
            printf("15.Bank Account Number:  %s\n", f.bank_number);
            printf("16.Bank Name:  %s\n", f.bank_name);
            printf("17.Branch Code:  %d\n", f.branch_code);
            printf("18.Linked Number to the Bank:  %s\n", f.linked_number);
            break;
        }
    }

    fclose(fp);

    if(id_matched)
    {
        edit_personaldetails(f);
    }
    else
    {
        printf("Farmer with ID %d not found in the system! \n", id);
    }

}

void farmer_land_parcels (int id)
{
    FILE *fp = fopen("Parcels.txt", "r");

    if(fp==NULL)
    {
        printf("Error! File not found.\n");
        return;
    }

    Parcel p;

    int id_matched=0;

    printf("\t\t LAND PARCEL DETAILS OF FARMER %d\n", id);

    while((fscanf(fp, "%d|%d|%99[^|]|%f|%14[^|]|%29[^|]|%29[^\n]\n",
                  &p.id,
                  &p.farmerId,
                  p.location,
                  &p.area,
                  p.dop,
                  p.soilType,
                  p.crops) ==7 ))
    {
        if(p.farmerId==id)
        {
            id_matched=1;
            printf("Parcel ID:  %d\n", p.id);
            printf("1.Location of the parcel:  %s\n", p.location);
            printf("2.Area (in acres):  %.2f\n", p.area);
            printf("3.Date of Purchase (YYYY-MM-DD):  %s\n", p.dop);
            printf("4.Soil Type:  %s\n", p.soilType);
            printf("5.Type of crops grown:  %s\n", p.crops);
            printf("\n");
        }
    }

    fclose(fp);
    getchar();

    if(id_matched==1)
    {
        printf("\n");
        parcel_AddEditDeleteMenu(id);
    }
    else
    {
        printf("No parcel found for Farmer %d in the system! \n", id);
    }
}

void application_schemes(int id)
{
    while(1)
    {
    int chosen_option;
    printf("Which scheme do you want to apply for: \n1.Loan \n2.Subsidy : ");
    scanf("%d", &chosen_option);

    switch(chosen_option)
    {
    case 1:
        loan_application(id);
        break;
    case 2:
        subsidy_application(id);
        break;
    default:
        printf("Error! Please enter either 1 or 2: ");
        continue;
    }
    break;
    }
}

void chatbot()
{
    printf("Welcome to the chatbot.");
}

void track_cropcycle(int id)
{
    printf("Crop Cycle Tracking for Farmer ID %d\n", id);
}
