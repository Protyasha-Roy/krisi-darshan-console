#include <stdio.h>
#include "assigned_parcel.h"
#include "utils.h"

void list_assigned_land_parcels()
{
    clear_screen();
    FILE *fp = fopen("Assigned_Parcel.txt", "r");

    if(fp==NULL)
    {
        printf("Error! File not found.\n");
        return;
    }

    AssignedParcel assignedParcel;

    while (fscanf(fp, "%d|%d|%d|%c|%99[^|]|%f|%14[^|]|%29[^|]|%49[^\n]",
                  &assignedParcel.agentId,
                  &assignedParcel.id,
                  &assignedParcel.farmerId,
                  &assignedParcel.status,
                  assignedParcel.location,
                  &assignedParcel.area,
                  assignedParcel.dop,
                  assignedParcel.soilType,
                  assignedParcel.crops) != EOF)
    {
        printf("\n\t\tPARCEL ID:%d\n", assignedParcel.id);
        printf("Agent's Id:             %d\n",assignedParcel.agentId);
        printf("Parcel's Id:            %d\n",assignedParcel.id);
        printf("Farmer's Id:            %d\n",assignedParcel.farmerId);
        printf("Land parcel status:     %c\n",assignedParcel.status);
        printf("Location:               %s\n",assignedParcel.location);
        printf("Area:                   %.1f\n",assignedParcel.area);
        printf("Date:                   %s\n",assignedParcel.dop);
        printf("Soil type:              %s\n",assignedParcel.soilType);
        printf("Crops:                  %s\n",assignedParcel.crops);
    }

    fclose(fp);
}

void list_unassigned_land_parcels()
{

}

void assign_field_agent()
{
    clear_screen();

    printf("Enter land ");
}

void update_field_agent()
{

}

void delete_field_agent()
{

}
