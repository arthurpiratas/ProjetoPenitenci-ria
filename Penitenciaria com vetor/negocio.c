#include <stdio.h>
#include <string.h>
#include "Entidade.h"
#include "CRUD.h"
#include "Validacoes.h"
#include "Negocio.h"
#include <stdlib.h>
#include <time.h>
#define true 1
#define false 0
#define Max_Detento 200;


void cadastroDetento(Detentos denVec[], Penas penVec[]){
    Detentos den;


    time_t agora;
    char dataEntrada[50];
    agora = time(NULL);
    strftime( dataEntrada, sizeof(dataEntrada), "%d/%m/%Y", localtime( &agora ) );

    system("cls");
    printf("******* Cadastro Detento ******* \n");
    printf("Os Campos com * devem ser preenchido obrigatóriamente \n");

    printf("Digite o nome do Detento *\n");
    fflush(stdin);
    gets(den.Nome);

    den.ID = retornaProximoId(6, denVec);

    printf("Digite a Data de Nascimento ex: dd/mm/aa \n");
    fflush(stdin);
    gets(den.dataNascimento);

    strcpy(den.dataEntrada, dataEntrada);

    printf("Digite a Data de Saida ex: dd/mm/aa *\n");
    fflush(stdin);
    gets(den.dataSaida);

    printf("Digite o nome da mãe *\n");
    fflush(stdin);
    gets(den.nomeMae);

    printf("Digite sua escolaridade \n");
    fflush(stdin);
    gets(den.escolaridade);

    printf("Digite o número da Ala *\n");
    scanf("%d", &den.numeroAla);

    printf("Digite o número de Telefone \n");
    scanf("%d", &den.telefone);

    do{
    printf("Digite a Pena *\n");
    scanf("%d", &den.IDpena);
    if(!verificaPenaExiste(den.IDpena, penVec)){
        printf("Digite uma pena válida!");
    }
    }while(!verificaPenaExiste(den.IDpena, penVec));

    den.ativo = true;

    printf("Digite a profissão \n");
    fflush(stdin);
    gets(den.Profissao);

    printf("Digite o número do quarto *\n");
    scanf("%d", &den.numeroQuarto);

    printf("Digite o número do CPF *\n");
    scanf("%ld", &den.loginCPF);

    if(validaString(den.Nome) && validaIntPositivo(den.loginCPF)){

        den.preenchido = true;

        if(!verificaDetentoExiste(den.Nome, denVec) && (!verificaDetentoExisteCPFcdt(den.loginCPF, denVec))){
                if(cadastroDetentoCRUD(den, 6)){
                    printf("Cadastro Realizado com Sucesso! \n");
                    copiaDetentoParaVetor(den, denVec);
                    }else{
                    printf("Cadastro não realizado! \n");
                }

         }else {

             printf("Detento %s já cadastrado \n", den.Nome);

         }

    }else{
        printf("Favor digitar Nome \n");
    }
}

void listaDetentos(Detentos denVec[], Penas pen[]){

    listaDetentoCRUD(denVec, pen);
}

