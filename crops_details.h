#ifndef CROPS_DETAILS_H_INCLUDED
#define CROPS_DETAILS_H_INCLUDED

typedef struct
{
    int id;
    char crop_name[50];
    int parcelId;
    int farmerId;
    char sowing_date[15];
    char harvesting_date[15];
    char current_status[30];
    char fertilizers_used[50];
    char pesticides_used [50];
}Crops;

void add_cropdetails(int id);
void edit_cropdetails(int id);
void delete_cropdetails(int id);

#endif // CROPS_DETAILS_H_INCLUDED
