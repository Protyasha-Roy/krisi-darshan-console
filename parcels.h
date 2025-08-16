#ifndef PARCELS_H_INCLUDED
#define PARCELS_H_INCLUDED

typedef struct {
    int id;
    int farmerId;
    char location[100];
    float area;
    char dop[15];
    char soilType[30];
    char crops[50];
} Parcel;

void add_landparcels(int id);
void edit_landparcels(int id);
void delete_landparcels(int id);
void update_parcel_crops(int id);

#endif // PARCELS_H_INCLUDED
