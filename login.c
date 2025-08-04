#include <stdio.h>
#include "login.h"

void login(char option, int id, char password[]) {
    printf("%c %d %s\n", option, id, password);
}

void loginForm(char option) {
    LoginForm person;

    printf("Enter your ID: ");
    scanf("%d", &person.id);
    printf("Enter your password: ");
    scanf("%s", person.password);

    login(option, person.id, person.password);
}
