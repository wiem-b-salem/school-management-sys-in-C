#include "/home/wiem/Desktop/mei/uni/projects/C/FINALSCHOOLMANAGEMENT/header/admin/crudenseignant.h"
#include <stdio.h>

void creerenseignant() {
  FILE *fp = fopen("enseignants.txt", "a");
  Enseignant E;
  printf("Entrer l'id de l'enseignant: ");
  scanf("%d", &E.id);
  printf("Entrer le nom de l'enseignant: ");
  scanf("%49s", E.nom);  // Ensure no overflow
  printf("Entrer le prenom de l'enseignant: ");
  scanf("%49s", E.prenom);  // Ensure no overflow
  printf("Entrer l'email professionnel de l'enseignant: ");
  scanf("%99s", E.email);  // Ensure no overflow
  printf("Entrer le numéro de téléphone de l'enseignant: ");
  scanf("%14s", E.numerodetel);  // Ensure no overflow
  printf("Entrer la spécialité de l'enseignant: ");
  scanf("%49s", E.spécialité);  // Ensure no overflow
  fprintf(fp, "%d %s %s %s %s %s \n", E.id, E.nom, E.prenom, E.email, E.numerodetel, E.spécialité);
  printf("Enseignant ajouté!\n");
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

  while (fscanf(fp, "%d %49s %49s %99s %14s %49s", &E.id, E.nom, E.prenom, E.email,
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
  while (fscanf(fp, "%d %49s %49s %99s %14s %49s", &E.id, E.nom, E.prenom, E.numerodetel,
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
    printf("L'enseignant avec l'ID %d a été supprimé.\n", id);
  } else {
    printf("L'enseignant avec l'ID %d n'a pas été trouvé.\n", id);
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

  while (fscanf(fp, "%d %49s %49s %99s %14s %49s", &E.id, E.nom, E.prenom, E.numerodetel,
                E.spécialité, E.email) != EOF) {
    if (E.id == id) {
      trouve = 1;
      printf("Entrer le nouveau id de l'enseignant: ");
      scanf("%d", &E.id);
      printf("Entrer le nouveau nom de l'enseignant: ");
      scanf("%49s", E.nom);  // Ensure no overflow
      printf("Entrer le nouveau prenom de l'enseignant: ");
      scanf("%49s", E.prenom);  // Ensure no overflow
      printf("Entrer le nouveau email professionnel de l'enseignant: ");
      scanf("%99s", E.email);  // Ensure no overflow
      printf("Entrer le nouveau numéro de téléphone de l'enseignant: ");
      scanf("%14s", E.numerodetel);  // Ensure no overflow
      printf("Entrer la nouvelle spécialité de l'enseignant: ");
      scanf("%49s", E.spécialité);  // Ensure no overflow
    }
    fprintf(temp, "%d %s %s %s %s %s\n", E.id, E.nom, E.prenom, E.numerodetel,
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

void crudenseignant() {
  int choix;

  do {
    printf("Bonjour \n");
    printf("1 - CREER UN ENSEIGNANT \n");
    printf("2 - SUPPRIMER UN ENSEIGNANT\n");
    printf("3 - MODIFIER UN ENSEIGNANT\n");
    printf("4 - LISTER LES ENSEIGNANTS\n");
    printf("0 - QUITTER\n");
    printf("Sélectionnez votre choix \n");
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
