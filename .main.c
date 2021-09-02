//Librerias Standar
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h> //!libreria Para Limpiar BUFFER

//Librerias Creadas
#include "lib/fecha.h"
#include "lib/caracter.h"
#include "lib/newProduct.h"
#include "lib/newProveedor.h"

//Defines utilizados
#define USER "admin"
#define PASSWORD "123"
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
void Venta();
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
    printf("\n");
    fecha();
    printf("\tProyecto Farmacia \t Por: Luis Escobedo\n");
    Wsize();
}

int Menu() // Menu Principal de Opciones
{

    int opc = 0;

    printf("\n\t\t1.- Proveedores\n");
    printf("\t\t2.- Productos\n");
    printf("\t\t3.- Venta\n");
    printf("\t\t4.- Ver Facturas\n");    
    printf("\t\t5.- Salir\n");
    printf("\t\t Digite una opcion 1-5 \n");
    scanf("%i", &opc);
    
    switch (opc)
    {

    case 1://Funcion De Los Proveedores
        __fpurge(stdin);
        Proveedores();
        break;
    case 2: //Funcion Products
        __fpurge(stdin);
        Productos();
        break;

    case 3: //Funcion Ventas
        __fpurge(stdin);
        Venta();

         printf("\nDesea volver al menu S/N: ");
        scanf("%s",decision);
        if (strcmp(YES,decision)==0)
        {
            system("clear");
            
            Datos();
            
            Menu();
        }else
        __fpurge(stdin);
        Venta();
        
     
        break;

    case 4: //Ver Facturas
        system("clear");
        Datos();
        printf("\n");
        system("pwd");
        system("nautilus Datos/fac");
        system("ls Datos/fac/");
         printf("\nDesea volver al menu S/N: ");
        scanf("%s",decision);
        if (strcmp(YES,decision)==0)
        {
            system("clear");
            
            Datos();
            
            Menu();
        }else
        

        
     
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
        
       
        printf("\n");
        Wsize();
         printf("\n");


        //Accedemos al archivo.
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
         fclose(f); //!Cierro mi archivo para evitar errores
        
        //?Preguntamos si desea volver al menu
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
        __fpurge(stdin);
        NewProducts();
        break;

    case 3: //Regresar al Menu
        system("clear");
        __fpurge(stdin);
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

void Venta(){
    int respuestaCompra = 0;
    int contador = 0;
    float aumento = 0;
    float subtotal=0;
    float total=0;
    FILE *factura;
    struct compra {
        char nproducto[50];
        float precio;
        unsigned int cantidad;
    }realizaCompra[15];
    system("clear");
    Wsize();
    printf("\n\t\tSelecciono Las Ventas\n");
    Wsize();
    system("nautilus Datos/Products/listProducts.txt");
    printf("\nSeleccione Productos...\n");
 

        while (contador<15)
        {   
            
            //Solicitamos Los Datos Al Usuario
            printf("\n %i Digite el nombre del producto: ",contador+1);
            __fpurge(stdin);
            scanf("%s",realizaCompra[contador].nproducto);
            printf("\n %i Digite el precio: ", contador+1);
            __fpurge(stdin);
            scanf("%f",&realizaCompra[contador].precio);
            printf("\n %i Digite la cantidad a llevar: ",contador+1);
            __fpurge(stdin);
            scanf("%u",&realizaCompra[contador].cantidad);

            //Preguntamos Si desea Agregar mas Productos
            printf("\n\n Desea agregar mas Productos \n\t 1-Si \n\t 2-No\n");
            __fpurge(stdin);
            scanf("%d",&respuestaCompra);
            
            //Condicon Evaluar si quiere mas Producto
            if (respuestaCompra == 1)
            {
                system("clear");
                subtotal = (realizaCompra[contador].cantidad) * (realizaCompra[contador].precio);
                aumento = aumento + subtotal;
                Wsize();
                printf("\n\t Usted lleva: %.2f\n",aumento);
                
                contador++;
                continue;   //Continua
                
           
            }else if(respuestaCompra==2){
                subtotal = (realizaCompra[contador].cantidad) * (realizaCompra[contador].precio);
                aumento = aumento + subtotal;
                contador++;                        
                break;
            } else break;

                      

        }//Fin While
        system("clear");
        Datos();

          total = aumento;
        factura = fopen("Datos/fac/list.txt","w");
        if (factura == NULL)
        {
            printf("\n\nNo se ha Podido Abrir\n");
            exit(1);
        }//For va imprimir
        for (int i = 0; i < contador; i++)
          {
              fprintf(factura,"\n\nProducto: %s \n\t\tCantidad: %u \tPrecio: %.2f \tSubtotal: %.2f",realizaCompra[i].nproducto,realizaCompra[i].cantidad,realizaCompra[i].precio,realizaCompra[i].cantidad * realizaCompra[i].precio);
          }
          
        fclose(factura);

          for (int i = 0; i < contador; i++)
          {
              printf("\n\nProducto: %s \n\t\tCantidad: %u \tPrecio: %.2f \tSubtotal: %.2f",realizaCompra[i].nproducto,realizaCompra[i].cantidad,realizaCompra[i].precio,realizaCompra[i].cantidad * realizaCompra[i].precio);
          }
          
            printf("\n\n\t\tUsted debe un total: %.2f\n",total);
            Wsize();
            printf("\n\t\tGRACIAS POR SU COMPRA\n");
            system("./Datos/fac/script.sh");
        

}