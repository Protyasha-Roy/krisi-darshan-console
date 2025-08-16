#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "admin.h"
#include "menus.h"
#include "agent_utils.h"
#include "login.h"
#include <string.h>

void list_agents(int adminId)
{
    clear_screen();

    FILE *fp = fopen("Agents.txt", "r");
    Agent agent;

    while(fscanf(fp, "%d|%99[^|]|%14[^|]|%c|%19[^|]|%99[^|]|%19[^|]|%49[^|]|%299[^|]|%d|%29[^|]|%49[^|]|%d|%19[^\n]\n",
                 &agent.id,
                 agent.fullName,
                 agent.dob,
                 &agent.gender,
                 agent.nid,
                 agent.literacy,
                 agent.mobile,
                 agent.email,
                 agent.address,
                 &agent.postal_code,
                 agent.bank_number,
                 agent.bank_name,
                 &agent.branch_code,
                 agent.linked_number
                ) != EOF)
    {
        printf("\t\t PERSONAL DETAILS OF AGENT: %s\n", agent.fullName);
        printf("\t-----------------------------------------------------\n");
        printf("\tID:                     %d\n", agent.id);
        printf("\tFull name:              %s\n", agent.fullName);
        printf("\tDate of birth:          %s\n", agent.dob);
        printf("\tGender:                 %c\n", agent.gender);
        printf("\tNID:                    %s\n", agent.nid);
        printf("\tLiteracy level:         %s\n", agent.literacy);
        printf("\tMobile Number:          %s\n", agent.mobile);
        printf("\tEmail address:          %s\n", agent.email);
        printf("\tAddress:                %s\n", agent.address);
        printf("\tPostal Code:            %d\n", agent.postal_code);
        printf("\tBank Account Number:    %s\n", agent.bank_number);
        printf("\tBank Name:              %s\n", agent.bank_name);
        printf("\tBranch Code:            %d\n", agent.branch_code);
        printf("\tBank linked Number:     %s\n", agent.linked_number);
        printf("\t-----------------------------------------------------\n\n");
    }

    fclose(fp);

    while (1)
    {
        int back_exit;
        printf("\nChoose an option: \n");
        printf("1. 'B' - Go back\n2. 'E' - Exit: \n");
        printf("\t-> Enter you choice: ");
        scanf("%d", &back_exit);
        getchar();

        switch(back_exit)
        {
        case 1:
            clear_screen();
            adminMenu(adminId);
            break;
        case 2:
            exit(1);
            break;
        default:
            printf("\n\tError! Please enter a valid option!\n\n");
            continue;
        }
        break;
    }
}

