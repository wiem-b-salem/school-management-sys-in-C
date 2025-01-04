#include "../../header/admin/crudparent.h"
#include <stdio.h>
#include <string.h>

void creerparent() {
    FILE *fp = fopen("parents.txt", "a");
    if (!fp) {
        perror("Erreur d'ouverture du fichier");
        return;
    }
    parent P;
    char buffer[100];

    // Initialize all fields to "0"
    memset(&P, 0, sizeof(parent));
    for (int i = 0; i < 5; i++) {
        strcpy(P.student_ids[i], "0");
    }

    printf("Entrer l'id du parent: ");
    fgets(buffer, sizeof(buffer), stdin); // Clear the newline character from the input buffer
    scanf("%d", &P.id);
    fgets(buffer, sizeof(buffer), stdin); // Clear the newline character from the input buffer

    printf("Entrer le nom du parent: ");
    fgets(P.nom, sizeof(P.nom), stdin);
    P.nom[strcspn(P.nom, "\n")] = '\0'; // Remove the newline character

    printf("Entrer le prenom du parent: ");
    fgets(P.prenom, sizeof(P.prenom), stdin);
    P.prenom[strcspn(P.prenom, "\n")] = '\0'; // Remove the newline character

    printf("Entrer l'email du parent: ");
    fgets(P.email, sizeof(P.email), stdin);
    P.email[strcspn(P.email, "\n")] = '\0'; // Remove the newline character

    printf("Entrer le numéro de téléphone du parent: ");
    fgets(P.numerodetel, sizeof(P.numerodetel), stdin);
    P.numerodetel[strcspn(P.numerodetel, "\n")] = '\0'; // Remove the newline character

    printf("Entrer le mot de passe du parent: ");
    fgets(P.password, sizeof(P.password), stdin);
    P.password[strcspn(P.password, "\n")] = '\0'; // Remove the newline character

    printf("Entrer les IDs des étudiants (séparés par des espaces, max 5, '0' si non disponible): ");
    for (int i = 0; i < 5; i++) {
        fgets(P.student_ids[i], sizeof(P.student_ids[i]), stdin);
        P.student_ids[i][strcspn(P.student_ids[i], "\n")] = '\0'; // Remove the newline character
        if (strcmp(P.student_ids[i], "0") == 0) {
            break;
        }
    }

    fprintf(fp, "%d %s %s %s %s %s", P.id, P.nom, P.prenom, P.email, P.numerodetel, P.password);
    for (int i = 0; i < 5; i++) {
        fprintf(fp, " %s", P.student_ids[i]);
    }
    fprintf(fp, "\n");

    printf("Parent ajouté!\n");
    fclose(fp);
}

void supprimerparent() {
    FILE *fp = fopen("parents.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) {
        perror("Erreur d'ouverture des fichiers");
        return;
    }
    int id, trouve = 0;
    parent P;
    printf("Entrez l'ID du parent à supprimer : ");
    scanf("%d", &id);
    while (fscanf(fp, "%d %49s %49s %99s %14s %49s", &P.id, P.nom, P.prenom, P.email, P.numerodetel, P.password) != EOF) {
        for (int i = 0; i < 5; i++) {
            fscanf(fp, "%9s", P.student_ids[i]);
        }
        if (P.id == id) {
            trouve = 1;
        } else {
            fprintf(temp, "%d %s %s %s %s %s", P.id, P.nom, P.prenom, P.email, P.numerodetel, P.password);
            for (int i = 0; i < 5; i++) {
                fprintf(temp, " %s", P.student_ids[i]);
            }
            fprintf(temp, "\n");
        }
    }

    fclose(fp);
    fclose(temp);

    remove("parents.txt");
    rename("temp.txt", "parents.txt");
    if (trouve) {
        printf("Le parent avec l'id %d a été supprimé.\n", id);
    } else {
        printf("Le parent avec l'id %d n'a pas été trouvé.\n", id);
    }
}

