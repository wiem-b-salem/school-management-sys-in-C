#include <stdio.h>
#include "etudiant.h"
#include "classe.h"
#include "nouveaute.h"
#include "menuadmin.h"
#include "nouveaute_parent.h"
#include "nouveaute_enseignant.h"
#include "evenement_enseignant.h"
#include "absence.h"  // Inclure le fichier d'en-tête pour les absences

int main()
{
    Etudiant etudiants[100];
    Classe classes[50];
    Nouveaute nouveautes[50];
    EvenementEnseignant evenements[50];  // Tableau pour stocker les événements
    Absence absences[50];                // Tableau pour stocker les absences
    int nbEtudiants = 0, nbClasses = 0, nbNouveautes = 0, nbEvenements = 0, nbAbsences = 0;

    // Charger les données depuis les fichiers
    nbEtudiants = chargerEtudiants(etudiants);
    nbClasses = chargerClasses(classes);
    nbNouveautes = chargerNouveautes(nouveautes);
    nbAbsences = chargerAbsences(absences);  // Charger les absences

    int choix;
    do
    {
        printf("=== Bienvenue dans le système de management d'école ===\n \n");
        printf("Sélectionnez votre choix : \n");
        printf("0 - S'inscrire comme admin\n");
        printf("1 - S'inscrire comme parent\n");
        printf("2 - S'inscrire comme enseignant\n");

        if (scanf("%d", &choix) != 1)
        {
            while (getchar() != '\n');
            printf("Entrée invalide. Veuillez entrer un nombre entre 0 et 2.\n");
            continue; // Redemander l'entrée
        }
    } while (choix < 0 || choix > 2);

    if (choix == 0)
    {
        printf("Bonjour Admin \n");
        menuAdmin();
    }
    else if (choix == 1)
    {
        printf("Bonjour parent \n");
        NouveauteParent nouveauteParent = chargerNouveautesParent();
        afficherNouveautesParent(nouveauteParent);
    }
    else if (choix == 2)
    {
        printf("Bonjour enseignant \n");

        // Appel du menu des absences de l'enseignant
        menuAbsencesEnseignant(absences, nbAbsences);

        // Appel de la fonction pour gérer le menu des événements de l'enseignant
        menuEnseignant(evenements, &nbEvenements);

        NouveauteEnseignant nouveauteEnseignant = chargerNouveautesEnseignant();  // Charger les nouveautés spécifiques à l'enseignant
        afficherNouveautesEnseignant(nouveauteEnseignant);
    }

    // Sauvegarder les données lors de la sortie du programme
    sauvegarderEtudiants(etudiants, nbEtudiants);
    sauvegarderClasses(classes, nbClasses);
    sauvegarderNouveautes(nouveautes, nbNouveautes);
    sauvegarderAbsences(absences, nbAbsences);  // Sauvegarder les absences
    return 0;
}
