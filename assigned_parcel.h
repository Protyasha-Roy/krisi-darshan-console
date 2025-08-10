#ifndef ASSIGNED_PARCEL_H_INCLUDED
#define ASSIGNED_PARCEL_H_INCLUDED

typedef struct {
    int agentId;
    int id;
    char farmerId[20];
    char status;
    char location[100];
    float area;
    char dop[15];
    char soilType[30];
    char crops[50];
} AssignedParcel;

#endif // ASSIGNED_PARCEL_H_INCLUDED
