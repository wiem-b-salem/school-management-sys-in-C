#include <stdio.h>
#include "../../header/ecole/absence.h"
// Fonction pour afficher les absences
void afficherAbsences(Absence absences[], int nbAbsences) {
    int i ;
    printf("\n=== Liste des absences ===\n");
    for ( i = 0; i < nbAbsences; i++) {
        printf("Absence %d : %s\n", i + 1, absences[i].nomEtudiant);
        printf("Mati�re : %s\n", absences[i].matiere);
        printf("Date : %s\n", absences[i].date);
        printf("----------------------------\n");
    }
}

// Fonction pour ajouter une absence
void ajouterAbsence(Absence absence) {
    FILE *file = fopen("absences.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s|%s|%s\n", absence.nomEtudiant, absence.matiere, absence.date);
        fclose(file);
        printf("Absence ajout�e avec succ�s!\n");
    } else {
        printf("Erreur lors de l'ajout de l'absence.\n");
    }
}

// Fonction pour supprimer une absence en fonction de l'index
void supprimerAbsence(int index) {
    int i ;
    Absence absences[100];
    int nbAbsences = chargerAbsences(absences);

    if (index < 0 || index >= nbAbsences) {
        printf("Absence non trouv�e.\n");
        return;
    }

    // Re-d�placer les absences apr�s le supprim�
    for ( i = index; i < nbAbsences - 1; i++) {
        absences[i] = absences[i + 1];
    }

    nbAbsences--;
    sauvegarderAbsences(absences, nbAbsences);
    printf("Absence supprim�e avec succ�s!\n");
}

// Fonction pour modifier une absence
void modifierAbsence(int index, Absence absence) {
    Absence absences[100];
    int nbAbsences = chargerAbsences(absences);

    if (index < 0 || index >= nbAbsences) {
        printf("Absence non trouv�e.\n");
        return;
    }

    // Modifier l'absence � l'index sp�cifi�
    absences[index] = absence;
    sauvegarderAbsences(absences, nbAbsences);
    printf("Absence modifi�e avec succ�s!\n");
}

// Fonction pour charger les absences depuis le fichier
int chargerAbsences(Absence absences[]) {
    FILE *file = fopen("absences.txt", "r");
    if (file == NULL) {
        printf("Aucune absence trouv�e.\n");
        return 0;
    }

    int i = 0;
    while (fscanf(file, "%99[^|]|%49[^|]|%19[^\n]\n", absences[i].nomEtudiant, absences[i].matiere, absences[i].date) != EOF) {
        i++;
    }
    fclose(file);
    return i;
}

// Fonction pour sauvegarder les absences dans le fichier
void sauvegarderAbsences(Absence absences[], int nbAbsences) {
    int i ;
    FILE *file = fopen("absences.txt", "w");
    if (file != NULL) {
        for ( i = 0; i < nbAbsences; i++) {
            fprintf(file, "%s|%s|%s\n", absences[i].nomEtudiant, absences[i].matiere, absences[i].date);
        }
        fclose(file);
    } else {
        printf("Erreur lors de la sauvegarde des absences.\n");
    }
}

// Nouvelle fonction pour g�rer le menu des absences de l'enseignant
void menuAbsencesEnseignant() {
    Absence absences[100];
    int nbAbsences = chargerAbsences(absences);
    int choix;

    do {
        printf("\n=== Menu Enseignant - Gestion des Absences ===\n");
        printf("1 - Afficher les absences\n");
        printf("2 - Ajouter une absence\n");
        printf("3 - Supprimer une absence\n");
        printf("4 - Modifier une absence\n");
        printf("0 - Quitter\n");
        printf("S�lectionnez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                afficherAbsences(absences, nbAbsences);
                break;
            case 2:
                {
                    Absence nouvelleAbsence;
                    printf("Entrez le nom de l'�tudiant : ");
                    getchar();  // pour consommer le caract�re '\n' restant
                    fgets(nouvelleAbsence.nomEtudiant, sizeof(nouvelleAbsence.nomEtudiant), stdin);
                    printf("Entrez la mati�re : ");
                    fgets(nouvelleAbsence.matiere, sizeof(nouvelleAbsence.matiere), stdin);
                    printf("Entrez la date de l'absence : ");
                    fgets(nouvelleAbsence.date, sizeof(nouvelleAbsence.date), stdin);
                    ajouterAbsence(nouvelleAbsence);
                }
                break;
            case 3:
                {
                    int index;
                    printf("Entrez l'index de l'absence � supprimer : ");
                    scanf("%d", &index);
                    supprimerAbsence(index - 1);  // L'index est bas� sur 1 dans l'interface utilisateur
                }
                break;
            case 4:
                {
                    int index;
                    printf("Entrez l'index de l'absence � modifier : ");
                    scanf("%d", &index);
                    Absence absenceModifiee;
                    printf("Entrez le nom modifi� de l'�tudiant : ");
                    getchar();
                    fgets(absenceModifiee.nomEtudiant, sizeof(absenceModifiee.nomEtudiant), stdin);
                    printf("Entrez la mati�re modifi�e : ");
                    fgets(absenceModifiee.matiere, sizeof(absenceModifiee.matiere), stdin);
                    printf("Entrez la date modifi�e : ");
                    fgets(absenceModifiee.date, sizeof(absenceModifiee.date), stdin);
                    modifierAbsence(index - 1, absenceModifiee);  // Index de 1 dans l'interface
                }
                break;
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);
}

