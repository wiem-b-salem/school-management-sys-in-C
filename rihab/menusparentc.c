#include "crudabsence.h" // Assurez-vous que le fichier header est bien nommé
#include "crudnotes.h"   // Assurez-vous que le fichier header est correct
#include <stdio.h>
#include <stdlib.h>

#ifndef CRUDABSENCE_H
#define CRUDABSENCE_H

void crudparentc() {
    int choix;

    do {
        printf("\n*** MENU PARENT ***\n");
        printf("Veuillez choisir une option :\n");
        printf("1 - Gérer les absences\n");
        printf("2 - Gérer les notes\n");
        printf("0 - Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        // Gestion des choix du menu parent
        switch (choix) {
        case 1:
            printf("\n--- Gestion des Absences ---\n");
            // Appel du menu CRUD pour les absences
            // Fonction à appeler
            break;

        case 2:
            printf("\n--- Gestion des Notes ---\n");
            // Appel du menu CRUD pour les notes
           // Fonction à appeler
            break;

        case 0:
            printf("Retour au menu principal...\n");
            break;

        default:
            printf("Choix invalide. Veuillez réessayer.\n");
            break;
        }
    } while (choix != 0); // Correction de l'emplacement du `while`
}

#endif
