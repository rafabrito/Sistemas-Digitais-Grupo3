#include <stdio.h>
#include <stdlib.h>

extern int mulMatriz(int lin, int col, int matrizA[lin][col], int matrizB[lin][col], int res[lin][col]);

int main()
{

  FILE *matriz1;
  FILE *matriz2;
  FILE *resultado;
  int i, j, a, b;
  

  matriz1 = fopen("matriz1.txt","r");
  matriz2 = fopen("matriz2.txt","r");
  resultado = fopen("resultado.txt","w");

  fscanf(matriz1, "%d", &a);
  fscanf(matriz2, "%d", &b);

  int aa[a][a], bb[a][a], res[a][a];

  if(a==b) {

    for(i = 0 ; i < a ; i++){
      for(j = 0 ; j < a ; j++){
        fscanf(matriz1, "%d", &aa[i][j]);
        res[i][j] = 0;
        }
      }


    for(i = 0 ; i < a ; i++){
      for(j = 0 ; j < a ; j++){
        fscanf(matriz2, "%d", &bb[i][j]);
        }
      }

      //-----------------------------multiplicação

      mulMatriz(a, a, aa, bb, res);

      //------------------------------------------


     for(i = 0 ; i < a ; i++){
      for(j = 0 ; j < a ; j++){
        fprintf(resultado, "%d\t", res[i][j]);
        }
        fprintf(resultado, "\n");
      }
  } else {
    fprintf(resultado, "matrizes com tamanhos diferentes\n");
  }

  fclose(matriz1);
  fclose(matriz2);
  fclose(resultado);

}
