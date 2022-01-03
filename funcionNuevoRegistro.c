//codigo de la funcion de nuevo registro

#include <stdio.h>
#include <string.h>

#define separar"================================================================================\n"
//variables que utiliza la funcion NuevoRegistro
char b[2]=" ";    //variable que se come al bug
char nombre[20]=" ";     //variable que almacena el nombre del usuario
char aPaterno[20]=" ";  //variable donde almacepamos el apellido paterno del usuario
char aMaterno[20]=" ";  //variable donde almacepamos el apellido materno del usuario
char edad[10]=" ";       //variable que almacena la edad del usuario 
char nickname[20]=" ";   //variable que almacena el nickname del usuario
char contrasena1[20]=" ";  //variable que almacena la contraseña del usuario
char contrasena2[20]=" ";  //variable que almacena la segunda contraseña del usuario
char correo[50]=" ";      //variable que almacena el correo del usuario
char numero[20]=" ";      //variable que almacena el numero telefonico del usuario


int respuesta1=0;     //variable que almacena la respuesta a la pregunta sobre si los datos del usuario son correctos
int repetir1=0;      //bandera que indica si se deve o no repetir el ciclo de nuevo registro; un valor de 1 indica repetir 
int repetir2=0;     //bandera que indica si se deve repetir el ciclo de la pregunta al usuario sobre sis sus datos son correctos
int repetir3=0;    //bandera que indica si se deve repetir el ciclo 


//variables que utiliza la funcion GuardarDatosUsuario

char *nicknameLectura;    //lectura del nickname del registro de usuarios
char *contrasenaLectura;   //lectura de la contraseña del registro de usuarios
int B1=0; //sila bandera toma el valor de 1 indica al programa que no hubo coincidencias de nickname y contraseña en el archivo Administrador.txt   
int B2=0; //si la banderatoma el valor de 1 indica que no hubo coincidencias de nickname y contraseña en el archivo usuarios.txt
int resultadoCerrarArchivo=-1; //guarda el resultado obtenido al cerrar el archivo despues de escribir los datos de un nuevo registro
FILE *archivo;  //creamos el apuntador a archivo para Administrador.txt
char lectura[100]; //variable donde almacenamos lo leido en cada renglon del registro de usuarios
char s2[] = "|";  //caracter que utilizaremos como separador en el registro de usuarios
char *segmentoDeCadena;  //apuntador donde almacenamos los segmentos de cadena que obtenemos
FILE *archivo2; //creamos el apuntador al archivo usuarios.txt





