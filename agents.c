#include <stdio.h>
#include <string.h>
#include "assigned_parcel.h"
#include "agents.h"

void assigned_parcels(int agentId)
{
    FILE *fp = fopen("Assigned_Parcel.txt", "r");

    if(fp==NULL)
    {
        printf("Error! File not found.\n");
        return;
    }

    AssignedParcel assignedParcel;

    int id_matched=0;

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
        if (assignedParcel.agentId == agentId)
        {
            id_matched=1;

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
    }

    fclose(fp);

    if(!id_matched)
    {
        printf("No assigned parcel found.\n");
    }

}

void upload_report(int id)
{
    FILE *fp = fopen("Land_Parcel_Report.txt", "a");

    if(fp==NULL)
    {
        printf("Error! File not found.\n");
        return;
    }
    UploadReport uploadReport;

    printf("Enter parcel Id:");
    scanf("%d",&uploadReport.parcelId);
    getchar();

    printf("Enter farmer's name:");
    fgets(uploadReport.farmerName, sizeof(uploadReport.farmerName), stdin);
    uploadReport.farmerName[strcspn(uploadReport.farmerName, "\n")]='\0';

    printf("Enter date of visit:");
    fgets(uploadReport.dov, sizeof(uploadReport.dov), stdin);
    uploadReport.dov[strcspn(uploadReport.dov, "\n")]='\0';

    printf("Enter observation:");
    fgets(uploadReport.observation, sizeof(uploadReport.observation), stdin);
    uploadReport.observation[strcspn(uploadReport.observation, "\n")]='\0';

    printf("Report result:");
    fgets(uploadReport.reportResul, sizeof(uploadReport.reportResul), stdin);
    uploadReport.reportResul[strcspn(uploadReport.reportResul, "\n")]='\0';

    printf("Enter recomendetion:");
    fgets(uploadReport.recomendation, sizeof(uploadReport.recomendation), stdin);
    uploadReport.recomendation[strcspn(uploadReport.recomendation, "\n")]='\0';


    fprintf(fp, "%d|%s|%s|%s|%s|%s\n",
            uploadReport.parcelId,
            uploadReport.farmerName,
            uploadReport.dov,
            uploadReport.observation,
            uploadReport.reportResul,
            uploadReport.recomendation);

    fclose(fp);

    printf("Report upload successful.");
}

void manage_report(int id)
{
    printf("Reports of Agent ID %d\n", id);
}

void manage_schedules (int id)
{
    printf("Schedule of Agent ID %d\n", id);
}
