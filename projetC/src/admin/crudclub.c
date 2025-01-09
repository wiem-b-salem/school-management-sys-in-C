//wiem
#include "../../header/admin/crudclub.h"
#include <stdio.h>
#include <string.h>

void creerclub() {
    FILE *fp = fopen("clubs.txt", "a");
    Club C;
    printf("Entrer l'ID du club: ");
    scanf("%9s", C.id);
    printf("Entrer le nom du club: ");
    scanf("%49s", C.nom);
    printf("Entrer l'ID du professeur responsable: ");
    scanf("%9s", C.professor_id);
    printf("Entrer la classe: ");
    scanf("%1s", C.classe);
    fprintf(fp, "%s %s %s %s\n", C.id, C.nom, C.professor_id, C.classe);
    printf("Club créé avec succès!\n");
    fclose(fp);
}

void afficherclub() {
    FILE *fp = fopen("clubs.txt", "r");
    Club C;
    if (!fp) {
        perror("Erreur d'ouverture du fichier");
        return;
    }
    printf("Liste des clubs:\n");
    printf("Club ID\t\tNom\t\tProfesseur ID\t\tClasse\n");
    while (fscanf(fp, "%9s %49s %9s %1s", C.id, C.nom, C.professor_id, C.classe) != EOF) {
        printf("%s\t\t%-10s\t%-10s\t\t%s\n", C.id, C.nom, C.professor_id, C.classe);
    }
    fclose(fp);
}

void supprimerclub() {
    FILE *fp = fopen("clubs.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) {
        perror("Erreur d'ouverture des fichiers");
        return;
    }
    char id[10];
    int trouve = 0;
    Club C;
    printf("Entrez l'ID du club à supprimer: ");
    scanf("%9s", id);
    while (fscanf(fp, "%9s %49s %9s %1s", C.id, C.nom, C.professor_id, C.classe) != EOF) {
        if (strcmp(C.id, id) == 0) {
            trouve = 1;
        } else {
            fprintf(temp, "%s %s %s %s\n", C.id, C.nom, C.professor_id, C.classe);
        }
    }
    fclose(fp);
    fclose(temp);
    remove("clubs.txt");
    rename("temp.txt", "clubs.txt");
    if (trouve) {
        printf("Club supprimé avec succès.\n");
    } else {
        printf("Club non trouvé.\n");
    }
}

void modifierclub() {
    FILE *fp = fopen("clubs.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) {
        perror("Erreur d'ouverture des fichiers");
        return;
    }
    char id[10];
    int trouve = 0;
    Club C;
    printf("Entrez l'ID du club à modifier: ");
    scanf("%9s", id);
    while (fscanf(fp, "%9s %49s %9s %1s", C.id, C.nom, C.professor_id, C.classe) != EOF) {
        if (strcmp(C.id, id) == 0) {
            trouve = 1;
            printf("Entrer le nouvel ID du club: ");
            scanf("%9s", C.id);
            printf("Entrer le nouveau nom du club: ");
            scanf("%49s", C.nom);
            printf("Entrer le nouvel ID du professeur responsable: ");
            scanf("%9s", C.professor_id);
            printf("Entrer la nouvelle classe: ");
            scanf("%1s", C.classe);
        }
        fprintf(temp, "%s %s %s %s\n", C.id, C.nom, C.professor_id, C.classe);
    }
    fclose(fp);
    fclose(temp);
    remove("clubs.txt");
    rename("temp.txt", "clubs.txt");
    if (trouve) {
        printf("Club modifié avec succès.\n");
    } else {
        printf("Club non trouvé.\n");
    }
}

void crudclub() {
    int choix;
    do {
        printf("1 - CREER UN CLUB\n");
        printf("2 - SUPPRIMER UN CLUB\n");
        printf("3 - MODIFIER UN CLUB\n");
        printf("4 - LISTER LES CLUBS\n");
        printf("0 - QUITTER\n");
        printf("Votre choix: ");
        printf("--------------------------------- \n");
        scanf("%d", &choix);
    } while (choix < 0 || choix > 4);

    switch (choix) {
        case 1:
            creerclub();
            break;
        case 2:
            supprimerclub();
            break;
        case 3:
            modifierclub();
            break;
        case 4:
            afficherclub();
            break;
        case 0:
            printf("Au revoir!\n");
            break;
        default:
            break;
    }
}
