#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../header/ecole/message.h"

void envoyerMessage(const char *sender, const char *receiver, const char *content) {
    FILE *file = fopen("messages.txt", "a");
    if (!file) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", t);

    fprintf(file, "%s|%s|%s|%s\n", sender, receiver, content, timestamp);
    fclose(file);

    printf("Message envoyé avec succès.\n");
}

void afficherMessages(const char *email) {
    FILE *file = fopen("messages.txt", "r");
    if (!file) {
        printf("Aucun message à afficher.\n");
        return;
    }

    Message message;
    int i = 1;
    printf("\n=== Liste des messages ===\n");
    while (fscanf(file, "%99[^|]|%99[^|]|%499[^|]|%19[^\n]\n", message.sender, message.receiver, message.content, message.timestamp) != EOF) {
        if (strcmp(message.receiver, email) == 0) {
            printf("%d. De: %s\n", i++, message.sender);
        }
    }
    fclose(file);
}

void afficherMessageDetail(const char *email, int messageIndex) {
    FILE *file = fopen("messages.txt", "r");
    if (!file) {
        printf("Aucun message à afficher.\n");
        return;
    }

    Message message;
    int i = 1;
    while (fscanf(file, "%99[^|]|%99[^|]|%499[^|]|%19[^\n]\n", message.sender, message.receiver, message.content, message.timestamp) != EOF) {
        if (strcmp(message.receiver, email) == 0) {
            if (i == messageIndex) {
                printf("\n=== Message de %s ===\n", message.sender);
                printf("Date: %s\n", message.timestamp);
                printf("Message: %s\n", message.content);
                break;
            }
            i++;
        }
    }
    fclose(file);
}