#include<stdio.h>
#include "../../header/admin/crudenseignant.h"
#include "../../header/admin/crudparent.h"
#include "../../header/admin/crudnotes.h"
#include "../../header/admin/crudclub.h"
#include "../../header/admin/crudemploi.h"


void menuadmin()
{
    char tabchoix[10][15]={"Enseignant","Parent","Etudiant","Classe","Cours","Emploi","Evenement","Club","Notes","Profile"};
    int choix;
    do
    {
        printf("Bonjour \n");
        printf("Selectionnez votre choix \n");
        for (int i = 0; i < 10; i++)
        {
            printf("%d - Gerer %s \n",i+1,tabchoix[i]);
        }
        printf("11 - Boite de messagerie\n");
        printf("0 - QUITTER\n");
        scanf("%d",&choix);
    } while (choix<0 || choix>11);

    switch (choix)
    {
    case 1:
        crudenseignant();     
        break;
    
    case 2:
        crudparent();
        break;
    
    case 3:
        //crudeleve();
        break;
    
    case 4:
        //crudclasse();
        break;
    
    case 5:
        //crudcours();
        
        break;
    
    case 6:
        crudemploi();
        break;
    
    case 7:
        //crudevent();
        break;
    
    case 8:
        crudclub();
        break;
    
    case 9:
        crudnotes();
        break;

    case 10:
        gererprofileadmin();
        
        break;
    
    case 11:
        
        break;
    
    case 0:
        printf("Au revoir \n");
        
        break;

    default:
        break;
    }
    

}