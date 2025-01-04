#include <stdio.h>
#include <string.h>
#include "../../header/parent/parent.h"
#include "../../header/parent/gererprofileparent.h"

void gererProfileParent() {
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

    while (fscanf(fp, "%d %49s %49s %99s %14s %49s", &P.id, P.nom, P.prenom, P.email, P.numerodetel, P.password) != EOF) {
        for (int i = 0; i < 5; i++) {
            fscanf(fp, "%9s", P.student_ids[i]);
        }
        if (P.id == id) {
            trouve = 1;
            printf("Entrer le nouveau nom du parent: ");
            scanf("%49s", P.nom);
            printf("Entrer le nouveau prenom du parent: ");
            scanf("%49s", P.prenom);
            printf("Entrer le nouveau email du parent: ");
            scanf("%99s", P.email);
            printf("Entrer le nouveau numéro de téléphone du parent: ");
            scanf("%14s", P.numerodetel);
            printf("Entrer le nouveau mot de passe du parent: ");
            scanf("%49s", P.password);
        }
        fprintf(temp, "%d %s %s %s %s %s", P.id, P.nom, P.prenom, P.email, P.numerodetel, P.password);
        for (int i = 0; i < 5; i++) {
            fprintf(temp, " %s", P.student_ids[i]);
        }
        fprintf(temp, "\n");
    }

    fclose(fp);
    fclose(temp);
    remove("parents.txt");
    rename("temp.txt", "parents.txt");

    if (trouve) {
        printf("Profile parent modifié avec succès.\n");
    } else {
        printf("Parent non trouvé.\n");
    }
}