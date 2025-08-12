#include <stdio.h>
#include <string.h>
#include "menus.h"
#include "login.h"
#include "farmer.h"
#include "parcels.h"
#include "utils.h"

void delete_landparcels()
{
    FILE *fp;
    FILE *temp;
    fp=fopen("Parcels.txt", "r");
    temp=fopen("temp3.txt", "w");

    Parcel p,tempParcel;

    int id;
    int id_matched=0;

    int chosen_parcelId;
        printf("Enter ID of parcel to edit: ");
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
            id_matched=1;

            fprintf(temp,"%d|%d|%s|%f|%s|%s|%s\n",
                    p.id,
                    p.farmerId,
                    p.location,
                    p.area,
                    p.dop,
                    p.soilType,
                    p.crops);
        }

        if(!id_matched)
    {
        printf("Parcel %d not found in the system! \n", id);
    }
    }

    fclose(fp);
    fclose(temp);

    remove("Parcels.txt");
    rename("temp3.txt", "Parcels.txt");

    printf("Deleted Parcel successfully!\n");

}


void edit_landparcels()
{
    FILE *fp;
    FILE *temp;
    fp= fopen("Parcels.txt", "r");

    if(fp==NULL)
    {
        printf("Error! File not found!\n");
        return;
    }

    Parcel p,tempParcel;

        int chosen_parcelId;
        printf("Enter ID of parcel to edit: ");
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

                printf("Enter the number of the detail you want to edit (1-5): ");
                scanf("%d", &land_parcel);
                getchar();

                switch(land_parcel)
                {
                case 1:
                    printf("Enter new Location: ");
                    fgets(p.location, sizeof(p.location), stdin);
                    p.location[strcspn(p.location, "\n")]='\0';
                    break;
                case 2:
                    printf("Enter updated area (in acres): ");
                    scanf("%f", &p.area);
                    getchar();
                    break;
                case 3:
                    printf("Enter updated date of purchase: ");
                    fgets(p.dop, sizeof(p.dop), stdin);
                    p.dop[strcspn(p.dop, "\n")]='\0';
                    break;
                case 4:
                    printf("Enter updated soil type: ");
                    fgets(p.soilType, sizeof(p.soilType), stdin);
                    p.soilType[strcspn(p.soilType, "\n")]='\0';
                    break;
                case 5:
                    printf("Enter new types of crops grown: ");
                    fgets(p.crops, sizeof(p.crops), stdin);
                    p.crops[strcspn(p.crops, "\n")]='\0';
                    break;
                default:
                    printf("Invalid choice! Please enter a number between 1-5: ");
                    continue;
                }

                printf("Parcel updated successfully. \n");

                printf("Do you want to edit another field? (Y/N): ");
                scanf(" %c", &continue_editing);
                getchar();
            }
            while(continue_editing == 'Y' || continue_editing == 'y');
        }
        else
        {
            printf("Error! Invalid Parcel ID!\n");
        }

    fp=fopen("Parcels.txt", "r");
    temp=fopen("temp2.txt", "w");

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


    printf("Parcel details updated successfully!\n");
}


int check_Duplication(FILE *fp2, int ParcelId)
{
    int id;
    while(fscanf(fp2, "%d", &id) != EOF)
    {
        if(id != ParcelId)
        {
            return 0;
        }
        else
        {
            return 1;
        }
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
        p.id = generateId(0, 37864632);
    }

    while(check_Duplication(fp2, p.id) == 1);

    fclose(fp2);

    printf("Enter the details of the new land parcel: \n");

    printf("Enter the location of the new land parcel: ");
    getchar();
    fgets(p.location, sizeof(p.location), stdin);
    p.location[strcspn(p.location, "\n")] = '\0';

    printf("Enter the area in acres of the new land parcel: ");
    scanf("%f", &p.area);
    getchar();

    printf("Enter the Date of Purchase of the new land parcel (YYYY-MM-DD): ");
    fgets(p.dop, sizeof(p.dop), stdin);
    p.dop[strcspn(p.dop, "\n")] = '\0';

    printf("Enter the soil type of the new land parcel: ");
    fgets(p.soilType, sizeof(p.soilType), stdin);
    p.soilType[strcspn(p.soilType, "\n")] = '\0';

    printf("Enter the type of crops grown in the new land parcel: ");
    fgets(p.crops, sizeof(p.crops), stdin);
    p.crops[strcspn(p.crops, "\n")] = '\0';


    fprintf(fp,
            "\n%d|%d|%s|%f|%s|%s|%s\n",
            p.id,
            p.farmerId,
            p.location,
            p.area,
            p.dop,
            p.soilType,
            p.crops);
    fclose(fp);
    printf("New Land Parcel Added.");
    }



