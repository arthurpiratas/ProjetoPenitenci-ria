#ifndef VALIDACOES_H_INCLUDED
#define VALIDACOES_H_INCLUDED



int validaString(char String[]);
int validaIntPositivo(int numero);
void limpaVetor(char String[]);
int retornarIDaleatorio();
int verificaDetentoExiste(char stringN[], Detentos denVec[]);
void copiaDetentoParaVetor(Detentos den, Detentos denVec[]);
int verificaDetentoExisteCPF(long int CPF, Detentos denVec[], int atual);
int verificaDetentoExisteCPFcdt(long int CPF, Detentos denVec[]);
int verificaPenaExiste(int IDpena, Penas penVec[]);
void copiaPenaParaVetor(Penas pen, Penas penVec[]);
int verificaDecsPenaExiste(char stringP[], Penas penVec[]);
int verificaAtividadeExiste(int ID, Atividade atvVec[]);
int verificaAtividadeAlocada(FuncAtividade funatv[], FuncAtividade atv);
int verificaAtividadeExisteDesc(char stringA[], Atividade atvVec[]);

#endif // VALIDACOES_H_INCLUDED
