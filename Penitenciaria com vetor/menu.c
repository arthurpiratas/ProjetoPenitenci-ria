#include <stdio.h>
#include <stdlib.h>
#include "Entidade.h"
#include "Validacoes.h"
#include "Negocio.h"
#include "CRUD.h"
#include "Menu.h"
#include <locale.h>
#include <time.h>


void menuCadastros(Detentos denVec[], Penas penVec[], Atividade atvVec[],  Visitantes visVec[]){

    int controle = 0;

    system("cls");

    do{

    printf("\n***** Menu de Cadastros ****** \n");
    printf("Digite \n1 - Cadastro Detento \n2 - Cadastro Pena \n3 - Cadastro Atividade \n4- Cadastro de Visistantes \n5- Cadastro de Visitas \n6- Sair \n");
    fflush(stdin);
    scanf("%d", &controle);

    switch(controle){
        case 1:
            menuCadastroDetento(denVec, penVec);
            break;
        case 2:
            menuCadastroPena(penVec);
            break;
        case 3:
            menuCadastroAtividade(atvVec);
        case 4:
            menuCadastroVisitantes(visVec);
            break;
        case 5:
            break;
        default:
            printf("Digite uma opção válida \n");
            break;
    }

    }while(controle != 6);
}

void menuCadastroDetento(Detentos denVec[], Penas penVec[]){

    int controle = 0;
    system("cls");
    while(controle != 6){

    printf("\n***** Menu de Cadastros Detento ****** \n");
    printf("Digite 1 - Cadastra Detento \n2 - Lista Detento \n3 - Altera Detento \n4 - Exclui Detento \n5 - Busca Detento \n6 - Sair \n");
    fflush(stdin);
    scanf("%d", &controle);

        switch(controle){

            case 1:
                cadastroDetento(denVec, penVec);
                break;
            case 2:
                listaDetentos(denVec, penVec);
                break;
            case 3:
                alteraDetento(denVec, penVec);
                carregaDetentosVetor(6, denVec);
                break;
            case 4:
                excluiDetento(denVec, penVec);
                break;
            case 5:
                ConsultaDetentoNome(denVec, penVec);
                break;
            case 6:
                break;
            default:
                printf("Digite uma opção válida \n");
                break;
        }

    }
}


void menuCadastroPena(Penas penVec[]){

    int controle = 0;
    system("cls");
    while(controle != 5){

    printf("\n***** Menu de Cadastros Penas ****** \n");
    printf("Digite 1 - Cadastra Pena \n2 - Lista Pena \n3 - Altera Pena \n4 - Consulta pena \n5 Sair \n");
    fflush(stdin);
    scanf("%d", &controle);

        switch(controle){

            case 1:
                cadastroPena(penVec);
                break;
            case 2:
                listaPenas(penVec);
                break;
            case 3:
                alteraPena(penVec);
                carregaPenasVetor(8, penVec);
                break;
            case 4:
                consultaPenaID(penVec);
                break;
            case 5:
                break;
            default:
                printf("Digite uma opção válida \n");
                break;
        }

    }
}

void menuCadastroAtividade(Atividade atvVec[]){

    int controle = 0;
    system("cls");
    while(controle != 5){

    printf("\n***** Menu de Cadastros Atividade ****** \n");
    printf("Digite 1 - Cadastra Atividade \n2 - Lista Atividade \n3 - Altera Atividade \n4 - Consulta Atividade \n5 Sair \n");
    fflush(stdin);
    scanf("%d", &controle);

        switch(controle){

            case 1:
                cadastraAtividade(atvVec);
                break;
            case 2:
                listarAtividade(atvVec);
                break;
            case 3:
                alteraAtividade(atvVec);
                carregaAtividadesVetor(2,atvVec);
                break;
            case 4:
                consultaAtividade(atvVec);
                break;
            default:
                printf("Digite uma opção válida \n");
                break;
        }

    }
}

void menuGereciamentoAtividade(Detentos denVec[], Atividade atvVec[], FuncAtividade funcAtvVec[]){

    int controle = 0;
    system("cls");
    while(controle != 5){

    printf("\n***** Menu de Atividade ****** \n");
    printf("Digite 1 - Cadastrar Atividade em detento \n2 - Lista Atividade de Detentos \n3 - Lista de detentos por Atividades \n4 - Exclui Atividade do Detento \n5 Sair \n");
    fflush(stdin);
    scanf("%d", &controle);

        switch(controle){

            case 1:
                cadastroFuncAtividade(funcAtvVec, atvVec, denVec);
                break;
            case 2:
                listaFuncAtvividadeDEN(funcAtvVec, atvVec, denVec, 1);
                break;
            case 3:
                listaFuncAtvividadeDEN(funcAtvVec, atvVec, denVec, 2);
                break;
            case 4:
                excluiAtividadeDetento(funcAtvVec, denVec, atvVec);
                break;
            case 5:
                break;
            default:
                printf("Digite uma opção válida \n");
                break;
        }

    }
}

void menuCadastroVisitantes(Visitantes visVec[]){

    int controle = 0;
    system("cls");
    while(controle != 5){

    printf("\n***** Menu de Cadastros Visitante ****** \n");
    printf("Digite 1 - Cadastra Visitante \n2 - Lista Visitante \n3 - Altera Visitante \n4 - Exclui Visitante \n5 Sair \n");
    fflush(stdin);
    scanf("%d", &controle);

        switch(controle){

            case 1:
                cadastraVisitantes(visVec);
                break;
            case 2:
                listaVisitantes(visVec);
                break;
            case 3:
                alteraVisitantes(visVec);
                carregaVisitantesVetor(4,visVec);
                break;
            case 4:
                excluiVisitantes(visVec);
                break;
            case 5:
                break;
            default:
                printf("Digite uma opção válida \n");
                break;
        }

    }
}

void menuGereciamentoVisitas(Detentos denVec[], Visitas visitaVec[], Visitantes visVec[]){

    int controle = 0;
    system("cls");
    while(controle != 5){

    printf("\n***** Menu de Atividade ****** \n");
    printf("Digite 1 - Cadastrar Visita  \n2 - Listar  Visitas \n3 - Alterar visitas \n4 - Exclui Atividade do Detento \n5 Sair \n");
    fflush(stdin);
    scanf("%d", &controle);

        switch(controle){

            case 1:
                cadastraVisita(visitaVec, visVec, denVec);
                break;
            case 2:
                listaVisitas(denVec, visVec, visitaVec);
                break;
            case 3:
                alteraVisitas(visitaVec, visVec, denVec);
                break;
            case 4:
                excluirVisitas(visitaVec, visVec, denVec);
                break;
            case 5:
                break;
            default:
                printf("Digite uma opção válida \n");
                break;
        }

    }
}


