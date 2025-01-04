#include "menuadmin.h"
#include "etudiant.h"
#include "classe.h"
#include "nouveaute.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction du menu de l'admin pour g�rer les �tudiants, classes et nouveaut�s
void menuAdmin() {
    int choix;
    do {
        printf("=== Menu Admin ===\n");
        printf("1 - G�rer les �tudiants\n");
        printf("2 - G�rer les classes\n");
        printf("3 - G�rer les nouveaut�s (�v�nements, Clubs, Notes, Moyennes)\n");
        printf("0 - QUITTER\n");

        printf("S�lectionnez votre choix: ");

        if (scanf("%d", &choix) != 1) {
            // G�rer l'entr�e invalide
            printf("Entr�e invalide. Veuillez entrer un num�ro valide.\n");
            while (getchar() != '\n');
        }
    } while (choix < 0 || choix > 3);

    switch (choix) {
        case 1:
            gestionEtudiants();  // Appel � la fonction dans etudiant.c
            break;
        case 2:
            gestionClasses();  // Appel � la fonction dans classe.c
            break;
        case 3:
            gestionNouveautes();  // Appel � la fonction dans nouveaute.c
            break;
        case 0:
            printf("Au revoir!\n");
            break;
        default:
            break;
    }
}