void modifierparent() {
    int id, trouve = 0;
    parent P;
    FILE *fp = fopen("parents.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!fp || !temp) {
        perror("Erreur d'ouverture des fichiers");
        return;
    }
    printf("Entrez l'ID du parent à modifier : ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %49s %49s %99s %14s %49s", &P.id, P.nom, P.prenom, P.email, P.numerodetel, P.password) != EOF) {
        for (int i = 0; i < 5; i++) {
            fscanf(fp, "%9s", P.student_ids[i]);
        }
        if (P.id == id) {
            trouve = 1;
            printf("Entrer le nouveau id du parent: ");
            scanf("%d", &P.id);
            printf("Entrer le nouveau nom du parent: ");
            scanf("%49s", P.nom);
            printf("Entrer le nouveau prenom du parent: ");
            scanf("%49s", P.prenom);
            printf("Entrer le nouveau email du parent: ");
            scanf("%99s", P.email);
            printf("Entrer le nouveau numéro de téléphone du parent: ");
            scanf("%14s", P.numerodetel);
            printf("Entrer le nouveau mot de passe du parent: ");
            scanf("%49s", P.password);
            printf("Entrer les nouveaux IDs des étudiants (séparés par des espaces, max 5, '0' si non disponible): ");
            for (int i = 0; i < 5; i++) {
                fgets(P.student_ids[i], sizeof(P.student_ids[i]), stdin);
                P.student_ids[i][strcspn(P.student_ids[i], "\n")] = '\0'; // Remove the newline character
                if (strcmp(P.student_ids[i], "0") == 0) {
                    break;
                }
            }
        }
        fprintf(temp, "%d %s %s %s %s %s", P.id, P.nom, P.prenom, P.email, P.numerodetel, P.password);
        for (int i = 0; i < 5; i++) {
            fprintf(temp, " %s", P.student_ids[i]);
        }
        fprintf(temp, "\n");
    }

    fclose(fp);
    fclose(temp);
    remove("parents.txt");
    rename("temp.txt", "parents.txt");

    if (trouve) {
        printf("Parent modifié avec succès.\n");
    } else {
        printf("Parent non trouvé.\n");
    }
}

void afficherparent() {
    FILE *fp = fopen("parents.txt", "r");
    if (!fp) {
        perror("Erreur d'ouverture du fichier");
        return;
    }
    parent P;
    printf("\nListe des parents:\n");
    printf("%-10s %-15s %-15s %-25s %-20s %-15s %-30s\n",
           "ID", "Nom", "Prenom", "Email", "Numero de téléphone",
           "Mot de passe", "Étudiants");
    printf("------------------------------------------------------------------------------------------------------------------------\n");

    while (fscanf(fp, "%d %49s %49s %99s %14s %49s", &P.id, P.nom, P.prenom, P.email, P.numerodetel, P.password) != EOF) {
        for (int i = 0; i < 5; i++) {
            fscanf(fp, "%9s", P.student_ids[i]);
        }
        printf("%-10d %-15s %-15s %-25s %-20s %-15s ", P.id, P.nom, P.prenom, P.email, P.numerodetel, P.password);
        for (int i = 0; i < 5; i++) {
            printf("%s ", P.student_ids[i]);
        }
        printf("\n");
    }
    fclose(fp);
}

void crudparent() {
    int choix;

    do {
      printf("-------------------------------------------------------------------------------------------- \n");
        printf("Selectionnez votre choix \n");
        printf("1 - CREER UN PARENT\n");
        printf("2 - SUPPRIMER UN PARENT\n");
        printf("3 - MODIFIER UN PARENT\n");
        printf("4 - LISTER LES PARENTS\n");
        printf("0 - QUITTER\n");
        printf("--------------------------------- \n");
        scanf("%d", &choix);
    } while (choix < 0 || choix > 4);

    switch (choix) {
        case 1:
            creerparent();
            break;
        case 2:
            supprimerparent();
            break;
        case 3:
            modifierparent();
            break;
        case 4:
            afficherparent();
            break;
            case 0:
            printf("Retour au menu principal.\n");
            printf("-------------------------------------------------------------------------------------------- \n");
            break;
        default:
            break;
    }
}