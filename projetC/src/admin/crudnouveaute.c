#include <stdio.h>
#include <string.h>
#include "../../header/ecole/nouveaute.h"

// Charger les nouveaut�s � partir du fichier
int chargerNouveautes(Nouveaute *nouveautes) {
    FILE *file = fopen("nouveautes.txt", "r");
    if (!file) {
        return 0;
    }

    int i = 0;
    while (fscanf(file, "%d %s %[^\n]\n", &nouveautes[i].id, nouveautes[i].type, nouveautes[i].description) == 3) {
        i++;
    }

    fclose(file);
    return i;
}

// Sauvegarder les nouveaut�s dans le fichier
void sauvegarderNouveautes(Nouveaute *nouveautes, int nbNouveautes) {
    int i ;
    FILE *file = fopen("nouveautes.txt", "w");
    if (!file) {
        printf("Erreur lors de l'ouverture du fichier pour la sauvegarde.\n");
        return;
    }

    for ( i = 0; i < nbNouveautes; i++) {
        fprintf(file, "%d %s %s\n", nouveautes[i].id, nouveautes[i].type, nouveautes[i].description);
    }

    fclose(file);
}

// Ajouter une nouveaut�
void ajouterNouveaute(Nouveaute *nouveautes, int *nbNouveautes) {
    Nouveaute n;
    printf("Entrez l'ID de la nouveaut�: ");
    scanf("%d", &n.id);
    printf("Entrez le type de nouveaut� (�v�nement, club, etc.): ");
    scanf("%s", n.type);
    printf("Entrez la description: ");
    getchar(); // Consommer le '\n' restant
    fgets(n.description, sizeof(n.description), stdin);
    n.description[strcspn(n.description, "\n")] = '\0'; // Supprimer le '\n'

    nouveautes[*nbNouveautes] = n;
    (*nbNouveautes)++;

    sauvegarderNouveautes(nouveautes, *nbNouveautes);
    printf("Nouveaut� ajout�e et sauvegard�e avec succ�s!\n");
}

// Afficher une nouveaut�
void afficherNouveaute(Nouveaute nouveaute) {
    printf("ID: %d\n", nouveaute.id);
    printf("Type: %s\n", nouveaute.type);
    printf("Description: %s\n", nouveaute.description);
}

// Afficher toutes les nouveaut�s
void afficherToutesLesNouveautes(Nouveaute *nouveautes, int nbNouveautes) {
    int i ;
    if (nbNouveautes == 0) {
        printf("Aucune nouveaut� � afficher.\n");
        return;
    }

    for ( i = 0; i < nbNouveautes; i++) {
        afficherNouveaute(nouveautes[i]);
        printf("\n");
    }
}

// Modifier une nouveaut�
void modifierNouveaute(Nouveaute *nouveautes, int nbNouveautes) {
    int id, found = 0;
    int i ;
    printf("Entrez l'ID de la nouveaut� � modifier: ");
    scanf("%d", &id);

    for ( i = 0; i < nbNouveautes; i++) {
        if (nouveautes[i].id == id) {
            found = 1;
            printf("Nouveaut� trouv�e. Entrez les nouvelles informations.\n");
            printf("Type: ");
            scanf("%s", nouveautes[i].type);
            printf("Description: ");
            getchar();
            fgets(nouveautes[i].description, sizeof(nouveautes[i].description), stdin);
            nouveautes[i].description[strcspn(nouveautes[i].description, "\n")] = '\0';
            printf("Nouveaut� modifi�e avec succ�s!\n");
            break;
        }
    }

    if (!found) {
        printf("Nouveaut� avec l'ID %d non trouv�e.\n", id);
    }

    sauvegarderNouveautes(nouveautes, nbNouveautes);
}

// Supprimer une nouveaut�
void supprimerNouveaute(Nouveaute *nouveautes, int *nbNouveautes) {
    int id, found = 0;
    int i , j ;
    printf("Entrez l'ID de la nouveaut� � supprimer: ");
    scanf("%d", &id);

    for ( i = 0; i < *nbNouveautes; i++) {
        if (nouveautes[i].id == id) {
            found = 1;
            for (j = i; j < *nbNouveautes - 1; j++) {
                nouveautes[j] = nouveautes[j + 1];
            }
            (*nbNouveautes)--;
            printf("Nouveaut� supprim�e avec succ�s!\n");
            break;
        }
    }

    if (!found) {
        printf("Nouveaut� avec l'ID %d non trouv�e.\n", id);
    }

    sauvegarderNouveautes(nouveautes, *nbNouveautes);
}

// Gestion des nouveaut�s via un menu
void crudnouveaute() {
    Nouveaute nouveautes[100];
    int nbNouveautes = chargerNouveautes(nouveautes);

    int choix;
    do {
        printf("=== Gestion des nouveaut�s ===\n");
        printf("1 - Ajouter une nouveaut�\n");
        printf("2 - Afficher toutes les nouveaut�s\n");
        printf("3 - Modifier une nouveaut�\n");
        printf("4 - Supprimer une nouveaut�\n");
        printf("0 - Retour\n");

        printf("S�lectionnez votre choix: ");
        printf("--------------------------------- \n");
        if (scanf("%d", &choix) != 1) {
            printf("Entr�e invalide.\n");
            while (getchar() != '\n');
        }

        switch (choix) {
            case 1:
                ajouterNouveaute(nouveautes, &nbNouveautes);
                break;
            case 2:
                afficherToutesLesNouveautes(nouveautes, nbNouveautes);
                break;
            case 3:
                modifierNouveaute(nouveautes, nbNouveautes);
                break;
            case 4:
                supprimerNouveaute(nouveautes, &nbNouveautes);
                break;
            case 0:
                return;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);
}