void alteraDetento(Detentos denVec[], Penas penVec[]){

    system("cls");
    char nome[50];
    int flagNomeIgual = false;
    Detentos den, denBusca;
    printf("******Altera Detento******* \n");

    listaDetentos(denVec, penVec);

    printf("\n\nDigite o nome do cntato a ser alterado  \n");
    fflush(stdin);
    gets(nome);

    if(verificaDetentoExiste(nome, denVec)){

            printf("Digite o novo nome do Detento \n");
            fflush(stdin);
            gets(den.Nome);
            if(!verificaDetentoExiste(den.Nome, denVec) || (strcmp(nome, den.Nome) == 0)  ){
                denBusca = retornaDetentoPorNome(nome, denVec);

                if(denBusca.ativo == false){
                    printf("Detento nao existe \n");
                }else{

                    den.ID = denBusca.ID;
                    printf("Digite a Data de Nascimento ex: dd/mm/aa \n");
                    fflush(stdin);
                    gets(den.dataNascimento);

                    printf("Digite a Data de entrada \n");
                    fflush(stdin);
                    gets(den.dataEntrada);


                    printf("Digite a Data de Saida ex: dd/mm/aa *\n");
                    fflush(stdin);
                    gets(den.dataSaida);

                    printf("Digite o nome da mãe *\n");
                    fflush(stdin);
                    gets(den.nomeMae);

                    printf("Digite sua escolaridade \n");
                    fflush(stdin);
                    gets(den.escolaridade);

                    printf("Digite o número da Ala *\n");
                    scanf("%d", &den.numeroAla);

                    printf("Digite o número de Telefone \n");
                    scanf("%d", &den.telefone);

                    do{
                        printf("Digite a Pena *\n");
                        scanf("%d", &den.IDpena);
                        if(!verificaPenaExiste(den.IDpena, penVec)){
                        printf("Digite uma pena válida!");
                    }
                    }while(!verificaPenaExiste(den.IDpena, penVec));

                    den.ativo = true;

                    printf("Digite a profissão \n");
                    fflush(stdin);
                    gets(den.Profissao);

                    printf("Digite o número do quarto *\n");
                    scanf("%d", &den.numeroQuarto);

                    printf("Digite o número do CPF *\n");
                    scanf("%ld", &den.loginCPF);

                    den.ativo = true;
                    den.preenchido = true;

                    if(validaIntPositivo(den.loginCPF) && validaString(den.Nome)){
                            if(!verificaDetentoExisteCPF(den.loginCPF, denVec, den.ID)){
                               if(alteraDetentoCRUD(den, denBusca.ID)){
                                printf("Detento %s Alteado! \n", den.Nome);
                                copiaDetentoParaVetor(den, denVec);

                                }else{
                                    printf("Erro na alteracao! \n");
                                }
                            }else{
                                printf("Erro! CPF pertence a outro Detento \n");
                            }

                    }else{
                        printf("Dados não foram preenchidos corretamente! \n");
                    }
                }

            }else{
                printf("Erro! O Detento %s já cadastrado no Sistema, tentar novamente com outro Nome\n", den.Nome);
            }
    }else{
        printf("Detento nao existe \n");
    }


}

void excluiDetento(Detentos denVect[], Penas penVec[]){

    system("cls");
    char nome[50];
    Detentos den;

    printf("****Exclui Detento**** \n");

    listaDetentos(denVect, penVec);

    printf("Digite O Nome do detento a ser excluido \n");
    fflush(stdin);
    gets(nome);

    system("cls");
    printf("****Exclui Detento**** \n");

    if(validaString(nome)){
        if(verificaDetentoExiste(nome, denVect)){
                den = retornaDetentoPorNome(nome, denVect);
                printf("Detento %s , ID %d \n", den.Nome, den.ID);
                den.ativo = false;

                if(alteraDetentoCRUD(den,den.ID)){
                    denVect[den.ID].ativo = false;
                    printf("O Detento %s Foi excluido do Sistema! \n", nome);
                }else{
                    printf("Erro! Não foi possivel excluir detento! \n");
                }

        }else{
            printf("Este detento não existe no nosso registro! \n");

        }
    }else{
        printf("Erro! Nome não digitado! \n");
    }
}

void ConsultaDetentoNome(Detentos denVec[], Penas penVec[]){
    system("cls");
    int result = 0, cont = 0;
    char nome[50];
    Detentos den, denBusca;


    printf("***Busca Detentos pelo Nome *** \n");

    do{
    printf("Digite o CPF do Detento \n");
    fflush(stdin);
    gets(nome);
    }while(!verificaDetentoExiste(nome, denVec));

    den = retornaDetentoPorNome(nome, denVec);


        if(den.ativo == true && den.preenchido == true){

            printf("ID %d \nNome %s \nData de Nascimento %s \nPena %s \nRegime %s", den.ID, den.Nome, den.dataNascimento, penVec[den.IDpena].descricao, penVec[den.IDpena].Regiume);
            cont++;
        }



    printf("******** A busca retornou %d Detentos ********* \n", cont);
}

