#include <stdio.h>
#include <string.h>
#include "Entidade.h"
#include "Validacoes.h"
#include "CRUD.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define true 1
#define false 0
#define Max_Detento 200
#define Max_Penas 100
#define Max_Atividade 100
#define Max_FuncAtividade 500

const char FUNCIONARIO[17] = "funcionario.bin";
const char ATIVIDADE[15] = "atividade.bin";
const char FUNCATIVIDADE[19] = "funcAtividade.bin";
const char VISITANTES[15] = "visitantes.bin";
const char VISITAS[15] = "visitas.bin";
const char DETENTOS[15] = "detentos.bin";
const char ENTRADASAIDA[15] = "entradaSaida.bin";
const char PENAS[15] = "penas.bin";




void abrirArquivo(int arquivo, char tipo[], FILE **pf){

     char string[20] = "";

     switch(arquivo){
        case 1:
            strcpy(string, FUNCIONARIO);
            break;
        case 2:
            strcpy(string, ATIVIDADE);
            break;
        case 3:
            strcpy(string, FUNCATIVIDADE);
            break;
        case 4:
            strcpy(string, VISITANTES);
            break;
        case 5:
            strcpy(string, VISITAS);
            break;
        case 6:
            strcpy(string, DETENTOS);
            break;
        case 7:
            strcpy(string, ENTRADASAIDA);
            break;
        case 8:
            strcpy(string, PENAS);
            break;

     }
    if(!(*pf = fopen(string, tipo))){
            printf("Erro!");
            exit(1);
    }else {
        printf("Banco aberto  \n");


}

}

/* CRUD Detento */

int cadastroDetentoCRUD(Detentos den, int enty){

    FILE *pf;
    int a = 0;
    abrirArquivo(enty, "a+b", &pf);

    fseek(pf, 0, SEEK_END);

    if(fwrite(&den, sizeof(Detentos), 1, pf) != 1){
        a = 0;
    }else {
        a = 1;
    }
    fclose(pf);

    return a;

}

void carregaDetentosVetor(int enty, Detentos den[]){

    FILE *pf;
    int indix = 0;
    abrirArquivo(enty, "a+b", &pf);
    fseek(pf, 0, SEEK_SET);
    memset(den, 0, sizeof(Detentos));


    do{
            if(fread(&den[indix], sizeof(Detentos), 1, pf) == 1){
                indix++;
            }


    }while(!feof(pf));

    fclose(pf);

}

void listaDetentoCRUD(Detentos den[], Penas penVec[]){

    system("cls");
    int result = 0, cont = 0;

    Penas pen;



    printf("***Lista de Detentos*** \n");


    for(result = 0; result <= 200; result++){
        if(den[result].ativo == true && den[result].preenchido == true){

            printf("ID %d \nNome %s \nData de Nascimento %s \nPena %s \nRegime %s", den[result].ID, den[result].Nome, den[result].dataNascimento, penVec[den[result].IDpena].descricao, penVec[den[result].IDpena].Regiume);
            cont++;
        }
    }


    printf("******** A busca retornou %d Detentos ********* \n", cont);

}

int retornaProximoId(int enty, Detentos den[]){

    int result = 0, index;

    for(index = 0; index < Max_Detento; index++){
        if(den[index].preenchido == true){
            result++;
        }else{
            break;
        }
    }

    return result;

}



Detentos retornaDetentoPorNome(char nome[], Detentos denVec[]){


    int index = 0;
    Detentos den;

    for(index = 0; index < 200; index++){
        if(strcmp(denVec[index].Nome, nome) == 0){
                strcpy(den.Nome, denVec[index].Nome);
                strcpy(den.nomeMae, denVec[index].nomeMae);
                den.ID = denVec[index].ID;
                strcpy(den.dataNascimento, denVec[index].dataNascimento);
                den.avaliacao = denVec[index].avaliacao;
                strcpy(den.dataEntrada, denVec[index].dataEntrada);
                strcpy(den.dataSaida, denVec[index].dataSaida);
                strcpy(den.escolaridade, denVec[index].escolaridade);
                den.IDpena = denVec[index].IDpena;
                den.numeroAla = denVec[index].numeroAla;
                den.numeroQuarto = denVec[index].numeroQuarto;
                strcpy(den.Profissao, denVec[index].Profissao);
                den.telefone = denVec[index].telefone;
                den.preenchido = denVec[index].preenchido;
                den.ativo = denVec[index].ativo;
                break;
        }
    }

    return den;

}

