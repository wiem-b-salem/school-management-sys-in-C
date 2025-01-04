#include "menues/crudparent.h"
#include "menues/crudprof.h"
#include "menues/crudnotes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menuadmin() {
  char tabchoix[10][15] = {"Enseignant", "Parent", "Etudiant",  "Classe",
                           "Cours",      "Emploi", "Evenement", "Club",
                           "Notes",      "Profile"};
  int choix;
  do {
    printf("Selectionnez votre choix \n");
    for (int i = 0; i < 10; i++) {
      printf("%d - Gerer %s \n", i + 1, tabchoix[i]);
    }
    printf("11 - Boite de messagerie\n");
    printf("0 - QUITTER\n");

    // Check the return value of scanf
    if (scanf("%d", &choix) != 1) {
      // Handle the invalid input case
      printf("Entrée invalide, veuillez entrer un numéro valide.\n");
      while (getchar() != '\n')
        ; // Clear the input buffer
    }
  } while (choix < 0 || choix > 11);

  switch (choix) {
  case 1:
    crudprof();
    break;

  case 2:
    crudparent();
    break;

    /* case 3:
       crudeleve();
       break;

     case 4:
       crudclasse();
       break;

     case 5:
       crudcours();

       break;

     case 6:
       crudemploi();
       break;

     case 7:
       crudevent();
       break;

     case 8:
       crudclub();
       break; */

  case 9:
    crudnotes();
    break;

    /*case 10:

      break;

    case 11:

      break; */

  case 0:
    printf("Au revoir");

    break;

  default:
    break;
  }
}
