#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utils.h"
#include <ctype.h>
#include "login.h"


void changePass(int id) {
    FILE *fp;
    FILE *temp;

    fp=fopen("Users.txt", "r");

    User u, tempUser;

    if(fp==NULL)
    {
        printf("Error! File not found!\n");
        return;
    }

    int id_matched=0;

    while (fscanf(fp, "%d %s %c", &tempUser.id, tempUser.password, &tempUser.type)!=EOF)
    {
        if(tempUser.id==id)
        {
            u=tempUser;
            id_matched=1;
            break;
        }
    }
    fclose(fp);

    if(id_matched=1)
    {
        printf("Enter the new password: ");
        getchar();
        fgets(u.password, sizeof(u.password), stdin);
        u.password[strcspn(u.password, "\n")]='\0';
    }

    printf("Password updated successfully!\n");

    fp=fopen("Users.txt", "r");
    temp=fopen("temp.txt", "w");

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

    while (fscanf(fp, "%d %s %c", &tempUser.id, tempUser.password, &tempUser.type)!=EOF)
    {
        if(tempUser.id==u.id)
        {
            fprintf(temp, "%d %s %c\n", u.id, u.password, u.type);
        }
        else
        {
            fprintf(temp, "%d %s %c\n", tempUser.id, tempUser.password, tempUser.type);
        }

    }

    fclose(fp);
    fclose(temp);

    remove("Users.txt");
    rename("temp.txt", "Users.txt");
}

int checkIdDuplication(FILE *fp2, int farmerId)
{
    int id;
    while(fscanf(fp2, "%d", &id) != EOF)
    {
        if(id != farmerId)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}


void clear_screen()
{
    printf("\033[2J\033[H");
    fflush(stdout);
}

int generateId(int lower, int upper)
{
    srand(time(NULL));

    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

char *lowercased_str(char str[])
{
    for(int i = 0; i < strlen(str); i++)
    {
        str[i] = tolower(str[i]);
    }
    str[strlen(str)] = '\0';
    return str;
}
