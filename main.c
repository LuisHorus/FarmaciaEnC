#include<stdio.h>
#include<string.h>

#define USER "admin"
#define PASSWORD "123"
int main(){

    char user [80];
    char clave [80];
    printf("\t\t Inicio de Sesion\n");
    
    printf("\t\t Usuario\n");
    printf("\t\t");
    scanf("%s",user);

    printf("\t\t Clave\n");
    printf("\t\t");
    scanf("%s",clave);

    if (strcmp (user, USER) == 0 && strcmp(clave,PASSWORD) == 0)
    {
        printf("\nAcceso Permitido");
    }else{
        printf("\n Usuario y/o Clave Incorrectos");
    }
    

    return 0;
}