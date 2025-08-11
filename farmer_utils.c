#include <stdio.h>
#include "login.h"
#include <string.h>
#include "utils.h"

void list_farmers()
{
    clear_screen();
    FILE *fp = fopen("Farmers.txt", "r");
    Farmer farmer;

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

        printf("\t\t PERSONAL DETAILS OF FARMER: %s\n", farmer.fullName);
        printf("ID:                             %d\n", farmer.id);
        printf("Full name:                      %s\n", farmer.fullName);
        printf("Date of birth:                  %s\n", farmer.dob);
        printf("Gender:                         %c\n", farmer.gender);
        printf("NID:                            %s\n", farmer.nid);
        printf("Literacy level:                 %s\n", farmer.literacy);
        printf("Mobile Number:                  %s\n", farmer.mobile);
        printf("Email address:                  %s\n", farmer.email);
        printf("Address:                        %s\n", farmer.address);
        printf("Postal Code:                    %d\n", farmer.postal_code);
        printf("Farming Experience:             %.2f\n", farmer.farming_experience);
        printf("Area of Land Parcels:           %.2f\n", farmer.area);
        printf("Number of Land Parcels:         %d\n", farmer.land_parcels);
        printf("Types of crops:                 %s\n", farmer.crops);
        printf("Ownership Type:                 %c\n", farmer.ownership);
        printf("Bank Account Number:            %s\n", farmer.bank_number);
        printf("Bank Name:                      %s\n", farmer.bank_name);
        printf("Branch Code:                    %d\n", farmer.branch_code);
        printf("Linked Number to the Bank:      %s\n\n", farmer.linked_number);
    }

    fclose(fp);
}

void search_by_id(FILE *fp, Farmer farmer)
{
    clear_screen();

    int id;
    int id_matched = 0;

    printf("Enter farmer's ID: ");
    scanf("%d", &id);

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
        if (farmer.id == id)
        {
            id_matched = 1;

            printf("\t\t PERSONAL DETAILS OF FARMER: %d\n", id);
            printf("ID:                             %d\n", farmer.id);
            printf("Full name:                      %s\n", farmer.fullName);
            printf("Date of birth:                  %s\n", farmer.dob);
            printf("Gender:                         %c\n", farmer.gender);
            printf("NID:                            %s\n", farmer.nid);
            printf("Literacy level:                 %s\n", farmer.literacy);
            printf("Mobile Number:                  %s\n", farmer.mobile);
            printf("Email address:                  %s\n", farmer.email);
            printf("Address:                        %s\n", farmer.address);
            printf("Postal Code:                    %d\n", farmer.postal_code);
            printf("Farming Experience:             %.2f\n", farmer.farming_experience);
            printf("Area of Land Parcels:           %.2f\n", farmer.area);
            printf("Number of Land Parcels:         %d\n", farmer.land_parcels);
            printf("Types of crops:                 %s\n", farmer.crops);
            printf("Ownership Type:                 %c\n", farmer.ownership);
            printf("Bank Account Number:            %s\n", farmer.bank_number);
            printf("Bank Name:                      %s\n", farmer.bank_name);
            printf("Branch Code:                    %d\n", farmer.branch_code);
            printf("Linked Number to the Bank:      %s\n\n", farmer.linked_number);
            break;
        }
    }

    fclose(fp);

    if(!id_matched)
    {
        printf("Farmer with ID: %d not found!\n", id);
    }
}

