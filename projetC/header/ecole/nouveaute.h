#ifndef NOUVEAUTE_H
#define NOUVEAUTE_H

typedef struct {
    int id;
    char type[50];
    char description[255];
} Nouveaute;

// D�clarations des fonctions
int chargerNouveautes(Nouveaute *nouveautes);
void sauvegarderNouveautes(Nouveaute *nouveautes, int nbNouveautes);
void ajouterNouveaute(Nouveaute *nouveautes, int *nbNouveautes);
void afficherNouveaute(Nouveaute nouveaute);
void afficherToutesLesNouveautes(Nouveaute *nouveautes, int nbNouveautes);
void modifierNouveaute(Nouveaute *nouveautes, int nbNouveautes);
void supprimerNouveaute(Nouveaute *nouveautes, int *nbNouveautes);

// Fonction pour g�rer les nouveaut�s via un menu
void crudnouveaute();

#endif
