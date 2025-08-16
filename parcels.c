#include <stdio.h>
#include <string.h>
#include "menus.h"
#include "crops_details.h"
#include "login.h"
#include "farmer.h"
#include "parcels.h"
#include "utils.h"
#include <stdlib.h>

void update_parcel_crops(int id)
{
    FILE *fp;
    FILE *fp2;
    FILE *temp;

    fp=fopen("Crops.txt", "r");
    fp2=fopen("Parcels.txt", "r");
    temp=fopen("temp.txt", "w");;

    if(fp==NULL || fp2==NULL || temp==NULL)
    {
        printf("\n\tError! File not found!\n\n");
        if(fp)
        {
            fclose(fp);
        }

        if(fp2)
        {
            fclose(fp2);
        }

        if(temp)
        {
            fclose(temp);
        }
        return;
    }

    Parcel p;
    Crops c;

    while(fscanf(fp2, "%d|%d|%99[^|]|%f|%14[^|]|%29[^|]|%49[^\n]\n",
                 &p.id,
                 &p.farmerId,
                 p.location,
                 &p.area,
                 p.dop,
                 p.soilType,
                 p.crops) != EOF)
    {

        if(p.id==id)
        {
            strcpy(p.crops, ""); //clearing the existing crop field
            rewind(fp);
            while(fscanf(fp, "%d|%49[^|]|%d|%d|%14[^|]|%14[^|]|%29[^|]|%49[^|]|%49[^\n]\n",
                         &c.id,
                         c.crop_name,
                         &c.parcelId,
                         &c.farmerId,
                         c.sowing_date,
                         c.harvesting_date,
                         c.current_status,
                         c.fertilizers_used,
                         c.pesticides_used) == 9)
            {

                if(c.parcelId == id)
                {
                    if(strlen(p.crops) > 0) strcat(p.crops, ", "); //if there is an existing crop we add a comma to separate them
                    strcat(p.crops, c.crop_name);
                }
            }
        }

        fprintf(temp, "%d|%d|%s|%f|%s|%s|%s\n",
                p.id,
                p.farmerId,
                p.location,
                p.area,
                p.dop,
                p.soilType,
                p.crops);
    }

    fclose(fp);
    fclose(fp2);
    fclose(temp);

    remove("Parcels.txt");
    rename("temp.txt", "Parcels.txt");
}


void delete_landparcels(int id)
{
    FILE *fp;
    FILE *temp;
    fp=fopen("Parcels.txt", "r");
    temp=fopen("temp3.txt", "w");

    Parcel p,tempParcel, deletedParcel;

    int id_matched=0;

    int chosen_parcelId;
    printf("\t-> Enter ID of parcel to edit: ");
    scanf("%d", &chosen_parcelId);
    getchar();

    while(fscanf(fp, "%d|%d|%99[^|]|%f|%14[^|]|%29[^|]|%29[^\n]\n",
                 &p.id,
                 &p.farmerId,
                 p.location,
                 &p.area,
                 p.dop,
                 p.soilType,
                 p.crops) !=EOF )
    {
        if(p.id != chosen_parcelId)
        {
            fprintf(temp,"%d|%d|%s|%f|%s|%s|%s\n",
                    p.id,
                    p.farmerId,
                    p.location,
                    p.area,
                    p.dop,
                    p.soilType,
                    p.crops);
        }
        else
        {
            id_matched=1;
            deletedParcel=p;
        }
    }

    fclose(fp);
    fclose(temp);


    remove("Parcels.txt");
    rename("temp3.txt", "Parcels.txt");

    if(id_matched==1)
    {
        printf("\n\tDeleted parcel successfully.\n\n");
    }
    else
    {
        printf("\n\tParcel with ID %d is not in the system!\n\n", chosen_parcelId);
    }

    update_AreaAndParcelNumber(id, -deletedParcel.area, -1);

    while (1)
    {
        int back_exit;
        printf("\n\t1. 'B' - Go back\n\t2. 'E' - Exit: \n\n");
        printf("\t-> Enter you choice: ");
        scanf("%d", &back_exit);
        getchar();

        switch(back_exit)
        {
        case 1:
            clear_screen();
            parcel_AddEditDeleteMenu(id);
            break;
        case 2:
            exit(1);
            break;
        default:
            printf("\n\tError! Please enter a valid option!\n\n");
            continue;
        }
        break;
    }
}