void add_agent(int adminId)
{
    clear_screen();

    FILE *fp;
    FILE *fp2;

    fp = fopen("Agents.txt", "a");
    if (fp == NULL)
    {
        perror("\n\tError opening Agents.txt\n\n");
        return;
    }

    fp2 = fopen("Users.txt", "a");
    if (fp2 == NULL)
    {
        perror("\n\tError opening Users.txt\n\n");
        fclose(fp);
        return;
    }

    Agent agent;
    User user;

    do
    {
        agent.id = generateId(0, 2147483640);
    }
    while(checkIdDuplication(fp2, agent.id) == 1);

    user.id = agent.id;
    user.type = 't';

    printf("\tPERSONAL DETAILS\n");

    getchar();
    printf("\t-> Enter full name: ");
    fgets(agent.fullName, sizeof(agent.fullName), stdin);
    agent.fullName[strcspn(agent.fullName, "\n")] = '\0';

    printf("\t-> Enter DOB(YYYY-MM-DD): ");
    fgets(agent.dob, sizeof(agent.dob), stdin);
    agent.dob[strcspn(agent.dob, "\n")] = '\0';

    printf("\t-> Enter gender(M/F/O): ");
    scanf("%c", &agent.gender);

    getchar();
    printf("\t-> Enter NID: ");
    fgets(agent.nid, sizeof(agent.nid), stdin);
    agent.nid[strcspn(agent.nid, "\n")] = '\0';

    printf("\t-> Enter literacy level: ");
    fgets(agent.literacy, sizeof(agent.literacy), stdin);
    agent.literacy[strcspn(agent.literacy, "\n")] = '\0';

    printf("\t-> Enter mobile number: ");
    fgets(agent.mobile, sizeof(agent.mobile), stdin);
    agent.mobile[strcspn(agent.mobile, "\n")] = '\0';

    printf("\t-> Enter email address: ");
    fgets(agent.email, sizeof(agent.email), stdin);
    agent.email[strcspn(agent.email, "\n")] = '\0';

    printf("\t-> Enter full address: ");
    fgets(agent.address, sizeof(agent.address), stdin);
    agent.address[strcspn(agent.address, "\n")] = '\0';

    printf("\t-> Enter postal code: ");
    scanf("%d", &agent.postal_code);

    printf("\n\tBANK DETAILS\n");

    getchar();
    printf("\t-> Enter bank account number: ");
    fgets(agent.bank_number, sizeof(agent.bank_number), stdin);
    agent.bank_number[strcspn(agent.bank_number, "\n")] = '\0';

    printf("\t-> Branch code: ");
    scanf("%d", &agent.branch_code);

    getchar();
    printf("\t-> Enter name of the bank: ");
    fgets(agent.bank_name, sizeof(agent.bank_name), stdin);
    agent.bank_name[strcspn(agent.bank_name, "\n")] = '\0';

    printf("\t-> Enter linked mobile number: ");
    fgets(agent.linked_number, sizeof(agent.linked_number), stdin);
    agent.linked_number[strcspn(agent.linked_number, "\n")] = '\0';

    printf("\t-> Now create password for Krishi-Darshan account: ");
    fgets(user.password, sizeof(user.password), stdin);
    user.password[strcspn(user.password, "\n")] = '\0';

    fprintf(fp,
            "%d|%s|%s|%c|%s|%s|%s|%s|%s|%d|%s|%s|%d|%s\n",
            agent.id,
            agent.fullName,
            agent.dob,
            agent.gender,
            agent.nid,
            agent.literacy,
            agent.mobile,
            agent.email,
            agent.address,
            agent.postal_code,
            agent.bank_number,
            agent.bank_name,
            agent.branch_code,
            agent.linked_number
           );

    fprintf(fp2, "%d %s %c\n", user.id, user.password, user.type);

    fclose(fp);
    fclose(fp2);

    printf("\n\tAgent registration is complete. ID is: %d.\n", user.id);

    while (1)
    {
        int back_exit;
        printf("\n\tChoose an option: \n");
        printf("\t1. 'B' - Go back\n\t2. 'E' - Exit: \n");
        printf("\t-> Enter you choice: ");
        scanf("%d", &back_exit);
        getchar();

        switch(back_exit)
        {
        case 1:
            clear_screen();
            adminMenu(adminId);
            break;
        case 2:
            exit(1);
            break;
        default:
            printf("\n\tError! Please enter a valid option!\n\n");
            continue;
        }
        break;
    }
}

