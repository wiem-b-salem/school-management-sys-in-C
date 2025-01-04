#include <stdio.h>
#include <string.h>
#include "../../header/admin/crudenseignant.h"
#include "../../header/admin/crudparent.h"
#include "../../header/admin/crudnotes.h"
#include "../../header/admin/crudclub.h"
#include "../../header/admin/crudemploi.h"
#include "../../header/ecole/classe.h"
#include "../../header/ecole/cours.h"
#include "../../header/ecole/nouveaute.h"
#include "../../header/admin/admin.h"
#include "../../header/parent/eleve.h"
#include "../../header/ecole/event.h"
#include "../../header/ecole/message.h"

void menuadmin() {
    char tabchoix[11][15] = {"Enseignant", "Parent", "Etudiant", "Classe", "Cours", "Emploi", "Evenement", "Club", "Notes", "Profile", "Nouveaute"};
    int choix;
    do {
        printf("Bonjour \n");
        printf("Selectionnez votre choix \n");
        for (int i = 0; i < 11; i++) {
            printf("%d - Gerer %s \n", i + 1, tabchoix[i]);
        }
        printf("12 - Boite de messagerie\n");
        printf("0 - QUITTER\n");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                crudenseignant();
                break;
            case 2:
                crudparent();
                break;
            case 3:
                crudeleve();
                break;
            case 4:
                crudclasse();
                break;
            case 5:
                crudcours();
                break;
            case 6:
                crudemploi();
                break;
            case 7:
                crudevenement();
                break;
            case 8:
                crudclub();
                break;
            case 9:
                crudnotes();
                break;
            case 10:
                gererprofileadmin();
                break;
            case 11:
                crudnouveaute();
                break;
            case 12:
                {
                    int subChoix;
                    char email[100];
                    printf("Entrez votre email: ");
                    scanf("%s", email);

                    do {
                        printf("1 - Voir les messages\n");
                        printf("2 - Envoyer un message\n");
                        printf("0 - Retour\n");
                        scanf("%d", &subChoix);
                    } while (subChoix < 0 || subChoix > 2);

                    if (subChoix == 1) {
                        afficherMessages(email);
                        int messageIndex;
                        printf("Entrez le numéro du message à lire (0 pour retourner) : ");
                        scanf("%d", &messageIndex);
                        if (messageIndex > 0) {
                            afficherMessageDetail(email, messageIndex);
                        }
                    } else if (subChoix == 2) {
                        char receiver[100];
                        char content[500];
                        printf("Entrez l'email du destinataire : ");
                        scanf("%s", receiver);
                        printf("Entrez votre message : ");
                        getchar(); // Clear newline character from buffer
                        fgets(content, sizeof(content), stdin);
                        envoyerMessage(email, receiver, content);
                    }
                }
                break;
            case 0:
                printf("Au revoir \n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    } while (choix != 0);
}