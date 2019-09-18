#include "Biblioteca.h"

struct NO{
  char Nome[100];
  struct NO *dir;
  struct NO *esq;
};

void InserindoPalavras(ArvorePortugues *Raiz, char *NomeS){
  char Nome[100];
  int x = 0, y = 0, Key;
  while(NomeS[x] != '\0'){
    if (NomeS[x] == ','){
      strcat(Nome, "\0");
      Key = InsereArvorePT(Raiz, Nome);
      memset (&Nome, 0, sizeof(Nome));
      y = 0;
      x++;
    }
    Nome[y] = NomeS[x];
    x++;
    y++;
  }
  Key = InsereArvorePT(Raiz, Nome);
}

ArvorePortugues *CriaArvorePT(){
  ArvorePortugues *Raiz;
	Raiz = (ArvorePortugues*)malloc(sizeof(ArvorePortugues));
	if (Raiz != NULL){
		*Raiz = NULL;
	}
	return Raiz;
}

void emOrdem_ArvorePortugues(ArvorePortugues *Raiz){
	if (*Raiz != NULL){
		emOrdem_ArvorePortugues(&((*Raiz)->esq));
		printf("  - %s\n", (*Raiz)->Nome);
		emOrdem_ArvorePortugues(&((*Raiz)->dir));
	}
}

int InsereArvorePT(ArvorePortugues *Raiz, char *Nome){
	if (Raiz == NULL){
		return 0;
	}
	struct NO* novo;
	novo = (struct NO*)malloc(sizeof(struct NO));
	if (novo == NULL){
		return 0;
	}
  strcpy(novo->Nome, Nome);
	novo->dir = NULL;
	novo->esq = NULL;
	if (*Raiz == NULL){
		*Raiz = novo;						//Quando a arvore nao possui elementos
	}else{
		struct NO *atual = *Raiz, *ant = NULL;
		while(atual != NULL){
			ant = atual;
			if (strcmp(atual->Nome, Nome) == 0){
				free(novo);					//O valor já esxiste na arvore!
				return 0;
			}
			if (strcmp(atual->Nome, Nome) < 0){
        atual = atual->dir;
			}else{							//Descendo a arvore de acordo com o valor.
      	atual = atual->esq;
			}
		}
		if (strcmp(ant->Nome, Nome) < 1){
      // printf("Estou adicionando o nome (%s) a DIREITA de %s\n", Nome, ant->Nome);
			ant->dir = novo;
		}else{
      // printf("Estou adicionando o nome (%s) a ESQUERDA de %s\n", Nome, ant->Nome);
			ant->esq = novo;
		}
	}
	return 1;
}
