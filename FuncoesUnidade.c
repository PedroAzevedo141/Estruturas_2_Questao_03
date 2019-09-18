#include "Biblioteca.h"

struct Unidade{
  char Nome[100];
  ListaIngles *Conteudo;
  Unidade *Prox;
};

int MenuPrincipal(){
  int Menu;
  printf("-=-=-=-=-=-=- MENU -=-=-=-=-=-=-=-\n"
  "1 - Adicionar Unidade.\n"
  "2 - Mostrar Unidades PT-EN\n"
  "3 - Mostrar Unidades EN-PT\n"
  "0 - Sair\n"
  ">>> ");
  scanf("%d", &Menu);
  return Menu;
}

void SeparacaoString(char StringPrincipal[], char *Unidade, char *ListaEng, char *Arvore){
  int x = 0, y = 0, Key = 0;
  while (StringPrincipal[x] != '\0'){
    if (Key == 0){
      if (StringPrincipal[x] == ','){
        y = 0;
        Key = 1;
      }else{
        Unidade[y] = StringPrincipal[x];
        y++;
      }
    }else if (Key == 1){
      if (StringPrincipal[x] == ':'){
        y = 0;
        Key = 2;
      }else{
        ListaEng[y] = StringPrincipal[x];
        y++;
      }
    }else if (Key == 2){
      if (StringPrincipal[x] == '.'){
        y = 0;
        Key = 3;
      }else{
        Arvore[y] = StringPrincipal[x];
        y++;
      }
    }
    x++;
  }
  strcat(Unidade, "\0");
  strcat(ListaEng, "\0");
  strcat(Arvore, "\0");
}

Unidade * CriaLista_Unidade(){
  return NULL;
}

Unidade * InserirUnidade(Unidade *Lista, char *Nome, ListaIngles *ListIng){
  int Key;
  Unidade *novo;
  novo = (Unidade*)malloc(sizeof(Unidade));
  strcpy(novo->Nome, Nome);
  novo->Prox = NULL;
  novo->Conteudo = ListIng;
  if (Lista == NULL){
    Lista = novo;
  }else{
    Unidade *atual = Lista, *ant = NULL;
    while(atual != NULL){
      Key = PreferenciaAlfabetica(Nome, atual->Nome);
      if (Key == 2){
        printf("Iguais!\n");
        free (novo);
        novo = NULL;
      }else if (Key == 1){
        if (ant == NULL){
          novo->Prox = atual;
          return novo;
        }else{
          ant->Prox = novo;
          novo->Prox = atual;
          return Lista;
        }
      }
      ant = atual;
      atual = atual->Prox;
    }
    ant->Prox = novo;
  }
  return Lista;
}

Unidade *BuscarUnidade(Unidade *Lista, char *Pesquisa){
  if (!Lista){
    printf("Essa unidade nao existe! Tente Novamente!\n");
  }else{
    Unidade *Aux = Lista;
    while(Aux != NULL){
      if (strcmp(Aux->Nome, Pesquisa) == 0){
        return Aux;
      }
    }
  }
  return NULL;
}

void MostraUnidade(Unidade *Lista, char *Pesquisa){
  if (!Lista){
    printf("Essa unidade nao existe! Tente Novamente!\n");
  }else{
    Unidade *Aux = Lista, *Key = NULL;
    while(Aux != NULL){
      if (strcmp(Aux->Nome, Pesquisa) == 0){
        Key = Aux;
        break;
      }
      Aux = Aux->Prox;
    }
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("A unidade %s possui de Vocabulario:\n", Key->Nome);
    MostrarListaIngles(Key->Conteudo);
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  }
}

int PreferenciaAlfabetica(char *Nome1, char *Nome2){
  int x = 0, Caracter01, Caracter02;
  while((Nome1[x] != '\0') && (Nome2[x] != '\0')){
    Caracter01 = (int)Nome1[x];
    Caracter02 = (int)Nome2[x];
    if (Caracter01 < Caracter02){
      return 1;
    }else if (Caracter01 == Caracter02){
      x++;
    }else{
      return 0;
    }
  }
  return 2;
}

// ListaIngles *Consulta_ListaIngles_Unidade(Unidade *Lista, char *Nome){
//   Lista = InserirUnidade(Lista, Nome);
//   Unidade *Aux = Lista;
//   while(Aux != NULL){
//     if (strcmp(Aux->Conteudo.Nome, Nome) == 0){
//       return Aux->Conteudo;
//     }
//     Aux = Aux->Prox;
//   }
// }
