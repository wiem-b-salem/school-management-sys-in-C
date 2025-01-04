#include <stdio.h>
#include "evenement_enseignant.h"

// Fonction pour afficher les �v�nements
void afficherEvenements(EvenementEnseignant evenements[], int nbEvenements) {
    int i ;
    if (nbEvenements == 0) {
        printf("Aucun �v�nement � afficher.\n");
        return;
    }

    printf("\n=== Liste des �v�nements ===\n");
    for ( i = 0; i < nbEvenements; i++) {
        printf("�v�nement %d :\n", i + 1);
        printf("  Titre : %s\n", evenements[i].titre);
        printf("  Description : %s\n", evenements[i].description);
        printf("  Date : %s\n", evenements[i].date);
        printf("\n");
    }
}

// Fonction pour ajouter un �v�nement
void ajouterEvenement(EvenementEnseignant evenements[], int *nbEvenements) {
    EvenementEnseignant nouvelEvenement;

    printf("Entrez le titre de l'�v�nement : ");
    getchar();  // Pour ignorer le caract�re '\n' restant dans le buffer
    fgets(nouvelEvenement.titre, sizeof(nouvelEvenement.titre), stdin);
    strtok(nouvelEvenement.titre, "\n");  // Supprimer le '\n' � la fin

    printf("Entrez la description de l'�v�nement : ");
    fgets(nouvelEvenement.description, sizeof(nouvelEvenement.description), stdin);
    strtok(nouvelEvenement.description, "\n");

    printf("Entrez la date de l'�v�nement (ex : 10/01/2024) : ");
    fgets(nouvelEvenement.date, sizeof(nouvelEvenement.date), stdin);
    strtok(nouvelEvenement.date, "\n");

    evenements[*nbEvenements] = nouvelEvenement;
    (*nbEvenements)++;

    printf("�v�nement ajout� avec succ�s.\n");
}

// Fonction pour modifier un �v�nement
void modifierEvenement(EvenementEnseignant evenements[], int nbEvenements) {
    int choix;
    afficherEvenements(evenements, nbEvenements);

    printf("Entrez le num�ro de l'�v�nement � modifier : ");
    scanf("%d", &choix);
    choix--;  // Ajuster l'indice pour correspondre � l'index du tableau

    if (choix < 0 || choix >= nbEvenements) {
        printf("Num�ro d'�v�nement invalide.\n");
        return;
    }

    printf("Entrez le nouveau titre de l'�v�nement : ");
    getchar();  // Pour ignorer le caract�re '\n' restant dans le buffer
    fgets(evenements[choix].titre, sizeof(evenements[choix].titre), stdin);
    strtok(evenements[choix].titre, "\n");

    printf("Entrez la nouvelle description de l'�v�nement : ");
    fgets(evenements[choix].description, sizeof(evenements[choix].description), stdin);
    strtok(evenements[choix].description, "\n");

    printf("Entrez la nouvelle date de l'�v�nement : ");
    fgets(evenements[choix].date, sizeof(evenements[choix].date), stdin);
    strtok(evenements[choix].date, "\n");

    printf("�v�nement modifi� avec succ�s.\n");
}

// Fonction pour supprimer un �v�nement
void supprimerEvenement(EvenementEnseignant evenements[], int *nbEvenements) {
    int choix;
    int i;
    afficherEvenements(evenements, *nbEvenements);

    printf("Entrez le num�ro de l'�v�nement � supprimer : ");
    scanf("%d", &choix);
    choix--;  // Ajuster l'indice pour correspondre � l'index du tableau

    if (choix < 0 || choix >= *nbEvenements) {
        printf("Num�ro d'�v�nement invalide.\n");
        return;
    }

    for ( i = choix; i < *nbEvenements - 1; i++) {
        evenements[i] = evenements[i + 1];
    }

    (*nbEvenements)--;

    printf("�v�nement supprim� avec succ�s.\n");
}
// Fonction pour sauvegarder les �v�nements dans le fichier
void sauvegarderEvenements(EvenementEnseignant evenements[], int nbEvenements) {
    int i ;
    FILE *file = fopen("evenements.txt", "w");
    if (file != NULL) {
        for ( i = 0; i < nbEvenements; i++) {
            fprintf(file, "%s|%s|%s\n", evenements[i].titre, evenements[i].date, evenements[i].description);
        }
        fclose(file);
    } else {
        printf("Erreur lors de la sauvegarde des �v�nements.\n");
    }
}

// Fonction pour g�rer le menu des �v�nements de l'enseignant
void menuEnseignant(EvenementEnseignant evenements[], int *nbEvenements) {
    int choixEnseignant;
    do {
        printf("\n=== Menu Enseignant ===\n");
        printf("1 - Afficher les �v�nements\n");
        printf("2 - Ajouter un �v�nement\n");
        printf("3 - Modifier un �v�nement\n");
        printf("4 - Supprimer un �v�nement\n");
        printf("0 - Quitter\n");
        printf("S�lectionnez votre choix : ");
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
                printf("Choix invalide. Veuillez r�essayer.\n");
        }
    } while (choixEnseignant != 0);
}

