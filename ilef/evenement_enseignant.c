#include <stdio.h>
#include "evenement_enseignant.h"

// Fonction pour afficher les événements
void afficherEvenements(EvenementEnseignant evenements[], int nbEvenements) {
    int i ;
    if (nbEvenements == 0) {
        printf("Aucun événement à afficher.\n");
        return;
    }

    printf("\n=== Liste des événements ===\n");
    for ( i = 0; i < nbEvenements; i++) {
        printf("Événement %d :\n", i + 1);
        printf("  Titre : %s\n", evenements[i].titre);
        printf("  Description : %s\n", evenements[i].description);
        printf("  Date : %s\n", evenements[i].date);
        printf("\n");
    }
}

// Fonction pour ajouter un événement
void ajouterEvenement(EvenementEnseignant evenements[], int *nbEvenements) {
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

    evenements[*nbEvenements] = nouvelEvenement;
    (*nbEvenements)++;

    printf("Événement ajouté avec succès.\n");
}

// Fonction pour modifier un événement
void modifierEvenement(EvenementEnseignant evenements[], int nbEvenements) {
    int choix;
    afficherEvenements(evenements, nbEvenements);

    printf("Entrez le numéro de l'événement à modifier : ");
    scanf("%d", &choix);
    choix--;  // Ajuster l'indice pour correspondre à l'index du tableau

    if (choix < 0 || choix >= nbEvenements) {
        printf("Numéro d'événement invalide.\n");
        return;
    }

    printf("Entrez le nouveau titre de l'événement : ");
    getchar();  // Pour ignorer le caractère '\n' restant dans le buffer
    fgets(evenements[choix].titre, sizeof(evenements[choix].titre), stdin);
    strtok(evenements[choix].titre, "\n");

    printf("Entrez la nouvelle description de l'événement : ");
    fgets(evenements[choix].description, sizeof(evenements[choix].description), stdin);
    strtok(evenements[choix].description, "\n");

    printf("Entrez la nouvelle date de l'événement : ");
    fgets(evenements[choix].date, sizeof(evenements[choix].date), stdin);
    strtok(evenements[choix].date, "\n");

    printf("Événement modifié avec succès.\n");
}

// Fonction pour supprimer un événement
void supprimerEvenement(EvenementEnseignant evenements[], int *nbEvenements) {
    int choix;
    int i;
    afficherEvenements(evenements, *nbEvenements);

    printf("Entrez le numéro de l'événement à supprimer : ");
    scanf("%d", &choix);
    choix--;  // Ajuster l'indice pour correspondre à l'index du tableau

    if (choix < 0 || choix >= *nbEvenements) {
        printf("Numéro d'événement invalide.\n");
        return;
    }

    for ( i = choix; i < *nbEvenements - 1; i++) {
        evenements[i] = evenements[i + 1];
    }

    (*nbEvenements)--;

    printf("Événement supprimé avec succès.\n");
}
// Fonction pour sauvegarder les événements dans le fichier
void sauvegarderEvenements(EvenementEnseignant evenements[], int nbEvenements) {
    int i ;
    FILE *file = fopen("evenements.txt", "w");
    if (file != NULL) {
        for ( i = 0; i < nbEvenements; i++) {
            fprintf(file, "%s|%s|%s\n", evenements[i].titre, evenements[i].date, evenements[i].description);
        }
        fclose(file);
    } else {
        printf("Erreur lors de la sauvegarde des événements.\n");
    }
}

// Fonction pour gérer le menu des événements de l'enseignant
void menuEnseignant(EvenementEnseignant evenements[], int *nbEvenements) {
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
                afficherEvenements(evenements, *nbEvenements);
                break;
            case 2:
                ajouterEvenement(evenements, nbEvenements);
                break;
            case 3:
                modifierEvenement(evenements, *nbEvenements);
                break;
            case 4:
                supprimerEvenement(evenements, nbEvenements);
                break;
            case 0:
                printf("Au revoir enseignant !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choixEnseignant != 0);
}

