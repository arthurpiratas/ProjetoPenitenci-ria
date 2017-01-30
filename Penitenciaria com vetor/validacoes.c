#include <stdio.h>
#include <string.h>
#include "Entidade.h"
#include "Validacoes.h"
#include <stdlib.h>
#define true 1
#define false 0
#include <time.h>
#define MAX_Detentos 200
#define Max_Penas 100
#define Max_Atividade 100
#define Max_FuncAtividade 500
#define Max_Visitantes 200
#define Max_Visitas 500


int validaString(char String[]){
    int a = 0;
    if(strcmp(String, "") != 0){
        a = 1;
    }
    return a;
}

int validaIntPositivo(int numero){
    int a = 0;

    if(numero >= 0){
        a = 1;
    }
    return a;
}

void limpaVetor(char string[]){
    strcpy(string, "");
}

int retornarIDaleatorio(){

srand(time(NULL));

int rando = rand()%200;

return rando;

}

int verificaDetentoExiste(char stringN[], Detentos denVec[]){

    int index, result = 0;

        for(index = 0; index <= MAX_Detentos; index++){
           if(strcmp(denVec[index].Nome, stringN) == 0){
                result = 1;
                break;
            }
        }

        return result;
}

int verificaDetentoExisteID(int IDden, Detentos denVec[]){

    int index, result = 0;

        for(index = 0; index <= MAX_Detentos; index++){
           if(denVec[index].ID ==  IDden){
                result = 1;
                break;
            }
        }

        return result;
}

int verificaDetentoExisteCPF(long int CPF, Detentos denVec[], int atual){

    int index, result = 0;

        for(index = 0; index <= MAX_Detentos; index++){
           if(CPF == denVec[index].loginCPF){
                if(index == atual){
                    result = 0;
                }else{
                    result = 1;
                }

                break;
            }
        }

        return result;
}

int verificaDetentoExisteCPFcdt(long int CPF, Detentos denVec[]){

    int index, result = 0;

        for(index = 0; index <= MAX_Detentos; index++){
           if(CPF == denVec[index].loginCPF){
                result = 1;
                break;
            }
        }

        return result;
}


void copiaDetentoParaVetor(Detentos den, Detentos denVec[]){

    int ID = den.ID;

    strcpy(denVec[ID].Nome, den.Nome);
    denVec[ID].ID = den.ID;
    strcpy(denVec[ID].dataNascimento, den.dataNascimento);
    strcpy(denVec[ID].dataSaida, den.dataSaida);
    strcpy(denVec[ID].dataEntrada, den.dataEntrada);
    strcpy(denVec[ID].nomeMae, den.nomeMae);
    strcpy(denVec[ID].escolaridade, den.escolaridade);
    denVec[ID].numeroAla = den.numeroAla;
    denVec[ID].telefone = den.telefone;
    denVec[ID].IDpena = den.IDpena;
    denVec[ID].ativo = den.ativo;
    denVec[ID].preenchido = den.preenchido;
    strcpy(denVec[ID].Profissao, den.Profissao);
    denVec[ID].numeroQuarto = den.numeroQuarto;
    denVec[ID].loginCPF = den.loginCPF;

}

int verificaPenaExiste(int IDpena, Penas penVec[]){

    int index, result = 0;

        for(index = 0; index <= Max_Penas; index++){
           if(penVec[index].ID ==  IDpena){
                result = 1;
                break;
            }
        }

        return result;
}

int verificaDecsPenaExiste(char stringP[], Penas penVec[]){

    int index, result = 0;

        for(index = 0; index <= Max_Penas; index++){
           if(strcmp(penVec[index].descricao, stringP) == 0){
                result = 1;
                break;
            }
        }

        return result;
}

void copiaPenaParaVetor(Penas pen, Penas penVec[]){

    int ID = pen.ID;

    strcpy(penVec[ID].descricao, pen.descricao);
    penVec[ID].ID = pen.ID;
    strcpy(penVec[ID].Regiume, pen.Regiume);
    penVec[ID].grau = pen.grau;
    penVec[ID].preenchido = pen.preenchido;

}


int verificaAtividadeExiste(int ID, Atividade atvVec[]){

    int result = 0, cont;

     for(cont = 0; cont <= Max_Atividade; cont++){
        if(atvVec[cont].ID == ID){
            result++;
            break;
        }
     }

     return result;
}

int verificaAtividadeExisteDesc(char stringA[], Atividade atvVec[]){

    int index, result = 0;

        for(index = 0; index <= Max_Atividade; index++){
           if(strcmp(atvVec[index].descricao, stringA) == 0){
                result = 1;
                break;
            }
        }

        return result;
}

