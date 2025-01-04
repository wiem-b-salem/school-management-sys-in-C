#include "structs/menuadmin.h"
#include <stdio.h>

int main() {
  int choix;
  do {
    printf("=== Bienvenue dans le système de management d'école ===\n \n");
    printf("Selectionnez votre choix \n");
    printf("0 - s'inscrir comme admin\n");
    printf("1 - s'inscrir comme parent\n");
    printf("2 - s'incrir comme enseignant\n");
    if (scanf("%d", &choix) != 1) { // Si scanf échoue à lire un entier
      // Si l'utilisateur entre une entrée invalide, on vide le buffer et on
      // redemande          l'entrée
      while (getchar() != '\n')
        ; // Vider le buffer d'entrée
      printf("Entrée invalide. Veuillez entrer un nombre entre 0 et 2.\n");
      continue; // Redemander l'entrée
    }
  } while (choix < 0 || choix > 2);

  if (choix == 0) {
    printf("Bonjour Admin \n");
    /*call of function t3 el authentification admin lenna*/
    menuadmin();
  } else if (choix == 1) {
    printf("Bonjour parent \n");
    /*call of funtion ta3 el authentification parent lenna*/
    menuprof();
  } else {
    printf("Bonjour enseignant \n");
    /*call of function t3 el authentification prof lenna*/
  }
}