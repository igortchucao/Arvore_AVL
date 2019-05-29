#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funcoes.h"

int main()
{
    AVL* a;
    Matricula x;
    char letra[10];
    int lista_criada = 0;
    loop:
    printf("-----------------------------\n");
    printf("------ESCOLHA UMA OPcaO------\n");
    printf("-----------------------------\n");
    printf("-------1 CRIAR LISTA---------\n");
    printf("-----2 INSERIR MATRICULA-----\n");
    printf("-----3 REMOVER MATRICULA-----\n");
    printf("----------4 BUSCAR-----------\n");
    printf("-------5 IMPRIMIR LISTA------\n");
    printf("-----------9 SAIR------------\n");
    printf("-----------------------------\n");
    int ch;
    scanf("%i", &ch);
    system("cls");
    switch(ch)
    {
    case 1:
        cria(&lista_criada, &a);
        goto loop;
        break;
    case 2:
        if(lista_criada == 0)
        {
            printf("----CRIE A LISTA PRIMEIRO----\n\a");
            goto loop;
        }
        do
        {
            system("cls");
            printf("----DIGITE A MATRICULA (4 DIGITOS):---\n");
            scanf(" %i", &x.matricula);
        }while((x.matricula < 1000) || (x.matricula > 9999));
        printf("-------DIGITE O PRIMEIRO NOME (10 DIGITOS MAX):--------\n");
        fflush(stdin);
        fgets(x.nome, 50, stdin);
        printf("---DIGITE O TELEFONE (13):---\n");
        scanf(" %i", &x.tel);
        system("cls");
        inserir(&x, &a);
        balancear(&a);
        central(a);
        goto loop;
        break;
    case 3:
        if(lista_criada == 0)
        {
            printf("----CRIE A LISTA PRIMEIRO----\n\a");
            goto loop;
        }
        printf("--DIGITE A MATRICULA A RETIRAR:--\n");
        scanf("%i", &x.matricula);
        system("cls");
        if(buscar(&x, a))retirar(x, &a);
        else
        {
            system("cls");
            printf("---ELEMENTO NAO ENCONTRADO---\n");
            goto loop;
        }
        balancear(&a);
        central(a);
        printf("-----------REMOVIDO----------\n");
        goto loop;
        break;
    case 4:
        if(lista_criada == 0)
        {
            printf("----CRIE A LISTA PRIMEIRO----\n\a");
            goto loop;
        }
        printf("--DIGITE A MATRICULA REQUERIDA:--\n");
        scanf("%i", &x.matricula);
        system("cls");
        if(buscar(&x, a))printf("----------ENCONTRADO---------\n");
        else printf("-------NaO ENCONTRADO-------");
        goto loop;
        break;
    case 5:
        if(lista_criada == 0)
        {
            printf("----CRIE A LISTA PRIMEIRO----\n\a");
            goto loop;
        }
        central(a);
        goto loop;
        break;
    case 9:
        return 0;
    }
}
