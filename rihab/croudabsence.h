#ifndef CRUDABSENCE_H
#define CRUDABSENCE_H

#define MAX_ABSENCES 100 // Nombre maximum d'absences

typedef struct {
    int eleve_id;   // ID de l'élève
    int nb_absences; // Nombre d'absences
    char date[11];   // Date de l'absence (format jj/mm/aaaa)
} Absence;

// Déclarations des fonctions
void AjouterAbsence();
void AfficherAbsences();
void ModifierAbsence();
void SupprimerAbsence();
void GestionAbsences();

#endif // CRUDABSENCE_H
