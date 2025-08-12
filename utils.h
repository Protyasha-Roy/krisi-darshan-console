#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

void clear_screen();
int generateId(int lower, int upper);
char *lowercased_str(char str[]);
int checkIdDuplication(FILE *fp2, int farmerId);

#endif // UTILS_H_INCLUDED