Detentos retornaDetentoPorCPF(long int CPF, Detentos denVec[]){


    int index = 0;
    Detentos den;

    for(index = 0; index < 200; index++){
        if(denVec[index].loginCPF = CPF){
                strcpy(den.Nome, denVec[index].Nome);
                strcpy(den.nomeMae, denVec[index].nomeMae);
                den.ID = denVec[index].ID;
                strcpy(den.dataNascimento, denVec[index].dataNascimento);
                den.avaliacao = denVec[index].avaliacao;
                strcpy(den.dataEntrada, denVec[index].dataEntrada);
                strcpy(den.dataSaida, denVec[index].dataSaida);
                strcpy(den.escolaridade, denVec[index].escolaridade);
                den.IDpena = denVec[index].IDpena;
                den.numeroAla = denVec[index].numeroAla;
                den.numeroQuarto = denVec[index].numeroQuarto;
                strcpy(den.Profissao, denVec[index].Profissao);
                den.telefone = denVec[index].telefone;
                den.preenchido = denVec[index].preenchido;
                den.ativo = denVec[index].ativo;
                break;
        }
    }

    return den;

}

int  alteraDetentoCRUD(Detentos den, int id){

    FILE *pf;
    int retorno = 0;
    abrirArquivo(6, "r+b", &pf);


    rewind(pf);



    fseek(pf, (id)*sizeof(Detentos), SEEK_SET);

    if(fwrite(&den, sizeof(Detentos), 1, pf) != 1){
        retorno = 0;
    }else {
        retorno = 1;
    }
    fclose(pf);

    return retorno;

}

void realocaDetentos(Detentos denVec[]){
    /* método teste para realocação de detento para lugares que estão desativados */
    int cont = Max_Detento, cont2;

    do{
        for(cont2 = cont; cont2 >= 0; cont2--){
            if(denVec[cont2-1].ativo = false){
                denVec[cont2].ID = denVec[cont2-1].ID;
                break;
            }
        }

        cont = denVec[cont2].ID;
    }while(denVec[cont].ativo != false);

    cont = 0;

    while(denVec[cont].ativo = true && denVec[cont].preenchido == true){

        FILE *pf;
        int index = 0;
        abrirArquivo(6, "w+b", &pf);

        fseek(pf, 0, SEEK_END);

        fwrite(&denVec[cont], sizeof(Detentos), 1, pf);
        cont++;
    }
}

/* CRUD Penas */

void carregaPenasVetor(int enty, Penas pen[]){

    FILE *pf;
    int indix = 0;
    abrirArquivo(enty, "a+b", &pf);
    fseek(pf, 0, SEEK_SET);
    memset(pen, 0, sizeof(Detentos));

    do{
            if(fread(&pen[indix], sizeof(Penas), 1, pf) == 1){
                indix++;
            }


    }while(!feof(pf));

    fclose(pf);

}

int retornaProximoIdPenas(Penas pen[]){

    int result = 0, index;

    for(index = 0; index < Max_Penas; index++){
        if(pen[result].preenchido == true){
            result++;
        }else{
            break;
        }
    }

    return result;

}

Penas retornaPenaDetentoPorID(int ID, Penas penVec[]){
    int index = 0;
    Penas pen;

    for(index; index <= Max_Penas; index++){
        if(penVec[index].ID == ID){
            strcpy(pen.descricao, penVec[index].descricao);
            strcpy(pen.Regiume, penVec[index].Regiume);
            pen.grau = penVec[index].grau;
            pen.ID = penVec[index].ID;
            pen.preenchido = penVec[index].preenchido;
            break;
        }
    }

    return pen;
}

int cadastraPenasCRUD(Penas pen, int enty){
    FILE *pf;
    int retorno = 0;
    abrirArquivo(enty, "a+b", &pf);

    fseek(pf, 0, SEEK_END);

    if(fwrite(&pen, sizeof(Penas), 1, pf) != 1){
        retorno = 0;
    }else {
        retorno = 1;
    }
    fclose(pf);

    return retorno;
}

