#include <stdio.h>
#include "assigned_parcel.h"
#include "agents.h"

void assigned_parcels(int id)
{
    FILE *fp = fopen("Assigned_Parcel.txt", "r");

    if(fp==NULL)
    {
        printf("Error! File not found.\n");
        return;
    }
    AssignedParcel assignedParcel;

    int id_matched=0;

    while (fscanf(fp, "%d|%d|%19[^|]|%c|%99[^|]|%f|%14[^|]|%29[^|]|%49[^\n]",
                  &assignedParcel.agentId,
                  &assignedParcel.id,
                  assignedParcel.farmerId,
                  &assignedParcel.status,
                  assignedParcel.location,
                  &assignedParcel.area,
                  assignedParcel.dop,
                  assignedParcel.soilType,
                  assignedParcel.crops) != EOF)
    {
        if (assignedParcel.agentId == id)
        {
            id_matched=1;

            printf("Agent's Id: %d\n",assignedParcel.agentId);
            printf("Parcel's Id: %d\n",assignedParcel.id);
            printf("Farmer's Id: %s\n",assignedParcel.farmerId);
            printf("Land parcel status: %c\n",assignedParcel.status);
            printf("Location: %s\n",assignedParcel.location);
            printf("Area: %.1f\n",assignedParcel.area);
            printf("Date: %s\n",assignedParcel.dop);
            printf("Soil type: %s\n",assignedParcel.soilType);
            printf("Crops: %s",assignedParcel.crops);
            break;
        }
    }

    fclose(fp);

    if(!id_matched)
    {
        printf("No assigned parcel found.\n");
    }

}



void upload_report(int id)
{
    printf("Upload your report on the land parcel: ");
}

void manage_report(int id)
{
    printf("Reports of Agent ID %d\n", id);
}

void manage_schedules (int id)
{
    printf("Schedule of Agent ID %d\n", id);
}
