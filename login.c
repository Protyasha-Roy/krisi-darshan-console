#include <stdio.h>
#include <string.h>
#include "login.h"

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

void login(int option, int id, char password[])
{
    User user;
    FILE *fp;


    switch(option)
    {
    case 1:
        fp = fopen("Users.txt", "r");
        int loggedIn = 0;

        if(fp == NULL)
        {
            printf("FIle not found");
        }

        while(fscanf(fp, "%d %s %c", &user.id, user.password, &user.type) != EOF)
        {
            if((id == user.id) && (strcmp(password, user.password) == 0))
            {
                loggedIn = 1;
                break;
            }
        }

        if(loggedIn == 1) {
            printf("Logged in");
        }
        else {
            printf("Did not match");
        }

        fclose(fp);
        break;
    case 2:
        printf("Login as agent");
        break;
    case 3:
        printf("Login as admin");
        break;
    default:
        printf("Invalid");
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
