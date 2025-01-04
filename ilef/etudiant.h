#ifndef ETUDIANT_H
#define ETUDIANT_H

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    float moyenne;
} Etudiant;

// Déclarations des fonctions
int chargerEtudiants(Etudiant *etudiants);
void sauvegarderEtudiants(Etudiant *etudiants, int nbEtudiants);
void ajouterEtudiant(Etudiant *etudiants, int *nbEtudiants);
void afficherEtudiant(Etudiant etudiant);
void afficherTousLesEtudiants(Etudiant *etudiants, int nbEtudiants);
void modifierEtudiant(Etudiant *etudiants, int nbEtudiants);
void supprimerEtudiant(Etudiant *etudiants, int *nbEtudiants);

// Fonction pour gérer les étudiants via un menu
void gestionEtudiants();

#endif
