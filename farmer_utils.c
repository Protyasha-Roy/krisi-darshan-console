#include <stdio.h>
#include <string.h>
#include "login.h"
#include "farmer.h"
#include "utils.h"

void edit_personaldetails(Farmer f)
{
    FILE *fp = fopen("Farmers.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

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

    char edit_choice;

    printf("Do you want to edit any of the details? (Y/N) ");
    scanf(" %c", &edit_choice);
    getchar();

    if(edit_choice=='Y' || edit_choice=='y')
    {
        char continue_editing;

        do
        {
            int personal_detail;

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
                printf("Invalid choice! Please enter a number between 1-18: ");
                continue;
            }

            printf("Detail updated successfully. \n");

            printf("Do you want to edit another field? (Y/N): ");
            scanf(" %c", &continue_editing);
            getchar();
        }
        while(continue_editing == 'Y' || continue_editing == 'y');
    }
    else
    {
        printf("Error! Please enter Y/N.");
    }

    Farmer tempFarmer;

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
}
