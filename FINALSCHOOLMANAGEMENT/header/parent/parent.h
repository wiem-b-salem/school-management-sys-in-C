#ifndef structparent
#define structparent

typedef struct {
  int id;
  char nom[50];
  char prenom[50];
  char email[100];
  char numerodetel[15];
  char password[50];
  char student_ids[5][10];
} parent;
void creerparent();
void supprimerparent();
void modifierparent();
void afficherparent();
void crudparent();

#endif