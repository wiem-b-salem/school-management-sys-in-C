#ifndef ELEMENTS_H
#define ELEMENTS_H

#define MAX_COURS 100

typedef struct {
    int id;
    char nom[50];
    char description[200];
    int type; // 1 = cours, 2 = events, 3 = notes, 4 = absences
} Element;

// وظائف عامة
void ajouterElement(Element elements[], int *count, int type);
void afficherElements(Element elements[], int count, int type);

#endif
#ifndef ELEMENTS_H
#define ELEMENTS_H

#define MAX_COURS 100

typedef struct {
    int id;
    char nom[50];
    char description[200];
    int type; // 1 = cours, 2 = events, 3 = notes, 4 = absences
} Element;

// وظائف عامة
void ajouterElement(Element elements[], int *count, int type);
void afficherElements(Element elements[], int count, int type);

#endif
