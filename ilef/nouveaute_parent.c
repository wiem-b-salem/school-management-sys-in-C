#include <stdio.h>
#include "nouveaute_parent.h"

// Fonction pour afficher les nouveautés du parent
void afficherNouveautesParent(NouveauteParent nouveautes) {
    int i;
    printf("\n=== Nouveautés pour le Parent ===\n");
    printf("Événements récents : %s\n", nouveautes.evenement);
    printf("Clubs : %s\n", nouveautes.club);
    printf("Moyenne : %.2f\n", nouveautes.moyenne);

    printf("Notes des matières :\n");
    for (i = 0; i < 5; i++) {
        printf("Matière %d : %d\n", i + 1, nouveautes.notes[i]);
    }
}

// Fonction pour charger les nouveautés spécifiques au parent
NouveauteParent chargerNouveautesParent() {
    int i;
    NouveauteParent nouveaute;

    // Données fictives à titre d'exemple
    sprintf(nouveaute.evenement, "Réunion des parents le 10 janvier");
    sprintf(nouveaute.club, "Club de sciences et club de sport");
    nouveaute.moyenne = 15.6;  // Moyenne fictive
    for (i = 0; i < 5; i++) {
        nouveaute.notes[i] = 12 + i;  // Notes fictives pour 5 matières
    }

    return nouveaute;
}
