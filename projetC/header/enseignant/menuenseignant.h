#ifndef structenseignant
#define structenseignant

typedef struct {
  int id;
  char nom[50];
  char prenom[50];
  char email[100];
  char password[50];
  char numerodetel[15];
  char spécialité[50];
  char class_ids[5][10];
  char club_id[10];
  float salaire;
  int absence;
  char event_ids[10][10];
} Enseignant;

void menuenseignant();
void creerenseignant();
void supprimerenseignant();
void modifierenseignant();
void afficherenseignant();
void crudprof();
void gererProfile();
void gererNotes();
void creerOuGererClub();
void afficherLesAbsences();
void BoitedeMessagerie();
void creerOuGererEvent();
void afficherNouveautes();

#endif