void cadastroPena(Penas penvec[]){

    Penas pen;
    system("cls");
    printf("**** Cadastro de Penas***** \n");

    printf("Digite a descrição da Penas \n");
    fflush(stdin);
    gets(pen.descricao);

    printf("Digite o Regime da Penas \n");
    fflush(stdin);
    gets(pen.Regiume);

    printf("Digite o grau da Penas  \n");
    fflush(stdin);
    scanf("%d", &pen.grau);

    pen.ID = retornaProximoIdPenas(penvec);

    if(validaString(pen.descricao) && validaString(pen.Regiume) && validaIntPositivo(pen.grau)){
            pen.preenchido = true;
            if(!verificaDecsPenaExiste(pen.descricao, penvec)){
                if(cadastraPenasCRUD(pen, 8)){
                        printf("Pena Cadastrada! \n");
                        copiaPenaParaVetor(pen, penvec);
                }else{
                    printf("Erro! Pena Não cadastrada \n");
                }
            }else{
                printf("Erro! Não é possível cadastrar essa pena, pois ela já foi cadastrada \n");
            }

    }else{
        printf("Favor, preencher todos os dados corretamente \n");
    }
}

void listaPenas(Penas penVec[]){
    listaPenasCRUD(penVec);
}


void alteraPena(Penas penVec[]){

    system("cls");

    char descricao[50];
    int ID;
    Penas pen, penBusca;

    printf("****** Alteração de Atividade *******");

    listaPenas(penVec);

    printf("Digite o ID do Contato a ser Alterado \n");
    scanf("%d", &ID);

    if(verificaPenaExiste(ID, penVec)){

            printf("Digite o Novo nome para descrição \n");
            fflush(stdin);
            gets(pen.descricao);

            if(!verificaDecsPenaExiste(pen.descricao, penVec) || (strcmp(penVec[ID].descricao, pen.descricao) == 0 )){
                  penBusca = retornaPenaDetentoPorID(ID, penVec);

                  printf("Digite o Grau \n");
                  scanf("%d", &pen.grau);

                  pen.ID = penBusca.ID;

                  printf("Digite o Regime \n");
                  fflush(stdin);
                  gets(pen.Regiume);
                  printf("%d %d", penBusca.ID, penBusca.preenchido);

                  if(validaString(pen.descricao), validaIntPositivo(pen.grau)){
                        pen.preenchido = penBusca.preenchido;
                        if(alteraPenasCRUD(pen, penBusca.ID)){
                            printf("A Pena %s Foi Alterada com Sucesso!",  pen.descricao);
                            copiaPenaParaVetor(pen, penVec);
                        }else{
                            printf("Erro! Pena não Alterada!");
                        }
                  }else{
                      printf("Erro! Digite os campos corretamente! \n");
                  }

            }else{
                printf("Erro! Nome já cadastrado, tente como outro! \n");
            }

    }else{
        printf("Erro! Esta Pena Não existe \n");
    }
}

void consultaPenaID(Penas penVec[]){

    system("cls");

    char descricao[50];
    int ID, cont = 0;
    Penas  penBusca;

    printf("****** Consulta de Pena *******");


    do{
    printf("Digite o ID da pena  \n");
    scanf("%d", &ID);

    }while(!verificaPenaExiste(ID, penVec));

    penBusca = retornaPenaDetentoPorID(ID, penVec);

    if(penBusca.preenchido == true){
            printf("ID da Pena: %d \nDescrição: %s \nRegime: %s \nGrau: %d \n", penBusca.ID, penBusca.descricao, penBusca.Regiume, penBusca.grau);
            cont++;
    }


    printf("******** A busca Penas %d Detentos ********* \n", cont);

}

void cadastraAtividade(Atividade atvVec[]){

    system("cls");
    Atividade atv;

    printf("************* Cadastro Atividade **************** \n");

    printf("Digite o Nome da Atividade \n");
    fflush(stdin);
    gets(atv.descricao);

    printf("Digite o nivel de avaliacao \n");
    fflush(stdin);
    scanf("%d", &atv.avaliacao);

    printf("Digite a remuneracao mensal \n");
    fflush(stdin);
    scanf("%f", &atv.remuneracao);

    atv.ID = retornaProximoIdAtiv(2, atvVec);
    if(validaString(atv.descricao), validaIntPositivo(atv.avaliacao)){
            atv.preenchido = true;
        if(!verificaAtividadeExisteDesc(atv.descricao, atvVec)){
            atv.ativo = true;
            if(cadastroAtividadeCRUD(atv, 2)){
                printf("Cadstro realizado!");
                copiaAtividadeParaVetor(atv, atvVec);
            }else{
                printf("Erro! Cadastro nao realizado");
            }

        }else{
            printf("A atividade Digitada ja existe, favor cadastrar novamente \n");
        }
    }else{
        printf("Os campos n'ao foram preenchidos corretamente, favor cadastrar novamente! \n");
    }


}

