//ilef
#include <stdio.h>
#include "../../header/ecole/classe.h"

// Charger les classes � partir du fichier
int chargerClasses(Classe *classes) {
    FILE *file = fopen("classes.txt", "r");
    if (!file) {
        return 0; // Si le fichier n'existe pas, pas de classes charg�es
    }

    int i = 0;
    while (fscanf(file, "%d %s %d\n", &classes[i].id, classes[i].nom, &classes[i].capacite) == 3) {
        i++;
    }

    fclose(file);
    return i;
}

// Sauvegarder les classes dans le fichier
void sauvegarderClasses(Classe *classes, int nbClasses) {
    int i ;
    FILE *file = fopen("classes.txt", "w");
    if (!file) {
        printf("Erreur lors de l'ouverture du fichier pour la sauvegarde.\n");
        return;
    }

    for ( i = 0; i < nbClasses; i++) {
        fprintf(file, "%d %s %d\n", classes[i].id, classes[i].nom, classes[i].capacite);
    }

    fclose(file);
}

// Ajouter une classe
void ajouterClasse(Classe *classes, int *nbClasses) {
    Classe c;
    printf("Entrez l'ID de la classe: ");
    scanf("%d", &c.id);
    printf("Entrez le nom de la classe: ");
    scanf("%s", c.nom);
    printf("Entrez la capacit� de la classe: ");
    scanf("%d", &c.capacite);

    classes[*nbClasses] = c;
    (*nbClasses)++;

    sauvegarderClasses(classes, *nbClasses);
    printf("Classe ajout�e et sauvegard�e avec succ�s!\n");
}

// Afficher une classe
void afficherClasse(Classe classe) {
    printf("ID: %d\n", classe.id);
    printf("Nom: %s\n", classe.nom);
    printf("Capacit�: %d\n", classe.capacite);
}

// Afficher toutes les classes
void afficherToutesLesClasses(Classe *classes, int nbClasses) {
    int i ;
    if (nbClasses == 0) {
        printf("Aucune classe � afficher.\n");
        return;
    }

    for ( i = 0; i < nbClasses; i++) {
        afficherClasse(classes[i]);
        printf("\n");
    }
}

// Modifier une classe
void modifierClasse(Classe *classes, int nbClasses) {
    int id,i, found = 0;
    printf("Entrez l'ID de la classe � modifier: ");
    scanf("%d", &id);

    for (i = 0; i < nbClasses; i++) {

        if (classes[i].id == id) {
            found = 1;
            printf("Classe trouv�e. Entrez les nouvelles informations.\n");
            printf("Nom: ");
            scanf("%s", classes[i].nom);
            printf("Capacit�: ");
            scanf("%d", &classes[i].capacite);
            printf("Classe modifi�e avec succ�s!\n");
            break;
        }
    }

    if (!found) {
        printf("Classe avec l'ID %d non trouv�e.\n", id);
    }

    sauvegarderClasses(classes, nbClasses);
}

// Supprimer une classe
void supprimerClasse(Classe *classes, int *nbClasses) {
    int id, found = 0;
    int i , j ;
    printf("Entrez l'ID de la classe � supprimer: ");
    scanf("%d", &id);

    for (i = 0; i < *nbClasses; i++) {
        if (classes[i].id == id) {
            found = 1;
            for ( j = i; j < *nbClasses - 1; j++) {
                classes[j] = classes[j + 1];
            }
            (*nbClasses)--;

            printf("Classe supprim�e avec succ�s!\n");
            break;
        }
    }

    if (!found) {
        printf("Classe avec l'ID %d non trouv�e.\n", id);
    }

    sauvegarderClasses(classes, *nbClasses);
}

// Fonction de gestion des classes
void crudclasse() {
    Classe classes[100];
    int nbClasses = chargerClasses(classes);

    int choix;
    do {
        printf("=== Gestion des classes ===\n");
        printf("1 - Ajouter une classe\n");
        printf("2 - Afficher toutes les classes\n");
        printf("3 - Modifier une classe\n");
        printf("4 - Supprimer une classe\n");
        printf("0 - Retour\n");

        printf("S�lectionnez votre choix: ");
        if (scanf("%d", &choix) != 1) {
            printf("Entr�e invalide.\n");
            while (getchar() != '\n');
        }

        switch (choix) {
            case 1:
                ajouterClasse(classes, &nbClasses);
                break;
            case 2:
                afficherToutesLesClasses(classes, nbClasses);
                break;
            case 3:
                modifierClasse(classes, nbClasses);
                break;
            case 4:
                supprimerClasse(classes, &nbClasses);
                break;
            case 0:
                return;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);
}
