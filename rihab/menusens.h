#ifndef MENUSENS_H
#define MENUSENS_H

// Structure pour représenter un cours pour l'enseignant
typedef struct {
    int id;
    char nom[50];
    char description[100];
} cours_enseignant;



// Prototypes des fonctions pour la gestion des cours de l'enseignant
void Ajoutercours_enseignant();
void Affichercours_enseignant();
void Modifiercours_enseignant();
void Supprimercours_enseignant();
void GestionCours_enseignant();

#endif // MENUSENS_H
