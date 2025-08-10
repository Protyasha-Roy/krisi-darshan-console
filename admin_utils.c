#include <stdio.h>
#include "login.h"
#include <string.h>
#include "utils.h"

void list_farmers()
{
    FILE *fp = fopen("Farmers.txt", "r");
    Farmer farmer;

    printf("ID\tNAME\tDOB\tGENDER\tNID\tLITERACY\tMOBILE\tEMAIL\tADDRESS\tPOSTAL\tEXPERIENCE\tAREA\tPARCELS\tCROPS\tOWNERSHIP\tBANK_NUMBER\tBANK_NAME\tBRANCH_CODE\tLINKED_NUMBER\n");
    while(fscanf(fp, "%d|%99[^|]|%14[^|]|%c|%19[^|]|%99[^|]|%19[^|]|%49[^|]|%299[^|]|%d|%f|%f|%d|%99[^|]|%c|%29[^|]|%49[^|]|%d|%19[^\n]\n",
                 &farmer.id,
                 farmer.fullName,
                 farmer.dob,
                 &farmer.gender,
                 farmer.nid,
                 farmer.literacy,
                 farmer.mobile,
                 farmer.email,
                 farmer.address,
                 &farmer.postal_code,
                 &farmer.farming_experience,
                 &farmer.area,
                 &farmer.land_parcels,
                 farmer.crops,
                 &farmer.ownership,
                 farmer.bank_number,
                 farmer.bank_name,
                 &farmer.branch_code,
                 farmer.linked_number
                ) != EOF)
    {

        printf("%d\t%s\t%s\t%c\t%s\t%s\t%s\t%s\t%s\t%d\t%f\t%f\t%d\t%s\t%c\t%s\t%s\t%d\t%s\n",
               farmer.id,
               farmer.fullName,
               farmer.dob,
               farmer.gender,
               farmer.nid,
               farmer.literacy,
               farmer.mobile,
               farmer.email,
               farmer.address,
               farmer.postal_code,
               farmer.farming_experience,
               farmer.area,
               farmer.land_parcels,
               farmer.crops,
               farmer.ownership,
               farmer.bank_number,
               farmer.bank_name,
               farmer.branch_code,
               farmer.linked_number
              );
    }
}

void search_farmer()
{
    FILE *fp = fopen("Farmers.txt", "r");
    int id;

    char name[100];

    int id_matched = 0;

    Farmer farmer;

//    int chosen_option;
//
//    printf("1. Search by ID");
//    printf("2. Search by name");
//    scanf("%d", &chosen_option);

    clear_screen();
    printf("Enter farmer's ID: ");
    scanf("%d", &id);
//    if(chosen_option == 1) {
//    }
//    else {
//        clear_screen();
//        printf("Enter farmer's full name: ");
//        fgets(name, 100, stdin);
//        name[strcspn(name, "\n")] = '\0';
//    }

    while((fscanf(fp, "%d|%99[^|]|%14[^|]|%c|%19[^|]|%99[^|]|%19[^|]|%49[^|]|%299[^|]|%d|%f|%f|%d|%99[^|]|%c|%29[^|]|%49[^|]|%d|%19[^\n]\n",
                  &farmer.id,
                  farmer.fullName,
                  farmer.dob,
                  &farmer.gender,
                  farmer.nid,
                  farmer.literacy,
                  farmer.mobile,
                  farmer.email,
                  farmer.address,
                  &farmer.postal_code,
                  &farmer.farming_experience,
                  &farmer.area,
                  &farmer.land_parcels,
                  farmer.crops,
                  &farmer.ownership,
                  farmer.bank_number,
                  farmer.bank_name,
                  &farmer.branch_code,
                  farmer.linked_number
                 ) != EOF))
    {
        if((farmer.id==id))
        {
            id_matched = 1;

            printf("\t\t PERSONAL DETAILS OF FARMER %d\n", id);
            printf("ID:  %d\n", farmer.id);
            printf("Full name:  %s\n", farmer.fullName);
            printf("Date of birth:  %s\n", farmer.dob);
            printf("Gender:  %c\n", farmer.gender);
            printf("NID:  %s\n", farmer.nid);
            printf("Literacy level:  %s\n", farmer.literacy);
            printf("Mobile Number:  %s\n", farmer.mobile);
            printf("Email address:  %s\n", farmer.email);
            printf("Address:  %s\n", farmer.address);
            printf("Postal Code:  %d\n", farmer.postal_code);
            printf("Farming Experience:  %.2f\n", farmer.farming_experience);
            printf("Area of Land Parcels:  %.2f\n", farmer.area);
            printf("Number of Land Parcels:  %d\n", farmer.land_parcels);
            printf("Types of crops:  %s\n", farmer.crops);
            printf("Ownership Type:  %c\n", farmer.ownership);
            printf("Bank Account Number:  %s\n", farmer.bank_number);
            printf("Bank Name:  %s\n", farmer.bank_name);
            printf("Branch Code:  %d\n", farmer.branch_code);
            printf("Linked Number to the Bank:  %s\n", farmer.linked_number);
            break;
        }
    }

    fclose(fp);

    if(!id_matched)
    {
        printf("Farmer with ID %d not found in the system! \n", id);
    }
}

