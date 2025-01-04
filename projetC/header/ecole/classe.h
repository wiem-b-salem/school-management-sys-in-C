#ifndef CLASSE_H
#define CLASSE_H

typedef struct {
    int id;
    char nom[50];
    int capacite;
} Classe;

int chargerClasses(Classe *classes);
void sauvegarderClasses(Classe *classes, int nbClasses);
void ajouterClasse(Classe *classes, int *nbClasses);
void afficherClasse(Classe classe);
void afficherToutesLesClasses(Classe *classes, int nbClasses);
void modifierClasse(Classe *classes, int nbClasses);
void supprimerClasse(Classe *classes, int *nbClasses);

// D�claration de la fonction gestionClasses
void crudclasse();

#endif
