#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

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
    float farming_experience;
    float area;
    int land_parcels;
    char crops[100];
    char ownership;
    char bank_number[30];
    char bank_name[50];
    int branch_code;
    char linked_number[20];
} Farmer;

typedef struct {
    int id;
    char password[20];
    char type;
} User;


void loginForm(int option);
void login(int option, int id, char password[]);
void registration();

#endif // LOGIN_H_INCLUDED
