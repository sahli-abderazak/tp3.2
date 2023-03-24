#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct etudiant etudiant;
typedef struct cellule*listEtudiant;
typedef struct cellule cellule;
struct etudiant
{
    int insc;
    char nom [20];
    char classe [20];
    float moy;
};
struct cellule

{
    etudiant e;
    listEtudiant suivant;
};
void saisieEtudiant(etudiant *e)
{

    printf("donner le num d'inscrit de l'etudiant :");
    scanf("%d",&(e->insc));
    printf("donner le nom de l'etudiant :");
    scanf("%s",e->nom);
    printf("donner le classe de l'etudiant :");
    scanf("%s",e->classe);
    printf("donner le moyenne de l'etudiant :");
    scanf("%f",&(e->moy));
}
void afficheEtudiant(etudiant e)
{
    printf(" le num d'inscrit est \n %d",e.insc);
    printf("le nom est \n %s ",e.nom);
    printf("classe est \n %s",e.classe);
    printf(" la moyenne est \n %.2f",e.moy);
}
void ajouterEtudiant(listEtudiant *l)
{
    cellule *n;
    n=malloc(sizeof(cellule));
    cellule *prec;
    cellule *p;
    etudiant e;
    saisieEtudiant(&e);
    n->e=e;
    n->suivant =NULL;
    if(*l==NULL)
    {
        *l=n;
    }
    else
    {
        prec=NULL;
        p=*l;
        while((p!=NULL)&&(p->e.insc<n->e.insc))
        {
            prec=p;
            p=p->suivant;
        }
        if(prec!=NULL)
        {
            prec->suivant=n;
            n->suivant=p;
        }
        else
        {
            n->suivant=p;
            *l=n;
        }
    }


}
void afficherListe(listEtudiant l)
{
    listEtudiant p;
    p=l;
    while(p!=NULL)
    {
        afficheEtudiant(p->e);
        p=p->suivant;
    }
}
void supprimerEtudiantEnTete(listEtudiant *l)
{
    listEtudiant p;
    while(*l!=NULL)
    {
        p=*l;
        *l=p->suivant;
        free(p);
    }
}
listEtudiant Recherche_Etudiant(listEtudiant l, int Numins)
{
    listEtudiant p;
    p=l;

    while((p!=NULL)&&(p->e.insc != Numins))
    {
        p=p->suivant;
    }
    return p;

}
float Moyenne_Classe(listEtudiant l, char* nomC)
{
    float cpt,m;
    int nb=0;
    listEtudiant p;
    p=l;
    while(p!=NULL)
    {
        if(strcmp(p->e.classe,nomC)==0)
        {
            cpt=cpt+p->e.moy;
            nb++;
        }
        p=p->suivant;
    }
    m=cpt/nb;
    return (m);
}
void RemplirListe(listEtudiant*l,int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        ajouterEtudiant(l);
    }
}
void SupprimerEtudiant(listEtudiant*l,int Numins)
{
    listEtudiant p;
    listEtudiant prec;
    if(*l != NULL)
    {
        p=*l;
        prec=NULL;
        while((p!=NULL)&&((p->e.insc)!= Numins))
        {
            prec=p;
            p=p->suivant;
        }
        if(prec!= NULL)
        {
            prec->suivant=p->suivant;
            free(p);
        }
        else
        {
            supprimerEtudiantEnTete(l);
        }
    }
}
int main()
{

    listEtudiant l=NULL;
    char nomC[20];
    int Numins,n;
    float moy;
    listEtudiant q=NULL;
    printf("donner le nombre des etudiants:");
    scanf("%d",&n);
    RemplirListe(&l,n);
    afficherListe(l);
     printf("donner le num insc");
    scanf("%d",&Numins);
   /*SupprimerEtudiant(&l,Numins);
       afficherListe(l);*/
   q=Recherche_Etudiant(l,Numins);
   afficheEtudiant(q->e);
    printf("donner le nom de la classe a chercher");
    scanf("%s",nomC);
    moy= Moyenne_Classe(l,nomC);
    printf("la moyenne est %f",moy);
}

