#include<stdio.h>
#include "/home/wiem/Desktop/mei/uni/projects/C/FINALSCHOOLMANAGEMENT/header/admin/admin.h"
#include "/home/wiem/Desktop/mei/uni/projects/C/FINALSCHOOLMANAGEMENT/header/enseignant/enseignant.h"

int main()
{
    int choix;
    do
    {
        printf("Bonjour \n");
        printf("Selectionnez votre choix \n");
        printf("1 - s'inscrir comme parent\n");
        printf("2 - s'incrir comme enseignant\n");
        scanf("%d",&choix);
    } while (choix<0 || choix>2);
    
    if(choix==0)
    {
        printf("Bonjour Admin \n");
        menuadmin();
    }
    else if (choix==1)
    {
        printf("Bonjour parent \n");
        //menuparent();
    }
    else
    {
        printf("Bonjour enseignant \n");
        menuenseignant();
    }

}