void copiaAtividadeParaVetor(Atividade atv, Atividade atvVec[]){

    int ID = atv.ID;
    strcpy(atvVec[ID].descricao, atv.descricao);
    atvVec[ID].ID = atv.ID;
    atvVec[ID].avaliacao = atv.avaliacao;
    atvVec[ID].remuneracao = atv.remuneracao;
    atvVec[ID].preenchido = atv.preenchido;
    atvVec[ID].ativo = atv.ativo;

}

int verificaAtividadeAlocada(FuncAtividade funatv[], FuncAtividade atv){

    int result = 0, cont;

    for(cont = 0; cont <= Max_FuncAtividade; cont++){
        if(funatv[cont].IDdetento == atv.IDdetento && funatv[cont].IDatividade == atv.IDatividade && (strcmp(funatv[cont].diaSemana, atv.diaSemana) == 0) && funatv[cont].Ativa == true && funatv[result].turno == atv.turno) {
            result++;
        }
    }

    return result;
}



void copiaFuncAtividadeParaVetor(FuncAtividade funcAtv, FuncAtividade funcAtvVec[]){


    int ID = funcAtv.IDfuncAtv;
    strcpy(funcAtvVec[ID].dataAtividade, funcAtv.dataAtividade);
    strcpy(funcAtvVec[ID].diaSemana,  funcAtv.diaSemana);
    funcAtvVec[ID].turno = funcAtv.turno;
    funcAtvVec[ID].IDatividade = funcAtv.IDatividade;
    funcAtvVec[ID].IDdetento = funcAtv.IDdetento;
    funcAtvVec[ID].preenchido = funcAtv.preenchido;
    funcAtvVec[ID].Ativa = funcAtv.Ativa;


}

int verificaVisitanteExisteNome(char stringN[], Visitantes visVec[]){

    int index, result = 0;

        for(index = 0; index <= Max_Visitantes; index++){
           if(strcmp(visVec[index].Nome , stringN) == 0){
                result = 1;
                break;
            }
        }

        return result;
}

int verificaVisitantesExisteCPF(long int  CPF, Visitantes visVec[]){

    int result = 0, cont;

     for(cont = 0; cont <= Max_Visitantes; cont++){
        if(visVec[cont].CPF == CPF){
            result++;
            break;
        }
     }

     return result;
}

int verificaVisitantesExisteID(int  ID, Visitantes visVec[]){

    int result = 0, cont;

     for(cont = 0; cont <= Max_Visitantes; cont++){
        if(visVec[cont].ID == ID){
            result++;
            break;
        }
     }

     return result;
}


void copiaVisitantesParaVetor(Visitantes vis, Visitantes visVec[]){

    int ID = vis.ID;
    strcpy(visVec[ID].Nome, vis.Nome);
    visVec[ID].ID = vis.ID;
    strcpy(visVec[ID].dataNascimento, vis.dataNascimento);
    strcpy(visVec[ID].escolaridade, vis.escolaridade);
    strcpy(visVec[ID].profissao, vis.profissao);
    visVec[ID].preenchido = vis.preenchido;
    visVec[ID].ativo = vis.ativo;

}

int verificaVisitaAgendadaPorSala(char data[], int sala, Visitas vecVis[]){

    int cont = 0;
    int retorno = 0;

    for(cont = 0; cont <= Max_Visitas; cont++){
        if((strcmp(data, vecVis[cont].dataVisita) == 0) && sala == vecVis[cont].salaVisista && sala <=  15){
            retorno = 1;
            break;
        }
    }

    return retorno;
}

void copiaVisitasParaVetor(Visitas vis, Visitas visVec[]){

    int ID = vis.IDvisitas;
    visVec[ID].IDdetento = vis.IDdetento;
    visVec[ID].IDvisitantes = vis.IDvisitantes;
    strcpy(visVec[ID].dataVisita, vis.dataVisita);
    visVec[ID].salaVisista = vis.salaVisista;
    visVec[ID].preenchido = vis.preenchido;

}

int verificaVisitaExisteID(int  ID, Visitas visVec[]){

    int result = 0, cont;

     for(cont = 0; cont <= Max_Visitas; cont++){
        if(visVec[cont].IDvisitas == ID){
            result++;
            break;
        }
     }

     return result;
}

int verificaDataMenorMaior(char data1[20], char data2[20]){

    /* 1 - Data 1 menor que data 2 */
    /* 2 - Data 1 maior que data 2 */
    /* 3 - Data 1 igual a data 2 */

    int cont = 0;

    time_t t1;
    time_t t2;

    struct tm tm;
    int ano, mes;

    sscanf( data1, "%d.%d.%d", &tm.tm_mday, tm.tm_mon, tm.tm_year);

    t1 = mktime(&tm);

    sscanf( data2, "%d.%d.%d", &tm.tm_mday, tm.tm_mon, tm.tm_year);

    t1 = mktime(&tm);

    if(data1 < data2){
        cont = 1;
    } else if(data1 > data2){
        cont = 2;
    }else{
        cont = 3;
    }

    return cont;

}


