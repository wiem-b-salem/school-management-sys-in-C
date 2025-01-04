#include "crudevent.h"
#include "crudcours.h"
#include "crudnotes.h"
#include "crudabsence.h"
#include "crudCour.h"
#include <stdio.h>
#include <stdlib.h>

// Fonction du menu Administrateur
void Admin() {
    int choix;
    do {
        printf("\n=== Menu Administrateur ===\n");
        printf("1 - Gérer les événements\n");
        printf("2 - Gérer les cours\n");
        printf("5 - Gérer les cours dispensés\n");
        printf("0 - Quitter\n");
        printf("Votre choix : ");

        if (scanf("%d", &choix) != 1) {
            printf("Entrée invalide, veuillez réessayer.\n");
            while (getchar() != '\n'); // Vider le buffer
            continue;
        }

        switch (choix) {
            case 1:
                printf("\n=== Gestion des événements ===\n");
               int isIDUnique(evenement events[], int nbEvents, int id);
void ajouterEvent();
void afficherEvents();
void modifierEvent();
void supprimerEvent();
                break;
            case 2:
                printf("\n=== Gestion des cours ===\n");
                Ajoutercours();
                break;
            case 0:
                printf("Au revoir Administrateur !\n");
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (choix != 0);
    Admin(); // Appeler le menu Administrateur
}