void listarAtividade(Atividade atvVec[]){

    listaAtividadeCRUD(atvVec);
}

void consultaAtividade(Atividade atvVec[]){

    system("cls");

    char descricao[50];
    int ID, cont = 0, controle = 0;
    Atividade  atvBusca;

    printf("****** Consulta de Atividade ******* \n");

    printf("Digite 1 para pesquisar por Nome e 2 para pesquisar por ID \n");
    fflush(stdin);
    scanf("%d", &controle);

    switch(controle){

        case 1:
            do{
            printf("Digite a descricao da avaliacao \n");
            fflush(stdin);
            gets(descricao);

            }while(!validaString(descricao));

            atvBusca = retornaAtividadeporDesc(descricao, atvVec);
            break;
        case 2:
            do{
            printf("Digite o ID da Avaliacao \n");
            fflush(stdin);
            scanf("%d", &ID);

            }while(!validaIntPositivo(ID));

            atvBusca = retornaAtividadeporID(ID, atvVec);
            break;
        default:
            printf("Esta opcao nao e valida \n");

    }

   if(atvBusca.ativo == true){
            printf("ID da Atividade: %d \nDescrição: %s \nNivel de avaliacao: %d \nRemuneracao: %f \n", atvBusca.ID, atvBusca.descricao, atvBusca.avaliacao, atvBusca.remuneracao);
            cont++;
    }


    printf("******** A busca retornou %d Atividades  ********* \n", cont);

}

void alteraAtividade(Atividade atvVec[]){

    system("cls");

    char descricao[50];
    int ID;
    Atividade atv, atvBusca;

    printf("****** Alteração de Atividade *******");

    listaAtividadeCRUD(atvVec);

    printf("Digite o ID da Atividade a ser Alterada \n");
    scanf("%d", &ID);

    if(verificaAtividadeExiste(ID, atvVec)){

            printf("Digite o Novo nome para descrição \n");
            fflush(stdin);
            gets(atv.descricao);

            if(!verificaAtividadeExisteDesc(atv.descricao, atvVec) || (strcmp(atvVec[ID].descricao, atv.descricao) == 0 )){
                   atvBusca = retornaAtividadeporID(ID, atvVec);

                  printf("Digite o nivel de avaliacao \n");
                  fflush(stdin);
                  scanf("%d", &atv.avaliacao);

                  printf("Digite a remuneracao mensal \n");
                  fflush(stdin);
                  scanf("%f", &atv.remuneracao);

                  atv.ID = atvBusca.ID;

                  if(validaString(atv.descricao), validaIntPositivo(atv.avaliacao)){
                        atv.preenchido = atvBusca.preenchido;
                        atv.ativo = atvBusca.ativo;
                        if(alteraAtividadeCRUD(atv, atv.ID)){
                            printf("A Atividade %s Foi Alterada com Sucesso!",  atv.descricao);
                            copiaAtividadeParaVetor(atv, atvVec);
                        }else{
                            printf("Erro! Atividade não Alterada!");
                        }
                  }else{
                      printf("Erro! Digite os campos corretamente! \n");
                  }

            }else{
                printf("Erro! Descricao já cadastrada, tente com outra! \n");
            }

    }else{
        printf("Erro! Esta Atividade Não existe \n");
    }
}


