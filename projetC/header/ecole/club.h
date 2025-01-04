#ifndef structclub
#define structclub

typedef struct {
    char id[10];                
    char nom[50];               
    char professor_id[10];      
    char student_ids[30][10]; 
    char classe[2];       
} Club;

#endif
