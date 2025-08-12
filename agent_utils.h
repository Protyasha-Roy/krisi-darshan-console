#ifndef AGENT_UTILS_H_INCLUDED
#define AGENT_UTILS_H_INCLUDED

typedef struct {
    int id;
    char fullName[100];
    char dob[15];
    char gender;
    char nid[20];
    char literacy[100];
    char mobile[20];
    char email[50];
    char address[300];
    int postal_code;
    char bank_number[30];
    char bank_name[50];
    int branch_code;
    char linked_number[20];
} Agent;

void list_agents();
void add_agent();
void search_agent();
void update_agent();
void delete_agent();

#endif // AGENT_UTILS_H_INCLUDED
