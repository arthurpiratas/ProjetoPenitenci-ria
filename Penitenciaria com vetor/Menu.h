#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void menuCadastros(Detentos denVec[], Penas penVec[], Atividade atvVec[]);
void menuCadastroDetento(Detentos denVec[], Penas penVec[]);
void menuCadastroPena(Penas penVec[]);
void menuCadastroAtividade(Atividade atvVec[]);
void menuGereciamentoAtividade(Detentos denVec[], Atividade atvVec[], FuncAtividade fncAtvVec[]);


#endif // MENU_H_INCLUDED
