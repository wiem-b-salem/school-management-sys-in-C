#ifndef CRUD_H
#define CRUD_H

// Structure représentant un club
typedef struct {
    int id;
    char nom[50];
    char description[200];
} Club;

// Prototypes des fonctions CRUD
void ajouterClub(Club *clubs, int *nbClubs, int maxClubs);
void afficherClubs(const Club *clubs, int nbClubs);
void modifierClub(Club *clubs, int nbClubs, int id);
void supprimerClub(Club *clubs, int *nbClubs, int id);

#endif // CRUD_H
