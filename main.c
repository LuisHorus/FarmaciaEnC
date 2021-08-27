#include <stdio.h>
#include <string.h>
#include "lib/caracter.h"
#include "lib/newProduct.h"
#define USER "admin"
#define PASSWORD "123"
#include <stdlib.h>
#include <stdio_ext.h> //!libreria Para Limpiar BUFFER
#include "lib/newProveedor.h"
#define YES "s"

//Variables Globales
int opc;
 
FILE *f; // leer archivos
char aux[200];
char decision[3];

// Declaracion de Funciones
void Datos();
int Proveedores();
void Productos();
int Menu();

int main()
{
    char user[80];
    char clave[80];
    int opc_main=0;
    int contador=0;
    int opc=0;

    Datos(); // Imprime Los datos 
    do  //Se crea este ciclo para introducir el login del usuario
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

void Datos()    //Variable que contiene los datos
{
    system("clear");
    Wsize();
    printf("\n\t\t\tProyecto Farmacia \t\t Por: Luis Escobedo\n");
    Wsize();
}

int Menu() // Menu Principal de Opciones
{

    int opc = 0;

    printf("\n\t\t1.- Proveedores\n");
    printf("\t\t2.- Productos\n");
    printf("\t\t3.- Venta\n");
    printf("\t\t4.- Facturas\n");    
    printf("\t\t5.- Salir\n");
    printf("\t\t Digite una opcion 1-5 \n");
    scanf("%i", &opc);
    
    switch (opc)
    {

    case 1:
        Proveedores();
        break;
    case 2:
        Productos();
        break;

    case 3:
        // Productos();
        break;

    case 4:
        // Productos();
        break;

    case 5:
        system("clear");
        exit(1);
        break;
    
    default: //Tenemos este default por alguna opcion invalida
        system("clear");
        printf("Opcion Invalida\n Intente Nuevamente Porfavor\n");
        
        Menu(); //No retorna al menu Una Funcion Recursiva La volvemos a llamar
        __fpurge(stdin);
        break;
    }

    return 0;
}

int Proveedores(){ //Declaramos el valor de Proveedores
   
    Datos();
    printf("\n\t\t Proveedores\n");
    Wsize();

    printf("\n\t1.- Registrar nuevos Proveedores \n");
    printf("\t2.- Listar Proveedores\n");
    printf("\t3.- Volver al Menu\n");

    printf("\nDigite una Opcion: ");
    scanf("%i",&opc);
    
    //Creo un Menu de opciones anteriores
    switch (opc)
    {
        case 1: 
        
        printf("Registrar Nuevos Proveedores, presione enter para acceder....\n");
        getchar();    
        NewProveedor(); //Llamamos la funcion que esta en nuestra libreria
        break;

    case 2:
        system("clear");
        printf("Listar Proveedores, presione enter para acceder....\n");
        system("pwd");
        getchar();
        char direccion[50];
        

      
        f = fopen("Datos/Provedores/list.txt", "r"); //Nos abre el archivo
        if (f == NULL)  //Verificamos si el archivo existe
        {
            printf("\nEl archivo no existe. ");
        }
        while (!feof(f))    //Este bucle nos imprime en pantalla
        {
            fgets(aux,200,f);
            printf("%s",aux);
        }

        printf("\nDesea volver al menu S/N: ");
        scanf("%s",decision);
        if (strcmp(YES,decision)==0)
        {
            system("clear");
            
            Datos();
            
            Menu();
        }else
        __fpurge(stdin);
        Proveedores();
        
     
        break;
    case 3:
        system("clear");
        Datos();
        Menu();
        break;
    default:printf("Opcion Invalida");
        break;
    }
return 0;
}

void Productos(){

    Datos();
    
    printf("\n\t Usted Seleciono Productos....\n");
    Wsize();//Libreria Caracter

    printf("\n\n\t\t1.- Ver Productos En Alamacen");
    printf("\n\t\t2.- Agregar Nuevos Productos");
    printf("\n\t\t3.- Volver al Menu Principal");
    printf("\n\n\t\tPorfavor Digite una opcion valida: ");
    __fpurge(stdin);//Siempre es bueno Limpiar el buffer de entrada para evitar problemas
    scanf("%i",&opc);
    switch (opc) 
    {
    case 1: //Listar Productos
        
            system("clear");
        printf("Listar Productos, presione enter para acceder....\n");
        system("pwd");
        getchar();
        char direccion[250];
        
     
        f = fopen("Datos/Products/listProducts.txt", "r"); //Nos abre el archivo
        if (f == NULL)  //Verificamos si el archivo existe
        {
            printf("\nEl archivo no existe. ");
        }
        while (!feof(f))    //Este bucle nos imprime en pantalla
        {
            fgets(aux,200,f);
            printf("%s",aux);
        }

        printf("\nDesea volver al menu S/N: ");
        __fpurge(stdin);
        scanf("%s",decision);
        if (strcmp(YES,decision)==0)
        {
            system("clear");
            
            Datos();
            
            Menu();
        }else
        __fpurge(stdin);
        Productos();

        break;
    case 2: //Registrar nuevos Productos
        NewProducts();
        break;

    case 3: //Regresar al Menu
        system("clear");
        Datos();
        Menu();
        break;


    default: 
        __fpurge(stdin);
        system("clear");
        printf("\n\n\n\t\t\t Opcion Invalida Intente de Nuevo \n");
        printf("\n\tPresione Enter para continuar");
        getchar();
        Productos();
    }

}