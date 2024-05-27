#include <stdio.h>
#include <Windows.h>
#include <string.h>


int credenciales(char user[20], char password[20]){
  //user: luis.pozo / contra: luis123
  //user: marti.damian / contra: marti123
  //user: sari.chiribog / contra: sari123
  
  if(strcmp(user, "luis.pozo") == 0 && strcmp(password, "luis123") == 0){
    printf("Verificando");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf("\nBienvenido Luis Pozo!\n");
    Sleep(1000);
    printf("\n");
  }else if (strcmp(user, "marti.damian") == 0 && strcmp(password, "marti123") == 0)
  {
    printf("Verificando");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf("\nBienvenida Martina Damian!\n");
    Sleep(1000);
    printf("\n");
  }else if (strcmp(user, "sari.chiriboga") == 0 && strcmp(password, "sari123") == 0)
  {
    printf("Verificando");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf("\nBienvenida Sara Chiriboga!\n");
    Sleep(1000);
    printf("\n");
  }else{
    printf("Verificando");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf("\nUsuario y/o contrase%ca no encontrados :(\n", 164);
    return 0;
  }
  return 1;
}

void icon(){
    printf("%c%c%c%c%c %c%c%c%c%c%c %c%c%c%c%c\n", 201, 219, 219, 219, 219, 201, 219, 219, 219, 219, 219, 201, 219, 219, 219, 219);
    printf("%c%c%c   %c%c%c  %c %c%c%c  %c%c\n", 186, 219, 219, 186, 219, 219, 219, 186, 219, 219, 219, 219);
    printf("%c%c%c   %c%c%c%   c%c%c %c%c%c  %c%c\n", 186, 219, 219, 186, 219, 219, 219, 219, 219, 186, 219, 219, 219, 219);
    printf("%c%c%c   %c%c%c    %c%c%c  %c%c\n", 186, 219, 219, 186, 219, 219, 186, 219, 219, 219, 219);
    printf("%c%c%c%c%c %c%c%c    %c%c%c%c%c\t\n", 186, 219, 219, 219, 219, 186, 219, 219, 186, 219, 219, 219, 219);
    printf("%c%c%c%c%c %c%c%c    %c%c%c%c%c\n" , 200, 205, 205, 205, 188, 200, 205, 188, 200, 205, 205, 205, 188);
    printf("====================\n");
    printf("      VINYLS\n");
    printf("====================\n");
}
