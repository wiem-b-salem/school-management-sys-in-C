#include <stdio.h>
#include "../../header/parent/nouveauteparent.h"

// Fonction pour afficher les nouveaut�s du parent
void afficherNouveautesParent(NouveauteParent nouveautes) {
    int i;
    printf("\n=== Nouveaut�s pour le Parent ===\n");
    printf("�v�nements r�cents : %s\n", nouveautes.evenement);
    printf("Clubs : %s\n", nouveautes.club);
    printf("Moyenne : %.2f\n", nouveautes.moyenne);

    printf("Notes des mati�res :\n");
    for (i = 0; i < 5; i++) {
        printf("Mati�re %d : %d\n", i + 1, nouveautes.notes[i]);
    }
}

// Fonction pour charger les nouveaut�s sp�cifiques au parent
NouveauteParent chargerNouveautesParent() {
    int i;
    NouveauteParent nouveaute;

    // Donn�es fictives � titre d'exemple
    sprintf(nouveaute.evenement, "R�union des parents le 10 janvier");
    sprintf(nouveaute.club, "Club de sciences et club de sport");
    nouveaute.moyenne = 15.6;  // Moyenne fictive
    for (i = 0; i < 5; i++) {
        nouveaute.notes[i] = 12 + i;  // Notes fictives pour 5 mati�res
    }

    return nouveaute;
}
