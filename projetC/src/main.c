#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../header/admin/admin.h"
#include "../header/enseignant/enseignant.h"
#include "../header/parent/parent.h"

void generateCaptcha(char *captcha, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < length; i++) {
        int key = rand() % (int)(sizeof(charset) - 1);
        captcha[i] = charset[key];
    }
    captcha[length] = '\0';
}

int main() {
    int choix;
    char email[100];
    char password[50];
    char captcha[6];
    char inputCaptcha[6];
    srand(time(0));

    do {
        printf("Bonjour \n");
        printf("Selectionnez votre choix \n");
        printf("0 - Admin\n");
        printf("1 - s'inscrire comme parent\n");
        printf("2 - s'inscrire comme enseignant\n");
        scanf("%d", &choix);
    } while (choix < 0 || choix > 2);

    if (choix == 0) {
        printf("Bonjour Admin \n");
        printf("Entrez le mot de passe: ");
        scanf("%s", password);

        // Check admin password
        if (strcmp(password, "ABCabc123@") == 0) {
            generateCaptcha(captcha, 5);
            printf("Entrez le captcha suivant: %s\n", captcha);
            scanf("%s", inputCaptcha);

            if (strcmp(captcha, inputCaptcha) == 0) {
                menuadmin();
            } else {
                printf("Captcha incorrect.\n");
            }
        } else {
            printf("Mot de passe incorrect.\n");
        }
    } else if (choix == 1) {
        printf("Bonjour parent \n");
        menuparent();
    } else {
        printf("Bonjour enseignant \n");
        menuenseignant();
    }

    return 0;
}