void cadastroFuncAtividade(FuncAtividade funcAtvVec[], Atividade atvVec[], Detentos denVec[]){

    system("cls");

    printf("****** Cadastro de Atividade para Detento ******* \n");

    FuncAtividade funcAtv;
    Detentos den;
    long int CPF = 0;


    do{

    if(CPF == 0){
        printf("CPF Digitado não é válido, favor digitar CPF correto \n");
    }

    printf("Digite o CPF do Detento \n");
    fflush(stdin);
    scanf("%ld", &CPF);

    }while(!verificaDetentoExisteCPFcdt(CPF, denVec));

    den = retornaDetentoPorCPF(CPF, denVec);

    funcAtv.IDdetento = den.ID;

    listaAtividadeCRUD(atvVec);

    printf("\n");

    do{


    printf("Digite o ID da Atividade \n");
    fflush(stdin);
    scanf("%d", &funcAtv.IDatividade);

    }while(!verificaAtividadeExiste(funcAtv.IDatividade, atvVec));

    printf("Digite o dia da Semana da Atividade \n");
    fflush(stdin);
    gets(funcAtv.diaSemana);

    printf("Digite o turno, N - Noite, M - Manhã e T - Tarde \n");
    fflush(stdin);
    scanf("%c", &funcAtv.turno);

    printf("Digite a data do inicio da Atividade \n");
    fflush(stdin);
    gets(funcAtv.dataAtividade);

    funcAtv.IDfuncAtv = retornaProximoIdFuncAtiv(3, funcAtvVec);

    funcAtv.preenchido = true;
    funcAtv.Ativa = true;

    if(!verificaAtividadeAlocada(funcAtvVec, funcAtv)){
        if(cadastroFuncAtividadeCRUD(funcAtv, 3)){
            printf("Atividade  Cadastrada para o Detento %s \n", den.Nome);
            copiaFuncAtividadeParaVetor(funcAtv, funcAtvVec);
        }else{
            printf("Erro! Atividade não alocada \n");
        }
    }else{
        printf("Já existe uma atividade alocada para este dia/turno na semana \n");
    }

}

void listaFuncAtvividadeDEN(FuncAtividade funcAtv[], Atividade atvVec[], Detentos denVec[], int flag){

    system("cls");


    Detentos den;
    long int CPF = 0;
    int ID, IDatv;

    if(flag == 1){
        printf("****** Lista Atividades de Detentos ******* \n");
        do{

            printf("Digite o CPF do Detento \n");
            fflush(stdin);
            scanf("%ld", &CPF);



        }while(!verificaDetentoExisteCPFcdt(CPF, denVec));

        den = retornaDetentoPorCPF(CPF, denVec);


        ID = den.ID;

    }else{

        printf("****** Lista Detentos por Atividade ******* \n");

        listaAtividadeCRUD(atvVec);
        printf("\n");
        do{

            printf("Digte o ID da Atividade \n");
            fflush(stdin);
            scanf("%d", &IDatv);

        }while(!verificaAtividadeExiste(IDatv, atvVec));

        ID = IDatv;
    }

    listaFuncAtividadeCRUD(ID, funcAtv, atvVec, denVec, flag);


}

void excluiAtividadeDetento(FuncAtividade funcAtvVec[], Detentos denVec[], Atividade atvVec[]){

    system("cls");

    printf("****** Exclui Atividade de  Detento ******* \n");

    Detentos den;
    FuncAtividade funcAtv;

    den.loginCPF = 0;

    do{

     if(validaIntPositivo(den.loginCPF)){
        printf("Digite um CPF válido para continuar \n");
     }
     printf("Digite o CPF do Detento \n");
     fflush(stdin);
     scanf("%ld", &den.loginCPF);

    }while(!verificaDetentoExisteCPFcdt(den.loginCPF, denVec));

    den = retornaDetentoPorCPF(den.loginCPF, denVec);

    funcAtv.IDdetento = den.ID;

    listaFuncAtividadeCRUD(den.ID, funcAtvVec, atvVec, denVec, 1);

    printf("Digite o ID da Atividade a ser excluida \n");
    fflush(stdin);
    scanf("%d", &funcAtv.IDatividade);

    printf("Digite o dia da semana a ser excluido \n");
    fflush(stdin);
    gets(funcAtv.diaSemana);

    printf("Digite o turno da atividade a ser excluida \n");
    fflush(stdin);
    scanf("%c", &funcAtv.turno);

    if(verificaAtividadeAlocada(funcAtvVec, funcAtv)){
        funcAtv.IDfuncAtv = retornaFuncAtvID(funcAtv.IDatividade, funcAtv.IDdetento, funcAtvVec, funcAtv.turno, funcAtv.diaSemana);
        funcAtv.preenchido = true;
        funcAtv.Ativa = false;

        if(alteraFuncAtvCRUD(funcAtv, funcAtv.IDfuncAtv)){
             copiaFuncAtividadeParaVetor(funcAtv, funcAtvVec);
             printf("Esta atividade foi excluida no dia do Detento %s na semana", den.Nome);

        }else{
            printf("Erro! Atividade não exluida! \n");
        }

    }else{
        printf("Não existe uma atividade alocada para este dia/turno na semana, favor, tentar novamente \n ");
    }


}

