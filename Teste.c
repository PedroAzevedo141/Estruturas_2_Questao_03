#include <stdio.h>
#include <string.h>//necessário para strcat
int main (void)
{
  char str[10];
  strcat(str, "d");
  strcat(str, "e");
  //Concatena a string " de C" com o conteúdo da string str

  printf("str = %s\n", str);
  //Será exibido curso de C

  return 0;
}
