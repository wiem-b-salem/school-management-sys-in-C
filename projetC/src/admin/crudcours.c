#include "/home/wiem/Desktop/projetC/header/ecole/cours.h"
#include <stdio.h>

// D�finir la structure cours si elle n'est pas d�j� d�finie
typedef struct {
    int id;
    char nom[50];
    char description[200];
} cours;

void creercours() {
    cours C;  // D�claration correcte de la variable C de type cours

    FILE *fp = fopen("cours.txt", "a");
    if (!fp) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    printf("Entrer l'ID du cours : ");
    scanf("%d", &C.id);
    printf("Entrer le nom du cours : ");
    scanf("%s", C.nom);
    printf("Entrer la description du cours : ");
    scanf("%s", C.description);

    fprintf(fp, "%d %s %s\n", C.id, C.nom, C.description);
    printf("Cours ajout� avec succ�s !\n");
    fclose(fp);
}


void supprimercours() {
  FILE *fp = fopen("cours.txt", "r");
  FILE *temp = fopen("temp.txt", "w");
  if (!fp || !temp) {
    perror("Erreur d'ouverture des fichiers");
    return;
  }
  int id, trouve = 0;
  cours C;
  printf("Entrez l'ID du cours � supprimer : ");
  scanf("%d", &id);

  while (fscanf(fp, "%d %s %s", &C.id, C.nom, C.description) != EOF) {
    if (C.id == id) {
      trouve = 1;
    } else {
      fprintf(temp, "%d %s %s\n", C.id, C.nom, C.description);
    }
  }

  fclose(fp);
  fclose(temp);
  remove("cours.txt");
  rename("temp.txt", "cours.txt");

  if (trouve) {
    printf("Le cours avec l'ID %d a �t� supprim�.\n", id);
  } else {
    printf("Le cours avec l'ID %d n'a pas �t� trouv�.\n", id);
  }
}

void modifiercours() {
  int id, trouve = 0;
  cours C;
  FILE *fp = fopen("cours.txt", "r");
  FILE *temp = fopen("temp.txt", "w");
  if (!fp || !temp) {
    perror("Erreur d'ouverture des fichiers");
    return;
  }

  printf("Entrez l'ID du cours � modifier : ");
  scanf("%d", &id);

  while (fscanf(fp, "%d %s %s", &C.id, C.nom, C.description) != EOF) {
    if (C.id == id) {
      trouve = 1;
      printf("Entrer le nouvel ID du cours : ");
      scanf("%d", &C.id);
      printf("Entrer le nouveau nom du cours : ");
      scanf("%s", C.nom);
      printf("Entrer la nouvelle description du cours : ");
      scanf("%s", C.description);
    }
    fprintf(temp, "%d %s %s\n", C.id, C.nom, C.description);
  }

  fclose(fp);
  fclose(temp);
  remove("cours.txt");
  rename("temp.txt", "cours.txt");

  if (trouve) {
    printf("Cours modifi� avec succ�s !\n");
  } else {
    printf("Cours non trouv�.\n");
  }
}

void affichercours() {
  FILE *fp = fopen("cours.txt", "r");
  if (!fp) {
    perror("Erreur d'ouverture du fichier");
    return;
  }
  cours C;
  printf("\nListe des cours :\n");
  printf("ID\tNom\t\tDescription\n");
  printf("-----------------------------------------\n");

  while (fscanf(fp, "%d %s %s", &C.id, C.nom, C.description) != EOF) {
    printf("%d\t%-10s\t%s\n", C.id, C.nom, C.description);
  }
  fclose(fp);
}

void crudcours() {
  int choix;

  do {
    printf("Bonjour\n");
    printf("S�lectionnez votre choix :\n");
    printf("1 - CR�ER UN COURS\n");
    printf("2 - SUPPRIMER UN COURS\n");
    printf("3 - MODIFIER UN COURS\n");
    printf("4 - LISTER LES COURS\n");
    printf("0 - QUITTER\n");
    printf("--------------------------------- \n");
    scanf("%d", &choix);
  } while (choix < 0 || choix > 4);

  switch (choix) {
  case 1:
    creercours();
    break;

  case 2:
    supprimercours();
    break;

  case 3:
    modifiercours();
    break;

  case 4:
    affichercours();
    break;

  default:
    break;
  }
}

