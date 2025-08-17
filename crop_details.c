#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "crops_details.h"
#include "menus.h"
#include "login.h"
#include "farmer.h"
#include "parcels.h"
#include "utils.h"


void add_cropdetails(int id)
{
    FILE *fp;
    FILE *fp2;

    fp=fopen("Crops.txt", "a");

    fp2=fopen("Crops.txt", "r");

    Crops c;

    c.farmerId=id;

    do
    {
        c.id = generateId(0, 37861632);
    }

    while(checkIdDuplication(fp2, c.id) == 1);

    fclose(fp2);

    printf("\tEnter the details of the new crop: \n\n");

    getchar();
    printf("\t ->Enter the name of the new crop: ");
    fgets(c.crop_name, sizeof(c.crop_name), stdin);
    c.crop_name[strcspn(c.crop_name, "\n")] = '\0';

    printf("\t ->Enter the Parcel ID of the crop in which the crop is sowed: ");
    scanf("%d", &c.parcelId);
    getchar();

    printf("\t ->Enter the sowing date of the crop (YYYY-MM-DD): ");
    fgets(c.sowing_date, sizeof(c.sowing_date), stdin);
    c.sowing_date[strcspn(c.sowing_date, "\n")] = '\0';

    printf("\t ->Enter the harvesting date of the crop (YYYY-MM-DD): ");
    fgets(c.harvesting_date, sizeof(c.harvesting_date), stdin);
    c.harvesting_date[strcspn(c.harvesting_date, "\n")] = '\0';

    printf("\t ->Enter the current status of the crop: ");
    fgets(c.current_status, sizeof(c.current_status), stdin);
    c.current_status[strcspn(c.current_status, "\n")] = '\0';

    printf("\t ->Enter the types of fertilizers used: ");
    fgets(c.fertilizers_used, sizeof(c.fertilizers_used), stdin);
    c.fertilizers_used[strcspn(c.fertilizers_used, "\n")] = '\0';

    printf("\t ->Enter the types of pesticides used: ");
    fgets(c.pesticides_used, sizeof(c.pesticides_used), stdin);
    c.pesticides_used[strcspn(c.pesticides_used, "\n")] = '\0';


    fprintf(fp,
            "%d|%s|%d|%d|%s|%s|%s|%s|%s\n",
            c.id,
            c.crop_name,
            c.parcelId,
            c.farmerId,
            c.sowing_date,
            c.harvesting_date,
            c.current_status,
            c.fertilizers_used,
            c.pesticides_used);
    fclose(fp);

    update_parcel_crops(c.parcelId);

    printf("New Crop Added. \n");

    while (1)
    {
        int back_exit;
        printf("\t--------------------------------\n");
        printf("\t1. Go Back \n");
        printf("\t2. Exit \n");
        printf("\t--------------------------------\n\n");
        printf("\t-> Choose an option: ");
        scanf("%d", &back_exit);
        getchar();

        switch(back_exit)
        {
        case 1:
            clear_screen();
            crop_AddEditDeleteMenu(id);
            break;
        case 2:
            exit(1);
            break;
        default:
            printf("\n\tError! Please enter a valid input!\n\n");
            continue;
        }
        break;
    }

}

