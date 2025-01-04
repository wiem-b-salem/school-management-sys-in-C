#include "../../header/admin/crudnotes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void creernotes() {
  FILE *fp = fopen("notes.txt", "a");
  if (!fp) {
    perror("Erreur d'ouverture du fichier");
    return;
  }

  notes N;
  printf("Entrez l'ID de l'élève : ");
  scanf("%d", &N.eleve_id);
  printf("Entrez l'ID du professeur : ");
  scanf("%d", &N.prof_id);
  printf("Entrez la note de contrôle : ");
  scanf("%f", &N.notecntrl);
  printf("Entrez la note d'examen : ");
  scanf("%f", &N.noteexam);
  printf("Entrez la note orale : ");
  scanf("%f", &N.noteorale);

  fprintf(fp, "%d %d %.2f %.2f %.2f\n", N.eleve_id, N.prof_id, N.notecntrl,
          N.noteexam, N.noteorale);
  printf("Note ajoutée avec succès !\n");

  fclose(fp);
}

void supprimernotes() {
  FILE *fp = fopen("notes.txt", "r");
  FILE *temp = fopen("temp.txt", "w");

  if (!fp || !temp) {
    perror("Erreur d'ouverture des fichiers");
    return;
  }

  int eleve_id;
  int trouve = 0;
  notes N;

  printf("Entrez l'ID de l'élève dont vous voulez supprimer ses notes : ");
  scanf("%d", &eleve_id);

  while (fscanf(fp, "%d %d %f %f %f", &N.eleve_id, &N.prof_id, &N.notecntrl,
                &N.noteexam, &N.noteorale) != EOF) {
    if (N.eleve_id != eleve_id) {
      fprintf(temp, "%d %d %.2f %.2f %.2f\n", N.eleve_id, N.prof_id,
              N.notecntrl, N.noteexam, N.noteorale);
    } else {
      trouve = 1;
    }
  }

  fclose(fp);
  fclose(temp);

  remove("notes.txt");
  rename("temp.txt", "notes.txt");

  if (trouve) {
    printf("Notes supprimées avec succès !\n");
  } else {
    printf("Aucune note trouvée pour cet ID d'élève.\n");
  }
}

void modifiernotes() {
  FILE *fp = fopen("notes.txt", "r");
  FILE *temp = fopen("temp.txt", "w");

  if (!fp || !temp) {
    perror("Erreur d'ouverture des fichiers");
    return;
  }

  int eleve_id;
  int trouve = 0;
  notes N;

  printf("Entrez l'ID de l'élève dont vous voulez modifier les notes : ");
  scanf("%d", &eleve_id);

  while (fscanf(fp, "%d %d %f %f %f", &N.eleve_id, &N.prof_id, &N.notecntrl,
                &N.noteexam, &N.noteorale) != EOF) {
    if (N.eleve_id == eleve_id) {
      trouve = 1;
      printf("Entrez la nouvelle note de contrôle : ");
      scanf("%f", &N.notecntrl);
      printf("Entrez la nouvelle note d'examen : ");
      scanf("%f", &N.noteexam);
      printf("Entrez la nouvelle note orale : ");
      scanf("%f", &N.noteorale);
    }
    fprintf(temp, "%d %d %.2f %.2f %.2f\n", N.eleve_id, N.prof_id, N.notecntrl,
            N.noteexam, N.noteorale);
  }

  fclose(fp);
  fclose(temp);

  remove("notes.txt");
  rename("temp.txt", "notes.txt");

  if (trouve) {
    printf("Notes modifiées avec succès !\n");
  } else {
    printf("Aucune note trouvée pour cet ID d'élève.\n");
  }
}

void affichernotes() {
  FILE *fp = fopen("notes.txt", "r");
  if (!fp) {
    perror("Erreur d'ouverture du fichier");
    return;
  }

  notes N;

  printf("\nListe des Notes :\n");
  printf("ID Élève\tID Professeur\tNote Contrôle\tNote Examen\tNote Orale\n");
  printf("---------------------------------------------------------------\n");

  while (fscanf(fp, "%d %d %f %f %f", &N.eleve_id, &N.prof_id, &N.notecntrl,
                &N.noteexam, &N.noteorale) != EOF) {
    printf("%-10d\t%-10d\t%.2f\t\t%.2f\t\t%.2f\n", N.eleve_id, N.prof_id,
           N.notecntrl, N.noteexam, N.noteorale);
  }

  fclose(fp);
}
void crudnotes() {
  int choix;

  do {
    printf("Bonjour \n");
    printf("Selectionnez votre choix \n");
    printf("1 - CREER UNE NOTE\n");
    printf("2 - SUPPRIMER UNE NOTE\n");
    printf("3 - MODIFER UNE NOTE\n");
    printf("4 - LISTER LES NOTES\n");
    printf("0 - QUITTER\n");
    printf("--------------------------------- \n");
    scanf("%d", &choix);
  } while (choix < 0 || choix > 4);

  switch (choix) {
  case 1:
    creernotes();
    break;

  case 2:
    supprimernotes();
    break;

  case 3:
    modifiernotes();
    break;

  case 4:
    affichernotes();
    break;

  default:
    break;
  }
}