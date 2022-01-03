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

//funciones
void MenuPrincipal (void);   //funcion que presenta el menu principal
void NuevoRegistro (void);    //funcion que registra a un nuevo usuario
void IngresoAlSistema (void);  //esta funcion loguea a un usuario que ya tiene una cuenta
void GuardarDatosUsuario (void); //se ejecuta cuando queremos guardar los datos del usuario en el archivo de texto

//Variables y/o macros:
#define separador"\n\n================================================================================\n\n"
#define separar"================================================================================\n"
#define nombres"Team Nuez: \n 39- Ruiz Cortés Ibrahim Harún, 319234327\n 23- Mani Tuxpan Aaron, 319134076\n 33- Rayon Olivar Saul, 422102364\n 00- Bruno Gilberto Santana Rodríguez,\n"

//variables que utiliza la funcion MenuPrincipal
char a=' ';        //variable que almacena la respuesta para el menu principal
int repetir=0;    //variable que permite repetir en caso de que se ingrese un caracter no valido

//variables que utiliza la funcion NuevoRegistro
char b[2]=" ";    //variable que se come al bug
char nombre[50]=" ";     //variable que almacena el nombre del usuario
char edad[50]=" ";       //variable que almacena la edad del usuario 
char nickname[50]=" ";   //variable que almacena el nickname del usuario
char contrasena1[50]=" ";  //variable que almacena la contraseña del usuario
char contrasena2[50]=" ";  //variable que almacena la segunda contraseña del usuario
char correo[50]=" ";      //variable que almacena el correo del usuario
char numero[50]=" ";      //variable que almacena el numero telefonico del usuario


int respuesta1=0;     //variable que almacena la respuesta a la pregunta sobre si los datos del usuario son correctos
int repetir1=0;      //bandera que indica si se deve o no repetir el ciclo de nuevo registro; un valor de 1 indica repetir 
int repetir2=0;     //bandera que indica si se deve repetir el ciclo de la pregunta al usuario sobre sis sus datos son correctos
int repetir3=0;    //bandera que indica si se deve repetir el ciclo 



            //FUNCION PRINCIPAL
void main()
{
  //nombres
  printf(separador);
  printf(nombres);
  printf(separador);
  //El programa:
  MenuPrincipal();
  
 
}





                              //DECLARACION DE LAS FUNCIONES SECUNDARIAS
                              
void MenuPrincipal (void)//declaracion de la funcion menu principal
{
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
}   //final de la funcion MenuPrincipal












void IngresoAlSistema (void)//declaracion de la funcion IngresoAlSistema
{      
}












