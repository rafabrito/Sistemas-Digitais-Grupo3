#include <stdio.h>
#include <stdlib.h>

int main()
{

  FILE *matriz1;
  FILE *matriz2;
  FILE *resultado;
  int i, j, a, b;
  

  matriz1 = fopen("matriz1.txt","r"); // abre arquivo texto para leitura
  matriz2 = fopen("matriz2.txt","r"); // abre arquivo texto para leitura
  resultado = fopen("resultado.txt","w"); // abre ou cria arquivo texto para escrita
  
  fscanf(matriz1, "%d", &a);  //leitura da dimenção da matriz 1
  fscanf(matriz2, "%d", &b);  //leitura da dimenção da matriz 2

  int (*aa)[a] = malloc(a * sizeof(*aa)); // Alocação de espaço na memória para a matriz 1
  int (*bb)[a] = malloc(a * sizeof(*bb)); // Alocação de espaço na memória para a matriz 2
  int (*res)[a] = malloc(a * sizeof(*res)); // Alocação de espaço na memória para a matriz resultado
  

  if(a==b) {

    for(i = 0 ; i < a ; i++){
      for(j = 0 ; j < a ; j++){
        fscanf(matriz1, "%d", &aa[i][j]); // leitura dos valores da matriz 1
        res[i][j] = 0; // inicializando os valores da matriz resultado com 0
      }
    }

    for(i = 0 ; i < a ; i++){
      for(j = 0 ; j < a ; j++){
        fscanf(matriz2, "%d", &bb[i][j]); // leitura dos valores da matriz 2
      }
    }

    //-----------------------------multiplicação

    for(i = 0 ; i < a ; i++){ 
      for(j = 0 ; j < a ; j++){
        for(b = 0 ; b < a ; b++){
          res[i][j] += aa[i][b] * bb[b][j]; // somando e atribuindo valores da multiplicação da linha da matriz 1 com a coluna da matriz 2 
        }
      } 
    }

    //------------------------------------------


    for(i = 0 ; i < a ; i++){
      for(j = 0 ; j < a ; j++){
        fprintf(resultado, "%d\t", res[i][j]); // escrita dos valores da matriz resultado num arquivo texto
      }
        fprintf(resultado, "\n"); 
    } 
        
  } else {
    fprintf(resultado, "matrizes com tamanhos diferentes\n"); 
  }

  free(aa); // libera espaço alocado
  free(bb); // libera espaço alocado
  free(res); // libera espaço alocado

  fclose(matriz1); // fecha arquivo texto
  fclose(matriz2); // fecha arquivo texto
  fclose(resultado); // fecha arquivo texto

}
