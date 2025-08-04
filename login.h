#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

struct Farmer {
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
    int farming_experience;
    float area;
    int land_parcels;
    char crops[100];
    char ownership;
    char bank_number[30];
    char bank_name[50];
    int branch_code;
    char linked_number[20];
};

typedef struct {
    int id;
    char password[20];
} LoginForm;

void loginForm(char option);
void login(char option, int id, char password[]);

#endif // LOGIN_H_INCLUDED
