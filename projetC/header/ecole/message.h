#ifndef MESSAGES_H
#define MESSAGES_H

typedef struct {
    char sender[100];
    char receiver[100];
    char content[500];
    char timestamp[20];
} Message;

void envoyerMessage(const char *sender, const char *receiver, const char *content);
void afficherMessages(const char *email);
void afficherMessageDetail(const char *email, int messageIndex);

#endif // MESSAGES_H