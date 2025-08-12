#include <stdio.h>
#include "utils.h"
#include "agent_utils.h"
#include "login.h"
#include <string.h>

void list_agents()
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
        printf("ID:                     %d\n", agent.id);
        printf("Full name:              %s\n", agent.fullName);
        printf("Date of birth:          %s\n", agent.dob);
        printf("Gender:                 %c\n", agent.gender);
        printf("NID:                    %s\n", agent.nid);
        printf("Literacy level:         %s\n", agent.literacy);
        printf("Mobile Number:          %s\n", agent.mobile);
        printf("Email address:          %s\n", agent.email);
        printf("Address:                %s\n", agent.address);
        printf("Postal Code:            %d\n", agent.postal_code);
        printf("Bank Account Number:    %s\n", agent.bank_number);
        printf("Bank Name:              %s\n", agent.bank_name);
        printf("Branch Code:            %d\n", agent.branch_code);
        printf("Bank linked Number:     %s\n\n", agent.linked_number);
    }

    fclose(fp);
}

void add_agent()
{
    clear_screen();

    FILE *fp;
    FILE *fp2;

    fp = fopen("Agents.txt", "a");
    if (fp == NULL)
    {
        perror("Error opening Agents.txt");
        return;
    }

    fp2 = fopen("Users.txt", "a");
    if (fp2 == NULL)
    {
        perror("Error opening Users.txt");
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
    printf("Enter full name: ");
    fgets(agent.fullName, sizeof(agent.fullName), stdin);
    agent.fullName[strcspn(agent.fullName, "\n")] = '\0';

    printf("Enter DOB(YYYY-MM-DD): ");
    fgets(agent.dob, sizeof(agent.dob), stdin);
    agent.dob[strcspn(agent.dob, "\n")] = '\0';

    printf("Enter gender(M/F/O): ");
    scanf("%c", &agent.gender);

    getchar();
    printf("Enter NID: ");
    fgets(agent.nid, sizeof(agent.nid), stdin);
    agent.nid[strcspn(agent.nid, "\n")] = '\0';

    printf("Enter literacy level: ");
    fgets(agent.literacy, sizeof(agent.literacy), stdin);
    agent.literacy[strcspn(agent.literacy, "\n")] = '\0';

    printf("Enter mobile number: ");
    fgets(agent.mobile, sizeof(agent.mobile), stdin);
    agent.mobile[strcspn(agent.mobile, "\n")] = '\0';

    printf("Enter email address: ");
    fgets(agent.email, sizeof(agent.email), stdin);
    agent.email[strcspn(agent.email, "\n")] = '\0';

    printf("Enter full address: ");
    fgets(agent.address, sizeof(agent.address), stdin);
    agent.address[strcspn(agent.address, "\n")] = '\0';

    printf("Enter postal code: ");
    scanf("%d", &agent.postal_code);

    printf("\n\tBANK DETAILS\n");

    getchar();
    printf("Enter bank account number: ");
    fgets(agent.bank_number, sizeof(agent.bank_number), stdin);
    agent.bank_number[strcspn(agent.bank_number, "\n")] = '\0';

    printf("Branch code: ");
    scanf("%d", &agent.branch_code);

    getchar();
    printf("Enter name of the bank: ");
    fgets(agent.bank_name, sizeof(agent.bank_name), stdin);
    agent.bank_name[strcspn(agent.bank_name, "\n")] = '\0';

    printf("Enter linked mobile number: ");
    fgets(agent.linked_number, sizeof(agent.linked_number), stdin);
    agent.linked_number[strcspn(agent.linked_number, "\n")] = '\0';

    printf("Now create password for Krishi-Darshan account: ");
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

    printf("\nAgent registration is complete. ID is: %d.\n", user.id);
}

void update_agent()
{

}

void delete_agent()
{
    FILE *fp = fopen("Agents.txt", "r");
    FILE *temp = fopen("Temp.txt", "w");

    FILE *fp2 = fopen("Users.txt", "r");
    FILE *temp2 = fopen("Temp2.txt", "w");

    int id;
    int id_matched = 0;

    Agent agent;
    User user;

    printf("Enter agent's ID: ");
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
        printf("Agent with ID %d not found in the system! \n", id);
    }

    fclose(fp);
    fclose(temp);
    fclose(fp2);
    fclose(temp2);

    remove("Agents.txt");
    rename("Temp.txt", "Agents.txt");

    remove("Users.txt");
    rename("Temp2.txt", "Users.txt");

    printf("\nAgent profile deleted successfully.\n");
}

void search_agent_by_id(FILE *fp, Agent agent)
{
    clear_screen();

    int id;
    int id_matched = 0;

    printf("Enter agent's ID: ");
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
            printf("ID:                     %d\n", agent.id);
            printf("Full name:              %s\n", agent.fullName);
            printf("Date of birth:          %s\n", agent.dob);
            printf("Gender:                 %c\n", agent.gender);
            printf("NID:                    %s\n", agent.nid);
            printf("Literacy level:         %s\n", agent.literacy);
            printf("Mobile Number:          %s\n", agent.mobile);
            printf("Email address:          %s\n", agent.email);
            printf("Address:                %s\n", agent.address);
            printf("Postal Code:            %d\n", agent.postal_code);
            printf("Bank Account Number:    %s\n", agent.bank_number);
            printf("Bank Name:              %s\n", agent.bank_name);
            printf("Branch Code:            %d\n", agent.branch_code);
            printf("Bank linked Number:     %s\n\n", agent.linked_number);

            break;
        }
    }

    fclose(fp);

    if(!id_matched)
    {
        printf("Agent with ID: %d not found!\n", id);
    }
}

void search_agent_by_name(FILE *fp, Agent agent)
{
    clear_screen();
    char name[100];
    int string_matched = 1;

    getchar();
    printf("Enter partial name characters: ");
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
            printf("ID:                     %d\n", agent.id);
            printf("Full name:              %s\n", agent.fullName);
            printf("Date of birth:          %s\n", agent.dob);
            printf("Gender:                 %c\n", agent.gender);
            printf("NID:                    %s\n", agent.nid);
            printf("Literacy level:         %s\n", agent.literacy);
            printf("Mobile Number:          %s\n", agent.mobile);
            printf("Email address:          %s\n", agent.email);
            printf("Address:                %s\n", agent.address);
            printf("Postal Code:            %d\n", agent.postal_code);
            printf("Bank Account Number:    %s\n", agent.bank_number);
            printf("Bank Name:              %s\n", agent.bank_name);
            printf("Branch Code:            %d\n", agent.branch_code);
            printf("Bank linked Number:     %s\n\n", agent.linked_number);
        }
    }

    fclose(fp);

    if(!string_matched)
    {
        printf("No match found for %s\n", name);
    }
}

void search_agent()
{
    FILE *fp = fopen("Agents.txt", "r");

    Agent agent;

    int chosen_option;

    clear_screen();
    printf("1. Search by ID\n");
    printf("2. Search by name\n");

    printf("Choose an option: ");
    scanf("%d", &chosen_option);

    switch(chosen_option)
    {
    case 1:
        search_agent_by_id(fp, agent);
        break;
    case 2:
        search_agent_by_name(fp, agent);
        break;
    default:
        printf("Invalid option chosen! Try again");
        search_agent();
        break;
    }
}

