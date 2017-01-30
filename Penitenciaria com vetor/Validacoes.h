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
int verificaDetentoExisteID(int IDden, Detentos denVec[]);
int verificaPenaExiste(int IDpena, Penas penVec[]);
void copiaPenaParaVetor(Penas pen, Penas penVec[]);
int verificaDecsPenaExiste(char stringP[], Penas penVec[]);
int verificaAtividadeExiste(int ID, Atividade atvVec[]);
int verificaAtividadeAlocada(FuncAtividade funatv[], FuncAtividade atv);
int verificaAtividadeExisteDesc(char stringA[], Atividade atvVec[]);
int verificaVisitanteExisteNome(char stringN[], Visitantes visVec[]);
int verificaVisitantesExisteCPF(long int  CPF, Visitantes visVec[]);
void copiaVisitantesParaVetor(Visitantes vis, Visitantes visVec[]);
int verificaVisitaAgendadaPorSala(char data[], int sala, Visitas vecVis[]);
void copiaVisitasParaVetor(Visitas vis, Visitas visVec[]);
int verificaVisitantesExisteID(int  ID, Visitantes visVec[]);
int verificaVisitaExisteID(int  ID, Visitas visVec[]);
int verificaDataMenorMaior(char data1[20], char data2[20]);

#endif // VALIDACOES_H_INCLUDED
