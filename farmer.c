#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "application_schemes.h"
#include "crops_details.h"
#include "menus.h"
#include "login.h"
#include "farmer.h"
#include "parcels.h"
#include "utils.h"
#include "bot.h"

void update_AreaAndParcelNumber(int id, float area, int parcel_number)
{
    FILE *fp;
    FILE *temp;

    fp==fopen("Farmers.txt", "r");
    temp=fopen("temp.txt", "w");

    if(fp==NULL ||temp==NULL)
    {
        printf("Error! File not found!");
        return;
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
                 )) != EOF)
    {
        if(f.id==id)
        {
            f.land_parcels+=parcel_number;
            f.area+=area;
        }

        fprintf(temp, "%d|%s|%s|%c|%s|%s|%s|%s|%s|%d|%.2f|%.2f|%d|%s|%c|%s|%s|%d|%s\n",
                f.id,
                f.fullName,
                f.dob,
                f.gender,
                f.nid,
                f.literacy,
                f.mobile,
                f.email,
                f.address,
                f.postal_code,
                f.farming_experience,
                f.area,
                f.land_parcels,
                f.crops,
                f.ownership,
                f.bank_number,
                f.bank_name,
                f.branch_code,
                f.linked_number);
    }

    fclose(fp);
    fclose(temp);

    remove("Farmers.txt");
    rename("temp.txt", "Farmers.txt");
}



