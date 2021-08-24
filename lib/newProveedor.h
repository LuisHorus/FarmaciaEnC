/*
    ?En esta Libreria se crea los nuevos Proveedores solo podemos tener un maximo de 10
*/

#include<stdio.h>
#include <stdlib.h>
#include <stdio_ext.h> //!libreria Para Limpiar BUFFER


#include<string.h>
#define YES "s"
#define NO "n"

extern int Wsize();
extern int Menu();

int NewProveedor() {

    char decision[2];
    int i=0;
    int contador=0;
    struct registroPoveedor
    {
        char empresa[60];
        char empleado[60];
        int  ncontacto;
    }proveedor[2];
    
    int tamanio= sizeof(proveedor);
    int primertamanio=sizeof(proveedor[0]);
    int longitud= tamanio/primertamanio; // Guarda el tamaño de mi arreglo
    __fpurge(stdin); //!Limpiar Buffer Importante
    printf("\nDesea ingresar datos del nuevo proveedor S/N: ");
    scanf("%s",decision);
    
    
    if(strcmp(YES,decision)==0){
        printf("Ingrese los siguientes Datos Porfavor");

        
            do  //Este do while nos pide informacion para guardar datos de los proveedores
            {system("clear");
                printf("\n\n Digite el nombre de la empresa: ");
                scanf("%s",proveedor[contador].empresa);

                printf("\nIngrese el nombre del empleado de la empresa: ");
                scanf("%s",proveedor[contador].empleado);

                printf("\nDigite el telefono de la empresa: ");
                scanf("%i",&proveedor[contador].ncontacto);
                
                printf("\nDesea ingresar datos del nuevo proveedor S/N: ");
                scanf("%s",decision);
                if (strcmp(YES,decision)==0)
                {   
                    contador++;
                    if (contador==longitud){
                         printf("\nLo siento a excedio el numero maximo\n");
                    }
                    
                }else{
                    
                        printf("\n\nRegistro completado...\n");
                        break;
                    }

                
                
            } while (contador<longitud);
            

        

          
            for (int j = 0; j < longitud; j++)  //Este For imprime los proveedores que tenemos
            {
                Wsize();
                printf("\n\n %i El nombre de la empresa es: %s",j+1,proveedor[j].empresa);
                printf("\n %i El nombre del empleado de la empresa es: %s",j+1,proveedor[j].empleado);
                printf("\n %i El telefono de la empresa es: %i\n",j+1,proveedor[j].ncontacto);
                Wsize();
            }
  


    }
    printf("\nDeasea volver al menu: S/n\n");
    scanf("%s",decision);
    if (strcmp(YES,decision)==0){
        system("clear");
        Wsize();
        Menu();

    }
    __fpurge(stdin); //!Limpiar Buffer Importante
    printf("\nvuelva pronto\n");
   



    return 0;
}