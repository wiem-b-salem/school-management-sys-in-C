#include <stdio.h>
#include <string.h>
#include "../../header/parent/eleve.h"
#include "../../header/parent/gererprofileetudiant.h"

void gererProfileEtudiant() {
    int id, trouve = 0;
    Etudiant E;
    FILE *fp = fopen("etudiants.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!fp || !temp) {
        perror("Erreur d'ouverture des fichiers");
        return;
    }

    printf("Entrez l'ID de l'étudiant à modifier : ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %49s %49s %f", &E.id, E.nom, E.prenom, &E.moyenne) != EOF) {
        if (E.id == id) {
            trouve = 1;
            printf("Entrer le nouveau nom de l'étudiant: ");
            scanf("%49s", E.nom);
            printf("Entrer le nouveau prenom de l'étudiant: ");
            scanf("%49s", E.prenom);
            printf("Entrer la nouvelle moyenne de l'étudiant: ");
            scanf("%f", &E.moyenne);
        }
        fprintf(temp, "%d %s %s %f\n", E.id, E.nom, E.prenom, E.moyenne);
    }

    fclose(fp);
    fclose(temp);
    remove("etudiants.txt");
    rename("temp.txt", "etudiants.txt");

    if (trouve) {
        printf("Profile étudiant modifié avec succès.\n");
    } else {
        printf("Étudiant non trouvé.\n");
    }
}