void delete_farmer()
{
    FILE *fp = fopen("Farmers.txt", "r");
    FILE *temp = fopen("Temp.txt", "w");

    FILE *fp2 = fopen("Users.txt", "r");
    FILE *temp2 = fopen("Temp2.txt", "w");

    int id;
    int id_matched = 0;

    Farmer farmer;
    User user;

    while((fscanf(fp, "%d|%99[^|]|%14[^|]|%c|%19[^|]|%99[^|]|%19[^|]|%49[^|]|%299[^|]|%d|%f|%f|%d|%99[^|]|%c|%29[^|]|%49[^|]|%d|%19[^\n]\n",
                  &farmer.id,
                  farmer.fullName,
                  farmer.dob,
                  &farmer.gender,
                  farmer.nid,
                  farmer.literacy,
                  farmer.mobile,
                  farmer.email,
                  farmer.address,
                  &farmer.postal_code,
                  &farmer.farming_experience,
                  &farmer.area,
                  &farmer.land_parcels,
                  farmer.crops,
                  &farmer.ownership,
                  farmer.bank_number,
                  farmer.bank_name,
                  &farmer.branch_code,
                  farmer.linked_number
                 ) != EOF) && (fscanf(fp2, "%d %s %c\n", &user.id, user.password, &user.type)))
    {
        if((farmer.id != id))
        {
            id_matched = 1;
            fprintf(temp, "%d|%s|%s|%c|%s|%s|%s|%s|%s|%d|%f|%f|%d|%s|%c|%s|%s|%d|%s\n",
                    farmer.id,
                    farmer.fullName,
                    farmer.dob,
                    farmer.gender,
                    farmer.nid,
                    farmer.literacy,
                    farmer.mobile,
                    farmer.email,
                    farmer.address,
                    farmer.postal_code,
                    farmer.farming_experience,
                    farmer.area,
                    farmer.land_parcels,
                    farmer.crops,
                    farmer.ownership,
                    farmer.bank_number,
                    farmer.bank_name,
                    farmer.branch_code,
                    farmer.linked_number
                   );

            fprintf(temp2, "%d %s %c\n", user.id, user.password, user.type);
        }
    }

    if(!id_matched)
    {
        printf("Farmer with ID %d not found in the system! \n", id);
    }

    fclose(fp);
    fclose(temp);
    fclose(fp2);
    fclose(temp2);

    remove("Farmers.txt");
    rename("Temp.txt", "Farmers.txt");

    remove("Users.txt");
    rename("Temp2.txt", "Users.txt");

    printf("\nFarmer profile deleted successfully.\n");
}
