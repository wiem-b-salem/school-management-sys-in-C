#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menusens.h"


void Ajoutercours_enseignant() {
    cours_enseignant C1;
    FILE *fp = fopen("cours_enseignant.txt", "a");
    if (!fp) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    printf("[DEBUG] Début de la fonction Ajoutercours_enseignant\n");

    printf("Entrer l'ID du cours : ");
    if (scanf("%d", &C1.id) != 1) {
        printf("Erreur : Entrée invalide pour l'ID du cours.\n");
        while (getchar() != '\n');
        fclose(fp);
        return;
    }
    while (getchar() != '\n');

    printf("Entrer le nom du cours (max 49 caractères) : ");
    if (scanf("%49[^\n]", C1.nom) != 1) {
        printf("Erreur : Entrée invalide pour le nom du cours.\n");
        while (getchar() != '\n');
        fclose(fp);
        return;
    }
    while (getchar() != '\n');

    printf("Entrer la description du cours (max 99 caractères) : ");
    if (scanf("%99[^\n]", C1.description) != 1) {
        printf("Erreur : Entrée invalide pour la description du cours.\n");
        while (getchar() != '\n');
        fclose(fp);
        return;
    }
    while (getchar() != '\n');

    fprintf(fp, "%d %s %s\n", C1.id, C1.nom, C1.description);
    printf("Cours ajouté avec succès !\n");

    printf("[DEBUG] Fin de la fonction Ajoutercours_enseignant\n");
    fclose(fp);
}

void Affichercours_enseignant() {
    cours_enseignant C1;
    FILE *fp = fopen("cours_enseignant.txt", "r");
    if (!fp) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    printf("\nListe des cours pour Enseignant :\n");
    printf("ID\tNom\tDescription\n");
    printf("-------------------------------\n");

    while (fscanf(fp, "%d %49s %99[^\n]", &C1.id, C1.nom, C1.description) == 3) {
        printf("%d\t%s\t%s\n", C1.id, C1.nom, C1.description);
    }

    fclose(fp);
}

void Modifiercours_enseignant() {
    int id, found = 0;
    cours_enseignant C1;
    FILE *fp = fopen("cours_enseignant.txt", "r");
    FILE *temp = fopen("temp_enseignant.txt", "w");
    if (!fp || !temp) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    printf("Entrer l'ID du cours à modifier : ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %49s %99[^\n]", &C1.id, C1.nom, C1.description) == 3) {
        if (C1.id == id) {
            found = 1;
            printf("Entrer le nouveau nom du cours (max 49 caractères) : ");
            scanf("%49s", C1.nom);
            printf("Entrer la nouvelle description du cours (max 99 caractères) : ");
            scanf("%99s", C1.description);
        }
        fprintf(temp, "%d %s %s\n", C1.id, C1.nom, C1.description);
    }

    fclose(fp);
    fclose(temp);

    remove("cours_enseignant.txt");
    rename("temp_enseignant.txt", "cours_enseignant.txt");

    if (found)
        printf("Cours modifié avec succès !\n");
    else
        printf("Cours avec ID %d non trouvé.\n", id);
}

void Supprimercours_enseignant() {
    int id, found = 0;
    cours_enseignant C1;
    FILE *fp = fopen("cours_enseignant.txt", "r");
    FILE *temp = fopen("temp_enseignant.txt", "w");
    if (!fp || !temp) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    printf("Entrer l'ID du cours à supprimer : ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %49s %99[^\n]", &C1.id, C1.nom, C1.description) == 3) {
        if (C1.id == id) {
            found = 1;
            continue;
        }
        fprintf(temp, "%d %s %s\n", C1.id, C1.nom, C1.description);
    }

    fclose(fp);
    fclose(temp);

    remove("cours_enseignant.txt");
    rename("temp_enseignant.txt", "cours_enseignant.txt");

    if (found)
        printf("Cours supprimé avec succès !\n");
    else
        printf("Cours avec ID %d non trouvé.\n", id);
}

void GestionCours_enseignant() {
    int choix;
    do {
        printf("\n=== Gestion des cours de l'Enseignant ===\n");
        printf("1. Ajouter un cours\n");
        printf("2. Modifier un cours\n");
        printf("3. Supprimer un cours\n");
        printf("4. Afficher les cours\n");
        printf("5. Retour au menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        while (getchar() != '\n');

        switch (choix) {
            case 1:
                printf("[DEBUG] Appel de la fonction Ajoutercours_enseignant\n");
                Ajoutercours_enseignant();
                break;
            case 2:
                Modifiercours_enseignant();
                break;
            case 3:
                Supprimercours_enseignant();
                break;
            case 4:
                Affichercours_enseignant();
                break;
            case 5:
                printf("Retour au menu principal...\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 5);
}
