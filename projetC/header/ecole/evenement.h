#ifndef EVENEMENT_H
#define EVENEMENT_H

// Structure pour représenter un événement de l'enseignant
typedef struct {
    char titre[100];       // Titre de l'événement
    char description[255]; // Description de l'événement
    char date[20];         // Date de l'événement (format: JJ/MM/AAAA)
} EvenementEnseignant;

// Déclaration des fonctions pour gérer les événements de l'enseignant
void afficherEvenements();  // Afficher les événements depuis le fichier
void ajouterEvenement();    // Ajouter un événement et le sauvegarder dans le fichier
void modifierEvenement();   // Modifier un événement dans le fichier
void supprimerEvenement();  // Supprimer un événement du fichier

// Fonction pour gérer le menu des événements de l'enseignant
void crudevenement();

#endif // EVENEMENT_H