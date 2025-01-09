#ifndef NOUVEAUTE_PARENT_H
#define NOUVEAUTE_PARENT_H

// Structure contenant les nouveaut�s sp�cifiques au parent
typedef struct {
    char evenement[100];   // Description des �v�nements r�cents
    char club[100];        // Clubs auxquels l'�tudiant participe
    float moyenne;         // Moyenne de l'�tudiant
    int notes[5];          // Notes de l'�tudiant pour 5 mati�res
} NouveauteParent;

// D�claration des fonctions
void afficherNouveautesParent(NouveauteParent nouveautes);
NouveauteParent chargerNouveautesParent();

#endif
