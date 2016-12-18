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

    den = malloc(sizeof(Detentos)*250);
    pen = malloc(sizeof(Penas)*100);
    atv = malloc(sizeof(Atividade)*100);
    funcAtv = malloc(sizeof(Atividade)*800);

    carregaDetentosVetor(6, den);
    carregaPenasVetor(8, pen);
    carregaAtividadesVetor(2, atv);
    carregaFuncAtividadesVetor(3, funcAtv);



    while (a != 3){

        printf("\n***** Penitenciária ***** \n \n");
        printf("1 - Menu Cadastros \n2 - Menu Atividade  \n3 - Sair \n");
        fflush(stdin);
        scanf("%d", &a);
        switch(a){

        case 1:
            menuCadastros(den, pen, atv);
            break;
        case 2:
            menuGereciamentoAtividade(den, atv, funcAtv);
            break;
        case 3:
            printf("Sistema off \n");
            break;
        default:
            printf("Digite um número correto \n");

        }
    }
    system("pause");


    return 0;
}

