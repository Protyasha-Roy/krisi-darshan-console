#include <stdio.h>
#include "login.h"

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
           printf("ID:  %d\n", f.id);
           printf("Full name:  %s\n", f.fullName);
           printf("Date of birth:  %s\n", f.dob);
           printf("Gender:  %c\n", f.gender);
           printf("NID:  %s\n", f.nid);
           printf("Literacy level:  %s\n", f.literacy);
           printf("Mobile Number:  %s\n", f.mobile);
           printf("Email address:  %s\n", f.email);
           printf("Address:  %s\n", f.address);
           printf("Postal Code:  %d\n", f.postal_code);
           printf("Farming Experience:  %.2f\n", f.farming_experience);
           printf("Area of Land Parcels:  %.2f\n", f.area);
           printf("Number of Land Parcels:  %d\n", f.land_parcels);
           printf("Types of crops:  %s\n", f.crops);
           printf("Ownership Type:  %c\n", f.ownership);
           printf("Bank Account Number:  %s\n", f.bank_number);
           printf("Bank Name:  %s\n", f.bank_name);
           printf("Branch Code:  %d\n", f.branch_code);
           printf("Linked Number to the Bank:  %s\n", f.linked_number);
           break;
       }
   }

   fclose(fp);

   if(!id_matched)
   {
       printf("Farmer with ID %d not found in the system! \n", id);
   }

}

void land_parcels (int id)
{
    printf("Land Parcels for Farmer ID %d\n", id);
}

void application_schemes(int id)
{
    printf("Application");
}

void chatbot()
{
    printf("Welcome to the chatbot.");
}

void track_cropcycle(int id)
{
    printf("Crop Cycle Tracking for Farmer ID %d\n", id);
}
