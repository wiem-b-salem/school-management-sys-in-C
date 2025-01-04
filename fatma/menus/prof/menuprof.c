#include "../../structs/prof.h"
#include "../../structs/club.h"
#include "../../structs/notes.h" 
#include <stdio.h>

void gererProfile(){
    Enseignant P;
    printf("\n===== GÉRER LE PROFIL =====\n");
    printf("1. Entrez votre nom :\n");
    scanf("%s",P.nom);
    printf("2. Entrez votre prénom :\n");
    scanf("%s",P.prenom);
    printf("3. Entrez votre email :\n");
    scanf("%s",P.email);
    printf("4. Entrez votre numéro de téléphone :\n");
    scanf("%s",P.numerodetel);
    printf("6. Entrez votre spécialité :\n");
    scanf("%s",P.spécialité);
    printf("\n Profil mis à jour avec succès! \n");
    printf("Nom : %s, Prénom : %s , Adresse Email: %s, Numéro de téléphone: %s, Spécialité: %s \n",P.nom,P.prenom,P.email,P.numerodetel,P.spécialité);
}

void ajouterClub() {
        FILE *fp = fopen("FICHIER_CLUBS.txt", "a");
        if (!fp) {
            perror("Erreur lors de l'ouverture du fichier");
            return;
        }

        Club club;
        printf("Entrez le nom du nouveau club : ");
        scanf(" %[^\n]", club.nom);
        printf("Entrez une description pour le club : ");
        scanf(" %[^\n]", club.description);
        club.membres = 0; 

        fprintf(fp, "%s|%d|%s\n", club.nom, club.membres, club.description);
        printf("Le club \"%s\" a été créé avec succès !\n", club.nom);

        fclose(fp);
    }

    void afficherClubs() {
        FILE *fp = fopen("FICHIER_CLUBS.txt", "r");
        if (!fp) {
            printf("Aucun club trouvé pour le moment.\n");
            return;
        }

        Club club;
        printf("\n===== LISTE DES CLUBS =====\n");
        while (fscanf(fp, " %49[^|]|%d|%99[^\n]\n", club.nom, &club.membres, club.description) != EOF) {
            printf("Nom : %s\n", club.nom);
            printf("Nombre de membres : %d\n", club.membres);
            printf("Description : %s\n", club.description);
            printf("---------------------------\n");
        }

        fclose(fp);
    }

