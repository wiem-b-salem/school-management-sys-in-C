#include "crudparent.h"
#include <stdio.h>

void creerparent() {
  FILE *fp = fopen("parents.txt", "a");
  parent P;
  printf("entrer l'id du parent");
  scanf("%d", &P.id);
  printf("entrer le nom du parent");
  scanf("%s", P.nom);
  printf("entrer le prenom du parent");
  scanf("%s", P.prenom);
  printf("entrer l'email du parent");
  scanf("%s", P.email);
  printf("entrer le numéro de téléphone du parent");
  scanf("%s", P.numerodetel);
  fprintf(fp, "%d %s %s %s %s \n", P.id, P.nom, P.prenom, P.email,
          P.numerodetel);
  printf("Parent ajouté!");
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
  while (fscanf(fp, "%d %s %s %s %s ", &P.id, P.nom, P.prenom, P.email,
                P.numerodetel) != EOF) {
    if (P.id == id) {
      trouve = 1;
    } else {
      fprintf(temp, "%d %s %s %s %s\n", P.id, P.nom, P.prenom, P.email,
              P.numerodetel);
    }
  }

  fclose(fp);
  fclose(temp);

  remove("parents.txt");
  rename("temp.txt", "parents.txt");
  if (trouve) {
    printf(" le parent avec l'id %d a été supprimé.\n", id);
  } else {
    printf("le parent avec l'id %d n'a pas été trouvé.\n", id);
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

  while (fscanf(fp, "%d %s %s %s %s ", &P.id, P.nom, P.prenom, P.email,
                P.numerodetel) != EOF) {
    if (P.id == id) {
      trouve = 1;
      printf("entrer le nouveau id du parent");
      scanf("%d", &P.id);
      printf("entrer le nouveau nom du parent");
      scanf("%s", P.nom);
      printf("entrer le nouveau prenom du parent");
      scanf("%s", P.prenom);
      printf("entrer le nouveau email du parent");
      scanf("%s", P.email);
      printf("entrer le nouveau numéro de téléphone du parent");
      scanf("%s", P.numerodetel);
      fprintf(fp, "%d %s %s %s %s \n", P.id, P.nom, P.prenom, P.email,
              P.numerodetel);
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
}
void afficherparent() {
  FILE *fp = fopen("parents.txt", "r");
  if (!fp) {
    perror("Erreur d'ouverture du fichier");
    return;
  }
  parent P;
  printf("\nListe des parents:\n");
  printf("ID\tNom\tPrenom\tEmail\t\tnumerodetel\n");
  printf("---------------------------------------------------------------\n");
  while (fscanf(fp, "%d %s %s %s %s", &P.id, P.nom, P.prenom, P.email,
                P.numerodetel) != EOF) {
    printf("%d\t%-10s\t%-10s\t%-15s\t%s\n", P.id, P.nom, P.prenom, P.email,
           P.numerodetel);
  }
  fclose(fp);
}

void crudparent() {
  int choix;

  do {
    printf("Bonjour \n");
    printf("Selectionnez votre choix \n");
    printf("1 - CREER UN PARENT\n");
    printf("2 - SUPPRIMER UN PARENT\n");
    printf("3 - MODIFER UN PARENT\n");
    printf("4 - LISTER LES PARENTS\n");
    printf("0 - QUITTER\n");
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

  default:
    break;
  }
}
