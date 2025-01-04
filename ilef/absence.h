#ifndef ABSENCE_H
#define ABSENCE_H

// Définition de la structure Absence
typedef struct {
    char nomEtudiant[100];
    char matiere[50];
    char date[20];
} Absence;

// Fonction pour afficher les absences
void afficherAbsences(Absence absences[], int nbAbsences);

// Fonction pour ajouter une absence
void ajouterAbsence(Absence absence);

// Fonction pour supprimer une absence
void supprimerAbsence(int index);

// Fonction pour modifier une absence
void modifierAbsence(int index, Absence absence);

// Fonction pour charger les absences depuis le fichier
int chargerAbsences(Absence absences[]);

// Fonction pour sauvegarder les absences dans le fichier
void sauvegarderAbsences(Absence absences[], int nbAbsences);

// Fonction pour gérer le menu des absences de l'enseignant
void menuAbsencesEnseignant();

#endif // ABSENCE_H

