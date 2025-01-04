#ifndef EVENEMENT_ENSEIGNANT_H
#define EVENEMENT_ENSEIGNANT_H

// Structure pour repr�senter un �v�nement de l'enseignant
typedef struct {
    char titre[100];       // Titre de l'�v�nement
    char description[255]; // Description de l'�v�nement
    char date[20];         // Date de l'�v�nement (format: JJ/MM/AAAA)
} EvenementEnseignant;

// D�claration des fonctions pour g�rer les �v�nements de l'enseignant
void afficherEvenements(EvenementEnseignant evenements[], int nbEvenements);
void ajouterEvenement(EvenementEnseignant evenements[], int *nbEvenements);
void modifierEvenement(EvenementEnseignant evenements[], int nbEvenements);
void supprimerEvenement(EvenementEnseignant evenements[], int *nbEvenements);
void sauvegarderEvenement(EvenementEnseignant[], int nbEvenements);

// Fonction pour g�rer le menu des �v�nements de l'enseignant
void menuEnseignant(EvenementEnseignant evenements[], int *nbEvenements);

#endif // EVENEMENT_ENSEIGNANT_H

