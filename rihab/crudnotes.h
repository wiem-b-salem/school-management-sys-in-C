#ifndef CRUDNOTES_H
#define CRUDNOTES_H

typedef struct {
    int eleve_id;
    int prof_id;
    float notecntrl;
    float noteexam;
    float noteorale;
} notes;

// Déclarations des fonctions
void Creernotes();
void Supprimernotes();
void Modifiernotes();
void Affichernotes();
void GestionNotes();

#endif // CRUDNOTES_H