void edit_personaldetails(Farmer f, int id)
{
    FILE *fp;
    FILE *temp;
    fp=fopen("Farmers.txt", "r");

    Farmer tempFarmer;

    if(fp==NULL)
    {
        printf("Error! File not found!\n");
        return;
    }

    int id_matched=0;

    while (fscanf(fp, "%d|%99[^|]|%14[^|]|%c|%19[^|]|%99[^|]|%19[^|]|%49[^|]|%299[^|]|%d|%f|%f|%d|%99[^|]|%c|%29[^|]|%49[^|]|%d|%19[^\n]\n",
                  &tempFarmer.id,
                  tempFarmer.fullName,
                  tempFarmer.dob,
                  &tempFarmer.gender,
                  tempFarmer.nid,
                  tempFarmer.literacy,
                  tempFarmer.mobile,
                  tempFarmer.email,
                  tempFarmer.address,
                  &tempFarmer.postal_code,
                  &tempFarmer.farming_experience,
                  &tempFarmer.area,
                  &tempFarmer.land_parcels,
                  tempFarmer.crops,
                  &tempFarmer.ownership,
                  tempFarmer.bank_number,
                  tempFarmer.bank_name,
                  &tempFarmer.branch_code,
                  tempFarmer.linked_number) !=EOF)
    {
        if (tempFarmer.id == id)
        {
            f=tempFarmer;
            id_matched=1;
            break;
        }
    }

    fclose(fp);

    if(id_matched==1)
    {
        char continue_editing;

        do
        {
            int personal_detail;

            while(1)
            {
                printf("Enter the number of the detail you want to edit (1-18): ");
                scanf("%d", &personal_detail);
                getchar();

                switch(personal_detail)
                {
                case 1:
                    printf("Enter new Full Name: ");
                    fgets(f.fullName, sizeof(f.fullName), stdin);
                    f.fullName[strcspn(f.fullName, "\n")]='\0';
                    break;
                case 2:
                    printf("Enter new Date of Birth (YYYY-MM-DD): ");
                    fgets(f.dob, sizeof(f.dob), stdin);
                    f.dob[strcspn(f.dob, "\n")]='\0';
                    break;
                case 3:
                    printf("Enter new Gender: (M/F/O) ");
                    scanf(" %c", &f.gender);
                    getchar();
                    break;
                case 4:
                    printf("Enter new NID: ");
                    fgets(f.nid, sizeof(f.nid), stdin);
                    f.nid[strcspn(f.nid, "\n")]='\0';
                    break;
                case 5:
                    printf("Enter new literacy level: ");
                    fgets(f.literacy, sizeof(f.literacy), stdin);
                    f.literacy[strcspn(f.literacy, "\n")]='\0';
                    break;
                case 6:
                    printf("Enter new mobile number: ");
                    fgets(f.mobile, sizeof(f.mobile), stdin);
                    f.mobile[strcspn(f.mobile, "\n")]='\0';
                    break;
                case 7:
                    printf("Enter new email address: ");
                    fgets(f.email, sizeof(f.email), stdin);
                    f.email[strcspn(f.email, "\n")]='\0';
                    break;
                case 8:
                    printf("Enter new address: ");
                    fgets(f.address, sizeof(f.address), stdin);
                    f.address[strcspn(f.address, "\n")]='\0';
                    break;
                case 9:
                    printf("Enter new postal code: ");
                    scanf("%d", &f.postal_code);
                    getchar();
                    break;
                case 10:
                    printf("Enter new farming experience (in years): ");
                    scanf("%f", &f.farming_experience);
                    getchar();
                    break;
                case 11:
                    printf("Enter new area: ");
                    scanf("%f", &f.area);
                    getchar();
                    break;
                case 12:
                    printf("Enter new number of land parcels: ");
                    scanf("%d", &f.land_parcels);
                    getchar();
                    break;
                case 13:
                    printf("Enter new crops: ");
                    fgets(f.crops, sizeof(f.crops), stdin);
                    f.crops[strcspn(f.crops, "\n")]='\0';
                    break;
                case 14:
                    printf("Enter new ownership (O/L/S): ");
                    scanf(" %c", &f.ownership);
                    getchar();
                    break;
                case 15:
                    printf("Enter new bank number: ");
                    fgets(f.bank_number, sizeof(f.bank_number), stdin);
                    f.bank_number[strcspn(f.bank_number, "\n")]='\0';
                    break;
                case 16:
                    printf("Enter new bank name: ");
                    fgets(f.bank_name, sizeof(f.bank_name), stdin);
                    f.bank_name[strcspn(f.bank_name, "\n")]='\0';
                    break;
                case 17:
                    printf("Enter new branch code: ");
                    scanf("%d", &f.branch_code);
                    getchar();
                    break;
                case 18:
                    printf("Enter new linked number: ");
                    fgets(f.linked_number, sizeof(f.linked_number), stdin);
                    f.linked_number[strcspn(f.linked_number, "\n")]='\0';
                    break;
                default:
                    printf("Error! Please enter a valid option! \n");
                    continue;
                }
                break;
            }

            printf("Detail updated successfully. \n");

            printf("Do you want to edit another field? (Y/N): ");
            scanf(" %c", &continue_editing);
            getchar();
        }
        while(continue_editing == 'Y' || continue_editing == 'y');
    }

    fp=fopen("Farmers.txt", "r");
    temp=fopen("temp.txt", "w");

    if(fp==NULL || temp==NULL)
    {
        printf("Error! File not found!\n");
        if(fp)
        {
            fclose(fp);
        }
        if(temp)
        {
            fclose(temp);
        }
        return;
    }

    //reading all the data that was previously stored before editing
    while(fscanf(fp, "%d|%99[^|]|%14[^|]|%c|%19[^|]|%99[^|]|%19[^|]|%49[^|]|%299[^|]|%d|%f|%f|%d|%99[^|]|%c|%29[^|]|%49[^|]|%d|%19[^\n]\n",
                 &tempFarmer.id,
                 tempFarmer.fullName,
                 tempFarmer.dob,
                 &tempFarmer.gender,
                 tempFarmer.nid,
                 tempFarmer.literacy,
                 tempFarmer.mobile,
                 tempFarmer.email,
                 tempFarmer.address,
                 &tempFarmer.postal_code,
                 &tempFarmer.farming_experience,
                 &tempFarmer.area,
                 &tempFarmer.land_parcels,
                 tempFarmer.crops,
                 &tempFarmer.ownership,
                 tempFarmer.bank_number,
                 tempFarmer.bank_name,
                 &tempFarmer.branch_code,
                 tempFarmer.linked_number) != EOF)
    {

        if(tempFarmer.id == f.id) //we check with which farmer id does the id of the farmer we edited match
        {
            // write the updated detail of the particular farmer in the new file
            fprintf(temp, "%d|%s|%s|%c|%s|%s|%s|%s|%s|%d|%.2f|%.2f|%d|%s|%c|%s|%s|%d|%s\n",
                    f.id,
                    f.fullName,
                    f.dob,
                    f.gender,
                    f.nid,
                    f.literacy,
                    f.mobile,
                    f.email,
                    f.address,
                    f.postal_code,
                    f.farming_experience,
                    f.area,
                    f.land_parcels,
                    f.crops,
                    f.ownership,
                    f.bank_number,
                    f.bank_name,
                    f.branch_code,
                    f.linked_number);
        }
        else
        {
            // write the previous data for the other farmers
            fprintf(temp, "%d|%s|%s|%c|%s|%s|%s|%s|%s|%d|%.2f|%.2f|%d|%s|%c|%s|%s|%d|%s\n",
                    tempFarmer.id,
                    tempFarmer.fullName,
                    tempFarmer.dob,
                    tempFarmer.gender,
                    tempFarmer.nid,
                    tempFarmer.literacy,
                    tempFarmer.mobile,
                    tempFarmer.email,
                    tempFarmer.address,
                    tempFarmer.postal_code,
                    tempFarmer.farming_experience,
                    tempFarmer.area,
                    tempFarmer.land_parcels,
                    tempFarmer.crops,
                    tempFarmer.ownership,
                    tempFarmer.bank_number,
                    tempFarmer.bank_name,
                    tempFarmer.branch_code,
                    tempFarmer.linked_number);
        }
    }

    fclose(fp);
    fclose(temp);

    // we then replace original file with temp file
    remove("Farmers.txt");
    rename("temp.txt", "Farmers.txt");

    printf("Farmer details updated successfully!\n");

    while (1)
    {
        int back_exit;
        printf("\nChoose an option: \n");
        printf("1. 'B' - Go back\n2. 'E' - Exit: \n");
        printf("Enter you choice: ");
        scanf("%d", &back_exit);
        getchar();

        switch(back_exit)
        {
        case 1:
            clear_screen();
            farmer_editmenu(id);
            break;
        case 2:
            exit(1);
            break;
        default:
            printf("Error! Please enter a valid option!");
            continue;
        }
        break;
    }
}



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

            printf("\n\t\tPERSONAL DETAILS OF FARMER %d\n\n", id);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %-30s\n", "1.Full name", f.fullName);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %-30s\n", "2.Date of birth", f.dob);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %c\n", "3.Gender", f.gender);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %-30s\n", "4.NID", f.nid);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %-30s\n", "5.Literacy level", f.literacy);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %-30s\n", "6.Mobile Number", f.mobile);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %-30s\n", "7.Email address", f.email);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %-30s\n", "8.Address", f.address);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %3d\n", "9.Postal Code", f.postal_code);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %4.2f\n", "10.Farming Experience", f.farming_experience);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %4.2f\n", "11.Area of Land Parcels", f.area);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %3d\n", "12.Number of Land Parcels", f.land_parcels);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %-30s\n", "13.Types of crops", f.crops);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %c\n", "14.Ownership Type", f.ownership);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %-30s\n", "15.Bank Account Number", f.bank_number);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %-30s\n", "16.Bank Name", f.bank_name);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %3d\n", "17.Branch Code", f.branch_code);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %-30s\n", "18.Linked Number to the Bank", f.linked_number);
            printf("---------------------------------------------------------------------------------------\n");
            break;
        }
    }

    fclose(fp);

    if(id_matched)
    {
        farmer_editmenu(id);
    }

    else
    {
        printf("Farmer with ID %d not found in the system! \n", id);
    }

}

