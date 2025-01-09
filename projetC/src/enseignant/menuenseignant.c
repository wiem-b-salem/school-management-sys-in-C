//wiem
#include <stdio.h>
#include <string.h>
#include "../../header/enseignant/enseignant.h"
#include "../../header/ecole/message.h"


int verifyEnseignantCredentials(const char *email, const char *password) {
    FILE *fp = fopen("enseignants.txt", "r");
    if (!fp) {
        perror("Erreur d'ouverture du fichier");
        return 0;
    }
    Enseignant E;
    while (fscanf(fp, "%d %49s %49s %99s %14s %49s %49s", &E.id, E.nom, E.prenom, E.email, E.numerodetel, E.spécialité, E.password) != EOF) {
        if (strcmp(E.email, email) == 0 && strcmp(E.password, password) == 0) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

void menuenseignant() {
    char email[100];
    char password[50];
    printf("Entrez votre email: ");
    scanf("%s", email);
    printf("Entrez votre mot de passe: ");
    scanf("%s", password);

    if (verifyEnseignantCredentials(email, password)) {
        printf("Connexion réussie. Bienvenue enseignant!\n");
        int choix;
        do {
            printf("Bonjour \n");
            printf("Selectionnez votre choix \n");
            printf("1 - Gerer profile \n");
            printf("2 - Gerer notes \n");
            printf("3 - Gerer cours \n");
            printf("4 - voir les absences \n");
            printf("5 - Boite de messagerie \n");
            printf("6 - Gere ou creer un club \n");
            printf("7 - Gerer ou creer un evenement\n");
            printf("8 - nouveaute \n");
            printf("0 - QUITTER \n");
            scanf("%d", &choix);
        } while (choix < 0 || choix > 8);

        switch (choix) {
            case 1:
                gererprofile();
                break;
            case 2:
                crudnotes();
                break;
                case 3:
                //crudcours();
                break;
            case 4:
                // Call function to view absences
                break;
            case 5:
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
            case 6:
                crudclub();
                break;
            case 7:
                crudevenementEnseignant();
                break;
            case 8:
                chargerNouveautesEnseignant();
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } else {
        printf("Email ou mot de passe incorrect.\n");
    }
}