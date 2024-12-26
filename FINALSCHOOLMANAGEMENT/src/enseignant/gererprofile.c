#include "/home/wiem/Desktop/mei/uni/projects/C/FINALSCHOOLMANAGEMENT/header/enseignant/enseignant.h"
#include <stdio.h>

void gererprofile(){
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