void creerOuGererClub() {
    int choix;
    do {
        printf("\n===== GÉRER OU CRÉER UN CLUB =====\n");
        printf("1 - Créer un nouveau club\n");
        printf("2 - Afficher la liste des clubs\n");
        printf("Entrez votre choix (1 ou 2): ");
        scanf(" %d", &choix);

        if (choix == 1) {
            ajouterClub();
        } else if (choix == 2) {
            afficherClubs();
        } else {
            printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 1 && choix != 2);  
}

void ajouterNotes() {
    FILE *fp = fopen("FICHIER_NOTES.txt", "a");
    if (!fp) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    notes n;
    printf("Entrez l'ID de l'élève : ");
    scanf("%d", &n.eleve_id);
    printf("Entrez l'ID du professeur : ");
    scanf("%d", &n.prof_id);
    printf("Entrez la note de contrôle : ");
    scanf("%f", &n.notecntrl);
    printf("Entrez la note d'examen : ");
    scanf("%f", &n.noteexam);
    printf("Entrez la note orale : ");
    scanf("%f", &n.noteorale);

    fprintf(fp, "%d %d %.2f %.2f %.2f\n", n.eleve_id, n.prof_id, n.notecntrl, n.noteexam, n.noteorale);
    printf("Note ajoutée avec succès!\n");

    fclose(fp);
}

void afficherNotes() {
    FILE *fp = fopen("FICHIER_NOTES.txt", "r");
    if (!fp) {
        printf("Aucune note disponible pour le moment.\n");
        return;
    }

    notes n;
    printf("\n===== LISTE DES NOTES =====\n");
    while (fscanf(fp, "%d %d %f %f %f", &n.eleve_id, &n.prof_id, &n.notecntrl, &n.noteexam, &n.noteorale) != EOF) {
        printf("ID Élève : %d\n", n.eleve_id);
        printf("ID Professeur : %d\n", n.prof_id);
        printf("Note Contrôle : %.2f\n", n.notecntrl);
        printf("Note Examen : %.2f\n", n.noteexam);
        printf("Note Orale : %.2f\n", n.noteorale);
        printf("----------------------------\n");
    }

    fclose(fp);
}

void modifierNotes() {
    FILE *fp = fopen("FICHIER_NOTES.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) {
        perror("Erreur d'ouverture des fichiers");
        return;
    }

    int eleve_id;
    int trouve = 0;
    notes n;

    printf("Entrez l'ID de l'élève pour modifier ses notes : ");
    scanf("%d", &eleve_id);

    while (fscanf(fp, "%d %d %f %f %f", &n.eleve_id, &n.prof_id, &n.notecntrl, &n.noteexam, &n.noteorale) != EOF) {
        if (n.eleve_id == eleve_id) {
            printf("Entrez la nouvelle note de contrôle : ");
            scanf("%f", &n.notecntrl);
            printf("Entrez la nouvelle note d'examen : ");
            scanf("%f", &n.noteexam);
            printf("Entrez la nouvelle note orale : ");
            scanf("%f", &n.noteorale);
            trouve = 1;
        }
        fprintf(temp, "%d %d %.2f %.2f %.2f\n", n.eleve_id, n.prof_id, n.notecntrl, n.noteexam, n.noteorale);
    }

    fclose(fp);
    fclose(temp);

    if (trouve) {
        remove("FICHIER_NOTES.txt");
        rename("temp.txt", "FICHIER_NOTES.txt");
        printf("Notes modifiées avec succès!\n");
    } else {
        printf("ID de l'élève introuvable.\n");
        remove("temp.txt");
    }
}

void supprimerNotes() {
    FILE *fp = fopen("FICHIER_NOTES.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) {
        perror("Erreur d'ouverture des fichiers");
        return;
    }

    int eleve_id;
    int trouve = 0;
    notes n;

    printf("Entrez l'ID de l'élève pour supprimer ses notes : ");
    scanf("%d", &eleve_id);

    while (fscanf(fp, "%d %d %f %f %f", &n.eleve_id, &n.prof_id, &n.notecntrl, &n.noteexam, &n.noteorale) != EOF) {
        if (n.eleve_id == eleve_id) {
            printf("Notes de l'élève ID %d supprimées avec succès!\n", eleve_id);
            trouve = 1;
        } else {
            fprintf(temp, "%d %d %.2f %.2f %.2f\n", n.eleve_id, n.prof_id, n.notecntrl, n.noteexam, n.noteorale);
        }
    }

    fclose(fp);
    fclose(temp);

    if (trouve) {
        remove("FICHIER_NOTES.txt");
        rename("temp.txt", "FICHIER_NOTES.txt");
    } else {
        printf("ID de l'élève introuvable.\n");
        remove("temp.txt");
    }
}

void gererNotes() {
    int choix;
    do {
        printf("\n===== GÉRER LES NOTES =====\n");
        printf("1 - Ajouter des notes\n");
        printf("2 - Modifier des notes\n");
        printf("3 - Supprimer des notes\n");
        printf("4 - Afficher les notes\n");
        printf("Entrez votre choix (1, 2, 3 ou 4) : ");
        scanf("%d", &choix);

        if (choix == 1) {
            ajouterNotes();
        } else if (choix == 2) {
            modifierNotes();
        } else if (choix == 3) {
            supprimerNotes();
        } else if (choix == 4) {
            afficherNotes();
        } else {
            printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix < 1 || choix > 4);
}

void menuprof() {
  int choix;
  do {
    printf("\n===== MENU PROFESSEUR =====\n");
    printf("0 - Gérer le profil\n");
    printf("1 - Gérer les notes\n");
    printf("2 - Gérer ou créer un club\n");
    printf("3 - Voir les absences\n");
    printf("4 - Boîte de messagerie\n");
    printf("5 - Gérer ou créer un événement\n");
    printf("6 - Nouveautés\n");
    printf("7 - QUITTER\n");
    printf("Sélectionnez votre choix : ");
    scanf("%d", &choix);

    switch (choix) {
    case 0:
      gererProfile();
      break;
    case 1:
      gererNotes();
      break;
    case 2:
      creerOuGererClub();
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
    case 7:
      printf("Au revoir !\n");
      break;
    default:
      printf("Choix invalide. Veuillez réessayer.\n");
    }
  } while (choix >= 0 && choix < 7);

  return 0;
}