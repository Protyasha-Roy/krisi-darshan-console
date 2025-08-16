#include <stdio.h>
#include <string.h>
#include "login.h"
#include "menus.h"
#include "utils.h"

int checkIdPassword(char filename[], char mode[], char type, int id, char password[])
{
    User user;
    FILE *fp;

    fp = fopen(filename, mode);
    int loggedIn = 0;

    if(fp == NULL)
    {
        printf("\n\tFile not found\n\n");
    }

    while(fscanf(fp, "%d %s %c", &user.id, user.password, &user.type) != EOF)
    {
        if((id == user.id) && (strcmp(password, user.password) == 0) && (user.type == type))
        {
            loggedIn = 1;
            break;
        }
    }

    fclose(fp);
    return loggedIn;
}

void login(int option, int id, char password[])
{
    clear_screen();
    int loggedIn;

    switch(option)
    {
    case 1:
        loggedIn = checkIdPassword("Users.txt", "r", 'f', id, password);
        loggedIn ?  FarmerMenu(id) : (printf("\n\tID or password is wrong. Try again!\n\n"), loginForm(1));
        break;
    case 2:
        loggedIn = checkIdPassword("Users.txt", "r", 't', id, password);
        loggedIn ?  AgentMenu(id) : (printf("\n\tID or password is wrong. Try again!\n\n"), loginForm(2));
        break;
    case 3:
        loggedIn = checkIdPassword("Users.txt", "r", 'a', id, password);
        loggedIn ? adminMenu(id) : (printf("\n\tID or password is wrong. Try again!\n\n"), loginForm(3));
        break;

    default:
        printf("\n\tInvalid Option chosen!\n\n");
        break;
    }
}

void loginForm(int option)
{
    User user;

    printf("\t-> Enter your ID: ");
    scanf("%d", &user.id);

    getchar();
    printf("\t-> Enter your password: ");
    scanf("%s", user.password);
    getchar();

    login(option, user.id, user.password);
}

void registration() {
    clear_screen();
    FILE *fp;
    FILE *fp2;

    fp = fopen("Farmers.txt", "a");
    fp2 = fopen("Users.txt", "a");

    Farmer farmer;
    User user;

    do {
        farmer.id = generateId(0, 2147483640);
    } while(checkIdDuplication(fp2, farmer.id) == 1);

    user.id = farmer.id;
    user.type = 'f';

    printf("\tPERSONAL DETAILS\n\n");

    getchar();
    printf("\t-> Enter full name: ");
    fgets(farmer.fullName, sizeof(farmer.fullName), stdin);
    farmer.fullName[strcspn(farmer.fullName, "\n")] = '\0';

    printf("\t-> Enter DOB(YYYY-MM-DD): ");
    fgets(farmer.dob, sizeof(farmer.dob), stdin);
    farmer.dob[strcspn(farmer.dob, "\n")] = '\0';

    printf("\t-> Enter gender(M/F/O): ");
    scanf("%c", &farmer.gender);

    getchar();
    printf("\t-> Enter NID: ");
    fgets(farmer.nid, sizeof(farmer.nid), stdin);
    farmer.nid[strcspn(farmer.nid, "\n")] = '\0';

    printf("\t-> Enter literacy level: ");
    fgets(farmer.literacy, sizeof(farmer.literacy), stdin);
    farmer.literacy[strcspn(farmer.literacy, "\n")] = '\0';

    printf("\t-> Enter mobile number: ");
    fgets(farmer.mobile, sizeof(farmer.mobile), stdin);
    farmer.mobile[strcspn(farmer.mobile, "\n")] = '\0';

    printf("\t-> Enter email address: ");
    fgets(farmer.email, sizeof(farmer.email), stdin);
    farmer.email[strcspn(farmer.email, "\n")] = '\0';

    printf("\t-> Enter full address: ");
    fgets(farmer.address, sizeof(farmer.address), stdin);
    farmer.address[strcspn(farmer.address, "\n")] = '\0';

    printf("\t-> Enter postal code: ");
    scanf("%d", &farmer.postal_code);

    getchar();
    printf("\t-> Total years of experience: ");
    scanf("%f", &farmer.farming_experience);

    printf("\n\tFARMING DETAILS\n\n");

    getchar();
    printf("\t-> Total area of land: ");
    scanf("%f", &farmer.area);

    getchar();
    printf("\t-> Main crops grown: ");
    fgets(farmer.crops, sizeof(farmer.crops), stdin);
    farmer.crops[strcspn(farmer.crops, "\n")] = '\0';

    printf("\t-> Number of land parcels: ");
    scanf("%d", &farmer.land_parcels);

    getchar();
    printf("\t-> Ownership type(O/L/S): ");
    scanf("%c", &farmer.ownership);

    printf("\t-> \n\tBANK DETAILS\n");

    getchar();
    printf("\t-> Enter bank account number: ");
    fgets(farmer.bank_number, sizeof(farmer.bank_number), stdin);
    farmer.bank_number[strcspn(farmer.bank_number, "\n")] = '\0';

    printf("\t-> Branch code: ");
    scanf("%d", &farmer.branch_code);

    getchar();
    printf("\t-> Enter name of the bank: ");
    fgets(farmer.bank_name, sizeof(farmer.bank_name), stdin);
    farmer.bank_name[strcspn(farmer.bank_name, "\n")] = '\0';

    printf("\t-> Enter linked mobile number: ");
    fgets(farmer.linked_number, sizeof(farmer.linked_number), stdin);
    farmer.linked_number[strcspn(farmer.linked_number, "\n")] = '\0';

    printf("\t-> Now create password for Krishi-Darshan account: ");
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

    printf("\n\tRegistration is complete. ID is: %d. Use this ID to login.\n\n", user.id);
}
