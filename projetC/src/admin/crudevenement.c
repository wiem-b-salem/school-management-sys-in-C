//rihab
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../header/ecole/event.h"

// Ajouter un �v�nement
void Ajouterevent() {
    evenement E;
    FILE *fp = fopen("evenement.txt", "a");
    if (!fp) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    printf("Entrer l'ID de l'�v�nement : ");
    scanf("%d", &E.id);
    printf("Entrer le nom de l'�v�nement (max 49 caract�res) : ");
    scanf("%49s", E.nom);
    printf("Entrer la description de l'�v�nement (max 99 caract�res) : ");
    scanf("%99s", E.description);

    fprintf(fp, "%d %s %s\n", E.id, E.nom, E.description);
    printf("�v�nement ajout� avec succ�s !\n");

    fclose(fp);
}

// Afficher les �v�nements
void Afficherevent() {
    evenement E;
    FILE *fp = fopen("evenement.txt", "r");
    if (!fp) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    printf("\nListe des �v�nements :\n");
    printf("ID\tNom\tDescription\n");
    printf("-------------------------------\n");

    while (fscanf(fp, "%d %49s %99[^\n]", &E.id, E.nom, E.description) == 3) {
        printf("%d\t%s\t%s\n", E.id, E.nom, E.description);
    }

    fclose(fp);
}

// Modifier un �v�nement
void Modifierevent() {
    int id, found = 0;
    evenement E;
    FILE *fp = fopen("evenement.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) {
        perror("Erreur d'ouverture des fichiers");
        return;
    }

    printf("Entrer l'ID de l'�v�nement � modifier : ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %49s %99[^\n]", &E.id, E.nom, E.description) == 3) {
        if (E.id == id) {
            found = 1;
            printf("Entrer le nouveau nom de l'�v�nement (max 49 caract�res) : ");
            scanf("%49s", E.nom);
            printf("Entrer la nouvelle description de l'�v�nement (max 99 caract�res) : ");
            scanf("%99s", E.description);
        }
        fprintf(temp, "%d %s %s\n", E.id, E.nom, E.description);
    }

    fclose(fp);
    fclose(temp);

    remove("evenement.txt");
    rename("temp.txt", "evenement.txt");

    if (found)
        printf("�v�nement modifi� avec succ�s !\n");
    else
        printf("�v�nement avec ID %d non trouv�.\n", id);
}

// Supprimer un �v�nement
void Supprimerevent() {
    int id, found = 0;
    evenement E;
    FILE *fp = fopen("evenement.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) {
        perror("Erreur d'ouverture des fichiers");
        return;
    }

    printf("Entrer l'ID de l'�v�nement � supprimer : ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %49s %99[^\n]", &E.id, E.nom, E.description) == 3) {
        if (E.id == id) {
            found = 1;
            continue; // Ne pas copier l'�v�nement � supprimer
        }
        fprintf(temp, "%d %s %s\n", E.id, E.nom, E.description);
    }

    fclose(fp);
    fclose(temp);

    remove("evenement.txt");
    rename("temp.txt", "evenement.txt");

    if (found)
        printf("�v�nement supprim� avec succ�s !\n");
    else
        printf("�v�nement avec ID %d non trouv�.\n", id);
}

// Menu de gestion des �v�nements
void crudevenement() {
    int choix;
    do {
        printf("\nGestion des �v�nements :\n");
        printf("1. Ajouter un �v�nement\n");
        printf("2. Modifier un �v�nement\n");
        printf("3. Supprimer un �v�nement\n");
        printf("4. Afficher les �v�nements\n");
        printf("5. Retour au menu principal\n");
        printf("Votre choix : ");
        printf("--------------------------------- \n");
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
                printf("Choix invalide. Veuillez r�essayer.\n");
        }
    } while (choix != 5);
}
