#ifndef EVENEMENT_ENSEIGNANT_H
#define EVENEMENT_ENSEIGNANT_H

// Structure pour représenter un événement de l'enseignant
typedef struct {
    char titre[100];       // Titre de l'événement
    char description[255]; // Description de l'événement
    char date[20];         // Date de l'événement (format: JJ/MM/AAAA)
} EvenementEnseignant;

// Déclaration des fonctions pour gérer les événements de l'enseignant
void afficherEvenements(EvenementEnseignant evenements[], int nbEvenements);
void ajouterEvenement(EvenementEnseignant evenements[], int *nbEvenements);
void modifierEvenement(EvenementEnseignant evenements[], int nbEvenements);
void supprimerEvenement(EvenementEnseignant evenements[], int *nbEvenements);
void sauvegarderEvenement(EvenementEnseignant[], int nbEvenements);

// Fonction pour gérer le menu des événements de l'enseignant
void menuEnseignant(EvenementEnseignant evenements[], int *nbEvenements);

#endif // EVENEMENT_ENSEIGNANT_H

