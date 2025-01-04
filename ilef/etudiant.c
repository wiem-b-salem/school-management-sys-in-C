#include <stdio.h>
#include "etudiant.h"

// Charger les étudiants à partir du fichier
int chargerEtudiants(Etudiant *etudiants) {
    FILE *file = fopen("etudiants.txt", "r");
    if (!file) {
        return 0;  // Si le fichier n'existe pas, on retourne 0 (pas d'étudiants chargés)
    }

    int i = 0;
    while (fscanf(file, "%d %s %s %f\n", &etudiants[i].id, etudiants[i].nom, etudiants[i].prenom, &etudiants[i].moyenne) == 4) {
        i++;
    }

    fclose(file);
    return i;  // Retourne le nombre d'étudiants chargés
}

// Sauvegarder les étudiants dans le fichier
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

// Ajouter un étudiant
void ajouterEtudiant(Etudiant *etudiants, int *nbEtudiants) {
    Etudiant e;
    printf("Entrez l'ID de l'étudiant: ");
    scanf("%d", &e.id);
    printf("Entrez le nom de l'étudiant: ");
    scanf("%s", e.nom);
    printf("Entrez le prénom de l'étudiant: ");
    scanf("%s", e.prenom);
    printf("Entrez la moyenne de l'étudiant: ");
    scanf("%f", &e.moyenne);

    etudiants[*nbEtudiants] = e;
    (*nbEtudiants)++;

    sauvegarderEtudiants(etudiants, *nbEtudiants);
    printf("Étudiant ajouté et sauvegardé avec succès!\n");
}

// Afficher un étudiant
void afficherEtudiant(Etudiant etudiant) {
    printf("ID: %d\n", etudiant.id);
    printf("Nom: %s\n", etudiant.nom);
    printf("Prénom: %s\n", etudiant.prenom);
    printf("Moyenne: %.2f\n", etudiant.moyenne);
}

// Afficher tous les étudiants
void afficherTousLesEtudiants(Etudiant *etudiants, int nbEtudiants) {
    int i ;
    if (nbEtudiants == 0) {
        printf("Aucun étudiant à afficher.\n");
        return;
    }

    for ( i = 0; i < nbEtudiants; i++) {
        afficherEtudiant(etudiants[i]);
        printf("\n");
    }
}

// Modifier un étudiant
void modifierEtudiant(Etudiant *etudiants, int nbEtudiants) {
    int id,i, found = 0;
    printf("Entrez l'ID de l'étudiant à modifier: ");
    scanf("%d", &id);

    for ( i = 0; i < nbEtudiants; i++) {
        if (etudiants[i].id == id) {
            found = 1;
            printf("Étudiant trouvé. Entrez les nouvelles informations.\n");
            printf("Nom: ");
            scanf("%s", etudiants[i].nom);
            printf("Prénom: ");
            scanf("%s", etudiants[i].prenom);
            printf("Moyenne: ");
            scanf("%f", &etudiants[i].moyenne);
            printf("Étudiant modifié avec succès!\n");
            break;
        }
    }

    if (!found) {
        printf("Étudiant avec l'ID %d non trouvé.\n", id);
    }

    sauvegarderEtudiants(etudiants, nbEtudiants);
}

// Supprimer un étudiant
void supprimerEtudiant(Etudiant *etudiants, int *nbEtudiants) {
    int id, found = 0;
    int i , j ;
    printf("Entrez l'ID de l'étudiant à supprimer: ");
    scanf("%d", &id);

    for ( i = 0; i < *nbEtudiants; i++) {
        if (etudiants[i].id == id) {
            found = 1;
            for (j = i; j < *nbEtudiants - 1; j++) {
                etudiants[j] = etudiants[j + 1];
            }
            (*nbEtudiants)--;
            printf("Étudiant supprimé avec succès!\n");
            break;
        }
    }

    if (!found) {
        printf("Étudiant avec l'ID %d non trouvé.\n", id);
    }

    sauvegarderEtudiants(etudiants, *nbEtudiants);
}

// Gestion des étudiants via un menu
void gestionEtudiants() {
    Etudiant etudiants[100];
    int nbEtudiants = chargerEtudiants(etudiants);

    int choix;
    do {
        printf("=== Gestion des étudiants ===\n");
        printf("1 - Ajouter un étudiant\n");
        printf("2 - Afficher tous les étudiants\n");
        printf("3 - Modifier un étudiant\n");
        printf("4 - Supprimer un étudiant\n");
        printf("0 - Retour\n");

        printf("Sélectionnez votre choix: ");
        if (scanf("%d", &choix) != 1) {
            printf("Entrée invalide.\n");
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
