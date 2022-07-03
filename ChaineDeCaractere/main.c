#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

int main()
{
    int oc = -1, choix;
    char texte[251] = {0};
    char mot[21] = {0};

    // Menu
    printf("\n\t\t\t********WELCOME********\n\n");
    printf("\n\t********Calcul du nombre d'occurence d'un mot dans un texte********\n\n");
    printf("\n\t\t 1 - Sans Automate\n");
    printf("\n\t\t 2 - Avec automate\n");
    printf("\n\t\t Faites votre choix : ");
    scanf("%d", &choix);

    // Vider le buffer
    scanf("%*[^\n]");
    getchar();

    printf("\n\tEntrez un texte : ");
    scanf("%250[^\n]", texte);
    getchar();
    printf("\n\tEntrez le mot a rechercher : ");
    scanf("%20[^\n]", mot);
    getchar();

    // Appel de la fonction
    switch (choix)
    {
        case 1:
            oc = rechercheOC(texte, mot, strlen(texte), strlen(mot));
            break;
        case  2:
            oc = automate(texte, mot, strlen(texte), strlen(mot));
            break;
        default:
            printf("\n\tChoix incorrect\n");
            break;
    }
    if(choix != -1)
        printf("\n\tLe nombre d'occurence de \"%s\" dans le texte est : %d\n", mot, oc);

    return 0;
}
