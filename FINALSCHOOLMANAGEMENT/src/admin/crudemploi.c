#include "/home/wiem/Desktop/mei/uni/projects/C/FINALSCHOOLMANAGEMENT/header/admin/crudemploi.h"
#include <stdio.h>
#include <string.h>

void creeremploi() {
    FILE *fp = fopen("emplois.txt", "a");
    Employment E;
    printf("Entrer l'ID de la classe: ");
    scanf("%9s", E.class_id);
    printf("Entrer la classe: ");
    scanf("%1s", E.classe);
    printf("Entrer l'ID du professeur: ");
    scanf("%9s", E.professor_id);
    printf("Entrer l'emploi du temps hebdomadaire (6 jours, 2 horaires par jour):\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Jour %d, Horaire %d: ", i + 1, j + 1);
            scanf("%9s", E.weekly_schedule[i][j]);
        }
    }
    fprintf(fp, "%s %s %s ", E.class_id, E.classe, E.professor_id);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 2; j++) {
            fprintf(fp, "%s ", E.weekly_schedule[i][j]);
        }
    }
    fprintf(fp, "\n");
    printf("Emploi créé avec succès!\n");
    fclose(fp);
}

void afficheremploi() {
    FILE *fp = fopen("emplois.txt", "r");
    Employment E;
    if (!fp) {
        perror("Erreur d'ouverture du fichier");
        return;
    }
    printf("Liste des emplois:\n");
    printf("Class ID\tClasse\tProfesseur ID\tEmploi du Temps\n");
    while (fscanf(fp, "%9s %1s %9s", E.class_id, E.classe, E.professor_id) != EOF) {
        printf("%s\t\t%s\t%s\t", E.class_id, E.classe, E.professor_id);
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 2; j++) {
                fscanf(fp, "%9s", E.weekly_schedule[i][j]);
                printf("%s ", E.weekly_schedule[i][j]);
            }
        }
        printf("\n");
    }
    fclose(fp);
}

void supprimeremploi() {
    FILE *fp = fopen("emplois.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) {
        perror("Erreur d'ouverture des fichiers");
        return;
    }
    char id[10];
    int trouve = 0;
    Employment E;
    printf("Entrez l'ID de la classe à supprimer: ");
    scanf("%9s", id);
    while (fscanf(fp, "%9s %1s %9s", E.class_id, E.classe, E.professor_id) != EOF) {
        int match = strcmp(E.class_id, id);
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 2; j++) {
                fscanf(fp, "%9s", E.weekly_schedule[i][j]);
            }
        }
        if (match == 0) {
            trouve = 1;
        } else {
            fprintf(temp, "%s %s %s ", E.class_id, E.classe, E.professor_id);
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 2; j++) {
                    fprintf(temp, "%s ", E.weekly_schedule[i][j]);
                }
            }
            fprintf(temp, "\n");
        }
    }
    fclose(fp);
    fclose(temp);
    remove("emplois.txt");
    rename("temp.txt", "emplois.txt");
    if (trouve) {
        printf("Emploi supprimé avec succès.\n");
    } else {
        printf("Emploi non trouvé.\n");
    }
}

void modifieremploi() {
    FILE *fp = fopen("emplois.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) {
        perror("Erreur d'ouverture des fichiers");
        return;
    }
    char id[10];
    int trouve = 0;
    Employment E;
    printf("Entrez l'ID de la classe à modifier: ");
    scanf("%9s", id);
    while (fscanf(fp, "%9s %1s %9s", E.class_id, E.classe, E.professor_id) != EOF) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 2; j++) {
                fscanf(fp, "%9s", E.weekly_schedule[i][j]);
            }
        }
        if (strcmp(E.class_id, id) == 0) {
            trouve = 1;
            printf("Entrez les nouvelles informations pour l'emploi:\n");
            printf("Nouvel ID de classe: ");
            scanf("%9s", E.class_id);
            printf("Nouvelle classe: ");
            scanf("%1s", E.classe);
            printf("Nouvel ID du professeur: ");
            scanf("%9s", E.professor_id);
            printf("Nouveau planning (6 jours, 2 horaires par jour):\n");
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 2; j++) {
                    printf("Jour %d, Horaire %d: ", i + 1, j + 1);
                    scanf("%9s", E.weekly_schedule[i][j]);
                }
            }
        }
        fprintf(temp, "%s %s %s ", E.class_id, E.classe, E.professor_id);
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 2; j++) {
                fprintf(temp, "%s ", E.weekly_schedule[i][j]);
            }
        }
        fprintf(temp, "\n");
    }
    fclose(fp);
    fclose(temp);
    remove("emplois.txt");
    rename("temp.txt", "emplois.txt");
    if (trouve) {
        printf("Emploi modifié avec succès.\n");
    } else {
        printf("Emploi non trouvé.\n");
    }
}

void crudemploi() {
    int choix;
    do {
        printf("1 - CREER UN EMPLOI\n");
        printf("2 - SUPPRIMER UN EMPLOI\n");
        printf("3 - MODIFIER UN EMPLOI\n");
        printf("4 - LISTER LES EMPLOIS\n");
        printf("0 - QUITTER\n");
        printf("Votre choix: ");
        scanf("%d", &choix);
    } while (choix < 0 || choix > 4);

    switch (choix) {
        case 1:
            creeremploi();
            break;
        case 2:
            supprimeremploi();
            break;
        case 3:
            modifieremploi();
            break;
        case 4:
            afficheremploi();
            break;
        case 0:
            printf("Au revoir!\n");
            break;
        default:
            break;
    }
}
