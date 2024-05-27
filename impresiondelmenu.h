#include <stdio.h>

void imprimirmenu(char pro[][20], int can[], float pre[], float iva[], float preciva[], float lim)
 {
    int i;
    
  printf("Numero\tNombre\tCantidad\tPrecio\tIVA\tTOTAL\n");
  for(i = 0; i <  lim + 1; i++){
    printf("%d\t%s\t%d\t\t%.2f\t%.2f\t%.2f\n",i + 1,pro[i],can[i],pre[i],iva[i],preciva[i]);
  }
  printf("=======================================================\n");
 }



