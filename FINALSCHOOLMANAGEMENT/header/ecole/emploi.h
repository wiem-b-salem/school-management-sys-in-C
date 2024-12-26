#ifndef structemploi
#define structemploi

typedef struct {
    char class_id[10];
    char classe[2];
    char professor_id[10]; 
    char student_ids[30][10];
    char weekly_schedule[6][2][10];
} Employment;

#endif