void main()     //funcion de nuevo registro
{
    
    printf(separar);
    do    //ciclo de nuevo registro
    {              
        repetir1=0; //inicializamos la bandera con cero por si el ciclo le da otro valor mas adelante
        //gets(b);  //este gets lo utilice para resolver un bug
        //el problema consiste en que al llamar a esta funcion desde el menu principal se salta el primer gets aunque limpie muchas veces el buffer
        printf(" ***NUEVO REGISTRO*** \n");   //titulo de nuevo registro siempre se muestra en este submenu
        printf("ingrese su nombre \n"); //pedimos el nombre del usuario
        fflush(stdin);      //usamos dos funciones para limpiar el buffer
        setbuf(stdin,NULL); //limpiamos el buffer
        gets(nombre);       //leemos el nombre del usuario y lo almacenamos en la variable (nombre)
        printf("ingrese su apellido paterno \n"); //pedimos el apellido paterno del usuario
        fflush(stdin);      //usamos dos funciones para limpiar el buffer
        setbuf(stdin,NULL); //limpiamos el buffer
        gets(aPaterno);       //leemos el apellido paterno y lo almacenamos en la variable (aPaterno)
        printf("ingrese su apellido materno \n"); //pedimos el apellido materno del usuario
        fflush(stdin);      //usamos dos funciones para limpiar el buffer
        setbuf(stdin,NULL); //limpiamos el buffer
        gets(aMaterno);       //leemos el apellido materno y lo almacenamos en la variable aMaterno
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
                printf("apellido paterno: %s \n",&aPaterno);
                printf("apellido materno: %s \n",&aMaterno);
                printf("edad: %s \n",&edad);
                printf("nickname: %s \n",&nickname);
                printf("contraseña: %s \n",&contrasena1);
                printf("contraseña: %s \n",&contrasena2);
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
                        //exatraemos el nickname y la contraseña de el registro de usuarios
                       //extraemos los datos de el archivo Administrador.txt
                        archivo = fopen("Administrador.txt","r"); //abrimos el archivo Administrador.txt en modo de lectura
                        if (archivo != NULL)   //si el archivo es distinto a null significa que se pudo abrir y podremos llevar a cabo la lectura
                        {
                            fgets(lectura, 100, archivo); //leemos de el archivo un renglon y lo almacenamos en la variable lectura
                            
                            if(fclose(archivo)==0) //si cerrar el archivo Administrador.txt retorna un cero indica que se pudo cerrar correctamente
                            {
                               // printf("\n\nSe ha CERRADO el archivo \n\n");
                            }
                            else
                            {
                                printf("\n\nHubo un problema al CERRAR el archivo (Administrador.txt)\n\n");
                            }
                        }
                        else
                        {
                            printf("\nhubo error al ABRIR el archivo (Administrador.txt) \n");
                        }
                        //una ves que tenemos la lectura de el archivo Administrador.txt la separamos en nickname y contraseña
                       
                    
                       
                    
                       segmentoDeCadena = strtok( lectura , s2 ); //separacion de el nickname del Administrador
                       nicknameLectura=segmentoDeCadena;//guardamos el nickname del Administrador en la variable nicknameAdmin
                       segmentoDeCadena = strtok( NULL, s2 ); //separacion de la contraseña del Administrador
                       contrasenaLectura=segmentoDeCadena;  //guardamos la contraseña del Administrador en la variable contrasenaAdmin
                       
                       //como tenemos separados el nickname y la contraseña del administrador las comparamos con las del nuevo registro
                       if(strcmp(nickname, nicknameLectura)==0 & strcmp(contrasena1, contrasenaLectura)==0 ) //comparamos los nickname
                        {
                            //mensaje en caso de que la combinacion de usuario y contraseña ya exista en el registro de usuarios
                            //printf("los datos que intentas registrar ya existen en Administrador.txt\n por favor intenta cambiando el nickname o cotraseña\n");
                            B1=0;
                        }
                        else
                        {
                           // printf("ahora deves guardar los datos\n");
                            B1=1;
                        }
                       //Extraemos los datos de el archivo usuarios.txt
                       
                       archivo2 = fopen("usuarios.txt","r"); //abrimos el archivo usuarios.txt en modo de lectura
                       if (archivo2 != NULL)   //si el archivo es distinto a null significa que se pudo abrir y podremos llevar a cabo la lectura
                        {
                            while (feof(archivo2) == 0)  // Mientras no se detecte el caracter EOF (End Of File) leemos todos los renglones del archivo usuarios.txt 
                            {
                                fgets(lectura, 100, archivo2); //leemos un renglon de el archivo usuarios.txt y lo guardamos en la variable lectura
                                
                                //una ves que tenemos la lectura de un renglon del archivo usuarios.txt la separamos en nickname y contraseña
                                
                                segmentoDeCadena = strtok( lectura , s2 ); //separacion de el nickname de algun usuario
                                nicknameLectura=segmentoDeCadena;//guardamos el nickname de algun usuario en la variable nicknameAdmin
                                segmentoDeCadena = strtok( NULL, s2 ); //separacion de la contraseña de algun usuario
                                contrasenaLectura=segmentoDeCadena;  //guardamos la contraseña de algun usuario en la variable contrasenaAdmin
                                
                                //como tenemos separados el nickname y la contraseña de algun usuario las comparamos con las del nuevo registro
                                if(strcmp(nickname, nicknameLectura)==0 & strcmp(contrasena1, contrasenaLectura)==0 ) //comparamos los nickname
                                {
                                    //mensaje en caso de que la combinacion de usuario y contraseña ya exista en el registro de usuarios
                                    //printf("los datos que intentas registrar ya existen en usuarios.txt\n por favor intenta cambiando el nickname o cotraseña\n");
                                    B2=0;
                                    break;
                                }   
                                else
                                {
                                    //printf("ahora deves guardar los datos\n");
                                    B2=1;
                                }
                            }
                            if(fclose(archivo2)==0)   //cerramos y evaluamos si se pudo cerrar el archivo usuarios.txt
                            {
                                // printf("\n\nSe ha CERRADO el archivo \n\n"); //vestigio del ejemplo del profe
                            }
                            else
                            {     //mensaje en caso de error al cerrar el archivo usuarios.txt
                                printf("\n\nHubo un problema al cerrar el archivo (usuarios.txt)\n\n");
                            }
                    
                        }
                        else
                        {  //mensaje en caso de error al abrir el archivo usuarios.txt
                            printf("\nhubo un error al ABRIR el archivo (usuarios.txt). \n");
                        }
                        //aqui guardamos los datos del nuevo registro en usuarios.txt
                        if( B1==1&B2==1 ) //si no hubo coincidencias de nickname y contraseña con el registro de usuarios podemos guardar los datos de nuevo registro
                        {
                           //printf("guardando datos..... \n");
                           archivo2 = fopen("usuarios.txt","a"); //abrimos el archivo usuarios.txt en modo agregar
                           if(archivo2!=NULL) //si el archivo usuarios.txt es distinto a null significa que se pudo abrir y podemos escribir en el
                    	    {
                                //fputs( cadena, archivo );
                                fprintf(archivo2,"\n%s|",nickname);
                                fprintf(archivo2,"%s|",contrasena1);
                                fprintf(archivo2,"%s|",nombre);
                                fprintf(archivo2,"%s|",aPaterno);
                                fprintf(archivo2,"%s|",aMaterno);
                                fprintf(archivo2,"%s|",edad);
                                fprintf(archivo2,"%s|",correo);
                                fprintf(archivo2,"%s|",numero);
                                
                                printf(separar);
                                printf("Registro Exitoso \n");
                                printf("Ya puede ingresar al sistema con su nickname y contraseña \n");
                                printf(separar);
                                repetir1=0;   //indicamos que no se repita el ciclo de nuevo registro
                            
                                resultadoCerrarArchivo= fclose ( archivo );
                                if(resultadoCerrarArchivo==0)
                                {
                                   // printf("\nSe ha CERRADO el archivo usuarios.txt \n");
                                   
                                }
                                else
                                {
                                    printf("\nHubo un problema al CERRAR el archivo usuarios.txt\n");
                                }
                            }
                            else
                            {
                                printf("\nHubo un problema al abrir el archivo usuarios.txt\n");
                            } 
                        }
                        else
                        { //mensajes en caso de que se halle coincidencia en el nickname y contraseña
                           printf(separar); 
                           printf("El nickname y contraseña ingresados ya existen \n");
                           printf("por favor ingresar un nickname o contraseña distintos \n");
                           printf("No se guardaros los datos \n");
                           printf(separar);
                           repetir1=1;   //indicamos se repita el ciclo de nuevo registro
                        }
                        
                        
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
                printf("apellido paterno: %s \n",&aPaterno);
                printf("pallido materno: %s \n",&aMaterno);
                printf("edad: %s \n",&edad);
                printf("nickname: %s \n",&nickname);
                printf("contraseña: %s \n",&contrasena1);
                printf("contraseña: %s \n",&contrasena2);
                printf("correo: %s \n",&correo);
                printf("numero de telefono: %s \n",&numero);
                printf(separar);
                printf("las contraseñas introducidas no coinciden \n" ); //indicamos que las contraseñas no coinciden
                printf("por favor vuelva a ingresar su contraseña \n" );   //pedimos nuevamente los datos
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
    
    
    
}
