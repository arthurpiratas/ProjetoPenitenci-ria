#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void menuCadastros(Detentos denVec[], Penas penVec[], Atividade atvVec[],  Visitantes visVec[]);
void menuCadastroDetento(Detentos denVec[], Penas penVec[]);
void menuCadastroPena(Penas penVec[]);
void menuCadastroAtividade(Atividade atvVec[]);
void menuGereciamentoAtividade(Detentos denVec[], Atividade atvVec[], FuncAtividade fncAtvVec[]);
void menuCadastroVisitantes(Visitantes visVec[]);
void menuGereciamentoVisitas(Detentos denVec[], Visitas visitaVec[], Visitantes visVec[]);


#endif // MENU_H_INCLUDED
