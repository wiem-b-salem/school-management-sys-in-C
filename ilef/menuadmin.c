#include "menuadmin.h"
#include "etudiant.h"
#include "classe.h"
#include "nouveaute.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction du menu de l'admin pour gérer les étudiants, classes et nouveautés
void menuAdmin() {
    int choix;
    do {
        printf("=== Menu Admin ===\n");
        printf("1 - Gérer les étudiants\n");
        printf("2 - Gérer les classes\n");
        printf("3 - Gérer les nouveautés (Événements, Clubs, Notes, Moyennes)\n");
        printf("0 - QUITTER\n");

        printf("Sélectionnez votre choix: ");

        if (scanf("%d", &choix) != 1) {
            // Gérer l'entrée invalide
            printf("Entrée invalide. Veuillez entrer un numéro valide.\n");
            while (getchar() != '\n');
        }
    } while (choix < 0 || choix > 3);

    switch (choix) {
        case 1:
            gestionEtudiants();  // Appel à la fonction dans etudiant.c
            break;
        case 2:
            gestionClasses();  // Appel à la fonction dans classe.c
            break;
        case 3:
            gestionNouveautes();  // Appel à la fonction dans nouveaute.c
            break;
        case 0:
            printf("Au revoir!\n");
            break;
        default:
            break;
    }
}
