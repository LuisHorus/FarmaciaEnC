#include <stdio.h>
#include <string.h>
#include "lib/caracter.h"
#define USER "admin"
#define PASSWORD "123"
#include <stdlib.h>
#include <stdio_ext.h> //!libreria Para Limpiar BUFFER

void Datos();
void Proveedores();
void Productos();
int Menu();

int main()
{
    char user[80];
    char clave[80];
    int opc_main=0;
    int contador=0;

    Datos();
    do
    {
        printf("\n\t\t Usuario\n");
        printf("\t\t");
        scanf("%s", user);

        printf("\t\t Clave\n");
        printf("\t\t");
        scanf("%s", clave);
        
        __fpurge(stdin); //!Limpiar Buffer Importante

        
            if (strcmp(user, USER) == 0 && strcmp(clave, PASSWORD) == 0){   
                     
                Datos();
                printf("\t\nAcceso Permitido\n");
                __fpurge(stdin); //!Limpiar Buffer Importante
                Menu();
                break; // Para Salir del bucle Do
            
            }else { contador++; //Cuenta el numero de intentos
                    system("clear");
                if (contador<3) {       
                printf("\n Usuario y/o Clave Incorrectos\n");
                printf("\t\t\t\t Lleva %i intentos de 3\n\n\n\n",contador);
                printf("\n Presione la tecla ENTER para continuar.........\n");
                getchar();
                __fpurge(stdin); //!Limpiar Buffer Importante
                } else{  printf("Demasiados Intentos\n");}   
                __fpurge(stdin); //!Limpiar Buffer Importante      
                }

    } while (contador<3);
        
    

    return 0;
}

void Datos()
{
    system("clear");
    Wsize();
    printf("\n\t\t\tProyecto Farmacia \t\t Por: Luis Escobedo\n");
    Wsize();
}

int Menu()
{

    int opc = 0;

    printf("\t\t1.- Proveedores\n");
    printf("\t\t2.- Productos\n");
    printf("\t\t3.- Nuevos productos\n");
    printf("\t\t4.- Nuevos Proveedores\n");
    printf("\t\t5.- Venta\n");
    printf("\t\t6.- Facturar\n");
    printf("\t\t Digite una opcion 1-6 \n");
    scanf("%i", &opc);
    
    switch (opc)
    {

    case 1:
        // Proveedores();
        break;
    case 2:
        // Productos();
        break;

    case 3:
        // Productos();
        break;

    case 4:
        // Productos();
        break;

    case 5:
        // Productos();
        break;

    case 6:
        // Productos();
        break;

    default:
        system("clear");
        printf("Opcion Invalida\n Intente Nuevamente Porfavor\n");
        
        Menu();
        __fpurge(stdin);
        break;
    }

    return 0;
}