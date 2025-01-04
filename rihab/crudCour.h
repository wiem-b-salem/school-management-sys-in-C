#ifndef CRUD_H
#define CRUD_H

// Structure pour représenter un cours
typedef struct {
    int id;
    char titre[50];
} Cours;

// Déclaration des fonctions
void ajouterCours();
void afficherCours();
void modifierCours();
void supprimerCours();

#endif // CRUD_H