void NuevoRegistro (void)//declaracion de la funcion NuevoRegistro
{
    printf(separar);
    do    //ciclo de nuevo registro
    {              
        repetir1=0; //inicializamos la bandera con cero por si el ciclo le da otro valor mas adelante
        gets(b);  //este gets lo utilice para resolver un bug
        printf(" ***NUEVO REGISTRO*** \n");   //titulo de nuevo registro siempre se muestra en este submenu
        printf("ingrese su nombre apellido paterno y apellido materno \n"); //pedimos el nombre completo del usuario
        fflush(stdin);      //usamos dos funciones para limpiar el buffer
        setbuf(stdin,NULL); //limpiamos el buffer
        gets(nombre);       //leemos el nombre del usuario
        printf("ingrese su edad \n");  //pedimos la edad del usuario
        fflush(stdin);
        setbuf(stdin,NULL);  //limpiamos el buffer
        gets(edad);        //leemos laedad del usuario
        printf("ingrese un nickname \n");   //pedimos el nickname del usuario
        fflush(stdin);
        setbuf(stdin,NULL);  //limpiamos el buffer
        gets(nickname);      //leemos el nickname del usuario
        printf("ingrese una contraseña \n");  //pedimos la contraseña del usuario
        fflush(stdin);
        setbuf(stdin,NULL);  //limpiamos el buffer
        gets(contrasena1);      //leemos la contraseñadel usuario
        printf("ingrese nuevamente su contraseña \n"); //pedimos nuevamente la contraseña del usuario
        fflush(stdin);
        setbuf(stdin,NULL);   //limpiamos el buffer
        gets(contrasena2);      //leemos nuevamente la contraseña del usuario
        printf("ingrese su correo electronico \n"); //pedimos el correo del usuario
        fflush(stdin);
        setbuf(stdin,NULL);  //limpiamos el buffer
        gets(correo);           //leemos el correo del usuario
        printf("ingrese su numero de celular \n");  //pedimos el numero de telefono del usuario
        fflush(stdin);
        setbuf(stdin,NULL);  //limpiamos el buffer
        gets(numero);          //leemos el numero telefonico del usuario
        
        do  //ciclo para que las contraseñas introducidas sean iguales
        { 
            repetir3=0;    //inicializamos la bandera con cero por si el ciclo le da otro valor mas adelante
            
            if(strcmp(&contrasena1,&contrasena2)==0)  //comparamos las dos contraseñas del usuario
            {   //en caso de que las dos contraseñas sean iguales hacemos todo lo que esta dentro de estos corchetes
                printf(separar);
                printf("*** sus datos son: ***\n");  //imprimimos en pantalla todos los datos del usuario
                printf("nombre: %s \n",&nombre);
                printf("edad: %s \n",&edad);
                printf("nickname: %s \n",&nickname);
                printf("contraseña1: %s \n",&contrasena1);
                printf("contraseña2: %s \n",&contrasena2);
                printf("correo: %s \n",&correo);
                printf("numero de telefono: %s \n",&numero);
                
                do                    //ciclo de la pregunta al usuario sobre si sus datos son correctos
                {
                    repetir2=0;   //inicializamos la bandera con cero por si el ciclo le da otro valor mas adelante
                    printf(separar);
                    printf("¿sus datos son correctos? \n");  //preguntamos si los datos son correctos
                    printf("introdusca un 1 si sus datos son correctos \n");  //indicamos que hacer si los datos son correctos
                    printf("introdusca un 0 si sus datos son incorrectos y quiere cambiarlos \n"); //indicamos que hacer si los datos no son correctos
                    
                    setbuf(stdin,NULL);       //limpiamos el buffer
                    scanf("%i",&respuesta1);  //escaneamos la respuesta del usuario sobre si sus datos son correctos
                    switch (respuesta1)      //comparamos la respuesta con distintos casos
                    {
                        case 1 :         //en caso de que la respuesta tome el valor de 1 hacemos lo siguiente:
                                         //ejecutaremos una funcion que guarde los datos en un archivo de texto
                        printf("OK");
                        repetir1=0;   //indicamos que no se repita el ciclo de nuevo registro
                        repetir2=0;  //indicamos que no se repita el ciclo de la pregunta al usuario sobre si sus datos son correctos
                        break;
                        case 0 :      //en caso de que la respuesta tome el valor de 0 hacemos lo siguiente:
                        printf(separar);
                        printf("por favor vuelva a introducir sus datos \n"); //pedimos de nuevo los datos al usuario
                        repetir1=1; //indicamos que se repita el ciclo de nuevo registro
                        repetir2=0; //indicamos que no se repita el ciclo de la pregunta al usuario sobre si sus datos son correctos
                 
                        break;
                        default :    //en caso de que la resouesta del usuario tome valores distintos de 0 y 1 hecemos lo siguiente:
                        printf("caracter no valido, por favor ingresa una opcion valida \n"); //pedimos al usuario que nos de una respuesta valida
                        repetir2=1; //indicamos que se repita el ciclo de la pregunta al usuario sobre si sus datos son correctos
                        break;
                 
                    }
                }while(repetir2==1); //condicion para que se repita el ciclo de la pregunta al usuario sobre si sus datos son correctos
                
            }
            else
            {  //cuando las dos contraseñas del usuario sean distintas hacemos lo que esta dentro de estos corchetes
                printf(separar);
                printf("*** sus datos son: ***\n");  //imprimimos en pantalla todos los datos del usuario
                printf("nombre: %s \n",&nombre);
                printf("edad: %s \n",&edad);
                printf("nickname: %s \n",&nickname);
                printf("contraseña1: %s \n",&contrasena1);
                printf("contraseña2: %s \n",&contrasena2);
                printf("correo: %s \n",&correo);
                printf("numero de telefono: %s \n",&numero);
                printf(separar);
                printf("las contraseñas introducidas no coinciden \n " ); //indicamos que las contraseñas no coinciden
                printf("por favor vuelva a ingresar su contraseña \n " );   //pedimos nuevamente los datos
                printf(separar);
                printf("ingrese una contraseña \n");  //pedimos la contraseña del usuario
                fflush(stdin);
                setbuf(stdin,NULL);  //limpiamos el buffer
                gets(contrasena1);      //leemos la contraseñadel usuario
                printf("ingrese nuevamente su contraseña \n"); //pedimos nuevamente la contraseña del usuario
                fflush(stdin);
                setbuf(stdin,NULL);   //limpiamos el buffer
                gets(contrasena2);      //leemos nuevamente la contraseña del usuario
                repetir3=1;  //indicamos que se repita el ciclo para que las contraseñas sean iguales
            
            }
        }while(repetir3==1); //condicion para que se repita el ciclo para que las contraseñas introducidas sean iguales    
    }while(repetir1==1); //condicion para que se repita el ciclo de nuevo registro
       
}  //final de la funcion NuevoRegistro












void GuardarDatosUsuario (void) //declaracion de la funcion que guarda los datos de usuario en el archivo de texto
{

}