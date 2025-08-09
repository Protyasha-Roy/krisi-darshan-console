#include <stdio.h>
#include "login.h"

void list_farmers() {
    FILE *fp = fopen("Farmers.txt", "r");
    Farmer farmer;

    printf("ID\tNAME\tDOB\tGENDER\tNID\tLITERACY\tMOBILE\tEMAIL\tADDRESS\tPOSTAL\tEXPERIENCE\tAREA\tPARCELS\tCROPS\tOWNERSHIP\tBANK_NUMBER\tBANK_NAME\tBRANCH_CODE\tLINKED_NUMBER\n");
    while(fscanf(fp, "%d|%99[^|]|%14[^|]|%c|%19[^|]|%99[^|]|%19[^|]|%49[^|]|%299[^|]|%d|%f|%f|%d|%99[^|]|%c|%29[^|]|%49[^|]|%d|%19[^\n]\n",
            &farmer.id,
            farmer.fullName,
            farmer.dob,
            &farmer.gender,
            farmer.nid,
            farmer.literacy,
            farmer.mobile,
            farmer.email,
            farmer.address,
            &farmer.postal_code,
            &farmer.farming_experience,
            &farmer.area,
            &farmer.land_parcels,
            farmer.crops,
            &farmer.ownership,
            farmer.bank_number,
            farmer.bank_name,
            &farmer.branch_code,
            farmer.linked_number
        ) != EOF) {

        printf("%d\t%s\t%s\t%c\t%s\t%s\t%s\t%s\t%s\t%d\t%f\t%f\t%d\t%s\t%c\t%s\t%s\t%d\t%s\n",
            farmer.id,
            farmer.fullName,
            farmer.dob,
            farmer.gender,
            farmer.nid,
            farmer.literacy,
            farmer.mobile,
            farmer.email,
            farmer.address,
            farmer.postal_code,
            farmer.farming_experience,
            farmer.area,
            farmer.land_parcels,
            farmer.crops,
            farmer.ownership,
            farmer.bank_number,
            farmer.bank_name,
            farmer.branch_code,
            farmer.linked_number
        );
    }
}

void search_farmer() {
    char id[];

    printf("Enter farmer's ID to see details: ");
}

void delete_farmer() {

}
