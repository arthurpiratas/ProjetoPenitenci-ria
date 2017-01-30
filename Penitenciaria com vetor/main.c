#include <stdio.h>
#include <stdlib.h>
#include "Entidade.h"
#include "Validacoes.h"
#include "Negocio.h"
#include "CRUD.h"
#include "Menu.h"
#include <locale.h>
#include <time.h>


int main()
{
    setlocale(LC_ALL, "Portuguese");

    int a = 0;

    Detentos *den;
    Penas *pen;
    Atividade *atv;
    FuncAtividade *funcAtv;
    Visitantes *visVec;
    Visitas *visitaVec;

    den = malloc(sizeof(Detentos)*250);
    pen = malloc(sizeof(Penas)*100);
    atv = malloc(sizeof(Atividade)*100);
    funcAtv = malloc(sizeof(Atividade)*800);
    visVec = malloc(sizeof(Visitantes)*200);
    visitaVec = malloc(sizeof(Visitas)*500);


    carregaAtividadesVetor(2, atv);
    carregaFuncAtividadesVetor(3, funcAtv);
    carregaVisitantesVetor(4, visVec);
    carregaVisitasVetor(5, visitaVec);
    carregaDetentosVetor(6, den);
    carregaPenasVetor(8, pen);



    while (a != 4){

        printf("\n***** Penitenciária ***** \n \n");
        printf("1 - Menu Cadastros \n2 - Menu Atividade  \n3 - Menu Visitas \n4 - Sair \n");
        fflush(stdin);
        scanf("%d", &a);
        switch(a){

        case 1:
            menuCadastros(den, pen, atv, visVec);
            break;
        case 2:
            menuGereciamentoAtividade(den, atv, funcAtv);
            break;
        case 3:
            menuGereciamentoVisitas(den, visitaVec, visVec);
            break;
        case 4:
            printf("Sistema off \n");
            break;
        default:
            printf("Digite um número correto \n");

        }
    }
    system("pause");


    return 0;
}

