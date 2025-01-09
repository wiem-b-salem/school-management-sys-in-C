#ifndef NOUVEAUTE_ENSEIGNANT_H
#define NOUVEAUTE_ENSEIGNANT_H

// Structure pour contenir les nouveaut�s de l'enseignant
typedef struct {
    char evenement[100];   // �v�nement r�cent
    char absence[200];     // Absences des �tudiants
    int notes[5];          // Notes pour 5 mati�res
} NouveauteEnseignant;

// Prototypes des fonctions
void afficherNouveautesEnseignant(NouveauteEnseignant nouveautes);
NouveauteEnseignant chargerNouveautesEnseignant();

#endif

