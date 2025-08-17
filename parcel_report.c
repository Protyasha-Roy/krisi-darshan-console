#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "agents.h"
#include "assigned_parcel.h"
#include "utils.h"

void update_parcel_report(int agent_id)
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

    printf("\t ->Enter Parcel ID to update: ");
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

            printf("\n\t Update changes:\n");

            printf("\t ->Farmer Name: ");
            fgets(updateReport.farmerName, sizeof(updateReport.farmerName), stdin);
            updateReport.farmerName[strcspn(updateReport.farmerName, "\n")]='\0';

            printf("\t ->Date of Visit (DD/MM/YYYY): ");
            fgets(updateReport.dov, sizeof(updateReport.dov), stdin);
            updateReport.dov[strcspn(updateReport.dov, "\n")]='\0';

            printf("\t ->Observation: ");
            fgets(updateReport.observation, sizeof(updateReport.observation), stdin);
            updateReport.observation[strcspn(updateReport.observation, "\n")]='\0';

            printf("\t ->Report Result: ");
            fgets(updateReport.reportResul, sizeof(updateReport.reportResul), stdin);
            updateReport.reportResul[strcspn(updateReport.reportResul, "\n")]='\0';

            printf("\t ->Recommendation: ");
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
        printf("\n\t ->Parcel report with ID %d updated successfully.\n", id);

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
            manage_report(agent_id);
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




void delete_parcel_report(int agentId)
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

    printf("\t ->Enter Parcel ID to delete: ");
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
        printf("\n\t ->Parcel report with ID %d deleted successfully.\n", id);

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
            manage_report(agentId);
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


void search_parcel_report(int id)
{
    clear_screen();

    int parcelid;
    int id_matched=0;

    printf("\n\t ->Search your land parcel report by id:");
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
            printf("---------------------------------------------------------------------------------------\n");
            printf("Land parcel Id:    %d\n",uploadReport.parcelId);
            printf("Farmer's name:     %s\n",uploadReport.farmerName);
            printf("Date of visit:     %s\n",uploadReport.dov);
            printf("Observation:       %s\n",uploadReport.observation);
            printf("Report result:     %s\n",uploadReport.reportResul);
            printf("Recommendation:    %s\n",uploadReport.recomendation);
            printf("---------------------------------------------------------------------------------------\n");
            break;
        }
    }

    fclose(fp);

    if(!id_matched)
    {
        printf("Parcel Id %d not found!\n",parcelid);
    }

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
            manage_report(id);
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
