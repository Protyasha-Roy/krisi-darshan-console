#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menus.h"
#include "assigned_parcel.h"
#include "agents.h"
#include "utils.h"
#include "parcel_report.h"

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

    while (fscanf(fp, "%d|%d|%d|%d|%c|%99[^|]|%f|%14[^|]|%29[^|]|%49[^\n]",
                  &assignedParcel.parcelId,
                  &assignedParcel.id,
                  &assignedParcel.agentId,
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

            printf("Parcel's Id:            %d\n",assignedParcel.parcelId);
            printf("Assigned Id:            %d\n",assignedParcel.id);
            printf("Agent's Id:             %d\n",assignedParcel.agentId);
            printf("Farmer's Id:            %d\n",assignedParcel.farmerId);
            printf("Land parcel status:     %c\n",assignedParcel.status);
            printf("Location:               %s\n",assignedParcel.location);
            printf("Area:                   %.1f\n",assignedParcel.area);
            printf("Date:                   %s\n",assignedParcel.dop);
            printf("Soil type:              %s\n",assignedParcel.soilType);
            printf("Crops:                  %s\n",assignedParcel.crops);
            break;
        }

        while (1)
    {
        int back_exit;
        printf("Choose an option: \n");
        printf("1. 'B' - Go back\n2. 'E' - Exit: \n");
        printf("Enter you choice: ");
        scanf("%d", &back_exit);
        getchar();

        switch(back_exit)
        {
        case 1:
            clear_screen();
            AgentMenu(agentId);
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

    while (1)
    {
        int back_exit;
        printf("Choose an option: \n");
        printf("1. 'B' - Go back\n2. 'E' - Exit: \n");
        printf("Enter you choice: ");
        scanf("%d", &back_exit);
        getchar();

        switch(back_exit)
        {
        case 1:
            clear_screen();
            AgentMenu(id);
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

void manage_report(int id)
{
    int selected_option;

    printf("\n");
    printf("1: Update land parcel report.\n");
    printf("2: Delete land parcel report.\n");
    printf("3: Search land parcel report.\n");
    printf("4. Go back\n");
    printf("5. Exit\n");

    printf("\nChoose an option: ");
    scanf("%d", &selected_option);

    switch(selected_option)
    {
    case 1:
        update_parcel_report(id);
        break;
    case 2:
        delete_parcel_report(id);
        break;
    case 3:
        search_parcel_report(id);
        break;
    case 4:
        clear_screen();
        AgentMenu(id);
        break;
    case 5:
        exit(1);
        break;
    default:
        printf("Please enter a valid option(1-3).");
        break;
    }

}


void manage_schedules (int id)
{
    int choosen_opt;

    printf("1. Create schedule.\n");
    printf("2. View schedule.\n");
    printf("3. Update schedule.\n");
    printf("4. Delete schedule.\n");
    printf("5. Go back.\n");

    printf("\nChoose an option:");
    scanf("%d",&choosen_opt);

        switch(choosen_opt)
    {
    case 1:
        create_schedule(id);
        break;
    case 2:
        view_schedule(id);
        break;
    case 3:
        update_schedule(id);
        break;
    case 4:
        delete_schedule(id);
        break;
    case 5:
        clear_screen();
        AgentMenu(id);
        break;
    case 6:
        exit(1);
        break;
    default:
        printf("Please enter a valid option(1-4).");
        break;
}
}


void create_schedule(int id)
{

    FILE *fp = fopen("Schedule.txt", "a");

    if (fp == NULL)
    {
        printf("Error! File not found.\n");
        return;
    }

    Schedule s;

    printf("Enter parcel Id: ");
    scanf("%d", &s.parcelId);
    getchar();

    printf("Enter agent's Id: ");
    scanf("%d", &s.agentId);
    getchar();

    printf("\nEnter information about schedule:\n");
    printf("Enter Farmer Name: ");
    fgets(s.farmerName, sizeof(s.farmerName), stdin);
    s.farmerName[strcspn(s.farmerName, "\n")]='\0';

    printf("Enter Location: ");
    fgets(s.location, sizeof(s.location), stdin);
    s.location[strcspn(s.location, "\n")]='\0';

    printf("Enter Date to Visit (DD/MM/YYYY): ");
    fgets(s.dov, sizeof(s.dov), stdin);
    s.dov[strcspn(s.dov, "\n")]='\0';

    printf("Enter Scheme Type: ");
    fgets(s.schemeType, sizeof(s.schemeType), stdin);
    s.schemeType[strcspn(s.schemeType, "\n")]='\0';

    fprintf(fp, "%d|%d|%s|%s|%s|%s\n",
            s.parcelId,s.agentId,s.farmerName,s.location,s.dov,s.schemeType);

    fclose(fp);

    printf("\nSchedule created.\n");

    while (1)
    {
        int back_exit;
        printf("Choose an option: \n");
        printf("1. 'B' - Go back\n2. 'E' - Exit: \n");
        printf("Enter you choice: ");
        scanf("%d", &back_exit);
        getchar();

        switch(back_exit)
        {
        case 1:
            clear_screen();
            manage_schedules(id);
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



void view_schedule(int id)
{

    int found = 0;

    printf("Enter agent Id:");
    scanf("%d",&id);
    getchar();

    FILE *fp = fopen("Schedule.txt", "r");

    if (!fp)
    {
        printf("Error! File not found.\n");
        return;
    }

    Schedule s;

    printf("\nSchedules for agent %d:\n",id);

    while (fscanf(fp, "%d|%d|%99[^|]|%99[^|]|%14[^|]|%49[^\n]",
                  &s.parcelId,
                  &s.agentId,
                  s.farmerName,
                  s.location,
                  s.dov,
                  s.schemeType) != EOF)
    {
        if (s.agentId == id)
        {
            found = 1;
            printf("Parcel Id:         %d\n",s.parcelId);
            printf("Farmer's name:     %s\n",s.farmerName);
            printf("Location:          %s\n",s.location);
            printf("Date to visit:     %s\n",s.dov);
            printf("Scheme type:       %s\n",s.schemeType);
            printf("\n\n");
        }
    }

    fclose(fp);

    if (!found)
    {
        printf("No schedules found.\n");
    }
    while (1)
    {
        int back_exit;
        printf("Choose an option: \n");
        printf("1. 'B' - Go back\n2. 'E' - Exit: \n");
        printf("Enter you choice: ");
        scanf("%d", &back_exit);
        getchar();

        switch(back_exit)
        {
        case 1:
            clear_screen();
            manage_schedules(id);
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



void update_schedule(int agentId)
{
    int id;
    int found = 0;

    printf("Enter parcel Id to update: ");
    scanf("%d", &id);
    getchar();

    FILE *fp = fopen("Schedule.txt", "r");
    FILE *temp = fopen("TempSchedule.txt", "w");

    if (!fp || !temp)
    {
        printf("Error! File not found.\n");
        return;
    }

    Schedule s;

    while (fscanf(fp, "%d|%d|%99[^|]|%99[^|]|%14[^|]|%49[^\n]\n",
                  &s.parcelId,
                  &s.agentId,
                  s.farmerName,
                  s.location,
                  s.dov,
                  s.schemeType) != EOF)
    {
        if (s.parcelId == id)
        {
            found = 1;

            printf("\nUpdate schedule:\n");

            printf("Enter farmer name: ");
            fgets(s.farmerName, sizeof(s.farmerName), stdin);
            s.farmerName[strcspn(s.farmerName, "\n")]='\0';

            printf("Enter location: ");
            fgets(s.location, sizeof(s.location), stdin);
            s.location[strcspn(s.location, "\n")]='\0';

            printf("Enter date of visit: ");
            fgets(s.dov, sizeof(s.dov), stdin);
            s.dov[strcspn(s.dov, "\n")]='\0';

            printf("Enter scheme type: ");
            fgets(s.schemeType, sizeof(s.schemeType), stdin);
            s.schemeType[strcspn(s.schemeType, "\n")]='\0';

            printf("\nSchedule updated!\n");
        }


        fprintf(temp, "%d|%d|%s|%s|%s|%s\n",
                s.parcelId,
                s.agentId,
                s.farmerName,
                s.location,
                s.dov,
                s.schemeType);
    }

    fclose(fp);
    fclose(temp);

    remove("Schedule.txt");
    rename("TempSchedule.txt", "Schedule.txt");

    if (!found)
    {
        printf("No schedules found.\n");
    }

    while (1)
    {
        int back_exit;
        printf("Choose an option: \n");
        printf("1. 'B' - Go back\n2. 'E' - Exit: \n");
        printf("Enter you choice: ");
        scanf("%d", &back_exit);
        getchar();

        switch(back_exit)
        {
        case 1:
            clear_screen();
            manage_schedules(agentId);
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


void delete_schedule(int agentId)
{

  int id;
  int found = 0;

    printf("Enter parcel Id to delete: ");
    scanf("%d", &id);
    getchar();

    FILE *fp = fopen("Schedule.txt", "r");
    FILE *temp = fopen("TempSchedule.txt", "w");

    if (!fp || !temp)
    {
        printf("Error! File not found.\n");
        return;
    }

    Schedule s;

    while (fscanf(fp, "%d|%d|%99[^|]|%99[^|]|%14[^|]|%49[^\n]\n",
                  &s.parcelId,
                  &s.agentId,
                  s.farmerName,
                  s.location,
                  s.dov,
                  s.schemeType) != EOF)
    {
        if (s.parcelId != id)
        {
          fprintf(temp, "%d|%d|%s|%s|%s|%s\n",
                 s.parcelId,
                 s.agentId,
                 s.farmerName,
                 s.location,
                 s.dov,
                 s.schemeType);

        }
        else
          found = 1;
    }

    fclose(fp);
    fclose(temp);

    remove("Schedule.txt");
    rename("TempSchedule.txt", "Schedule.txt");

    if (found)
    {
        printf("\nSchedule with parcel Id %d deleted successfully.\n", id);
    }

    while (1)
    {
        int back_exit;
        printf("Choose an option: \n");
        printf("1. 'B' - Go back\n2. 'E' - Exit: \n");
        printf("Enter you choice: ");
        scanf("%d", &back_exit);
        getchar();

        switch(back_exit)
        {
        case 1:
            clear_screen();
            manage_schedules(agentId);
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

