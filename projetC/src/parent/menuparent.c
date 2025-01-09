#include <stdio.h>
#include <string.h>
#include "../../header/parent/parent.h"
#include "../../header/parent/nouveauteparent.h"
#include "../../header/ecole/message.h"
#include "../../header/parent/gererprofileetudiant.h"
#include "../../header/parent/gererprofileparent.h"

int verifyParentCredentials(const char *email, const char *password) {
    FILE *fp = fopen("parents.txt", "r");
    if (!fp) {
        perror("Erreur d'ouverture du fichier");
        return 0;
    }
    parent P;
    while (fscanf(fp, "%d %s %s %s %s %s", &P.id, P.nom, P.prenom, P.email, P.numerodetel, P.password) != EOF) {
        if (strcmp(P.email, email) == 0 && strcmp(P.password, password) == 0) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

void menuparent() {
    char email[100];
    char password[50];
    printf("Entrez votre email: ");
    scanf("%s", email);
    printf("Entrez votre mot de passe: ");
    scanf("%s", password);

    if (verifyParentCredentials(email, password)) {
        printf("Connexion réussie. Bienvenue parent!\n");
        int choix;
        do {
            printf("Bonjour \n");
            printf("Selectionnez votre choix \n");
            printf("1 - Gerer profile \n");
            printf("2 - Gerer profile eleve \n");
            printf("3 - Nouveaute \n");
            printf("4 - Voir les notes \n");
            printf("5 - Voir les absences \n");
            printf("6 - Boite de messagerie \n");
            printf("0 - QUITTER \n");
            scanf("%d", &choix);
        } while (choix < 0 || choix > 6);

        switch (choix) {
            case 1:
                gererProfileParent();
                break;
            case 2:
                gererProfileEtudiant();
                break;
            case 3:
                chargerNouveautesParent();
                break;
            case 4:
                // Call function to view grades
                break;
            case 5:
                // Call function to view absences
                break;
            case 6:
                {
                    int subChoix;
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
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide.\n");
                break;
        }
    } else {
        printf("Email ou mot de passe incorrect.\n");
    }
}