void edit_landparcels(int id)
{
    FILE *fp;
    FILE *temp;
    fp= fopen("Parcels.txt", "r");

    if(fp==NULL)
    {
        printf("\n\tError! File not found!\n\n");
        return;
    }

    Parcel p,tempParcel;

    int chosen_parcelId;
    printf("\t-> Enter ID of parcel to edit: ");
    scanf("%d", &chosen_parcelId);
    getchar();

    int id_matched=0;

    while(fscanf(fp, "%d|%d|%99[^|]|%f|%14[^|]|%29[^|]|%29[^\n]\n",
                 &tempParcel.id,
                 &tempParcel.farmerId,
                 tempParcel.location,
                 &tempParcel.area,
                 tempParcel.dop,
                 tempParcel.soilType,
                 tempParcel.crops) !=EOF )
    {

        if(tempParcel.id==chosen_parcelId)
        {
            p=tempParcel;
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
            int land_parcel;
            while(1)
            {
                printf("\t-> Enter the number of the detail you want to edit (1-5): ");
                scanf("%d", &land_parcel);
                getchar();

                switch(land_parcel)
                {
                case 1:
                    printf("\t-> Enter new Location: ");
                    fgets(p.location, sizeof(p.location), stdin);
                    p.location[strcspn(p.location, "\n")]='\0';
                    break;
                case 2:
                    printf("\t-> Enter updated area (in acres): ");
                    scanf("%f", &p.area);
                    getchar();
                    break;
                case 3:
                    printf("\t-> Enter updated date of purchase: ");
                    fgets(p.dop, sizeof(p.dop), stdin);
                    p.dop[strcspn(p.dop, "\n")]='\0';
                    break;
                case 4:
                    printf("\t-> Enter updated soil type: ");
                    fgets(p.soilType, sizeof(p.soilType), stdin);
                    p.soilType[strcspn(p.soilType, "\n")]='\0';
                    break;
                case 5:
                    printf("\t-> Enter new types of crops grown: ");
                    fgets(p.crops, sizeof(p.crops), stdin);
                    p.crops[strcspn(p.crops, "\n")]='\0';
                    break;
                default:
                    printf("\n\tError! Please enter a valid option!\n\n");
                    continue;
                }
                break;
            }

            printf("\n\tParcel updated successfully.\n\n");

            printf("\t-> Do you want to edit another field? (Y/N): ");
            scanf(" %c", &continue_editing);
            getchar();
        }
        while(continue_editing == 'Y' || continue_editing == 'y');
    }
    else
    {
        printf("\n\tError! Invalid Parcel ID!\n\n");
    }

    fp=fopen("Parcels.txt", "r");
    temp=fopen("temp2.txt", "w");

    if(fp==NULL || temp==NULL)
    {
        printf("\n\tError! File not found!\n\n");
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

    while(fscanf(fp, "%d|%d|%99[^|]|%f|%14[^|]|%29[^|]|%29[^\n]\n",
                 &tempParcel.id,
                 &tempParcel.farmerId,
                 tempParcel.location,
                 &tempParcel.area,
                 tempParcel.dop,
                 tempParcel.soilType,
                 tempParcel.crops) !=EOF )
    {
        if(tempParcel.id == p.id) //we check with which parcel id does the id of the parcel we edited match
        {
            // write the updated detail of the particular parcel in the new file
            fprintf(temp,"%d|%d|%s|%f|%s|%s|%s\n",
                    p.id,
                    p.farmerId,
                    p.location,
                    p.area,
                    p.dop,
                    p.soilType,
                    p.crops);
        }
        else
        {
            // write the previous data for the other farmers
            fprintf(temp, "%d|%d|%s|%f|%s|%s|%s\n",
                    tempParcel.id,
                    tempParcel.farmerId,
                    tempParcel.location,
                    tempParcel.area,
                    tempParcel.dop,
                    tempParcel.soilType,
                    tempParcel.crops);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("Parcels.txt");
    rename("temp2.txt", "Parcels.txt");


    printf("\n\tParcel details updated successfully!\n\n");

    while (1)
    {
        int back_exit;
        printf("\n\t1. 'B' - Go back\n\t2. 'E' - Exit: \n\n");
        printf("\t-> Enter you choice: ");
        scanf("%d", &back_exit);
        getchar();

        switch(back_exit)
        {
        case 1:
            clear_screen();
            parcel_AddEditDeleteMenu(id);
            break;
        case 2:
            exit(1);
            break;
        default:
            printf("\n\tError! Please enter a valid option!\n\n");
            continue;
        }
        break;
    }

}



void add_landparcels(int id)
{
    FILE *fp;
    FILE *fp2;

    fp=fopen("Parcels.txt", "a");
    fp2=fopen("Parcels.txt", "r");


    Parcel p;
    p.farmerId=id;

    do
    {
        p.id = generateId(0, 37464632);
    }

    while(checkIdDuplication(fp2, p.id) == 1);

    fclose(fp2);

    printf("\tENTER DETAILS OF THE NEW LAND PARCEL\n\n");

    printf("\t-> Enter the location of the new land parcel: ");
    getchar();
    fgets(p.location, sizeof(p.location), stdin);
    p.location[strcspn(p.location, "\n")] = '\0';

    printf("\t-> Enter the area in acres of the new land parcel: ");
    scanf("%f", &p.area);
    getchar();

    printf("\t-> Enter the Date of Purchase of the new land parcel (YYYY-MM-DD): ");
    fgets(p.dop, sizeof(p.dop), stdin);
    p.dop[strcspn(p.dop, "\n")] = '\0';

    printf("\t-> Enter the soil type of the new land parcel: ");
    fgets(p.soilType, sizeof(p.soilType), stdin);
    p.soilType[strcspn(p.soilType, "\n")] = '\0';

    printf("\t-> Enter the type of crops grown in the new land parcel: ");
    fgets(p.crops, sizeof(p.crops), stdin);
    p.crops[strcspn(p.crops, "\n")] = '\0';


    fprintf(fp,
            "%d|%d|%s|%f|%s|%s|%s\n",
            p.id,
            p.farmerId,
            p.location,
            p.area,
            p.dop,
            p.soilType,
            p.crops);
    fclose(fp);

    update_AreaAndParcelNumber(id, p.area, 1);

    printf("\n\tNew Land Parcel Added.\n\n");


    while (1)
    {
        int back_exit;

        printf("\n\t1. 'B' - Go back\n\t2. 'E' - Exit: \n");
        printf("\t-> Enter you choice: ");
        scanf("%d", &back_exit);
        getchar();

        switch(back_exit)
        {
        case 1:
            clear_screen();
            parcel_AddEditDeleteMenu(id);
            break;
        case 2:
            exit(1);
            break;
        default:
            printf("\n\tError! Please enter a valid option!\n\n");
            continue;
        }
        break;
    }
}



