#include <stdio.h>
#include "crudabsence.h"
#include "crudnotes.h"
#include "crudcours.h"
#include "crudevent.h"
#include "menusens.h"

int main() {
    int choix;
    do {
        printf("\n=== Menu Principal ===\n");
        printf("0 - S'inscrire comme admin\n");
        printf("1 - S'inscrire comme parent\n");
        printf("2 - S'inscrire comme enseignant\n");
        printf("3 - Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 0:
                printf("Bonjour Admin\n");
                int choixAdmin;
                do {
                    printf("\n=== Menu Admin ===\n");
                    printf("1 - Gérer les cours\n");
                    printf("2 - Gérer les événements\n");
                    printf("3 - Retour au menu principal\n");
                    printf("Votre choix : ");
                    scanf("%d", &choixAdmin);

                    switch (choixAdmin) {
                        case 1:
                            GestionCours();  // Fonction pour gérer les cours
                            break;
                        case 2:
                            GestionEvent();  // Fonction pour gérer les événements
                            break;
                        case 3:
                            printf("Retour au menu principal...\n");
                            break;
                        default:
                            printf("Choix invalide. Veuillez réessayer.\n");
                    }
                } while (choixAdmin != 3);
                break;

            case 1:
                printf("Bonjour Parent\n");
                int choixParent;
                do {
                    printf("\n=== Menu Parent ===\n");
                    printf("1 - Consulter les absences\n");
                    printf("2 - Consulter les notes\n");
                    printf("3 - Retour au menu principal\n");
                    printf("Votre choix : ");
                    scanf("%d", &choixParent);

                    switch (choixParent) {
                        case 1:
                            GestionAbsences();  // Fonction pour gérer les absences
                            break;
                        case 2:
                          GestionNotes();  // Fonction pour gérer les notes
                            break;
                        case 3:
                            printf("Retour au menu principal...\n");
                            break;
                        default:
                            printf("Choix invalide. Veuillez réessayer.\n");
                    }
                } while (choixParent != 3);
                break;

            case 2:
                printf("Bonjour Enseignant\n");
                int choixEnseignant;
                do {
                    printf("\n=== Menu Enseignant ===\n");
                    printf("1 - Ajouter un cours\n");
                    printf("2 - Modifier un cours\n");
                    printf("3 - Supprimer un cours\n");
                    printf("4 - Afficher un cours\n");
                    printf("5 - Retour au menu principal\n");
                    printf("Votre choix : ");
                    scanf("%d", &choixEnseignant);

                    switch (choixEnseignant) {
                        case 1:
                            Ajoutercours_enseignant();
                            break;
                        case 2:
                           Modifiercours_enseignant();
                            break;
                        case 3:
                           Supprimercours_enseignant();
                            break;
                        case 4:
                           Affichercours_enseignant();
                            break;
                        case 5:
                            printf("Retour au menu principal...\n");
                            break;
                        default:
                            printf("Choix invalide. Veuillez réessayer.\n");
                    }
                } while (choixEnseignant != 5);
                break;

            case 3:
                printf("Merci d'avoir utilisé le système. À bientôt !\n");
                break;

            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 3);

    return 0;
}

