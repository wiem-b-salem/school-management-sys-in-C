#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// D�claration de la structure cours
typedef struct {
    int id;                    // Identifiant du cours
    char nom[50];              // Nom du cours (49 caract�res max + '\0')
    char description[100];     // Description du cours (99 caract�res max + '\0')
}
evenement ;

void crudevenement();