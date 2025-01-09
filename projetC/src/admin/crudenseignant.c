//fatma
#include "../../header/admin/crudenseignant.h"
#include <stdio.h>
#include <string.h>

void creerenseignant() {
    FILE *fp = fopen("enseignants.txt", "a");
    if (!fp) {
        perror("Erreur d'ouverture du fichier");
        return;
    }
    Enseignant E;
    char buffer[100];

    // Initialize all fields to "0"
    memset(&E, 0, sizeof(Enseignant));
    for (int i = 0; i < 5; i++) {
        strcpy(E.class_ids[i], "0");
    }
    strcpy(E.club_id, "0");
    for (int i = 0; i < 10; i++) {
        strcpy(E.event_ids[i], "0");
    }

    printf("Entrer l'id de l'enseignant: ");
    fgets(buffer, sizeof(buffer), stdin); // Clear the newline character from the input buffer
    scanf("%d", &E.id);
    fgets(buffer, sizeof(buffer), stdin); // Clear the newline character from the input buffer

    printf("Entrer le nom de l'enseignant: ");
    fgets(E.nom, sizeof(E.nom), stdin);
    E.nom[strcspn(E.nom, "\n")] = '\0'; // Remove the newline character

    printf("Entrer le prenom de l'enseignant: ");
    fgets(E.prenom, sizeof(E.prenom), stdin);
    E.prenom[strcspn(E.prenom, "\n")] = '\0'; // Remove the newline character

    printf("Entrer l'email professionnel de l'enseignant: ");
    fgets(E.email, sizeof(E.email), stdin);
    E.email[strcspn(E.email, "\n")] = '\0'; // Remove the newline character

    printf("Entrer le numéro de téléphone de l'enseignant: ");
    fgets(E.numerodetel, sizeof(E.numerodetel), stdin);
    E.numerodetel[strcspn(E.numerodetel, "\n")] = '\0'; // Remove the newline character

    printf("Entrer la spécialité de l'enseignant: ");
    fgets(E.spécialité, sizeof(E.spécialité), stdin);
    E.spécialité[strcspn(E.spécialité, "\n")] = '\0'; // Remove the newline character

    printf("Entrer le mot de passe de l'enseignant: ");
    fgets(E.password, sizeof(E.password), stdin);
    E.password[strcspn(E.password, "\n")] = '\0'; // Remove the newline character

    printf("Entrer les IDs des classes (séparés par des espaces, max 5, '0' si non disponible): ");
    for (int i = 0; i < 5; i++) {
        fgets(E.class_ids[i], sizeof(E.class_ids[i]), stdin);
        E.class_ids[i][strcspn(E.class_ids[i], "\n")] = '\0'; // Remove the newline character
        if (strcmp(E.class_ids[i], "0") == 0) {
            break;
        }
    }

    printf("Entrer l'ID du club ('0' si non disponible): ");
    fgets(E.club_id, sizeof(E.club_id), stdin);
    E.club_id[strcspn(E.club_id, "\n")] = '\0'; // Remove the newline character
    if (strcmp(E.club_id, "0") == 0) {
        strcpy(E.club_id, "0");
    }

    printf("Entrer le salaire: ");
    scanf("%f", &E.salaire);
    fgets(buffer, sizeof(buffer), stdin); // Clear the newline character from the input buffer

    printf("Entrer le nombre d'absences: ");
    scanf("%d", &E.absence);
    fgets(buffer, sizeof(buffer), stdin); // Clear the newline character from the input buffer

    printf("Entrer les IDs des événements (séparés par des espaces, max 10, '0' si non disponible): ");
    for (int i = 0; i < 10; i++) {
        fgets(E.event_ids[i], sizeof(E.event_ids[i]), stdin);
        E.event_ids[i][strcspn(E.event_ids[i], "\n")] = '\0'; // Remove the newline character
        if (strcmp(E.event_ids[i], "0") == 0) {
            break;
        }
    }

    fprintf(fp, "%d %s %s %s %s %s %s", E.id, E.nom, E.prenom, E.email, E.numerodetel, E.spécialité, E.password);
    for (int i = 0; i < 5; i++) {
        fprintf(fp, " %s", E.class_ids[i]);
    }
    fprintf(fp, " %s %.2f %d", E.club_id, E.salaire, E.absence);
    for (int i = 0; i < 10; i++) {
        fprintf(fp, " %s", E.event_ids[i]);
    }
    fprintf(fp, "\n");

    printf("Enseignant ajouté!\n");
    fclose(fp);
}

