#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"

int rechercheVal(char *vecteur, int taille, int val)
{
    int i;
    for (size_t i = 0; i < taille; i++)
        if(vecteur[i] == val)
            return i;
    
    return taille;
}

/*-------------------------------------------------------*/
int comparaisonVecteur(char *v, char *w, int taille)
{
    int i;
    for (size_t i = 0; i < taille; i++)
        if(v[i] != w[i])
            return i;

    return taille;

}

/*-----------------------------------------------------------*/
int rechercheOC(char *t, char *m, int tailleT, int tailleM)
{
    int i=0, k=0, occurence=0;
    while(i<tailleT)
    {
        if(tailleM <= tailleT-i)
        {
            // Appel de la fonction comparaisonVecteur
            k = comparaisonVecteur(&t[i], m, tailleM);
            if(k == tailleM)
            {
                occurence++;
                i = i + k;
            }
            else
                i = i + 1;
        }
        else
            return occurence;
    }

    return occurence;
}

/*--------------------------------------------------------------*/
int automate(char *t, char *m, int tailleT, int tailleM)
{
    char *tmp = t;
    int i=0, etat=0, occurence=0;
    while(i<tailleT)
    {
        if(tmp[i] == m[etat])
        {
            etat++;
            if(etat == tailleM)
            {
                occurence = occurence + 1;
                etat = 0;
            }
            i++;
        }
        else
        {
            if(etat > 0)
            {
                tmp = tmp + i;
                i = 0;
                tailleM = tailleM - 1;
            }
            else
            {
                i++;
                tailleM = tailleM - 1;
            }
            etat = 0;
        }
    }
    
    return occurence;
}
