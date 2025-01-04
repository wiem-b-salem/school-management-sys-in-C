#include "croudabsence.h"
#include <stdio.h>
#include <string.h>

Absence absences[MAX_ABSENCES]; // Tableau global pour stocker les absences
int nb_absences = 0;            // Compteur global

// Fonction pour ajouter une absence
void AjouterAbsence() {
    if (nb_absences >= MAX_ABSENCES) {
        printf("Limite d'absences atteinte !\n");
        return;
    }

    printf("Entrez l'ID de l'élève : ");
    if (scanf("%d", &absences[nb_absences].eleve_id) != 1) {
        printf("Entrée invalide pour l'ID de l'élève.\n");
        while (getchar() != '\n'); // Nettoyer le buffer
        return;
    }

    printf("Entrez le nombre d'absences : ");
    if (scanf("%d", &absences[nb_absences].nb_absences) != 1) {
        printf("Entrée invalide pour le nombre d'absences.\n");
        while (getchar() != '\n'); // Nettoyer le buffer
        return;
    }

    printf("Entrez la date (jj/mm/aaaa) : ");
    while (getchar() != '\n'); // Nettoyer le buffer
    fgets(absences[nb_absences].date, sizeof(absences[nb_absences].date), stdin);
    absences[nb_absences].date[strcspn(absences[nb_absences].date, "\n")] = '\0'; // Enlever le '\n' en fin de chaîne

    nb_absences++;
    printf("Absence ajoutée avec succès !\n");
}

// Fonction pour afficher les absences
void AfficherAbsences() {
    if (nb_absences == 0) {
        printf("Aucune absence enregistrée.\n");
        return;
    }
    int i;
    printf("\nListe des absences :\n");
    printf("ID Élève\tNombre d'absences\tDate\n");
    printf("-------------------------------------------\n");
    for ( i = 0; i < nb_absences; i++) {
        printf("%d\t\t%d\t\t%s\n", absences[i].eleve_id, absences[i].nb_absences, absences[i].date);
    }
}

// Fonction pour modifier une absence
void ModifierAbsence() {
    int id, found = 0;
    printf("Entrez l'ID de l'élève à modifier : ");
    if (scanf("%d", &id) != 1) {
        printf("Entrée invalide pour l'ID.\n");
        while (getchar() != '\n'); // Nettoyer le buffer
        return;
    }
int i;
    for ( i = 0; i < nb_absences; i++) {
        if (absences[i].eleve_id == id) {
            found = 1;

            printf("Entrez le nouveau nombre d'absences : ");
            if (scanf("%d", &absences[i].nb_absences) != 1) {
                printf("Entrée invalide pour le nombre d'absences.\n");
                while (getchar() != '\n'); // Nettoyer le buffer
                return;
            }

            printf("Entrez la nouvelle date (jj/mm/aaaa) : ");
            while (getchar() != '\n'); // Nettoyer le buffer
            fgets(absences[i].date, sizeof(absences[i].date), stdin);
            absences[i].date[strcspn(absences[i].date, "\n")] = '\0'; // Enlever le '\n' en fin de chaîne

            printf("Absence modifiée avec succès !\n");
            return;
        }
    }

    if (!found) {
        printf("Aucune absence trouvée pour l'ID %d.\n", id);
    }
}

// Fonction pour supprimer une absence
void SupprimerAbsence() {
    int id, found = 0;
    int i,j;
    printf("Entrez l'ID de l'élève à supprimer : ");
    if (scanf("%d", &id) != 1) {
        printf("Entrée invalide pour l'ID.\n");
        while (getchar() != '\n'); // Nettoyer le buffer
        return;
    }

    for ( i = 0; i < nb_absences; i++) {
        if (absences[i].eleve_id == id) {
            found = 1;

            // Décaler les absences restantes pour combler l'espace
            for ( j = i; j < nb_absences - 1; j++) {
                absences[j] = absences[j + 1];
            }

            nb_absences--;
            printf("Absence supprimée avec succès !\n");
            return;
        }
    }

    if (!found) {
        printf("Aucune absence trouvée pour l'ID %d.\n", id);
    }
}

// Fonction pour gérer le menu des absences
void GestionAbsences() {
    int choix;

    do {
        printf("\nMenu Gestion des Absences :\n");
        printf("1. Ajouter une absence\n");
        printf("2. Afficher les absences\n");
        printf("3. Modifier une absence\n");
        printf("4. Supprimer une absence\n");
        printf("5. Quitter\n");
        printf("Votre choix : ");

        // Lire et valider l'entrée utilisateur
        if (scanf("%d", &choix) != 1) {
            printf("Entrée invalide. Veuillez entrer un nombre.\n");
            while (getchar() != '\n'); // Nettoyer le buffer
            continue;
        }

        // Exécuter l'option choisie
        switch (choix) {
            case 1:
                AjouterAbsence();
                break;
            case 2:
                AfficherAbsences();
                break;
            case 3:
                ModifierAbsence();
                break;
            case 4:
                SupprimerAbsence();
                break;
            case 5:
                printf("Retour au menu principal...\n");
                break;
            default:
                printf("Choix invalide. Veuillez entrer un nombre entre 1 et 5.\n");
        }

    } while (choix != 5);
}