void edit_cropdetails(int id)
{
    FILE *fp;
    FILE *temp;
    fp= fopen("Crops.txt", "r");

    if(fp==NULL)
    {
        printf("Error! File not found!\n");
        return;
    }

    Crops c, tempCrops;

    int chosen_cropId;
    printf("Enter ID of crop to edit: ");
    scanf("%d", &chosen_cropId);
    getchar();

    int id_matched=0;

    while((fscanf(fp,
                  "%d|%49[^|]|%d|%d|%14[^|]|%14[^|]|%29[^|]|%49[^|]|%49[^\n]\n",
                  &tempCrops.id,
                  tempCrops.crop_name,
                  &tempCrops.parcelId,
                  &tempCrops.farmerId,
                  tempCrops.sowing_date,
                  tempCrops.harvesting_date,
                  tempCrops.current_status,
                  tempCrops.fertilizers_used,
                  tempCrops.pesticides_used) ==9 ))
    {

        if(tempCrops.id==chosen_cropId)
        {
            c=tempCrops;
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
            int crop_details;

            while(1)
            {
                printf("Enter the number of the detail you want to edit (1-7): ");
                scanf("%d", &crop_details);
                getchar();

                switch(crop_details)
                {
                case 1:
                    printf("\t ->Enter name of new crop: ");
                    fgets(c.crop_name, sizeof(c.crop_name), stdin);
                    c.crop_name[strcspn(c.crop_name, "\n")] = '\0';
                    break;
                case 2:
                    printf("\t ->Enter the Parcel ID of the new parcel the crop is in: ");
                    scanf("%d", &c.parcelId);
                    getchar();
                    break;
                case 3:
                    printf("\t ->Enter updated date of sowing: ");
                    fgets(c.sowing_date, sizeof(c.sowing_date), stdin);
                    c.sowing_date[strcspn(c.sowing_date, "\n")] = '\0';
                    break;
                case 4:
                    printf("\t ->Enter updated date of harvesting: ");
                    fgets(c.harvesting_date, sizeof(c.harvesting_date), stdin);
                    c.harvesting_date[strcspn(c.harvesting_date, "\n")] = '\0';
                    break;
                case 5:
                    printf("\t ->Enter updated status: ");
                    fgets(c.current_status, sizeof(c.current_status), stdin);
                    c.current_status[strcspn(c.current_status, "\n")] = '\0';

                    break;
                case 6:
                    printf("\t ->Enter the new types of fertilizers used: ");
                    fgets(c.fertilizers_used, sizeof(c.fertilizers_used), stdin);
                    c.fertilizers_used[strcspn(c.fertilizers_used, "\n")] = '\0';
                    break;
                case 7:
                    printf("\t ->Enter the new types of pesticides used: ");
                    fgets(c.pesticides_used, sizeof(c.pesticides_used), stdin);
                    c.pesticides_used[strcspn(c.pesticides_used, "\n")] = '\0';
                    break;
                default:
                    printf("Error! Please enter a valid option! \n");
                    continue;
                }
                break;
            }

            printf("Crop detail updated successfully. \n");

            printf("\t ->Do you want to edit another field? (Y/N): ");
            scanf(" %c", &continue_editing);
        }
        while(continue_editing == 'Y' || continue_editing == 'y');
    }
    else
    {
        printf("\t ->Error! Invalid Crop ID!\n");
    }

    fp=fopen("Crops.txt", "r");
    temp=fopen("temp4.txt", "w");

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

    while((fscanf(fp,
                  "%d|%49[^|]|%d|%d|%14[^|]|%14[^|]|%29[^|]|%49[^|]|%49[^\n]\n",
                  &tempCrops.id,
                  tempCrops.crop_name,
                  &tempCrops.parcelId,
                  &tempCrops.farmerId,
                  tempCrops.sowing_date,
                  tempCrops.harvesting_date,
                  tempCrops.current_status,
                  tempCrops.fertilizers_used,
                  tempCrops.pesticides_used) ==9 ))
    {
        if(tempCrops.id == c.id)
        {
            fprintf(temp,
                    "%d|%s|%d|%d|%s|%s|%s|%s|%s\n",
                    c.id,
                    c.crop_name,
                    c.parcelId,
                    c.farmerId,
                    c.sowing_date,
                    c.harvesting_date,
                    c.current_status,
                    c.fertilizers_used,
                    c.pesticides_used);
        }
        else
        {
            fprintf(temp,
                    "%d|%s|%d|%d|%s|%s|%s|%s|%s\n",
                    tempCrops.id,
                    tempCrops.crop_name,
                    tempCrops.parcelId,
                    tempCrops.farmerId,
                    tempCrops.sowing_date,
                    tempCrops.harvesting_date,
                    tempCrops.current_status,
                    tempCrops.fertilizers_used,
                    tempCrops.pesticides_used);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("Crops.txt");
    rename("temp4.txt", "Crops.txt");


    printf("Crop details updated successfully!\n");

    while (1)
    {
        int back_exit;
        printf("\t--------------------------------\n");
        printf("\t1. Go Back \n");
        printf("\t2. Exit \n");
        printf("\t--------------------------------\n\n");
        printf("\t-> Choose an option: ");
        scanf("%d", &back_exit);
        getchar();

        switch(back_exit)
        {
        case 1:
            clear_screen();
            crop_AddEditDeleteMenu(id);
            break;
        case 2:
            exit(1);
            break;
        default:
            printf("\n\tError! Please enter a valid input!\n\n");
            continue;
        }
        break;
    }
}


void delete_cropdetails(int id)
{

    FILE *fp;
    FILE *temp;
    fp=fopen("Crops.txt", "r");
    temp=fopen("temp5.txt", "w");

    Crops c,tempCrops;

    int chosen_cropId;

    printf("Enter ID of the crop to delete: ");
    scanf("%d", &chosen_cropId);
    getchar();

    int id_matched=0;

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
        if(c.id != chosen_cropId)
        {

            fprintf(temp,
                    "%d|%s|%d|%d|%s|%s|%s|%s|%s\n",
                    c.id,
                    c.crop_name,
                    c.parcelId,
                    c.farmerId,
                    c.sowing_date,
                    c.harvesting_date,
                    c.current_status,
                    c.fertilizers_used,
                    c.pesticides_used);
        }
        else
        {
            id_matched=1;
        }

    }

    if(id_matched==1)
    {
        printf("\t ->Deleted crop successfully! \n");
        update_parcel_crops(c.parcelId);

    }
    else
    {
        printf("\t ->Crop %d not found in the system! \n", chosen_cropId);
    }

    fclose(fp);
    fclose(temp);

    remove("Crops.txt");
    rename("temp5.txt", "Crops.txt");

    while (1)
    {
        int back_exit;
        printf("\t--------------------------------\n");
        printf("\t1. Go Back \n");
        printf("\t2. Exit \n");
        printf("\t--------------------------------\n\n");
        printf("\t-> Choose an option: ");
        scanf("%d", &back_exit);
        getchar();

        switch(back_exit)
        {
        case 1:
            clear_screen();
            crop_AddEditDeleteMenu(id);
            break;
        case 2:
            exit(1);
            break;
        default:
            printf("\n\tError! Please enter a valid input!\n\n");
            continue;
        }
        break;
    }

}

