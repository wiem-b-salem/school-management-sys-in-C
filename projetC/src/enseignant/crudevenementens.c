#include <stdio.h>
#include <string.h>
#include "../../header/ecole/evenement.h"

// Fonction pour afficher les événements
void afficherEvenements() {
    FILE *file = fopen("evenements.txt", "r");
    if (!file) {
        printf("Aucun événement à afficher.\n");
        return;
    }

    EvenementEnseignant evenement;
    int i = 1;
    printf("\n=== Liste des événements ===\n");
    while (fscanf(file, "%49[^|]|%49[^|]|%49[^\n]\n", evenement.titre, evenement.date, evenement.description) != EOF) {
        printf("Événement %d :\n", i++);
        printf("  Titre : %s\n", evenement.titre);
        printf("  Description : %s\n", evenement.description);
        printf("  Date : %s\n", evenement.date);
        printf("\n");
    }
    fclose(file);
}

// Fonction pour ajouter un événement
void ajouterEvenement() {
    FILE *file = fopen("evenements.txt", "a");
    if (!file) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    EvenementEnseignant nouvelEvenement;
    printf("Entrez le titre de l'événement : ");
    getchar();  // Pour ignorer le caractère '\n' restant dans le buffer
    fgets(nouvelEvenement.titre, sizeof(nouvelEvenement.titre), stdin);
    strtok(nouvelEvenement.titre, "\n");  // Supprimer le '\n' à la fin

    printf("Entrez la description de l'événement : ");
    fgets(nouvelEvenement.description, sizeof(nouvelEvenement.description), stdin);
    strtok(nouvelEvenement.description, "\n");

    printf("Entrez la date de l'événement (ex : 10/01/2024) : ");
    fgets(nouvelEvenement.date, sizeof(nouvelEvenement.date), stdin);
    strtok(nouvelEvenement.date, "\n");

    fprintf(file, "%s|%s|%s\n", nouvelEvenement.titre, nouvelEvenement.date, nouvelEvenement.description);
    fclose(file);

    printf("Événement ajouté avec succès.\n");
}

// Fonction pour modifier un événement
void modifierEvenement() {
    FILE *file = fopen("evenements.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!file || !temp) {
        perror("Erreur d'ouverture des fichiers");
        return;
    }

    EvenementEnseignant evenement;
    int choix, i = 1, trouve = 0;
    afficherEvenements();
    printf("Entrez le numéro de l'événement à modifier : ");
    scanf("%d", &choix);
    getchar();  // Pour ignorer le caractère '\n' restant dans le buffer

    while (fscanf(file, "%49[^|]|%49[^|]|%49[^\n]\n", evenement.titre, evenement.date, evenement.description) != EOF) {
        if (i == choix) {
            trouve = 1;
            printf("Entrez le nouveau titre de l'événement : ");
            fgets(evenement.titre, sizeof(evenement.titre), stdin);
            strtok(evenement.titre, "\n");

            printf("Entrez la nouvelle description de l'événement : ");
            fgets(evenement.description, sizeof(evenement.description), stdin);
            strtok(evenement.description, "\n");

            printf("Entrez la nouvelle date de l'événement : ");
            fgets(evenement.date, sizeof(evenement.date), stdin);
            strtok(evenement.date, "\n");
        }
        fprintf(temp, "%s|%s|%s\n", evenement.titre, evenement.date, evenement.description);
        i++;
    }

    fclose(file);
    fclose(temp);
    remove("evenements.txt");
    rename("temp.txt", "evenements.txt");

    if (trouve) {
        printf("Événement modifié avec succès.\n");
    } else {
        printf("Numéro d'événement invalide.\n");
    }
}

// Fonction pour supprimer un événement
void supprimerEvenement() {
    FILE *file = fopen("evenements.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!file || !temp) {
        perror("Erreur d'ouverture des fichiers");
        return;
    }

    EvenementEnseignant evenement;
    int choix, i = 1, trouve = 0;
    afficherEvenements();
    printf("Entrez le numéro de l'événement à supprimer : ");
    scanf("%d", &choix);
    getchar();  // Pour ignorer le caractère '\n' restant dans le buffer

    while (fscanf(file, "%49[^|]|%49[^|]|%49[^\n]\n", evenement.titre, evenement.date, evenement.description) != EOF) {
        if (i != choix) {
            fprintf(temp, "%s|%s|%s\n", evenement.titre, evenement.date, evenement.description);
        } else {
            trouve = 1;
        }
        i++;
    }

    fclose(file);
    fclose(temp);
    remove("evenements.txt");
    rename("temp.txt", "evenements.txt");

    if (trouve) {
        printf("Événement supprimé avec succès.\n");
    } else {
        printf("Numéro d'événement invalide.\n");
    }
}

// Fonction pour gérer le menu des événements de l'enseignant
void crudevenementEnseignant() {
    int choixEnseignant;
    do {
        printf("\n=== Menu Enseignant ===\n");
        printf("1 - Afficher les événements\n");
        printf("2 - Ajouter un événement\n");
        printf("3 - Modifier un événement\n");
        printf("4 - Supprimer un événement\n");
        printf("0 - Quitter\n");
        printf("Sélectionnez votre choix : ");
        scanf("%d", &choixEnseignant);

        switch (choixEnseignant) {
            case 1:
                afficherEvenements();
                break;
            case 2:
                ajouterEvenement();
                break;
            case 3:
                modifierEvenement();
                break;
            case 4:
                supprimerEvenement();
                break;
            case 0:
                printf("Au revoir enseignant !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choixEnseignant != 0);
}