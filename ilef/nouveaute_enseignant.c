#include <stdio.h>
#include "nouveaute_enseignant.h"

// Fonction pour afficher les nouveautés de l'enseignant
void afficherNouveautesEnseignant(NouveauteEnseignant nouveautes) {
    int i;
    printf("\n=== Nouveautes pour l'Enseignant ===\n");
    printf("evenements recents : %s\n", nouveautes.evenement);
    printf("Absences des etudiants : %s\n", nouveautes.absence);

    printf("Notes des matieres :\n");
    for (i = 0; i < 5; i++) {
        printf("Matiere %d : %d\n", i + 1, nouveautes.notes[i]);
    }
}

// Fonction pour charger les nouveautés spécifiques à l'enseignant
NouveauteEnseignant chargerNouveautesEnseignant() {
    int i;
    NouveauteEnseignant nouveaute;

    // Données fictives à titre d'exemple
    sprintf(nouveaute.evenement, "Seance de revision prevue le 15 janvier");
    sprintf(nouveaute.absence, "etudiant X a ete absent en cours de physique");
    for (i = 0; i < 5; i++) {
        nouveaute.notes[i] = 10 + i;  // Notes fictives pour 5 matières
    }

    return nouveaute;
}