void farmer_land_parcels (int id)
{
    clear_screen();
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
            id_matched = 1;

            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %3d\n", "Parcel ID", p.id);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %-30s\n", "1.Location of the parcel", p.location);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %4.2f\n", "2.Area (in acres)", p.area);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %-15s\n", "3.Date of Purchase (YYYY-MM-DD)", p.dop);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %-20s\n", "4.Soil Type", p.soilType);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %-30s\n", "5.Type of crops grown", p.crops);
            printf("---------------------------------------------------------------------------------------\n");
            printf("\n\n");

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
        parcel_AddEditDeleteMenu(id);
    }
}

void application_schemes(int id)
{
    while(1)
    {
        int chosen_option;
        printf("\nChoose an option: \n");
        printf("1.Apply for Loan \n");
        printf("2.Apply for Subsidy \n");
        printf("3.View Applied Forms \n");
        printf("4.Back \n");
        printf("Enter your choice: ");
        scanf("%d", &chosen_option);

        switch(chosen_option)
        {
        case 1:
            loan_application(id);
            break;
        case 2:
            subsidy_application(id);
            break;
        case 3:
            view_appliedforms(id);
            break;
        case 4:
            clear_screen();
            FarmerMenu(id);
        default:
            printf("Error! Please enter either 1 or 2: ");
            continue;
        }
        break;
    }
}


void chatbot(int id)
{
    clear_screen();
    printf("/t/tWelcome to the chatbot\n");
    bot(id);
}

void track_cropcycle(int id)
{
    clear_screen();
    FILE *fp = fopen("Crops.txt", "r");

    if(fp==NULL)
    {
        printf("Error! File not found.\n");
        return;
    }

    Crops c;

    int id_matched=0;

    printf("\t\t CROPS DETAILS OF FARMER %d\n", id);

    while((fscanf(fp,
                  "%d|%49[^|]|%d|%d|%14[^|]|%14[^|]|%29[^|]|%49[^|]|%49[^\n]\n",
                  &c.id,
                  c.crop_name,
                  &c.parcelId,
                  &c.farmerId,
                  c.sowing_date,
                  c.harvesting_date,
                  c.current_status,
                  c.fertilizers_used,
                  c.pesticides_used) ==9 ))
    {
        if(c.farmerId==id)
        {
            id_matched = 1;

            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %3d\n", "Crop ID", c.id);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %-30s\n", "1.Crop name", c.crop_name);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %3d\n", "2.Parcel ID", c.parcelId);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %-15s\n", "3.Sowing Date (YYYY-MM-DD)", c.sowing_date);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %-15s\n", "4.Harvesting Date (YYYY-MM-DD)", c.harvesting_date);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %-30s\n", "5.Current status of the crop", c.current_status);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %-30s\n", "6.Fertilizers Used", c.fertilizers_used);
            printf("---------------------------------------------------------------------------------------\n");
            printf("%-25s: %-30s\n", "7.Pesticides Used", c.pesticides_used);
            printf("---------------------------------------------------------------------------------------\n");
            printf("\n\n");

        }
    }

    fclose(fp);
    getchar();

    if(id_matched==1)
    {
        printf("\n");
        crop_AddEditDeleteMenu(id);
    }
    else
    {
        printf("No crop details found for Farmer %d in the system! \n", id);
        crop_AddEditDeleteMenu(id);
    }
}
