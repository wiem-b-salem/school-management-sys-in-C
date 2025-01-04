#ifndef NOUVEAUTE_PARENT_H
#define NOUVEAUTE_PARENT_H

// Structure contenant les nouveautés spécifiques au parent
typedef struct {
    char evenement[100];   // Description des événements récents
    char club[100];        // Clubs auxquels l'étudiant participe
    float moyenne;         // Moyenne de l'étudiant
    int notes[5];          // Notes de l'étudiant pour 5 matières
} NouveauteParent;

// Déclaration des fonctions
void afficherNouveautesParent(NouveauteParent nouveautes);
NouveauteParent chargerNouveautesParent();

#endif
