#include <stdio.h>
#include <string.h>
#include "login.h"
#include "utils.h"

//        while(fscanf(fp,
//                     "%d|%s|%s|%c|%s|%s|%s|%s|%s|%d|%f|%f|%d|%s|%c|%s|%s|%d|%s",
//                     &farmer.id, farmer.fullName, farmer.dob, &farmer.gender, farmer.nid,
//                      farmer.literacy, farmer.mobile, farmer.email, farmer.address, &farmer.postal_code,
//                      farmer.farming_experience, &farmer.area, &farmer.land_parcels, farmer.crops, &farmer.ownership,
//                      farmer.bank_number, farmer.bank_name, &farmer.branch_code, farmer.linked_number) != EOF)
//        {
//            registeredFarmer.id = farmer.id;
//            registeredFarmer.fullName = farmer.fullName;
//        }


void checkIdPassword(char filename[], char mode[], char type, int option, int id, char password[])
{
    User user;
    FILE *fp;

    fp = fopen(filename, mode);
    int loggedIn = 0;

    if(fp == NULL)
    {
        printf("FIle not found");
    }

    while(fscanf(fp, "%d %s %c", &user.id, user.password, &user.type) != EOF)
    {
        if((id == user.id) && (strcmp(password, user.password) == 0) && (user.type == type))
        {
            loggedIn = 1;
            break;
        }
    }

    if(loggedIn == 1)
    {
        printf("Logged in\n");
    }
    else
    {
        printf("Did not match\n");
        loginForm(option);
    }

    fclose(fp);
}

void login(int option, int id, char password[])
{
    User user;
    FILE *fp;

    switch(option)
    {
    case 1:
        checkIdPassword("Users.txt", "r", 'f', option, id, password);
        break;
    case 2:
        checkIdPassword("Users.txt", "r", 't', option, id, password);
        break;
    case 3:
        checkIdPassword("Users.txt", "r", 'a', option, id, password);
        break;

    default:
        printf("Invalid Option chosen!\n");
        break;
    }
}

void loginForm(int option)
{
    User user;

    printf("Enter your ID: ");
    scanf("%d", &user.id);
    printf("Enter your password: ");
    scanf("%s", user.password);

    login(option, user.id, user.password);
}

void registration() {
    FILE *fp;
    fp = fopen("Farmers.txt", "a");

    Farmer farmer;

    farmer.id = generateId(0, 2147483640);

    printf("Register as a farmer\n\n");

    printf("\tPERSONAL DETAILS\n");

    printf("Enter your full name: ");
    fgets(farmer.fullName, sizeof(farmer.fullName), stdin);
    getchar();

    printf("Enter your DOB(YYYY-MM-DD): ");
    fgets(farmer.dob, sizeof(farmer.dob), stdin);
    getchar();

    printf("Enter your gender(M/F/O): ");
    scanf("%c", &farmer.gender);
    getchar();

    printf("Enter your NID: ");
    fgets(farmer.nid, sizeof(farmer.nid), stdin);
    getchar();

    printf("Enter your literacy level: ");
    fgets(farmer.literacy, sizeof(farmer.literacy), stdin);
    getchar();

    printf("Enter your mobile number: ");
    fgets(farmer.mobile, sizeof(farmer.mobile), stdin);
    getchar();

    printf("Enter your email: ");
    fgets(farmer.email, sizeof(farmer.email), stdin);
    getchar();

    printf("Enter your full address: ");
    fgets(farmer.address, sizeof(farmer.address), stdin);
    getchar();

    printf("Enter your postal code: ");
    scanf("%d", &farmer.postal_code);
    getchar();

    printf("Total years of experience: ");
    scanf("%f", &farmer.farming_experience);
    getchar();

    printf("\n\tFARMING DETAILS\n");

    printf("Total area of land: ");
    scanf("%f", &farmer.area);
    getchar();

    printf("Main crops grown: ");
    fgets(farmer.crops, sizeof(farmer.crops), stdin);
    getchar();

    printf("Number of land parcels: ");
    scanf("%d", &farmer.land_parcels);
    getchar();

    printf("Ownership type(O/L/S): ");
    scanf("%c", &farmer.ownership);
    getchar();

    printf("\n\tBANK DETAILS\n");

    printf("Enter bank account number: ");
    fgets(farmer.bank_number, sizeof(farmer.bank_number), stdin);
    getchar();

    printf("Branch code: ");
    scanf("%d", &farmer.branch_code);
    getchar();

    printf("Enter name of the bank: ");
    fgets(farmer.bank_name, sizeof(farmer.bank_name), stdin);
    getchar();

    printf("Enter linked mobile number: ");
    fgets(farmer.linked_number, sizeof(farmer.linked_number), stdin);
    getchar();

    fprintf(fp,
        "%d|%s|%s|%c|%s|%s|%s|%s|%s|%d|%.2f|%.2f|%d|%s|%c|%s|%s|%d|%s\n",
        farmer.id,
        farmer.fullName,
        farmer.dob,
        farmer.gender,
        farmer.nid,
        farmer.literacy,
        farmer.mobile,
        farmer.email,
        farmer.address,
        farmer.postal_code,
        farmer.farming_experience,
        farmer.area,
        farmer.land_parcels,
        farmer.crops,
        farmer.ownership,
        farmer.bank_number,
        farmer.bank_name,
        farmer.branch_code,
        farmer.linked_number
    );

    fclose(fp);

    printf("\nFarmer data saved.\n");
}
