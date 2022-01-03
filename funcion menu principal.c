
/* Código fuente
Team Nuez:
 - Ruiz Cortés Ibrahim Harún, ibrahplague@gmail.com
 - Mani Tuxpan Aarón, aaron.mani.f4719@gmail.com
 - Bruno Gilberto Santana Rodríguez, brunogilbertosantanarodriguez@gmail.com
 - Rayon Olivar Saul, yosoysaul2017@gmail.com
*/
//Librerías:
#include <stdio.h>
#include <string.h>

//Variables y/o macros:
#define separador"\n================================================================================\n"
#define nombres"Team Nuez: \n 39- Ruiz Cortés Ibrahim Harún, 319234327\n 23- Mani Tuxpan Aaron, 319134076\n 33- Rayon Olivar Saul, 422102364\n 00- Bruno Gilberto Santana Rodríguez,\n"

//variables que utiliza la funcion MenuPrincipal
char a=' ';        //variable que almacena la respuesta para el menu principal
int repetir=0;    //variable que permite repetir en caso de que se ingrese un caracter no valido



void main(){
    
    do  //ciclo para las opciones del menu principal 
     {
        repetir=0; //inicializamos la bandera con cero por si el ciclo le da otro valor mas adelante
                                  //bienvenida y menu principal
        printf("BIENVENIDO A CINE NUEZ \n");
        printf("MENU PRICIPAL \n");
        printf(separar);
        printf("si ya eres usuario presiona i para INGRESO AL SISTEMA \n");    //instrucciones para el usuario
        printf("si aun no eres usuario presiona r para un NUEVO REGISTRO \n");
        printf(separar);
        setbuf(stdin,NULL);     // limpiamos el buffer
        scanf("%c",&a);         //escaneamos la respuesta y la guardamos en la variable a
                
        switch (a)     //switch evalua las posibles respuestas para ejecutar la funcion que elija el usuario
        {
            case 'i' :   //si ingreso una i ejecutara una funcion para ingresar al sistema
         
            break;
            case 'r' :   //si ingresa r ejecutara una funcion para un nuevo registro
            NuevoRegistro();   //llamamos a la funcion nuevo registro
            break;
            default :    //si ingresa cualquier otro caracter volvera a repetir el ciclo de las opciones del menu principal
                printf("caracter no valido, por favor ingresa una opcion valida \n");
                repetir=1; //cuando la variable repetir valga 1 se volvera a mostrar el menu principal
            break;
         
        }
     
    }
    while(repetir==1);    //condicion del ciclo de las opciones del menu principal 
}
    