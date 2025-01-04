#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crudevent.h"

// Ajouter un événement
void Ajouterevent() {
    evenement E;
    FILE *fp = fopen("evenement.txt", "a");
    if (!fp) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    printf("Entrer l'ID de l'événement : ");
    scanf("%d", &E.id);
    printf("Entrer le nom de l'événement (max 49 caractères) : ");
    scanf("%49s", E.nom);
    printf("Entrer la description de l'événement (max 99 caractères) : ");
    scanf("%99s", E.description);

    fprintf(fp, "%d %s %s\n", E.id, E.nom, E.description);
    printf("Événement ajouté avec succès !\n");

    fclose(fp);
}

// Afficher les événements
void Afficherevent() {
    evenement E;
    FILE *fp = fopen("evenement.txt", "r");
    if (!fp) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    printf("\nListe des événements :\n");
    printf("ID\tNom\tDescription\n");
    printf("-------------------------------\n");

    while (fscanf(fp, "%d %49s %99[^\n]", &E.id, E.nom, E.description) == 3) {
        printf("%d\t%s\t%s\n", E.id, E.nom, E.description);
    }

    fclose(fp);
}

// Modifier un événement
void Modifierevent() {
    int id, found = 0;
    evenement E;
    FILE *fp = fopen("evenement.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) {
        perror("Erreur d'ouverture des fichiers");
        return;
    }

    printf("Entrer l'ID de l'événement à modifier : ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %49s %99[^\n]", &E.id, E.nom, E.description) == 3) {
        if (E.id == id) {
            found = 1;
            printf("Entrer le nouveau nom de l'événement (max 49 caractères) : ");
            scanf("%49s", E.nom);
            printf("Entrer la nouvelle description de l'événement (max 99 caractères) : ");
            scanf("%99s", E.description);
        }
        fprintf(temp, "%d %s %s\n", E.id, E.nom, E.description);
    }

    fclose(fp);
    fclose(temp);

    remove("evenement.txt");
    rename("temp.txt", "evenement.txt");

    if (found)
        printf("Événement modifié avec succès !\n");
    else
        printf("Événement avec ID %d non trouvé.\n", id);
}

// Supprimer un événement
void Supprimerevent() {
    int id, found = 0;
    evenement E;
    FILE *fp = fopen("evenement.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) {
        perror("Erreur d'ouverture des fichiers");
        return;
    }

    printf("Entrer l'ID de l'événement à supprimer : ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %49s %99[^\n]", &E.id, E.nom, E.description) == 3) {
        if (E.id == id) {
            found = 1;
            continue; // Ne pas copier l'événement à supprimer
        }
        fprintf(temp, "%d %s %s\n", E.id, E.nom, E.description);
    }

    fclose(fp);
    fclose(temp);

    remove("evenement.txt");
    rename("temp.txt", "evenement.txt");

    if (found)
        printf("Événement supprimé avec succès !\n");
    else
        printf("Événement avec ID %d non trouvé.\n", id);
}

// Menu de gestion des événements
void GestionEvent() {
    int choix;
    do {
        printf("\nGestion des événements :\n");
        printf("1. Ajouter un événement\n");
        printf("2. Modifier un événement\n");
        printf("3. Supprimer un événement\n");
        printf("4. Afficher les événements\n");
        printf("5. Retour au menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                Ajouterevent();
                break;
            case 2:
                Modifierevent();
                break;
            case 3:
                Supprimerevent();
                break;
            case 4:
                Afficherevent();
                break;
            case 5:
                printf("Retour au menu principal...\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 5);
}
