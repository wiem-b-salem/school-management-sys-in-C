#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crudcours.h"
void Ajoutercours() {
    cours C;
    FILE *fp = fopen("cours.txt", "a");
    if (!fp) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    printf("Entrer l'ID du cours : ");
    scanf("%d", &C.id);
    printf("Entrer le nom du cours (max 49 caractères) : ");
    scanf("%49s", C.nom);
    printf("Entrer la description du cours (max 99 caractères) : ");
    scanf("%99s", C.description);

    fprintf(fp, "%d %s %s\n", C.id, C.nom, C.description);
    printf("Cours ajouté avec succès !\n");

    fclose(fp);
}

void Affichercours() {
    cours C;
    FILE *fp = fopen("cours.txt", "r");
    if (!fp) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    printf("\nListe des cours :\n");
    printf("ID\tNom\tDescription\n");
    printf("-------------------------------\n");

    while (fscanf(fp, "%d %49s %99[^\n]", &C.id, C.nom, C.description) == 3) {
        printf("%d\t%s\t%s\n", C.id, C.nom, C.description);
    }

    fclose(fp);
}

void Modifiercours() {
    int id, found = 0;
    cours C;
    FILE *fp = fopen("cours.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    printf("Entrer l'ID du cours à modifier : ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %49s %99[^\n]", &C.id, C.nom, C.description) == 3) {
        if (C.id == id) {
            found = 1;
            printf("Entrer le nouveau nom du cours (max 49 caractères) : ");
            scanf("%49s", C.nom);
            printf("Entrer la nouvelle description du cours (max 99 caractères) : ");
            scanf("%99s", C.description);
        }
        fprintf(temp, "%d %s %s\n", C.id, C.nom, C.description);
    }

    fclose(fp);
    fclose(temp);

    remove("cours.txt");
    rename("temp.txt", "cours.txt");

    if (found)
        printf("Cours modifié avec succès !\n");
    else
        printf("Cours avec ID %d non trouvé.\n", id);
}

void Supprimercours() {
    int id, found = 0;
    cours C;
    FILE *fp = fopen("cours.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    printf("Entrer l'ID du cours à supprimer : ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %49s %99[^\n]", &C.id, C.nom, C.description) == 3) {
        if (C.id == id) {
            found = 1;
            continue; // Ne pas copier le cours à supprimer
        }
        fprintf(temp, "%d %s %s\n", C.id, C.nom, C.description);
    }

    fclose(fp);
    fclose(temp);

    remove("cours.txt");
    rename("temp.txt", "cours.txt");

    if (found)
        printf("Cours supprimé avec succès !\n");
    else
        printf("Cours avec ID %d non trouvé.\n", id);
}

void GestionCours() {
    int choix;
    do {
        printf("\nGestion des cours :\n");
        printf("1. Ajouter un cours\n");
        printf("2. Modifier un cours\n");
        printf("3. Supprimer un cours\n");
        printf("4. Afficher les cours\n");
        printf("5. Retour au menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                Ajoutercours();
                break;
            case 2:
                Modifiercours();
                break;
            case 3:
                Supprimercours();
                break;
            case 4:
                Affichercours();
                break;
            case 5:
                printf("Retour au menu principal...\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 5);
}
