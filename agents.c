#include <stdio.h>
#include <string.h>
#include "assigned_parcel.h"
#include "agents.h"
#include "utils.h"

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
    int selected_option;

    printf("\n");
    printf("1: Update land parcel report.\n");
    printf("2: Delete land parcel report.\n");
    printf("3: Search land parcel report.\n");
    printf("\nChoose an option: ");
    scanf("%d", &selected_option);

    switch(selected_option)
    {
    case 1:
        update_parcel_report();
        break;
    case 2:
        delete_parcel_report();
        break;
    case 3:
        search_parcel_report();
        break;
    default:
        printf("Please enter a valid option(1-3).");
        break;
    }

}




void manage_schedules (int id)
{
    printf("Schedule of Agent ID %d\n", id);
}


void update_parcel_report()
{
    clear_screen();

    FILE *fp = fopen("Land_Parcel_Report.txt", "r");
    FILE *temp = fopen("Temp_Report.txt", "w");

    if (fp == NULL || temp == NULL)
    {
        printf("Error! File not found.\n");
        return;
    }

    int id;
    int id_found = 0;

    UploadReport updateReport;

    printf("Enter Parcel ID to update: ");
    scanf("%d", &id);
    getchar();

    while (fscanf(fp, "%d|%99[^|]|%14[^|]|%499[^|]|%499[^|]|%99[^\n]",
                  &updateReport.parcelId,
                  updateReport.farmerName,
                  updateReport.dov,
                  updateReport.observation,
                  updateReport.reportResul,
                  updateReport.recomendation) != EOF)
    {
        if (updateReport.parcelId == id)
        {
            id_found = 1;

            printf("\nUpdate changes:\n");

            printf("Farmer Name: ");
            fgets(updateReport.farmerName, sizeof(updateReport.farmerName), stdin);
            updateReport.farmerName[strcspn(updateReport.farmerName, "\n")]='\0';

            printf("Date of Visit (DD/MM/YYYY): ");
            fgets(updateReport.dov, sizeof(updateReport.dov), stdin);
            updateReport.dov[strcspn(updateReport.dov, "\n")]='\0';

            printf("Observation: ");
            fgets(updateReport.observation, sizeof(updateReport.observation), stdin);
            updateReport.observation[strcspn(updateReport.observation, "\n")]='\0';

            printf("Report Result: ");
            fgets(updateReport.reportResul, sizeof(updateReport.reportResul), stdin);
            updateReport.reportResul[strcspn(updateReport.reportResul, "\n")]='\0';

            printf("Recommendation: ");
            fgets(updateReport.recomendation, sizeof(updateReport.recomendation), stdin);
            updateReport.recomendation[strcspn(updateReport.recomendation, "\n")]='\0';
        }


        fprintf(temp, "%d|%s|%s|%s|%s|%s\n",
                updateReport.parcelId,
                updateReport.farmerName,
                updateReport.dov,
                updateReport.observation,
                updateReport.reportResul,
                updateReport.recomendation);
    }

    fclose(fp);
    fclose(temp);

    remove("Land_Parcel_Report.txt");
    rename("Temp_Report.txt", "Land_Parcel_Report.txt");

    if (id_found)
        printf("\nParcel report with ID %d updated successfully.\n", id);
}




void delete_parcel_report()
{
    clear_screen();

    FILE *fp = fopen("Land_Parcel_Report.txt", "r");
    FILE *temp = fopen("Temp_Report.txt", "w");


    if (fp == NULL||temp == NULL)
    {
        printf("Error! File not found.\n");
        return;
    }


    int id;
    int id_delete = 0;

    UploadReport updateReport;

    printf("Enter Parcel ID to delete: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d|%99[^|]|%14[^|]|%499[^|]|%499[^|]|%99[^\n]",
                  &updateReport.parcelId,
                  updateReport.farmerName,
                  updateReport.dov,
                  updateReport.observation,
                  updateReport.reportResul,
                  updateReport.recomendation) != EOF)
    {
        if (updateReport.parcelId != id)
        {
            fprintf(temp, "%d|%s|%s|%s|%s|%s\n",
                    updateReport.parcelId,
                    updateReport.farmerName,
                    updateReport.dov,
                    updateReport.observation,
                    updateReport.reportResul,
                    updateReport.recomendation);
        }
        else
        {
            id_delete = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("Land_Parcel_Report.txt");
    rename("Temp_Report.txt", "Land_Parcel_Report.txt");

    if (id_delete)
        printf("\nParcel report with ID %d deleted successfully.\n", id);
}


void search_parcel_report()
{
    clear_screen();

    int parcelid;
    int id_matched=0;

    printf("\nSearch your land parcel report by id:");
    scanf("%d",&parcelid);


    FILE *fp = fopen("Land_Parcel_Report.txt", "r");

    if(fp==NULL)
    {
        printf("Error! File not found.\n");
        return;
    }

    UploadReport uploadReport;

    while (fscanf(fp, "%d|%99[^|]|%14[^|]|%499[^|]|%499[^|]|%99[^\n]",
                  &uploadReport.parcelId,
                  uploadReport.farmerName,
                  uploadReport.dov,
                  uploadReport.observation,
                  uploadReport.reportResul,
                  uploadReport.recomendation) != EOF)

    {
        if(parcelid == uploadReport.parcelId)
        {

            id_matched=1;

            printf("\n\n");
            printf("Land parcel Id:    %d\n",uploadReport.parcelId);
            printf("Farmer's name:     %s\n",uploadReport.farmerName);
            printf("Date of visit:     %s\n",uploadReport.dov);
            printf("Observation:       %s\n",uploadReport.observation);
            printf("Report result:     %s\n",uploadReport.reportResul);
            printf("Recommendation:    %s\n",uploadReport.recomendation);
            break;
        }
    }

    fclose(fp);

    if(!id_matched)
    {
        printf("Parcel Id %d not found!\n",parcelid);
    }

}