void afficherenseignant() {
    FILE *fp = fopen("enseignants.txt", "r");
    if (!fp) {
        perror("Erreur d'ouverture du fichier");
        return;
    }
    Enseignant E;
    printf("La liste des enseignants: \n");
    printf("%-10s %-15s %-15s %-25s %-20s %-15s %-15s %-10s %-10s %-10s %-50s\n",
           "ID", "Nom", "Prenom", "Email", "Numero de téléphone",
           "Specialité", "Classes", "Club", "Salaire", "Absences", "Evénements");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    while (fscanf(fp, "%d %49s %49s %99s %14s %49s %49s", &E.id, E.nom, E.prenom, E.email, E.numerodetel, E.spécialité, E.password) != EOF) {
        for (int i = 0; i < 5; i++) {
            fscanf(fp, "%9s", E.class_ids[i]);
        }
        fscanf(fp, "%9s %f %d", E.club_id, &E.salaire, &E.absence);
        for (int i = 0; i < 10; i++) {
            fscanf(fp, "%9s", E.event_ids[i]);
        }
        printf("%-10d %-15s %-15s %-25s %-20s %-15s ", E.id, E.nom, E.prenom, E.email, E.numerodetel, E.spécialité);
        for (int i = 0; i < 5; i++) {
            printf("%s ", E.class_ids[i]);
        }
        printf("%-10s %-10.2f %-10d ", E.club_id, E.salaire, E.absence);
        for (int i = 0; i < 10; i++) {
            printf("%s ", E.event_ids[i]);
        }
        printf("\n");
    }
    fclose(fp);
}

void supprimerenseignant() {
    FILE *fp = fopen("enseignants.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) {
        perror("Erreur d'ouverture des fichiers");
        return;
    }
    int id, trouve = 0;
    Enseignant E;
    printf("Entrez l'ID de l'enseignant à supprimer : ");
    scanf("%d", &id);
    while (fscanf(fp, "%d %49s %49s %99s %14s %49s %49s", &E.id, E.nom, E.prenom, E.email, E.numerodetel, E.spécialité, E.password) != EOF) {
        for (int i = 0; i < 5; i++) {
            fscanf(fp, "%9s", E.class_ids[i]);
        }
        fscanf(fp, "%9s %f %d", E.club_id, &E.salaire, &E.absence);
        for (int i = 0; i < 10; i++) {
            fscanf(fp, "%9s", E.event_ids[i]);
        }
        if (E.id == id) {
            trouve = 1;
        } else {
            fprintf(temp, "%d %s %s %s %s %s %s", E.id, E.nom, E.prenom, E.email, E.numerodetel, E.spécialité, E.password);
            for (int i = 0; i < 5; i++) {
                fprintf(temp, " %s", E.class_ids[i]);
            }
            fprintf(temp, " %s %.2f %d", E.club_id, E.salaire, E.absence);
            for (int i = 0; i < 10; i++) {
                fprintf(temp, " %s", E.event_ids[i]);
            }
            fprintf(temp, "\n");
        }
    }

    fclose(fp);
    fclose(temp);

    remove("enseignants.txt");
    rename("temp.txt", "enseignants.txt");
    if (trouve) {
        printf("L'enseignant avec l'ID %d a été supprimé.\n", id);
    } else {
        printf("L'enseignant avec l'ID %d n'a pas été trouvé.\n", id);
    }
} 

