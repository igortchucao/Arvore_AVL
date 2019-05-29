#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funcoes.h"

typedef struct matricula {
    int matricula;
    int tel;
    char nome[50];
} Matricula;

typedef struct AVL AVL;
typedef struct AVL {
    Matricula chave;
    int fatbal;
    AVL* esq;
    AVL* dir;
} AVL;

void cria(int *lista_criada, AVL* *a){
    *a = NULL;
    printf("--------LISTA CRIADA!--------\n");
    *lista_criada = 1;
}

void inserir(Matricula *x, AVL* *a)
{
    if (*a == NULL)
    {
        (*a) = malloc(sizeof(AVL));
        (*a)->chave.matricula = (*x).matricula;
        (*a)->chave.tel = (*x).tel;
        for(int i = 0; i < sizeof((*x).nome); i++)(*a)->chave.nome[i] = (*x).nome[i];
        (*a)->esq = NULL;
        (*a)->dir = NULL;
        (*a)->fatbal = 0;
        printf("------MATRICULA INSERIDA-----\n");
        return;
    }
    if ((*x).matricula < (*a)->chave.matricula)
    {
        (*a)->fatbal = (*a)->fatbal - 1;
        inserir(x, &(*a)->esq);
    }
    else
    {
        if ((*x).matricula > (*a)->chave.matricula)
        {
            (*a)->fatbal = (*a)->fatbal + 1;
            inserir(x, &(*a)->dir);
        }
        else
        {
            system("cls");
            printf("Erro : MATRICULA JA EXISTENTE\n");
        }
    }
}

void balancear(AVL* *p)
{
    if (*p != NULL)
    {
        balancear(&(*p)->esq);
        if((*p)->fatbal == 2 && (*p)->dir->fatbal == 1)simples_esquerda(&*p);
        if((*p)->fatbal == 2 && (*p)->dir->fatbal == -1)dupla_esquerda(&*p);
        if((*p)->fatbal == -2 && (*p)->esq->fatbal == -1)simples_direita(&*p);
        if((*p)->fatbal == -2 && (*p)->esq->fatbal == 1)dupla_direita(&*p);
        balancear(&(*p)->dir);
     }
}

void simples_esquerda(AVL* *p)
{
    AVL* aux1;
    aux1 = *p;
    aux1->fatbal = 0;
    (*p) = (*p)->dir;
    (*p)->fatbal = 0;
    aux1->dir = (*p)->esq;
    (*p)->esq = aux1;
}

void simples_direita(AVL* *p)
{
    AVL* aux1;
    aux1 = *p;
    aux1->fatbal = 0;
    (*p) = (*p)->esq;
    (*p)->fatbal = 0;
    aux1->esq = (*p)->dir;
    (*p)->dir = aux1;
}

void dupla_esquerda(AVL* *p)
{
    AVL* aux1;
    AVL* aux2;
    (*p)->fatbal = -2;
    aux2 = (*p)->dir;
    aux2->fatbal = 0;
    aux1 = aux2->esq;
    aux1->fatbal = -1;
    (*p)->dir = aux1;
    aux2->esq = aux1->dir;
    aux1->dir = aux2;
    simples_esquerda(&*p);
}

void dupla_direita(AVL* *p)
{
    AVL* aux1;
    AVL* aux2;
    (*p)->fatbal = -2;
    aux2 = (*p)->esq;
    aux2->fatbal = 0;
    aux1 = aux2->dir;
    aux1->fatbal = -1;
    (*p)->esq = aux1;
    aux2->dir = aux1->esq;
    aux1->esq = aux2;
    simples_direita(&*p);
}

void retirar(Matricula x, AVL* *p)
{
    AVL* aux;
    if ((*p) == NULL)
    {
        printf("--Erro : REGISTRO NaO EXISTE-\n");
    }
    else if (x.matricula < (*p)->chave.matricula)
    {
        (*p)->fatbal = (*p)->fatbal + 1;
        retirar(x, &(*p)->esq);
        return;
    }
    else if (x.matricula > (*p)->chave.matricula)
    {
        (*p)->fatbal = (*p)->fatbal - 1;
        retirar(x, &(*p)->dir);
        return;
    }
    else if ((*p)->dir == NULL)
    {
        aux = (*p);
        (*p) = aux->esq;
        free(aux);
    }
    else if ((*p)->esq == NULL)
    {
        aux = (*p);
        (*p) = aux->dir;
        free(aux);
    }
    else
    {
        antecessor((*p), &(*p)->esq);
    }
}

void antecessor(AVL* q, AVL* *r)
{
    if ((*r)->dir != NULL)
    {
        antecessor(q, &(*r)->dir);
        return;
    }
    else
    {
        q->chave = (*r)->chave;
        q = *r;
        *r = (*r)->esq;
        free(q);
    }
}

int buscar(Matricula *x, AVL* p)
{
    if (p == NULL) return 0;
    if (x->matricula < p->chave.matricula)
    {
        buscar(x, p->esq);
    } else if (x->matricula > p->chave.matricula) buscar(x, p->dir);
    else return 1;
}

void central(AVL* p)
{
    if (p != NULL)
    {
        fflush(stdin);
        printf("MATRICULA: %i\n", p->chave.matricula);
        printf("NOME: ");
        printf(" %s", p->chave.nome);
        printf("TELEFONE: %i\n", p->chave.tel);
        printf("------------------------------\n");
        central(p->esq);
        central(p->dir);
     }
}
