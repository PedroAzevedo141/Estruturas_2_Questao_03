#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Unidade Unidade;
typedef struct NO *ArvorePortugues;
typedef struct ListaIngles ListaIngles;

// ===========- MENU PRINCIPAL -===========

int MenuPrincipal();
int PreferenciaAlfabetica(char *Nome1, char *Nome2);
void SeparacaoString(char *StringPrincipal, char *Unidade, char *ListaEng, char *Arvore);

// ===========- LISTA UNIDADE -===========

Unidade * CriaLista_Unidade();
void MostraUnidade(Unidade *Lista, char *Pesquisa);
Unidade * BuscandoUnidade(Unidade *Lista);
ListaIngles *Consulta_ListaIngles_Unidade(Unidade *Lista, char *Nome);
Unidade * InserirUnidade(Unidade *Lista, char *Nome, ListaIngles *ListIng);

//===========- LISTAS INGLES -===========

ListaIngles * CriaLista_LI();
void MostrarListaIngles(ListaIngles *Lista);
ListaIngles * BuscandoListaIngles(ListaIngles *Lista);
ListaIngles * InserirListaIngles(ListaIngles *Lista, char *Nome, ArvorePortugues *Raiz);

//===========- ARVORE PROTUGUES -===========

ArvorePortugues *CriaArvorePT();
void emOrdem_ArvorePortugues(ArvorePortugues *Raiz);
int InsereArvorePT(ArvorePortugues *Raiz, char *Nome);
void InserindoPalavras(ArvorePortugues *Raiz, char *NomeS);
