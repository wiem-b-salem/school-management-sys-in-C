#include <stdio.h>
#include "absence.h"

// Fonction pour afficher les absences
void afficherAbsences(Absence absences[], int nbAbsences) {
    int i ;
    printf("\n=== Liste des absences ===\n");
    for ( i = 0; i < nbAbsences; i++) {
        printf("Absence %d : %s\n", i + 1, absences[i].nomEtudiant);
        printf("Matière : %s\n", absences[i].matiere);
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
        printf("Absence ajoutée avec succès!\n");
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
        printf("Absence non trouvée.\n");
        return;
    }

    // Re-déplacer les absences après le supprimé
    for ( i = index; i < nbAbsences - 1; i++) {
        absences[i] = absences[i + 1];
    }

    nbAbsences--;
    sauvegarderAbsences(absences, nbAbsences);
    printf("Absence supprimée avec succès!\n");
}

// Fonction pour modifier une absence
void modifierAbsence(int index, Absence absence) {
    Absence absences[100];
    int nbAbsences = chargerAbsences(absences);

    if (index < 0 || index >= nbAbsences) {
        printf("Absence non trouvée.\n");
        return;
    }

    // Modifier l'absence à l'index spécifié
    absences[index] = absence;
    sauvegarderAbsences(absences, nbAbsences);
    printf("Absence modifiée avec succès!\n");
}

// Fonction pour charger les absences depuis le fichier
int chargerAbsences(Absence absences[]) {
    FILE *file = fopen("absences.txt", "r");
    if (file == NULL) {
        printf("Aucune absence trouvée.\n");
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

// Nouvelle fonction pour gérer le menu des absences de l'enseignant
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
        printf("Sélectionnez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                afficherAbsences(absences, nbAbsences);
                break;
            case 2:
                {
                    Absence nouvelleAbsence;
                    printf("Entrez le nom de l'étudiant : ");
                    getchar();  // pour consommer le caractère '\n' restant
                    fgets(nouvelleAbsence.nomEtudiant, sizeof(nouvelleAbsence.nomEtudiant), stdin);
                    printf("Entrez la matière : ");
                    fgets(nouvelleAbsence.matiere, sizeof(nouvelleAbsence.matiere), stdin);
                    printf("Entrez la date de l'absence : ");
                    fgets(nouvelleAbsence.date, sizeof(nouvelleAbsence.date), stdin);
                    ajouterAbsence(nouvelleAbsence);
                }
                break;
            case 3:
                {
                    int index;
                    printf("Entrez l'index de l'absence à supprimer : ");
                    scanf("%d", &index);
                    supprimerAbsence(index - 1);  // L'index est basé sur 1 dans l'interface utilisateur
                }
                break;
            case 4:
                {
                    int index;
                    printf("Entrez l'index de l'absence à modifier : ");
                    scanf("%d", &index);
                    Absence absenceModifiee;
                    printf("Entrez le nom modifié de l'étudiant : ");
                    getchar();
                    fgets(absenceModifiee.nomEtudiant, sizeof(absenceModifiee.nomEtudiant), stdin);
                    printf("Entrez la matière modifiée : ");
                    fgets(absenceModifiee.matiere, sizeof(absenceModifiee.matiere), stdin);
                    printf("Entrez la date modifiée : ");
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

