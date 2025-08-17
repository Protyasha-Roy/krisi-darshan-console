#include <stdio.h>
#include <stdlib.h>
#include "assigned_parcel.h"
#include "utils.h"
#include "menus.h"
#include "admin.h"
#include "parcels.h"
#include <string.h>


void list_assigned_land_parcels(int adminId)
{
    clear_screen();
    FILE *fp = fopen("Assigned_Parcel.txt", "r");

    if(fp==NULL)
    {
        printf("Error! File not found.\n");
        return;
    }

    AssignedParcel assigned;

    while (fscanf(fp, "%d|%d|%d|%d|%c|%99[^|]|%f|%14[^|]|%29[^|]|%49[^\n]",
                  &assigned.parcelId,
                  &assigned.id,
                  &assigned.agentId,
                  &assigned.farmerId,
                  &assigned.status,
                  assigned.location,
                  &assigned.area,
                  assigned.dop,
                  assigned.soilType,
                  assigned.crops) != EOF)
    {
        printf("\n\t\tPARCEL ID:%d\n", assigned.parcelId);

        printf("Parcel ID:              %d\n", assigned.parcelId);
        printf("Assigned Id:            %d\n",assigned.id);
        printf("Agent's Id:             %d\n",assigned.agentId);
        printf("Farmer's Id:            %d\n",assigned.farmerId);
        printf("Land parcel status:     %c\n",assigned.status);
        printf("Location:               %s\n",assigned.location);
        printf("Area:                   %.1f\n",assigned.area);
        printf("Date:                   %s\n",assigned.dop);
        printf("Soil type:              %s\n",assigned.soilType);
        printf("Crops:                  %s\n",assigned.crops);
    }

    fclose(fp);

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
            manage_land_parcels(adminId);
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

void list_unassigned_land_parcels(int adminId)
{
    clear_screen();
    FILE *fp = fopen("Parcels.txt", "r");

    if(fp==NULL)
    {
        printf("Error! File not found.\n");
        return;
    }

    Parcel p;

    printf("\t\t LAND PARCELS \n");

    while((fscanf(fp, "%d|%d|%99[^|]|%f|%14[^|]|%29[^|]|%29[^\n]\n",
                  &p.id,
                  &p.farmerId,
                  p.location,
                  &p.area,
                  p.dop,
                  p.soilType,
                  p.crops) ==7))
    {
        printf("Parcel ID:  %d\n", p.id);
        printf("1.Location of the parcel:  %s\n", p.location);
        printf("2.Area (in acres):  %.2f\n", p.area);
        printf("3.Date of Purchase (YYYY-MM-DD):  %s\n", p.dop);
        printf("4.Soil Type:  %s\n", p.soilType);
        printf("5.Type of crops grown:  %s\n", p.crops);
        printf("\n");
    }

    fclose(fp);
    getchar();

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
            manage_land_parcels(adminId);
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

void assign_field_agent(int adminId)
{
    clear_screen();
    FILE *fp = fopen("Assigned_Parcel.txt", "a");
    FILE *fp2 = fopen("Parcels.txt", "r");
    FILE *fp3 = fopen("temp.txt", "w");


    int parcelId;

    AssignedParcel assigned;
    Parcel parcel;

    getchar();
    printf("\t ->Enter land parcel ID: ");
    scanf("%d", &parcelId);

    if(parcelId)
    {
        do
        {
            assigned.id = generateId(0, 2147483640);
        }
        while(checkIdDuplication(fp, assigned.id) == 1);

        getchar();
        printf("Enter agent id: ");
        scanf("%d", &assigned.agentId);

        assigned.status = 'P';

        while((fscanf(fp2, "%d|%d|%99[^|]|%f|%14[^|]|%29[^|]|%29[^\n]\n",
                      &parcel.id,
                      &parcel.farmerId,
                      parcel.location,
                      &parcel.area,
                      parcel.dop,
                      parcel.soilType,
                      parcel.crops) == 7))
        {
            if(parcel.id == parcelId)
            {
                assigned.parcelId = parcel.id;
                strcpy(assigned.location, parcel.location);
                assigned.area = parcel.area;
                strcpy(assigned.dop, parcel.dop);
                strcpy(assigned.soilType, parcel.soilType);
                strcpy(assigned.crops, parcel.crops);
                break;
            }
        }

        fclose(fp2);
    }

    fprintf(fp,"%d|%d|%d|%d|%c|%s|%f|%s|%s|%s\n",
            assigned.parcelId,
            assigned.id,
            assigned.agentId,
            assigned.farmerId,
            assigned.status,
            assigned.location,
            assigned.area,
            assigned.dop,
            assigned.soilType,
            assigned.crops
           );

    printf("\t ->Successfully assigned agent to land parcel.\n");

    fclose(fp);

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
            manage_land_parcels(adminId);
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


void delete_field_agent(int adminId)
{
    clear_screen();

    FILE *fp = fopen("Assigned_Parcel.txt", "r");
    FILE *temp = fopen("temp.txt", "w");


    if (fp == NULL||temp == NULL)
    {
        printf("Error! File not found.\n");
        return;
    }


    int id;

    AssignedParcel assigned;

    getchar();
    printf("\t ->Enter assigned ID to delete: ");
    scanf("%d", &id);

     while (fscanf(fp, "%d|%d|%d|%d|%c|%99[^|]|%f|%14[^|]|%29[^|]|%49[^\n]",
                  &assigned.parcelId,
                  &assigned.id,
                  &assigned.agentId,
                  &assigned.farmerId,
                  &assigned.status,
                  assigned.location,
                  &assigned.area,
                  assigned.dop,
                  assigned.soilType,
                  assigned.crops) != EOF)
    {
        if (assigned.id != id)
        {
            fprintf(temp,"%d|%d|%d|%d|%c|%s|%f|%s|%s|%s\n",
            assigned.parcelId,
            assigned.id,
            assigned.agentId,
            assigned.farmerId,
            assigned.status,
            assigned.location,
            assigned.area,
            assigned.dop,
            assigned.soilType,
            assigned.crops
           );
        }
    }

    printf("\t ->Assigned parcel deleted successfully.\n");

    fclose(fp);
    fclose(temp);

    remove("Assigned_Parcel.txt");
    rename("temp.txt", "Assigned_Parcel.txt");

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
            manage_land_parcels(adminId);
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
