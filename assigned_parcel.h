#ifndef ASSIGNED_PARCEL_H_INCLUDED
#define ASSIGNED_PARCEL_H_INCLUDED

typedef struct
{
    int id;
    int agentId;
    int farmerId;
    char status;
    char location[100];
    float area;
    char dop[15];
    char soilType[30];
    char crops[50];
} AssignedParcel;

typedef struct
{
    int parcelId;
    char farmerName[100];
    char dov[15];
    char observation[500];
    char reportResul[500];
    char recomendation[100];
} UploadReport;

#endif // ASSIGNED_PARCEL_H_INCLUDED