void modifierenseignant() {
    int id, trouve = 0;
    Enseignant E;
    char buffer[100]; // Define the buffer variable
    FILE *fp = fopen("enseignants.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!fp || !temp) {
        perror("Erreur d'ouverture des fichiers");
        return;
    }
    printf("Entrez l'ID de l'enseignant à modifier : ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %49s %49s %99s %14s %49s %49s", &E.id, E.nom, E.prenom, E.email, E.numerodetel, E.spécialité, E.password) != EOF) {
        for (int i = 0; i < 5; i++) {
            fscanf(fp, "%9s", E.class_ids[i]);
        }
        fscanf(fp, "%9s %f %d", E.club_id, &E.salaire, &E.absence);
        for (int i = 0; i < 10; i++) {
            fscanf(fp, "%9s", E.event_ids[i]);
        }
        if (E.id == id) {
            trouve = 1;
            printf("Entrer le nouveau id de l'enseignant: ");
            scanf("%d", &E.id);
            fgets(buffer, sizeof(buffer), stdin); // Clear the newline character from the input buffer

            printf("Entrer le nouveau nom de l'enseignant: ");
            fgets(E.nom, sizeof(E.nom), stdin);
            E.nom[strcspn(E.nom, "\n")] = '\0'; // Remove the newline character

            printf("Entrer le nouveau prenom de l'enseignant: ");
            fgets(E.prenom, sizeof(E.prenom), stdin);
            E.prenom[strcspn(E.prenom, "\n")] = '\0'; // Remove the newline character

            printf("Entrer le nouveau email professionnel de l'enseignant: ");
            fgets(E.email, sizeof(E.email), stdin);
            E.email[strcspn(E.email, "\n")] = '\0'; // Remove the newline character

            printf("Entrer le nouveau numéro de téléphone de l'enseignant: ");
            fgets(E.numerodetel, sizeof(E.numerodetel), stdin);
            E.numerodetel[strcspn(E.numerodetel, "\n")] = '\0'; // Remove the newline character

            printf("Entrer la nouvelle spécialité de l'enseignant: ");
            fgets(E.spécialité, sizeof(E.spécialité), stdin);
            E.spécialité[strcspn(E.spécialité, "\n")] = '\0'; // Remove the newline character

            printf("Entrer le nouveau mot de passe de l'enseignant: ");
            fgets(E.password, sizeof(E.password), stdin);
            E.password[strcspn(E.password, "\n")] = '\0'; // Remove the newline character

            printf("Entrer les nouveaux IDs des classes (séparés par des espaces, max 5, '0' si non disponible): ");
            for (int i = 0; i < 5; i++) {
                fgets(E.class_ids[i], sizeof(E.class_ids[i]), stdin);
                E.class_ids[i][strcspn(E.class_ids[i], "\n")] = '\0'; // Remove the newline character
                if (strcmp(E.class_ids[i], "0") == 0) {
                    break;
                }
            }

            printf("Entrer le nouveau ID du club ('0' si non disponible): ");
            fgets(E.club_id, sizeof(E.club_id), stdin);
            E.club_id[strcspn(E.club_id, "\n")] = '\0'; // Remove the newline character
            if (strcmp(E.club_id, "0") == 0) {
                strcpy(E.club_id, "0");
            }

            printf("Entrer le nouveau salaire: ");
            scanf("%f", &E.salaire);
            fgets(buffer, sizeof(buffer), stdin); // Clear the newline character from the input buffer

            printf("Entrer le nouveau nombre d'absences: ");
            scanf("%d", &E.absence);
            fgets(buffer, sizeof(buffer), stdin); // Clear the newline character from the input buffer

            printf("Entrer les nouveaux IDs des événements (séparés par des espaces, max 10, '0' si non disponible): ");
            for (int i = 0; i < 10; i++) {
                fgets(E.event_ids[i], sizeof(E.event_ids[i]), stdin);
                E.event_ids[i][strcspn(E.event_ids[i], "\n")] = '\0'; // Remove the newline character
                if (strcmp(E.event_ids[i], "0") == 0) {
                    break;
                }
            }
        }
        fprintf(temp, "%d %s %s %s %s %s %s", E.id, E.nom, E.prenom, E.email, E.numerodetel, E.spécialité, E.password);
        for (int i = 0; i < 5; i++) {
            fprintf(temp, " %s", E.class_ids[i]);
        }
        fprintf(temp, " %s %.2f %d", E.club_id, E.salaire, E.absence);
        for (int i = 0; i < 10; i++) {
            fprintf(temp, " %s", E.event_ids[i]);
        }
        fprintf(temp, "\n");
    }

    fclose(fp);
    fclose(temp);
    remove("enseignants.txt");
    rename("temp.txt", "enseignants.txt");

    if (trouve) {
        printf("Enseignant modifié avec succès.\n");
    } else {
        printf("Enseignant non trouvé.\n");
    }
}

void crudenseignant() {
    int choix;

    do {
        printf("Bonjour \n");
        printf("1 - CREER UN ENSEIGNANT \n");
        printf("2 - SUPPRIMER UN ENSEIGNANT\n");
        printf("3 - MODIFIER UN ENSEIGNANT\n");
        printf("4 - LISTER LES ENSEIGNANTS\n");
        printf("0 - RETOUR\n");
        printf("Sélectionnez votre choix \n");
        printf("--------------------------------- \n");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                creerenseignant();
                break;
            case 2:
                supprimerenseignant();
                break;
            case 3:
                modifierenseignant();
                break;
            case 4:
                afficherenseignant();
                break;
            case 0:
                printf("Retour au menu principal.\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    } while (choix != 0);
}