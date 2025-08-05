#include <stdio.h>
#include <string.h>
#include "login.h"
#include "menus.h"

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
        printf("Logged in");
        adminMenu();
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
