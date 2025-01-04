#include <stdio.h>
#include <string.h>
#include "Element.h"

void ajouterElement(Element elements[], int *count, int type) {
    if (*count >= MAX_COURS) {
        printf("Liste pleine.\n");
        return;
    }
    Element newElement;
    newElement.type = type; // تحديد النوع

    printf("Entrer l'ID : ");
    scanf("%d", &newElement.id);
    printf("Entrer le nom : ");
    scanf("%s", newElement.nom);
    printf("Entrer la description : ");
    scanf("%s", newElement.description);

    elements[*count] = newElement; // إضافة العنصر إلى القائمة
    (*count)++;
    printf("Élément ajouté avec succès !\n");
}

void afficherElements(Element elements[], int count, int type) {
    printf("\nListe des éléments :\n");
    printf("ID\tNom\t\tDescription\n");
    printf("-----------------------------------------\n");
    int i;
    for ( i = 0; i < count; i++) {
        if (elements[i].type == type) { // عرض العناصر بناءً على النوع
            printf("%d\t%-10s\t%s\n", elements[i].id, elements[i].nom, elements[i].description);
        }
    }
}
