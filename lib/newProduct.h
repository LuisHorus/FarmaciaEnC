//?Librerias A Utilizar
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdio_ext.h> //!libreria Para Limpiar BUFFER
#define YES "s"
#define NO "n"


// Struct global para ser accedido de otros archivos
struct newProduct //Se crea la estructura para almacenar los siguientes datos.
    {
        char nameProduct[30];   //nombre Producto
        int cantidad;   // cantidad de productos
        float precioCompra; //Precio que nos lo vende el proveedor
        float precioVenta;  // Precio Que nosotros lo daremos

    }products[20];

  FILE *f;


  extern void Datos();
  extern int Menu();

//Funcion Donde declaremos nuestra logica
void NewProducts(){ //Esta funcion nos va listar los Productos

    system("clear");  
        Wsize();
        printf("\n\t Agregando nuevos Productos.....\n");
        Wsize();
        
        char res[3];
        int j=0;
        
        
        // do{

        for(j=0;j<30;j++){  //Se estaba haciendo con un so while pero fue mejor implemtar un for

        __fpurge(stdin);
        printf("\n\n\t\t %i Ingrese el nombre del nuevo Producto: ",j+1);
        __fpurge(stdin);
        scanf("%s",products[j].nameProduct);
        printf("\n\n\t\t %i Ingrese la cantidad de los nuevos Productos: ",j+1);
        __fpurge(stdin);
        scanf("%i",&products[j].cantidad);
        printf("\n\n\t\t %i Ingrese el precio de compra del nuevo Producto: ",j+1);
        __fpurge(stdin);
        scanf("%f",&products[j].precioCompra);
        printf("\n\n\t\t %i Ingrese el precio de venta del nuevo Producto: ",j+1);
        __fpurge(stdin);
        scanf("%f",&products[j].precioVenta);

        printf("\n\n\tDesea agregar otro S/N: ");
        __fpurge(stdin);
        scanf("%c",res);

            if (strcmp(res,YES)==0)
            {  
                // j++;
                continue;
            
                
            }else 
            
                Wsize();
                printf("\nRegsitro Exitoso\n");
                Wsize();
                break;

         }
        // }while (j<30);
        
        
        /* Ahora voy a guardar los datos en un nuevo archivo */


       f = fopen("Datos/Products/listProducts.txt", "w");

        if (f == NULL)
        {
            printf("El archivo no se encontro");
            exit(1);
        }
     
        
        //Este for Me guarda los datos en un archivo
        for (int i = 0; i < 30; i++) //Este For imprime los proveedores que tenemos
        {
            
            fprintf(f,"\n\n %i El nombre del producto es: %s", i + 1,products[i].nameProduct);
            fprintf(f,"\n %i Los Productos en Stock son: %i", i + 1,products[i].cantidad );
            fprintf(f,"\n %i El Precio de compra del producto es: %f", i + 1,products[i].precioCompra);
            fprintf(f,"\n %i El Precio de venta del producto es: %f\n", i + 1,products[i].precioVenta);
            
        }
        fclose(f); //!Cierro mi archivo para evitar errores
        
        //Se pregunta donde desea volver
        printf("\n\n\t\t\t Desea volver al menu princiapal s/n: ");
        __fpurge(stdin);
        scanf("%c",res);

         if (strcmp(res,YES)==0)
            {  system("clear");
                Datos();
                Menu();
                            
            }else 
            __fpurge(stdin);
            NewProducts();
                
                

        //  for (int i = 0; i < 3; i++)
        //  {
        //      printf("\n\nEl nombre del producto %i es: %s ",i+1,products[i].nameProduct);
        //      printf("\nLa cantidad del producto %i es: %i ",i+1,products[i].cantidad);
        //      printf("\nEl precio de compra del producto %i es: %f ",i+1,products[i].precioCompra);
        //      printf("\nEl precio de venta producto %i es: %f \n",i+1,products[i].precioVenta);
        //  }
        

    
    
    
    

}