void search_by_name(FILE *fp, Farmer farmer)
{
    clear_screen();

    char name[100];
    int name_matched = 0;

    getchar();
    printf("Enter farmer's full name exactly: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0';

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
        if (strcmp(lowercased_str(name), lowercased_str(farmer.fullName)) == 0)
        {
            name_matched = 1;

            printf("\t\t PERSONAL DETAILS OF FARMER: %s\n", farmer.fullName);
            printf("ID:                             %d\n", farmer.id);
            printf("Full name:                      %s\n", farmer.fullName);
            printf("Date of birth:                  %s\n", farmer.dob);
            printf("Gender:                         %c\n", farmer.gender);
            printf("NID:                            %s\n", farmer.nid);
            printf("Literacy level:                 %s\n", farmer.literacy);
            printf("Mobile Number:                  %s\n", farmer.mobile);
            printf("Email address:                  %s\n", farmer.email);
            printf("Address:                        %s\n", farmer.address);
            printf("Postal Code:                    %d\n", farmer.postal_code);
            printf("Farming Experience:             %.2f\n", farmer.farming_experience);
            printf("Area of Land Parcels:           %.2f\n", farmer.area);
            printf("Number of Land Parcels:         %d\n", farmer.land_parcels);
            printf("Types of crops:                 %s\n", farmer.crops);
            printf("Ownership Type:                 %c\n", farmer.ownership);
            printf("Bank Account Number:            %s\n", farmer.bank_number);
            printf("Bank Name:                      %s\n", farmer.bank_name);
            printf("Branch Code:                    %d\n", farmer.branch_code);
            printf("Linked Number to the Bank:      %s\n\n", farmer.linked_number);
            break;
        }
    }

    fclose(fp);

    if(!name_matched)
    {
        printf("Farmer with the name %s not found!\n", name);
    }
}

void search_partially(FILE *fp, Farmer farmer)
{
    clear_screen();
    char partial_name[100];
    int string_matched = 1;

    getchar();
    printf("Enter partial name characters: ");
    fgets(partial_name, 100, stdin);
    partial_name[strcspn(partial_name, "\n")] = '\0';

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
        if (strncmp(lowercased_str(partial_name), lowercased_str(farmer.fullName), strlen(partial_name)) == 0)
        {
            string_matched = 1;

            printf("\t\t PERSONAL DETAILS OF FARMER: %s\n", farmer.fullName);
            printf("ID:                             %d\n", farmer.id);
            printf("Full name:                      %s\n", farmer.fullName);
            printf("Date of birth:                  %s\n", farmer.dob);
            printf("Gender:                         %c\n", farmer.gender);
            printf("NID:                            %s\n", farmer.nid);
            printf("Literacy level:                 %s\n", farmer.literacy);
            printf("Mobile Number:                  %s\n", farmer.mobile);
            printf("Email address:                  %s\n", farmer.email);
            printf("Address:                        %s\n", farmer.address);
            printf("Postal Code:                    %d\n", farmer.postal_code);
            printf("Farming Experience:             %.2f\n", farmer.farming_experience);
            printf("Area of Land Parcels:           %.2f\n", farmer.area);
            printf("Number of Land Parcels:         %d\n", farmer.land_parcels);
            printf("Types of crops:                 %s\n", farmer.crops);
            printf("Ownership Type:                 %c\n", farmer.ownership);
            printf("Bank Account Number:            %s\n", farmer.bank_number);
            printf("Bank Name:                      %s\n", farmer.bank_name);
            printf("Branch Code:                    %d\n", farmer.branch_code);
            printf("Linked Number to the Bank:      %s\n\n", farmer.linked_number);
        }
    }

    fclose(fp);

    if(!string_matched)
    {
        printf("No match found for %s\n", partial_name);
    }
}

void search_farmer()
{
    FILE *fp = fopen("Farmers.txt", "r");

    Farmer farmer;

    int chosen_option;

    clear_screen();
    printf("1. Search by ID\n");
    printf("2. Search by name\n");
    printf("3. Search by partial name\n");

    printf("Choose an option: ");
    scanf("%d", &chosen_option);

    switch(chosen_option)
    {
    case 1:
        search_by_id(fp, farmer);
        break;
    case 2:
        search_by_name(fp,farmer);
        break;
    case 3:
        search_partially(fp, farmer);
        break;
    default:
        printf("Invalid option chosen! Try again");
        search_farmer();
        break;
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

    printf("Enter farmer's ID: ");
    scanf("%d", &id);

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
