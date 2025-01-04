#include "crudprof.h"
#include <stdio.h>

void creerenseignant() {
  FILE *fp = fopen("enseignants.txt", "a");
  Enseignant E;
  printf("entrer l'id de l'enseignant");
  scanf("%d", &E.id);
  printf("entrer le nom de l'enseignant");
  scanf("%s", E.nom);
  printf("entrer le prenom de l'enseignant");
  scanf("%s", E.prenom);
  printf("entrer l'email professionel  de l'enseignant");
  scanf("%s", E.email);
  printf("entrer le numéro de téléphone de l'enseignant");
  scanf("%s", E.numerodetel);
  printf("entrer la spécialité de l'enseignant");
  scanf("%s", E.spécialité);
  fprintf(fp, "%d %s %s %s %s %s \n", E.id, E.nom,E.prenom, E.email, E.numerodetel,E.spécialité);
  printf("Enseignant ajouté!");
  fclose(fp);
}

void afficherenseignant() {
  FILE *fp = fopen("enseignants.txt", "r");
  Enseignant E;
  if (!fp) {
    perror("Error opening file");
    return;
  }
  printf("La liste des enseignants: \n");
  printf("ID\tnom\tprenom\temail\t\tnumero de telephone\tspécialité\n");
  printf("---------------------------------------------------------------------"
         "---------------\n");

  while (fscanf(fp, "%d %s %s %s %s %s", &E.id, E.nom, E.prenom, E.email,
                E.numerodetel, E.spécialité) != EOF) {
    printf("%d\t%-10s\t%-10s\t%-12s\t%-10s\t%-10s\t%s\n", E.id, E.nom, E.prenom,
           E.email, E.numerodetel, E.spécialité);
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
  while (fscanf(fp, "%d %s %s %s %s %s", &E.id, E.nom, E.prenom, E.numerodetel,
                E.spécialité, E.email) != EOF) {
    if (E.id == id) {
      trouve = 1;
    } else {
      fprintf(temp, "%d %s %s %s %s %s\n", E.id, E.nom, E.prenom, E.email,
              E.numerodetel, E.spécialité);
    }
  }

  fclose(fp);
  fclose(temp);

  remove("enseignants.txt");
  rename("temp.txt", "enseignants.txt");
  if (trouve) {
    printf(" l'enseignant avec l'id %d a été supprimé.\n", id);
  } else {
    printf("l'enseignant avec l'id %d n'a pas été trouvé.\n", id);
  }
}

void modifierenseignant() {
  int id, trouve = 0;
  Enseignant E;
  FILE *fp = fopen("enseignants.txt", "r");
  FILE *temp = fopen("temp.txt", "w");

  if (!fp || !temp) {
    perror("Erreur d'ouverture des fichiers");
    return;
  }
  printf("Entrez l'ID de l'enseignant à modifier : ");
  scanf("%d", &id);

  while (fscanf(fp, "%d %s %s %s %s %s", &E.id, E.nom, E.prenom, E.numerodetel,
                E.spécialité, E.email) != EOF) {
    if (E.id == id) {
      trouve = 1;
      printf("entrer le nouveau id de l'enseignant");
      scanf("%d", &E.id);
      printf("entrer le nouveau nom de l'enseignant");
      scanf("%s", E.nom);
      printf("entrer le nouveau prenom de l'enseignant");
      scanf("%s", E.prenom);
      printf("entrer le nouveau email professionel  de l'enseignant");
      scanf("%s", E.email);
      printf("entrer le nouveau numéro de téléphone de l'enseignant");
      scanf("%s", E.numerodetel);
      printf("entrer la nouvelle  spécialité de l'enseignant");
      scanf("%s", E.spécialité);
    }
    fprintf(temp, "%d %s %s %s %s %s\n", &E.id, E.nom, E.prenom, E.numerodetel,
            E.spécialité, E.email);
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

void crudprof() {
  int choix;

  do {
    printf("Bonjour \n");
    printf("1 - CREER UN ENSEIGNANT \n");
    printf("2 - SUPPRIMER UN ENSEIGNANT\n");
    printf("3 - MODIFER UN ENSEIGNANT\n");
    printf("4 - LISTER LES ENSEIGNANTS\n");
    printf("0 - QUITTER\n");
    printf("Selectionnez votre choix \n");
    scanf("%d", &choix);
  } while (choix < 0 || choix > 4);

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

  default:
    break;
  }
}
