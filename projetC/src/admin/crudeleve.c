#include <stdio.h>
#include "../../header/parent/eleve.h"

// Charger les �tudiants � partir du fichier
int chargerEtudiants(Etudiant *etudiants) {
    FILE *file = fopen("etudiants.txt", "r");
    if (!file) {
        return 0;  // Si le fichier n'existe pas, on retourne 0 (pas d'�tudiants charg�s)
    }

    int i = 0;
    while (fscanf(file, "%d %s %s %f\n", &etudiants[i].id, etudiants[i].nom, etudiants[i].prenom, &etudiants[i].moyenne) == 4) {
        i++;
    }

    fclose(file);
    return i;  // Retourne le nombre d'�tudiants charg�s
}

// Sauvegarder les �tudiants dans le fichier
void sauvegarderEtudiants(Etudiant *etudiants, int nbEtudiants) {
    int i ;
    FILE *file = fopen("etudiants.txt", "w");
    if (!file) {
        printf("Erreur lors de l'ouverture du fichier pour la sauvegarde.\n");
        return;
    }

    for ( i = 0; i < nbEtudiants; i++) {
        fprintf(file, "%d %s %s %.2f\n", etudiants[i].id, etudiants[i].nom, etudiants[i].prenom, etudiants[i].moyenne);
    }

    fclose(file);
}

// Ajouter un �tudiant
void ajouterEtudiant(Etudiant *etudiants, int *nbEtudiants) {
    Etudiant e;
    printf("Entrez l'ID de l'�tudiant: ");
    scanf("%d", &e.id);
    printf("Entrez le nom de l'�tudiant: ");
    scanf("%s", e.nom);
    printf("Entrez le pr�nom de l'�tudiant: ");
    scanf("%s", e.prenom);
    printf("Entrez la moyenne de l'�tudiant: ");
    scanf("%f", &e.moyenne);

    etudiants[*nbEtudiants] = e;
    (*nbEtudiants)++;

    sauvegarderEtudiants(etudiants, *nbEtudiants);
    printf("�tudiant ajout� et sauvegard� avec succ�s!\n");
}

// Afficher un �tudiant
void afficherEtudiant(Etudiant etudiant) {
    printf("ID: %d\n", etudiant.id);
    printf("Nom: %s\n", etudiant.nom);
    printf("Pr�nom: %s\n", etudiant.prenom);
    printf("Moyenne: %.2f\n", etudiant.moyenne);
}

// Afficher tous les �tudiants
void afficherTousLesEtudiants(Etudiant *etudiants, int nbEtudiants) {
    int i ;
    if (nbEtudiants == 0) {
        printf("Aucun �tudiant � afficher.\n");
        return;
    }

    for ( i = 0; i < nbEtudiants; i++) {
        afficherEtudiant(etudiants[i]);
        printf("\n");
    }
}

// Modifier un �tudiant
void modifierEtudiant(Etudiant *etudiants, int nbEtudiants) {
    int id,i, found = 0;
    printf("Entrez l'ID de l'�tudiant � modifier: ");
    scanf("%d", &id);

    for ( i = 0; i < nbEtudiants; i++) {
        if (etudiants[i].id == id) {
            found = 1;
            printf("�tudiant trouv�. Entrez les nouvelles informations.\n");
            printf("Nom: ");
            scanf("%s", etudiants[i].nom);
            printf("Pr�nom: ");
            scanf("%s", etudiants[i].prenom);
            printf("Moyenne: ");
            scanf("%f", &etudiants[i].moyenne);
            printf("�tudiant modifi� avec succ�s!\n");
            break;
        }
    }

    if (!found) {
        printf("�tudiant avec l'ID %d non trouv�.\n", id);
    }

    sauvegarderEtudiants(etudiants, nbEtudiants);
}

// Supprimer un �tudiant
void supprimerEtudiant(Etudiant *etudiants, int *nbEtudiants) {
    int id, found = 0;
    int i , j ;
    printf("Entrez l'ID de l'�tudiant � supprimer: ");
    scanf("%d", &id);

    for ( i = 0; i < *nbEtudiants; i++) {
        if (etudiants[i].id == id) {
            found = 1;
            for (j = i; j < *nbEtudiants - 1; j++) {
                etudiants[j] = etudiants[j + 1];
            }
            (*nbEtudiants)--;
            printf("�tudiant supprim� avec succ�s!\n");
            break;
        }
    }

    if (!found) {
        printf("�tudiant avec l'ID %d non trouv�.\n", id);
    }

    sauvegarderEtudiants(etudiants, *nbEtudiants);
}

// Gestion des �tudiants via un menu
void crudeleve() {
    Etudiant etudiants[100];
    int nbEtudiants = chargerEtudiants(etudiants);

    int choix;
    do {
        printf("=== Gestion des �tudiants ===\n");
        printf("1 - Ajouter un �tudiant\n");
        printf("2 - Afficher tous les �tudiants\n");
        printf("3 - Modifier un �tudiant\n");
        printf("4 - Supprimer un �tudiant\n");
        printf("0 - Retour\n");

        printf("S�lectionnez votre choix: ");
        printf("--------------------------------- \n");
        if (scanf("%d", &choix) != 1) {
            printf("Entr�e invalide.\n");
            while (getchar() != '\n');
        }

        switch (choix) {
            case 1:
                ajouterEtudiant(etudiants, &nbEtudiants);
                break;
            case 2:
                afficherTousLesEtudiants(etudiants, nbEtudiants);
                break;
            case 3:
                modifierEtudiant(etudiants, nbEtudiants);
                break;
            case 4:
                supprimerEtudiant(etudiants, &nbEtudiants);
                break;
            case 0:
                return;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);
}
