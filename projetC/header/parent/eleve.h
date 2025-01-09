#ifndef ETUDIANT_H
#define ETUDIANT_H

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    float moyenne;
} Etudiant;

// D�clarations des fonctions
int chargerEtudiants(Etudiant *etudiants);
void sauvegarderEtudiants(Etudiant *etudiants, int nbEtudiants);
void ajouterEtudiant(Etudiant *etudiants, int *nbEtudiants);
void afficherEtudiant(Etudiant etudiant);
void afficherTousLesEtudiants(Etudiant *etudiants, int nbEtudiants);
void modifierEtudiant(Etudiant *etudiants, int nbEtudiants);
void supprimerEtudiant(Etudiant *etudiants, int *nbEtudiants);

// Fonction pour g�rer les �tudiants via un menu
void crudeleve();

#endif