void update_agent(int adminId)
{
    FILE *fp = fopen("Agents.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    int id;
    Agent agent;
    Agent tempAgent;
    int found = 0;

    if (fp==NULL || temp==NULL)
    {
        printf("\n\tError! File not found!\n\n");
        if (fp) fclose(fp);
        if (temp) fclose(temp);
        return;
    }

    char edit_choice;

    printf("\t-> Enter agent ID that you want to update: ");
    scanf("%d", &id);
    getchar();

    rewind(fp);
    while (fscanf(fp, "%d|%99[^|]|%14[^|]|%c|%19[^|]|%99[^|]|%19[^|]|%49[^|]|%299[^|]|%d|%29[^|]|%49[^|]|%d|%19[^\n]\n",
                  &tempAgent.id,
                  tempAgent.fullName,
                  tempAgent.dob,
                  &tempAgent.gender,
                  tempAgent.nid,
                  tempAgent.literacy,
                  tempAgent.mobile,
                  tempAgent.email,
                  tempAgent.address,
                  &tempAgent.postal_code,
                  tempAgent.bank_number,
                  tempAgent.bank_name,
                  &tempAgent.branch_code,
                  tempAgent.linked_number) != EOF)
    {
        if (tempAgent.id == id)
        {
            agent = tempAgent;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\n\tAgent with ID %d not found.\n\n", id);
        fclose(fp);
        fclose(temp);
        remove("temp.txt");
        return;
    }

    printf("\tAre you sure you want to edit field agent? (Y/N): ");
    scanf(" %c", &edit_choice);
    getchar();

    if(edit_choice=='Y' || edit_choice=='y')
    {
        char continue_editing;

        do
        {
            int personal_detail;

            printf("\t-----------------------------------\n");
            printf("\t1. Full Name\n");
            printf("\t2. Date of Birth (YYYY-MM-DD)\n");
            printf("\t3. Gender: (M/F/O)\n");
            printf("\t4. NID\n");
            printf("\t5. Literacy level\n");
            printf("\t6. Mobile number\n");
            printf("\t7. Email address\n");
            printf("\t8. Address\n");
            printf("\t9. Postal code\n");
            printf("\t10. Bank number\n");
            printf("\t11. Bank name\n");
            printf("\t12. Bbranch code\n");
            printf("\t13. Linked number\n");
            printf("\t-----------------------------------\n\n");

            printf("\t-> Enter the number of the detail you want to edit (1-13): ");
            scanf("%d", &personal_detail);
            getchar();

            switch(personal_detail)
            {
            case 1:
                printf("\t-> Enter new Full Name: ");
                fgets(agent.fullName, sizeof(agent.fullName), stdin);
                agent.fullName[strcspn(agent.fullName, "\n")]='\0';
                break;
            case 2:
                printf("\t-> Enter new Date of Birth (YYYY-MM-DD): ");
                fgets(agent.dob, sizeof(agent.dob), stdin);
                agent.dob[strcspn(agent.dob, "\n")]='\0';
                break;
            case 3:
                printf("\t-> Enter new Gender: (M/F/O) ");
                scanf(" %c", &agent.gender);
                getchar();
                break;
            case 4:
                printf("\t-> Enter new NID: ");
                fgets(agent.nid, sizeof(agent.nid), stdin);
                agent.nid[strcspn(agent.nid, "\n")]='\0';
                break;
            case 5:
                printf("\t-> Enter new literacy level: ");
                fgets(agent.literacy, sizeof(agent.literacy), stdin);
                agent.literacy[strcspn(agent.literacy, "\n")]='\0';
                break;
            case 6:
                printf("\t-> Enter new mobile number: ");
                fgets(agent.mobile, sizeof(agent.mobile), stdin);
                agent.mobile[strcspn(agent.mobile, "\n")]='\0';
                break;
            case 7:
                printf("\t-> Enter new email address: ");
                fgets(agent.email, sizeof(agent.email), stdin);
                agent.email[strcspn(agent.email, "\n")]='\0';
                break;
            case 8:
                printf("\t-> Enter new address: ");
                fgets(agent.address, sizeof(agent.address), stdin);
                agent.address[strcspn(agent.address, "\n")]='\0';
                break;
            case 9:
                printf("\t-> Enter new postal code: ");
                scanf("%d", &agent.postal_code);
                getchar();
                break;
            case 10:
                printf("\t-> Enter new bank number: ");
                fgets(agent.bank_number, sizeof(agent.bank_number), stdin);
                agent.bank_number[strcspn(agent.bank_number, "\n")]='\0';
                break;
            case 11:
                printf("\t-> Enter new bank name: ");
                fgets(agent.bank_name, sizeof(agent.bank_name), stdin);
                agent.bank_name[strcspn(agent.bank_name, "\n")]='\0';
                break;
            case 12:
                printf("\t-> Enter new branch code: ");
                scanf("%d", &agent.branch_code);
                getchar();
                break;
            case 13:
                printf("\t-> Enter new linked number: ");
                fgets(agent.linked_number, sizeof(agent.linked_number), stdin);
                agent.linked_number[strcspn(agent.linked_number, "\n")]='\0';
                break;
            default:
                printf("\n\tInvalid choice! Please enter a number between 1-13: ");
                continue;
            }

            printf("\n\tDetail updated successfully.\n\n");

            printf("\t-> Do you want to edit another field? (Y/N): ");
            scanf(" %c", &continue_editing);
            getchar();
        }
        while(continue_editing == 'Y' || continue_editing == 'y');
    }
    else
    {
        printf("\n\tEdit cancelled.\n\n");
        fclose(fp);
        fclose(temp);
        remove("temp.txt");
        return;
    }

    rewind(fp);

    while(fscanf(fp, "%d|%99[^|]|%14[^|]|%c|%19[^|]|%99[^|]|%19[^|]|%49[^|]|%299[^|]|%d|%29[^|]|%49[^|]|%d|%19[^\n]\n",
                 &tempAgent.id,
                 tempAgent.fullName,
                 tempAgent.dob,
                 &tempAgent.gender,
                 tempAgent.nid,
                 tempAgent.literacy,
                 tempAgent.mobile,
                 tempAgent.email,
                 tempAgent.address,
                 &tempAgent.postal_code,
                 tempAgent.bank_number,
                 tempAgent.bank_name,
                 &tempAgent.branch_code,
                 tempAgent.linked_number) != EOF)
    {

        if(tempAgent.id == id)
        {
            fprintf(temp, "%d|%s|%s|%c|%s|%s|%s|%s|%s|%d|%s|%s|%d|%s\n",
                    agent.id,
                    agent.fullName,
                    agent.dob,
                    agent.gender,
                    agent.nid,
                    agent.literacy,
                    agent.mobile,
                    agent.email,
                    agent.address,
                    agent.postal_code,
                    agent.bank_number,
                    agent.bank_name,
                    agent.branch_code,
                    agent.linked_number);
        }
        else
        {
            fprintf(temp, "%d|%s|%s|%c|%s|%s|%s|%s|%s|%d|%s|%s|%d|%s\n",
                    tempAgent.id,
                    tempAgent.fullName,
                    tempAgent.dob,
                    tempAgent.gender,
                    tempAgent.nid,
                    tempAgent.literacy,
                    tempAgent.mobile,
                    tempAgent.email,
                    tempAgent.address,
                    tempAgent.postal_code,
                    tempAgent.bank_number,
                    tempAgent.bank_name,
                    tempAgent.branch_code,
                    tempAgent.linked_number);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("Agents.txt");
    rename("temp.txt", "Agents.txt");

    printf("\n\tAgent details updated successfully!\n\n");

    while (1)
    {
        int back_exit;
        printf("\t1. 'B' - Go back\n\t2. 'E' - Exit: \n");
        printf("\t-> Enter you choice: ");
        scanf("%d", &back_exit);
        getchar();

        switch(back_exit)
        {
        case 1:
            clear_screen();
            adminMenu(adminId);
            break;
        case 2:
            exit(1);
            break;
        default:
            printf("\n\tError! Please enter a valid option!\n\n");
            continue;
        }
        break;
    }
}

void delete_agent(int adminId)
{
    FILE *fp = fopen("Agents.txt", "r");
    FILE *temp = fopen("Temp.txt", "w");

    FILE *fp2 = fopen("Users.txt", "r");
    FILE *temp2 = fopen("Temp2.txt", "w");

    int id;
    int id_matched = 0;

    Agent agent;
    User user;

    printf("\t-> Enter agent's ID: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d|%99[^|]|%14[^|]|%c|%19[^|]|%99[^|]|%19[^|]|%49[^|]|%299[^|]|%d|%29[^|]|%49[^|]|%d|%19[^\n]\n",
                  &agent.id,
                  agent.fullName,
                  agent.dob,
                  &agent.gender,
                  agent.nid,
                  agent.literacy,
                  agent.mobile,
                  agent.email,
                  agent.address,
                  &agent.postal_code,
                  agent.bank_number,
                  agent.bank_name,
                  &agent.branch_code,
                  agent.linked_number) != EOF)
    {
        if (agent.id != id)
        {
            fprintf(temp, "%d|%s|%s|%c|%s|%s|%s|%s|%s|%d|%s|%s|%d|%s\n",
                    agent.id,
                    agent.fullName,
                    agent.dob,
                    agent.gender,
                    agent.nid,
                    agent.literacy,
                    agent.mobile,
                    agent.email,
                    agent.address,
                    agent.postal_code,
                    agent.bank_number,
                    agent.bank_name,
                    agent.branch_code,
                    agent.linked_number);
        }
        else
        {
            id_matched = 1;
        }
    }

    while (fscanf(fp2, "%d %s %c\n", &user.id, user.password, &user.type) != EOF)
    {
        if (user.id != id)
        {
            fprintf(temp2, "%d %s %c\n", user.id, user.password, user.type);
        }
    }


    if(!id_matched)
    {
        printf("\n\tAgent with ID %d not found in the system!\n\n", id);
    }

    fclose(fp);
    fclose(temp);
    fclose(fp2);
    fclose(temp2);

    remove("Agents.txt");
    rename("Temp.txt", "Agents.txt");

    remove("Users.txt");
    rename("Temp2.txt", "Users.txt");

    printf("\n\tAgent profile deleted successfully.\n\n");

    while (1)
    {
        int back_exit;
        printf("\t1. 'B' - Go back\n\t2. 'E' - Exit: \n");
        printf("\t-> Enter you choice: ");
        scanf("%d", &back_exit);
        getchar();

        switch(back_exit)
        {
        case 1:
            clear_screen();
            adminMenu(adminId);
            break;
        case 2:
            exit(1);
            break;
        default:
            printf("\n\tError! Please enter a valid option!\n\n");
            continue;
        }
        break;
    }

}

void search_agent_by_id(FILE *fp, Agent agent, int adminId)
{
    clear_screen();

    int id;
    int id_matched = 0;

    printf("\t-> Enter agent's ID: ");
    scanf("%d", &id);

    while((fscanf(fp, "%d|%99[^|]|%14[^|]|%c|%19[^|]|%99[^|]|%19[^|]|%49[^|]|%299[^|]|%d|%29[^|]|%49[^|]|%d|%19[^\n]\n",
                  &agent.id,
                  agent.fullName,
                  agent.dob,
                  &agent.gender,
                  agent.nid,
                  agent.literacy,
                  agent.mobile,
                  agent.email,
                  agent.address,
                  &agent.postal_code,
                  agent.bank_number,
                  agent.bank_name,
                  &agent.branch_code,
                  agent.linked_number
                 ) != EOF))
    {
        if (agent.id == id)
        {
            id_matched = 1;

            printf("\t\t PERSONAL DETAILS OF agent: %d\n", id);
            printf("\t-----------------------------------\n");
            printf("\tID:                     %d\n", agent.id);
            printf("\tFull name:              %s\n", agent.fullName);
            printf("\tDate of birth:          %s\n", agent.dob);
            printf("\tGender:                 %c\n", agent.gender);
            printf("\tNID:                    %s\n", agent.nid);
            printf("\tLiteracy level:         %s\n", agent.literacy);
            printf("\tMobile Number:          %s\n", agent.mobile);
            printf("\tEmail address:          %s\n", agent.email);
            printf("\tAddress:                %s\n", agent.address);
            printf("\tPostal Code:            %d\n", agent.postal_code);
            printf("\tBank Account Number:    %s\n", agent.bank_number);
            printf("\tBank Name:              %s\n", agent.bank_name);
            printf("\tBranch Code:            %d\n", agent.branch_code);
            printf("\tBank linked Number:     %s\n", agent.linked_number);
            printf("\t-----------------------------------\n\n");

            break;
        }
    }

    fclose(fp);

    if(!id_matched)
    {
        printf("\n\tAgent with ID: %d not found!\n\n", id);
    }

    while (1)
    {
        int back_exit;
        printf("\t1. 'B' - Go back\n\t2. 'E' - Exit: \n");
        printf("\t-> Enter you choice: ");
        scanf("%d", &back_exit);
        getchar();

        switch(back_exit)
        {
        case 1:
            clear_screen();
            search_agent(adminId);
            break;
        case 2:
            exit(1);
            break;
        default:
            printf("\n\tError! Please enter a valid option!\n\n");
            continue;
        }
        break;
    }
}

void search_agent_by_name(FILE *fp, Agent agent, int adminId)
{
    clear_screen();
    char name[100];
    int string_matched = 1;

    getchar();
    printf("\t-> Enter partial name characters: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0';

    while((fscanf(fp, "%d|%99[^|]|%14[^|]|%c|%19[^|]|%99[^|]|%19[^|]|%49[^|]|%299[^|]|%d|%29[^|]|%49[^|]|%d|%19[^\n]\n",
                  &agent.id,
                  agent.fullName,
                  agent.dob,
                  &agent.gender,
                  agent.nid,
                  agent.literacy,
                  agent.mobile,
                  agent.email,
                  agent.address,
                  &agent.postal_code,
                  agent.bank_number,
                  agent.bank_name,
                  &agent.branch_code,
                  agent.linked_number
                 ) != EOF))
    {
        if (strncmp(lowercased_str(name), lowercased_str(agent.fullName), strlen(name)) == 0)
        {
            string_matched = 1;

            printf("\t\t PERSONAL DETAILS OF AGENT: %s\n", agent.fullName);
            printf("\t-----------------------------------\n");
            printf("\tID:                     %d\n", agent.id);
            printf("\tFull name:              %s\n", agent.fullName);
            printf("\tDate of birth:          %s\n", agent.dob);
            printf("\tGender:                 %c\n", agent.gender);
            printf("\tNID:                    %s\n", agent.nid);
            printf("\tLiteracy level:         %s\n", agent.literacy);
            printf("\tMobile Number:          %s\n", agent.mobile);
            printf("\tEmail address:          %s\n", agent.email);
            printf("\tAddress:                %s\n", agent.address);
            printf("\tPostal Code:            %d\n", agent.postal_code);
            printf("\tBank Account Number:    %s\n", agent.bank_number);
            printf("\tBank Name:              %s\n", agent.bank_name);
            printf("\tBranch Code:            %d\n", agent.branch_code);
            printf("\tBank linked Number:     %s\n", agent.linked_number);
            printf("\t-----------------------------------\n");
        }
    }

    fclose(fp);

    if(!string_matched)
    {
        printf("\n\tNo match found for %s\n\n", name);
    }

    while (1)
    {
        int back_exit;
        printf("\t1. 'B' - Go back\n\t2. 'E' - Exit: \n");
        printf("\t-> Enter you choice: ");
        scanf("%d", &back_exit);
        getchar();

        switch(back_exit)
        {
        case 1:
            clear_screen();
            search_agent(adminId);
            break;
        case 2:
            exit(1);
            break;
        default:
            printf("\n\tError! Please enter a valid option!\n\n");
            continue;
        }
        break;
    }
}

void search_agent(int adminId)
{
    FILE *fp = fopen("Agents.txt", "r");

    Agent agent;

    int chosen_option;

    clear_screen();
    printf("\t1. Search by ID\n");
    printf("\t2. Search by name\n");

    printf("\t-> Choose an option: ");
    scanf("%d", &chosen_option);

    switch(chosen_option)
    {
    case 1:
        search_agent_by_id(fp, agent, adminId);
        break;
    case 2:
        search_agent_by_name(fp, agent, adminId);
        break;
    default:
        printf("\n\tInvalid option chosen! Try again\n\n");
        search_agent(adminId);
        break;
    }

    while (1)
    {
        int back_exit;
        printf("\t1. 'B' - Go back\n\t2. 'E' - Exit: \n");
        printf("\t-> Enter you choice: ");
        scanf("%d", &back_exit);
        getchar();

        switch(back_exit)
        {
        case 1:
            clear_screen();
            adminMenu(adminId);
            break;
        case 2:
            exit(1);
            break;
        default:
            printf("\n\tError! Please enter a valid option!\n\n");
            continue;
        }
        break;
    }
}

