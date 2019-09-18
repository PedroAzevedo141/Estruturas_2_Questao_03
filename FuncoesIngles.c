#include "Biblioteca.h"

struct ListaIngles{
  char Nome[100];
  ArvorePortugues *Arv;
  ListaIngles *Prox;
};

ListaIngles * CriaLista_LI(){
  return NULL;
}

ListaIngles * InserirListaIngles(ListaIngles *Lista, char *Nome, ArvorePortugues *Raiz){
  ListaIngles *novo;
  novo = (ListaIngles*)malloc(sizeof(ListaIngles));
  strcpy(novo->Nome, Nome);
  novo->Prox = NULL;
  novo->Arv = Raiz;
  if (Lista == NULL){
    Lista = novo;
  }else{
    ListaIngles *atual = Lista, *ant = NULL;
    while(atual != NULL){
      ant = atual;
      atual = atual->Prox;
    }
    ant->Prox = novo;
  }
  return Lista;
}

void MostrarListaIngles(ListaIngles *Lista){
  ListaIngles *Aux = Lista;
  while(Aux != NULL){
    emOrdem_ArvorePortugues(Aux->Arv);
    printf("Sao EQUIVALENTES a -> %s\n", Aux->Nome);
    Aux = Aux->Prox;
  }
}
