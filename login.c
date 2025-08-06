#include <stdio.h>
#include <string.h>
#include "login.h"
#include "menus.h"
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
        adminMenu();
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

int checkIdDuplication(FILE *fp2, int *farmerId) {
    int id;
    while(fscanf(fp2, "%d", id) != EOF) {
        if(id != farmerId) {
            return 0;
        }
        else {
            return 1;
        }
    }
}

void registration() {
    FILE *fp;
    FILE *fp2;

    fp = fopen("Farmers.txt", "a");
    fp2 = fopen("Users.txt", "a");

    Farmer farmer;
    User user;

    do {
        farmer.id = generateId(0, 2147483640);

    } while(checkIdDuplication(fp2, &farmer.id) == 1);

    user.id = farmer.id;
    user.type = 'f';

    printf("Register as a farmer\n\n");

    printf("\tPERSONAL DETAILS\n");

    getchar();
    printf("Enter your full name: ");
    fgets(farmer.fullName, sizeof(farmer.fullName), stdin);
    farmer.fullName[strcspn(farmer.fullName, "\n")] = '\0';

    printf("Enter your DOB(YYYY-MM-DD): ");
    fgets(farmer.dob, sizeof(farmer.dob), stdin);
    farmer.dob[strcspn(farmer.dob, "\n")] = '\0';

    printf("Enter your gender(M/F/O): ");
    scanf("%c", &farmer.gender);

    getchar();
    printf("Enter your NID: ");
    fgets(farmer.nid, sizeof(farmer.nid), stdin);
    farmer.nid[strcspn(farmer.nid, "\n")] = '\0';

    printf("Enter your literacy level: ");
    fgets(farmer.literacy, sizeof(farmer.literacy), stdin);
    farmer.literacy[strcspn(farmer.literacy, "\n")] = '\0';

    printf("Enter your mobile number: ");
    fgets(farmer.mobile, sizeof(farmer.mobile), stdin);
    farmer.mobile[strcspn(farmer.mobile, "\n")] = '\0';

    printf("Enter your email: ");
    fgets(farmer.email, sizeof(farmer.email), stdin);
    farmer.email[strcspn(farmer.email, "\n")] = '\0';

    printf("Enter your full address: ");
    fgets(farmer.address, sizeof(farmer.address), stdin);
    farmer.address[strcspn(farmer.address, "\n")] = '\0';

    printf("Enter your postal code: ");
    scanf("%d", &farmer.postal_code);

    getchar();
    printf("Total years of experience: ");
    scanf("%f", &farmer.farming_experience);

    printf("\n\tFARMING DETAILS\n");

    getchar();
    printf("Total area of land: ");
    scanf("%f", &farmer.area);

    getchar();
    printf("Main crops grown: ");
    fgets(farmer.crops, sizeof(farmer.crops), stdin);
    farmer.crops[strcspn(farmer.crops, "\n")] = '\0';

    printf("Number of land parcels: ");
    scanf("%d", &farmer.land_parcels);

    getchar();
    printf("Ownership type(O/L/S): ");
    scanf("%c", &farmer.ownership);

    printf("\n\tBANK DETAILS\n");

    getchar();
    printf("Enter bank account number: ");
    fgets(farmer.bank_number, sizeof(farmer.bank_number), stdin);
    farmer.bank_number[strcspn(farmer.bank_number, "\n")] = '\0';

    printf("Branch code: ");
    scanf("%d", &farmer.branch_code);

    getchar();
    printf("Enter name of the bank: ");
    fgets(farmer.bank_name, sizeof(farmer.bank_name), stdin);
    farmer.bank_name[strcspn(farmer.bank_name, "\n")] = '\0';

    printf("Enter linked mobile number: ");
    fgets(farmer.linked_number, sizeof(farmer.linked_number), stdin);
    farmer.linked_number[strcspn(farmer.linked_number, "\n")] = '\0';

    printf("Now create password for your Krishi-Darshan account: ");
    fgets(user.password, sizeof(user.password), stdin);
    user.password[strcspn(user.password, "\n")] = '\0';

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

    fprintf(fp2, "%d %s %c\n", user.id, user.password, user.type);

    fclose(fp);
    fclose(fp2);

    printf("\nYour registration is complete. Your ID is: %d. Use this ID to login.\n", user.id);
}