void listaPenasCRUD(Penas pen[]){

    system("cls");
    int result = 0, cont = 0;


    printf("***Lista de Penas*** \n");


    for(result = 0; result <= 200; result++){
        if(pen[result].preenchido == true){
            printf("ID da Pena: %d \nDescrição: %s \nRegime: %s \nGrau: %d \n", pen[result].ID, pen[result].descricao, pen[result].Regiume, pen[result].grau);
            cont++;
        }
    }


    printf("******** A busca retornou %d Detentos ********* \n", cont);

}


int  alteraPenasCRUD(Penas pen, int id){

    FILE *pf;
    int retorno = 0;
    abrirArquivo(8, "r+b", &pf);

    rewind(pf);



    fseek(pf, (id)*sizeof(Penas), SEEK_SET);

    if(fwrite(&pen, sizeof(Penas), 1, pf) != 1){
        retorno = 0;
    }else {
        retorno = 1;
    }
    fclose(pf);

    return retorno;

}

/* Atividade */


int cadastroAtividadeCRUD(Atividade atv, int enty){

    FILE *pf;
    int index = 0;
    abrirArquivo(enty, "a+b", &pf);

    fseek(pf, 0, SEEK_SET);

    if(fwrite(&atv, sizeof(Atividade), 1, pf) != 1){
        index = 0;
    }else {
        index = 1;
    }
    fclose(pf);

    return index;

}

void carregaAtividadesVetor(int enty, Atividade atv[]){

    FILE *pf;
    int index = 0;
    abrirArquivo(enty, "a+b", &pf);
    fseek(pf, 0, SEEK_SET);
    memset(atv, 0, sizeof(Atividade));


    do{
            if(fread(&atv[index], sizeof(Atividade), 1, pf) == 1){
                index++;
            }


    }while(!feof(pf));

    fclose(pf);

}

void listaAtividadeCRUD(Atividade atv[]){

    system("cls");
    int result = 0, cont = 0;

    printf("***Lista de Atividades*** \n");


    for(result = 0; result <= Max_Atividade; result++){
        if(atv[result].ativo == true && atv[result].preenchido == true){

            printf("ID %d \nDescrição %s \nAvalição %d \nRemuneração %f \n", atv[result].ID, atv[result].descricao, atv[result].avaliacao, atv[result].remuneracao);
            cont++;
        }
    }


    printf("******** A busca retornou %d Detentos ********* \n", cont);

}

int retornaProximoIdAtiv(int enty, Atividade atv[]){

    int result = 0, index;

    for(index = 0; index <= Max_Atividade; index++){
        if(atv[index].preenchido == true){
            result++;
        }else{
            break;
        }
    }

    return result;

}



Atividade retornaAtividadeporID(int ID, Atividade atvVec[]){


    int index = 0;
    Atividade atv;

    for(index = 0; index < Max_Atividade; index++){
        if(atvVec[index].ID == ID){
                strcpy(atv.descricao, atvVec[index].descricao);
                atv.ID = atvVec[index].ID;
                atv.remuneracao = atvVec[index].remuneracao;
                atv.avaliacao = atvVec[index].avaliacao;
                atv.ativo = atvVec[index].ativo;
                atv.preenchido = atvVec[index].preenchido;
                break;
        }
    }

    return atv;

}

Atividade retornaAtividadeporDesc(char desc[], Atividade atvVec[]){


    int index = 0;
    Atividade atv;

    for(index = 0; index < Max_Atividade; index++){
        if(strcpy(atvVec[index].descricao, desc)){
                strcpy(atv.descricao, atvVec[index].descricao);
                atv.ID = atvVec[index].ID;
                atv.remuneracao = atvVec[index].remuneracao;
                atv.avaliacao = atvVec[index].avaliacao;
                atv.ativo = atvVec[index].ativo;
                atv.preenchido = atvVec[index].preenchido;
                break;
        }
    }

    return atv;

}


int  alteraAtividadeCRUD(Atividade atv, int id){

    FILE *pf;
    int retorno = 0;
    abrirArquivo(2, "r+b", &pf);


    rewind(pf);



    fseek(pf, (id)*sizeof(Atividade), SEEK_SET);
    if(fwrite(&atv, sizeof(Atividade), 1, pf) != 1){
        retorno = 0;
    }else {
        retorno = 1;
    }
    fclose(pf);

    return retorno;

}

/* funcAtividade */


