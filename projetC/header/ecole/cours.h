#ifndef CRUD_H
#define CRUD_H

// Structure pour repr�senter un cours
typedef struct {
    int id;
    char titre[50];
} Cours;

// D�claration des fonctions
void ajouterCours();
void afficherCours();
void modifierCours();
void supprimerCours();

void crudcours();

#endif // CRUD_H

