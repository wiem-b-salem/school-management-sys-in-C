#ifndef STRUCTCLUB_H
#define STRUCTCLUB_H


typedef struct {

    char nom[50];                
    char professor_id[10];        
    char student_ids[30][10];     
    int membres;         
    char classe[5];               
    char description[100];        
} Club;

#endif 