int cadastroFuncAtividadeCRUD(FuncAtividade funcAtv, int enty){

    FILE *pf;
    int index = 0;
    abrirArquivo(enty, "a+b", &pf);

    fseek(pf, 0, SEEK_END);

    if(fwrite(&funcAtv, sizeof(FuncAtividade), 1, pf) != 1){
        index = 0;
    }else {
        index = 1;
    }
    fclose(pf);

    return index;

}

void carregaFuncAtividadesVetor(int enty, FuncAtividade funcAtv[]){

    FILE *pf;
    int index = 0;
    abrirArquivo(enty, "a+b", &pf);
    fseek(pf, 0, SEEK_SET);
    memset(funcAtv, 0, sizeof(FuncAtividade));


    do{
            if(fread(&funcAtv[index], sizeof(FuncAtividade), 1, pf) == 1){
                index++;
            }


    }while(!feof(pf));

    fclose(pf);

}

void listaFuncAtividadeCRUD(int ID, FuncAtividade funcAtv[], Atividade atvVec[], Detentos denVec[], int flag){
    /* Lista as atividades de um detento , ou lista os detentos que fazem uma atividade */


    system("cls");
    int result = 0, cont = 0;


    if(flag == 1){
        printf("***Lista de Atividades do Detento*** \n");
        for(result = 0; result <= Max_FuncAtividade; result++){
        if(funcAtv[result].preenchido == true, funcAtv[result].IDdetento == ID && funcAtv[result].Ativa == true){
            printf("Detento %s \nAtividade  %s \n ID Atividade %d \nInício da Atividade %s \nAvaliação da Atividade %d \nRemuneração atividade %f \nDia da Atividade %s Turno %c",
                   denVec[ID].Nome, atvVec[funcAtv[result].IDatividade].descricao, atvVec[funcAtv[result].IDatividade].ID,
                   funcAtv[result].dataAtividade,atvVec[funcAtv[result].IDatividade].avaliacao,
                   atvVec[funcAtv[result].IDatividade].remuneracao, funcAtv[result].diaSemana, funcAtv[result].turno);
            cont++;
        }
    }

    printf("******** A busca retornou %d Atividades ********* \n", cont);

    }else{
        printf("***Lista de Detentos por atividades *** \n");

        for(result = 0; result <= Max_FuncAtividade; result++){
        if(funcAtv[result].preenchido == true, funcAtv[result].IDatividade == ID && funcAtv[result].Ativa == true){

            printf("Atividade %s \nDescrição  %s \nInício da Atividade %s \nAvaliação da Atividade %d \nRemuneração atividade %f \nDia da Semana %s Turno %c", atvVec[ID].descricao, denVec[funcAtv[result].IDdetento].Nome, funcAtv[result].dataAtividade, atvVec[ID].avaliacao, atvVec[ID].remuneracao, funcAtv[result].diaSemana, funcAtv[result].turno);
            cont++;
        }
    }

    printf("******** A busca retornou %d Atividades ********* \n", cont);
    }


}



int  alteraFuncAtvCRUD(FuncAtividade funcAtv, int id){

    FILE *pf;
    int retorno = 0;
    abrirArquivo(3, "r+b", &pf);


    rewind(pf);



    fseek(pf, (id)*sizeof(Atividade), SEEK_SET);

    if(fwrite(&funcAtv, sizeof(FuncAtividade), 1, pf) != 1){
        retorno = 0;
    }else {
        retorno = 1;
    }
    fclose(pf);

    return retorno;

}

int retornaProximoIdFuncAtiv(int enty, FuncAtividade funcAtv[]){

    int result = 0, index;

    for(index = 0; index < Max_FuncAtividade; index++){
        if(funcAtv[index].preenchido == true){
            result++;
        }else{
            break;
        }
    }

    return result;

}


int retornaFuncAtvID(int IDatividade, int IDdetento, FuncAtividade funcAtv[], char turno, char diaSemana[]){
    int cont = 0, index = 0;

    for(index = 0; index <= Max_FuncAtividade; index++){
        if(funcAtv[index].IDdetento == IDdetento && funcAtv[index].IDatividade == IDatividade && funcAtv[index].turno == turno && strcpy(funcAtv[index].diaSemana, diaSemana)){
            cont = funcAtv[index].IDfuncAtv;

        }
    }

    return cont;
}
