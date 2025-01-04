#ifndef NOUVEAUTE_ENSEIGNANT_H
#define NOUVEAUTE_ENSEIGNANT_H

// Structure pour contenir les nouveautés de l'enseignant
typedef struct {
    char evenement[100];   // Événement récent
    char absence[200];     // Absences des étudiants
    int notes[5];          // Notes pour 5 matières
} NouveauteEnseignant;

// Prototypes des fonctions
void afficherNouveautesEnseignant(NouveauteEnseignant nouveautes);
NouveauteEnseignant chargerNouveautesEnseignant();

#endif

