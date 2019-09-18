#include "FuncoesUnidade.c"
#include "FuncoesIngles.c"
#include "FuncoesArvoreBB.c"

int main (void){
  int Menu, Key, Inicializacao = 0;
  char String[500], Unidade_V[200], ListaEng_V[200], Arvore_V[200], Pesquisa[100];
  Unidade *RaizUnidade, *Aux;
  ArvorePortugues *RaizArvore;
  ListaIngles *RaizListaIngles;
  RaizArvore = CriaArvorePT();
  RaizListaIngles = CriaLista_LI();
  RaizUnidade = CriaLista_Unidade();

  while(1){
    Menu = MenuPrincipal();
    switch (Menu) {
      case 1:
        memset (&Unidade_V, 0, sizeof(Unidade_V));
        memset (&ListaEng_V, 0, sizeof(ListaEng_V));
        memset (&Arvore_V, 0, sizeof(Arvore_V));
        printf("%% ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", String);
        SeparacaoString(String, Unidade_V, ListaEng_V, Arvore_V);
        if (Inicializacao == 0){
          InserindoPalavras(RaizArvore, Arvore_V);
          RaizListaIngles = InserirListaIngles(RaizListaIngles, ListaEng_V, RaizArvore);
          RaizUnidade = InserirUnidade(RaizUnidade, Unidade_V, RaizListaIngles);
        }else{
          Aux = BuscarUnidade(RaizUnidade)
          if (Aux != NULL){
            RaizUnidade->Conteudo = CriaLista_LI();
            RaizUnidade = InserirUnidade(Aux, Unidade_V, InserirListaIngles(RaizUnidade->Conteudo, ListaEng_V, RaizArvore));
          }
        }
        break;

      case 2:
        printf("Informe o nome da UNIDADE: ");
        scanf("%s", Pesquisa);
        MostraUnidade(RaizUnidade, Pesquisa);
        break;
      case 3:
        break;
      case 0:
        exit(1);
    }
  }
  return 0;
}
