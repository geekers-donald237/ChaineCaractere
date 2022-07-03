#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int ChercherVal(char *chaine , char x){
    int i,cpt = 0;
    for (i = 0 ; i < strlen(chaine) ; i++){
        if(chaine[i] == x)
            cpt += 1;
    }
    return cpt;
}

int main(){ 
    char* tab;
    printf("enter votre chaine\n");
    scanf("%s",tab);
    printf("entrer la valeur a rechercher\n");
    char c;
    scanf("%c",&c);
    scanf("%c",&c);
    int p=ChercherVal(tab,c);
    printf("le nombre d'occurence de %c dans le texte est de %d\n",c,p);

    return 0;
}
    