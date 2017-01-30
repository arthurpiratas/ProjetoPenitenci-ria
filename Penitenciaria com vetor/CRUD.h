#ifndef CRUD_H_INCLUDED
#define CRUD_H_INCLUDED

void abrirArquivo(int arquivo, char tipo[], FILE **pf);
int cadastroDetentoCRUD(Detentos den, int enty);
void carregaDetentosVetor(int enty, Detentos den[]);
void listaDetentoCRUD(Detentos den[], Penas pen[]);
int retornaProximoId(int enty, Detentos den[]);
Detentos retornaDetentoPorNome(char nome[], Detentos denVec[]);
Detentos retornaDetentoPorCPF(long int CPF, Detentos denVec[]);
Detentos retornaDetentoPorID(int ID, Detentos denVec[]);
int alteraDetentoCRUD(Detentos den, int id);
void realocaDetentos(Detentos denVec[]);

void carregaPenasVetor(int enty, Penas pen[]);
int retornaProximoIdPenas(Penas pen[]);
Penas retornaPenaDetentoPorID(int ID, Penas penVec[]);
int cadastraPenasCRUD(Penas pen, int enty);
void listaPenasCRUD(Penas pen[]);
int  alteraPenasCRUD(Penas pen, int id);

int cadastroAtividadeCRUD(Atividade atv, int enty);
void carregaAtividadesVetor(int enty, Atividade atv[]);
void listaAtividadeCRUD(Atividade atv[]);
int retornaProximoIdAtiv(int enty, Atividade atv[]);
Atividade retornaAtividadeporID(int ID, Atividade atvVec[]);
Atividade retornaAtividadeporDesc(char desc[], Atividade atvVec[]);
int  alteraAtividadeCRUD(Atividade atv, int id);

int cadastroFuncAtividadeCRUD(FuncAtividade funcAtv, int enty);
void carregaFuncAtividadesVetor(int enty, FuncAtividade funcAtv[]);
void listaFuncAtividadeCRUD(int ID, FuncAtividade funcAtv[], Atividade atvVec[], Detentos denVec[], int flag);
int  alteraFuncAtvCRUD(FuncAtividade funcAtv, int id);
int retornaProximoIdFuncAtiv(int enty, FuncAtividade funcAtv[]);
int retornaFuncAtvID(int IDatividade, int IDdetento, FuncAtividade funcAtv[], char turno, char diaSemana[]);

int cadastroVisitantesCRUD(Visitantes vis, int enty);
void carregaVisitantesVetor(int enty, Visitantes vis[]);
void listaVisitantesCRUD(Visitantes vis[]);
int retornaProximoIdVisitantes(int enty, Visitantes vis[]);
Visitantes retornaVisitantesPorCPF(long int CPF, Visitantes visVec[]);
Visitantes retornaVisitantesPorID(int ID, Visitantes visVec[]);
int  alteraVisitantesCRUD(Visitantes vis, int id);

int cadastroVisitasCRUD(Visitas visitas, int enty);
void carregaVisitasVetor(int enty, Visitas visitas[]);
void listaVisitasCRUD(Visitas visitas[], Detentos denVec[], Visitantes visVec[]);
void listaVisitasPorDetentoCRUD(Visitas visitas[], Detentos denVec[], Visitantes visVec[], int ID);
void listaVisitasDataCRUD(Visitas visitas[], Detentos denVec[], Visitantes visVec[], int flag, char data[]);
int retornaProximoIdVisitas(int enty, Visitas visita[]);
Visitas retornaVisitasPorID(int ID, Visitas visVec[]);
int  retornaVisitasID(int IdDetento, int IDVisitante, Visitas visitaVec[], char Data[], int sala);
int alteraVisitasCRUD(Visitas visitas, int id);

#endif // CRUD_H_INCLUDED
