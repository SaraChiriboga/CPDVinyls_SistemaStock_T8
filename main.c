/*
EJERCICIO DE PROGRAMACIÓN

Se desea desarrollar un sistema de inventarios, el cual implemente las siguientes funcionalidades:
- Ingresar, editar y eliminar productos.
- Listar productos ingresados.
Los productos ingresados deberán tener mínimo las siguientes variables:
- Nombre del producto
- Cantidad
- Precio*/

#include <stdio.h>
#include <string.h>
#include "inicio.h"
#include "impresiondelmenu.h"

int main(void) {
  int cantidad[100], i = 0, siono, lim, funcionalidades, editar, acceso;
  char producto[100][20], usuario[20], contra[20];
  float precio[100], iva[100], preciva[100];
  
  //ACCESO LIMITADO A LA BASE DE DATOS DE LA TIENDA
  icon();
  repetiracceso:
  printf("User: ");
  scanf("%s", usuario);
  printf("Password: ");
  scanf("%s", contra);

  acceso = credenciales(usuario, contra);
  if(acceso == 0){
    goto repetiracceso;
  }
  //MENÚ DE FUNCIONALIDADES
  nuevo:
  printf("Ingrese el nombre del producto %d: ", i + 1);
  scanf("%s", producto[i]);
  printf("Ingrese la cantidad en stock: ");
  scanf("%d", &cantidad[i]);
  printf("Ingrese el precio del producto: ");
  scanf("%f", &precio[i]);

  iva[i]= precio[i] * (0.15) ;
  preciva[i]= precio[i] * 1.15;

  printf("Desea ingresar otro producto?\n1. Si\n2. No\n");
  printf("Respuesta: ");
  scanf("%d", &siono);
  if (siono == 1){
    i++;
    goto nuevo;
  }
  lim = i;

  //Primero va el numero que tiene en la lista, luego el nombre, la cantidad y el precio
  printf("=================================================================");
  printf("\nProductos ingresados:\n");  
  imprimirmenu(producto, cantidad, precio,iva, preciva, lim);

  funcionalidadnueva:
  printf("\nDesea editar, agregar o eliminar un producto:\n1. Editar\n2. Agregar\n3. Eliminar\n");
  printf("Respuesta: ");
  scanf("%d", &funcionalidades);
  switch(funcionalidades){
    case 1: //editar producto
      printf("Ingrese el numero del producto que desea editar: ");
      scanf("%d", &i);
      printf("Desea editar el nombre, la cantidad o el precio?\n1. Nombre\n2. Cantidad\n3. Precio\n");
      printf("Respuesta: ");
      scanf("%d", &editar);
      //¿Que vamos a editar?
      switch(editar){
        case 1:
          printf("Ingrese el nuevo nombre del producto: ");
          scanf("%s", producto[i - 1]);
          break;
        case 2:
          printf("Ingrese la nueva cantidad en stock: ");
          scanf("%d", &cantidad[i - 1]);
          break;
        case 3:
          printf("Ingrese el nuevo precio del producto: ");
          scanf("%f", &precio[i - 1]);
          iva[i-1]= precio[i-1] * 0.15 ;
          preciva[i-1]= precio[i-1]+iva[i-1];
          break;
      }
      //imprimir cambios
      printf("=================================================================\n");
      printf("Registro actualizado:\n");
      printf("\nProductos ingresados:\n");  
      imprimirmenu(producto, cantidad, precio,iva, preciva, lim);
      break;      
    case 2: //Ingresar un nuevo producto
      repetir:
      i++;
      printf("Ingrese el nombre del producto que desea agregar: ");
      scanf("%s", producto[i]);
      printf("Ingrese la cantidad en stock: ");
      scanf("%d", &cantidad[i]);
      printf("Ingrese el precio del producto: ");
      scanf("%f", &precio[i]);
      iva[i]= precio[i] * 0.15 ;
      preciva[i]= precio[i]+iva[i];
      
      printf("Desea agregar otro producto?\n1. Si\n2. No\n");
      printf("Respuesta: ");
      scanf("%d", &siono);
      if (siono == 1){
        goto repetir;
      }
      lim = i;

      //imprimir cambios
      printf("=================================================================");
      printf("\nRegistro actualizado:\n");
      printf("\nProductos ingresados:\n");  imprimirmenu(producto, cantidad, precio,iva, preciva, lim);
      break;
    case 3:
      printf("Ingrese el numero del producto que desea eliminar: ");
      lim = i;
      scanf("%d", &i);
      printf("=================================================================");
      printf("\nEl producto %s fue eliminado exitosamente!\n", producto[i - 1]);
      printf("=================================================================\n");
      for(i = i - 1; i < lim; i++){
        strcpy(producto[i], producto[i + 1]);
        cantidad[i] = cantidad[i + 1];
        precio[i] = precio[i + 1];
        iva[i]=iva[i+1];
        preciva[i]=preciva[i+1];
      }

      //imprimir resultados
      printf("Registro actualizado:\n");
      lim--;
      imprimirmenu(producto, cantidad, precio,iva, preciva, lim);
      
      break;
  }
  printf("\nDesea implementar otro cambio? \n1. Si\n2. No\n");
  printf("Respuesta: ");
  scanf("%d", &siono);
  if (siono == 1){
    goto funcionalidadnueva;
  }
  printf("La lista final de productos son:\n");
  imprimirmenu(producto, cantidad, precio,iva, preciva, lim);
  return 0;  
}