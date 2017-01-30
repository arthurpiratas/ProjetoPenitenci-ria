#ifndef NEGOCIO_H_INCLUDED
#define NEGOCIO_H_INCLUDED

void cadastroDetento(Detentos denVec[], Penas penVec[]);
void listaDetentos(Detentos denVec[], Penas penVec[]);
void alteraDetento(Detentos denVec[], Penas penVec[]);
void excluiDetento(Detentos denVect[], Penas penVec[]);
void ConsultaDetentoNome(Detentos denVec[], Penas penVec[]);

void cadastroPena(Penas penvec[]);
void listaPenas(Penas penVec[]);
void alteraPena(Penas penVec[]);
void consultaPenaID(Penas penVec[]);

void cadastraAtividade(Atividade atvVec[]);
void listarAtividade(Atividade atvVec[]);
void consultaAtividade(Atividade atvVec[]);
void alteraAtividade(Atividade atvVec[]);

void cadastroFuncAtividade(FuncAtividade funcAtvVec[], Atividade atvVec[], Detentos denVec[]);
void listaFuncAtvividadeDEN(FuncAtividade funcAtv[], Atividade atvVec[], Detentos denVec[], int flag);
void excluiAtividadeDetento(FuncAtividade funcAtvVec[], Detentos denVec[], Atividade atvVec[]);

void cadastraVisitantes(Visitantes visVec[]);
void listaVisitantes(Visitantes visVec[]);
void alteraVisitantes(Visitantes visVec[]);
void excluiVisitantes(Visitantes visVec[]);

void cadastraVisita(Visitas visitaVec[], Visitantes visVec[], Detentos denVec[]);
void listaVisitas(Detentos denVec[], Visitantes visVec[], Visitas visitaVec[]);
void alteraVisitas(Visitas visitaVec[], Visitantes visVec[], Detentos denVec[]);
void excluirVisitas(Visitas visitaVec[], Visitantes visVec[], Detentos denVec[]);
#endif // NEGOCIO_H_INCLUDED
