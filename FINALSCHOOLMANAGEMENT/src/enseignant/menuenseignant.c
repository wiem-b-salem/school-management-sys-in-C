#include<stdio.h>
#include "/home/wiem/Desktop/mei/uni/projects/C/FINALSCHOOLMANAGEMENT/header/admin/crudclub.h"
#include "/home/wiem/Desktop/mei/uni/projects/C/FINALSCHOOLMANAGEMENT/header/admin/crudnotes.h"
#include "/home/wiem/Desktop/mei/uni/projects/C/FINALSCHOOLMANAGEMENT/header/enseignant/enseignant.h"

void menuenseignant()
{
  int choix;
  do
  {
    printf("Bonjour \n");
    printf("Selectionnez votre choix \n");
    printf("1 - Gerer profile \n");
    printf("2 - Gerer notes \n");
    printf("3 - Gerer cours \n");
    printf("4 - voir les absences \n");
    printf("5 - Boite de messagerie \n");
    printf("6 - Gere ou creer un club \n");
    printf("7 - Gerer ou creer un evenement\n");
    printf("8 - nouveaute \n");
    printf("0 - QUITTER \n");
    scanf("%d",&choix);
  } while (choix<0 || choix>8);

  switch (choix) {
    case 1:
      gererprofile();
      break;
    case 2:
      crudnotes();
      break;
    case 6:
      crudclub();
      break;
   /* case 3:
      afficherLesAbsences();
      break;
    case 4:
      BoitedeMessagerie();
      break;
    case 5:
      dreerOuGererEvent();
      break;
    case 6:
      afficherNouveautes();
      break; */
    case 0:
      printf("Au revoir !\n");
      break;
    default:
      printf("Choix invalide. Veuillez réessayer.\n");
    }
   
    

}