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

#endif // PARCELS_H_INCLUDED
