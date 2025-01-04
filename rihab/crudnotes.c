#include <stdio.h>
#include <stdlib.h>
#include "crudnotes.h"

void Creernotes() {
    notes N;
    FILE *fp = fopen("notes.txt", "a");
    if (!fp) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    printf("Entrer l'ID de l'élève : ");
    scanf("%d", &N.eleve_id);
    printf("Entrer l'ID du professeur : ");
    scanf("%d", &N.prof_id);
    printf("Entrer la note de contrôle : ");
    scanf("%f", &N.notecntrl);
    printf("Entrer la note d'examen : ");
    scanf("%f", &N.noteexam);
    printf("Entrer la note orale : ");
    scanf("%f", &N.noteorale);

    fprintf(fp, "%d %d %.2f %.2f %.2f\n", N.eleve_id, N.prof_id, N.notecntrl, N.noteexam, N.noteorale);
    printf("Notes ajoutées avec succès !\n");

    fclose(fp);
}

void Affichernotes() {
    notes N;
    FILE *fp = fopen("notes.txt", "r");
    if (!fp) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    printf("\nListe des notes :\n");
    printf("ID Élève\tID Professeur\tNote Contrôle\tNote Examen\tNote Orale\n");
    printf("---------------------------------------------------------------\n");

    while (fscanf(fp, "%d %d %f %f %f", &N.eleve_id, &N.prof_id, &N.notecntrl, &N.noteexam, &N.noteorale) == 5) {
        printf("%d\t\t%d\t\t%.2f\t\t%.2f\t\t%.2f\n", N.eleve_id, N.prof_id, N.notecntrl, N.noteexam, N.noteorale);
    }

    fclose(fp);
}

void Modifiernotes() {
    int eleve_id, found = 0;
    notes N;
    FILE *fp = fopen("notes.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) {
        perror("Erreur d'ouverture des fichiers");
        return;
    }

    printf("Entrer l'ID de l'élève dont vous voulez modifier les notes : ");
    scanf("%d", &eleve_id);

    while (fscanf(fp, "%d %d %f %f %f", &N.eleve_id, &N.prof_id, &N.notecntrl, &N.noteexam, &N.noteorale) == 5) {
        if (N.eleve_id == eleve_id) {
            found = 1;
            printf("Entrer la nouvelle note de contrôle : ");
            scanf("%f", &N.notecntrl);
            printf("Entrer la nouvelle note d'examen : ");
            scanf("%f", &N.noteexam);
            printf("Entrer la nouvelle note orale : ");
            scanf("%f", &N.noteorale);
        }
        fprintf(temp, "%d %d %.2f %.2f %.2f\n", N.eleve_id, N.prof_id, N.notecntrl, N.noteexam, N.noteorale);
    }

    fclose(fp);
    fclose(temp);

    remove("notes.txt");
    rename("temp.txt", "notes.txt");

    if (found)
        printf("Notes modifiées avec succès !\n");
    else
        printf("Aucune note trouvée pour cet ID d'élève.\n");
}

void Supprimernotes() {
    int eleve_id, found = 0;
    notes N;
    FILE *fp = fopen("notes.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) {
        perror("Erreur d'ouverture des fichiers");
        return;
    }

    printf("Entrer l'ID de l'élève dont vous voulez supprimer les notes : ");
    scanf("%d", &eleve_id);

    while (fscanf(fp, "%d %d %f %f %f", &N.eleve_id, &N.prof_id, &N.notecntrl, &N.noteexam, &N.noteorale) == 5) {
        if (N.eleve_id == eleve_id) {
            found = 1;
            continue; // Ne pas copier les notes à supprimer
        }
        fprintf(temp, "%d %d %.2f %.2f %.2f\n", N.eleve_id, N.prof_id, N.notecntrl, N.noteexam, N.noteorale);
    }

    fclose(fp);
    fclose(temp);

    remove("notes.txt");
    rename("temp.txt", "notes.txt");

    if (found)
        printf("Notes supprimées avec succès !\n");
    else
        printf("Aucune note trouvée pour cet ID d'élève.\n");
}

void GestionNotes() {
    int choix;
    do {
        printf("\nGestion des notes :\n");
        printf("1. Ajouter une note\n");
        printf("2. Modifier une note\n");
        printf("3. Supprimer une note\n");
        printf("4. Afficher les notes\n");
        printf("5. Retour au menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                Creernotes();
                break;
            case 2:
                Modifiernotes();
                break;
            case 3:
                Supprimernotes();
                break;
            case 4:
                Affichernotes();
                break;
            case 5:
                printf("Retour au menu principal...\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 5);
}
