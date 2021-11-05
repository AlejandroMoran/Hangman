#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main () {
    system("color 17"); //cambiar color del texto
    int salir=1;
    while(salir==1) { //Ciclo del juego
    char palabra[20]; //palabra que se va a adivinar
    char pal='1';     //letra que se va a probar
    char temporal[21];  //arreglo que contiene la palabra pero solo con guiones
    char rep[32];  //arreglo que guarda las letras intentadas
    char ahorcado[7][9]= {{' ',' ','+','-','-','-','+',' ',' '},   //Imagen de el ahorcado
                         {' ',' ','|',' ',' ',' ','|',' ',' '},
                         {' ',' ',' ',' ',' ',' ','|',' ',' '},
                         {' ',' ',' ',' ',' ',' ','|',' ',' '},
                         {' ',' ',' ',' ',' ',' ','|',' ',' '},
                         {' ',' ',' ',' ',' ',' ','|',' ',' '},
                         {'=','=','=','=','=','=','=','=','='}};
    int largo=0,i=0,x,j=0,inicial=0,repe=0;
    int temp=0;
    int correcto=0;
    int perdido=0;
    int Ganado=0;
    int oportunidades=7;

    system("cls");  //limpiar la consola
    printf(">>BIENVENIDO<<\n\n");
    printf("Juego del ahorcado\n\n");
    printf("Solo se aceptan letras\n")	;
    printf("\nIngrese una palabra o palabras (no debe pasar de 20 caracteres)\n");
    gets(palabra);

    do { //ciclo de adivinar una palabra
        system("cls");
        temp=0;

        if(inicial==0){
            for(i=0 ; i<strlen(palabra); i++){   ///Lee el tamaño de la palabra
                if (palabra[i]==' '){  //Impresión de las lineas de la palabra en el arreglo temporal
                    temporal[i]=' ';
                    largo++;
                    }
                else{
                    temporal[i]='_';
                    largo++;
                    }
                }
            }

        inicial=1;  //Acumulador de palabras
        temporal[largo]='\0';

        for(i=0;i<j;i++){ //verifica si la letra que ingresaste ya habia sido probada
            if (rep[i]==pal){
                system("cls");
                printf("\nYa habias intentado esa letra!");
                printf("\n\n");
                repe=1;
                }
            }

        if(perdido == 0&&repe!=1){	///Acumula las palabras acertadas y las guarda en en arreglo temporal para que se vean en la consola
            for(i=0; i<strlen(palabra);i++){
                if(palabra[i]==pal){
                    temporal[i]= pal;
                    correcto++;
                    temp=1;
                    }
                }
            }

        if (perdido==0&&repe!=1){ //condicional que resta las oportunidades
            if (temp==0){
                oportunidades=oportunidades-1;
                }
            }

        printf("\n");

        for(i=0;i<strlen(temporal);i++){ //impresion de las lineas de la palabra a adivinar
            printf("%c",temporal[i]);
            }

        printf("\n");

        if(strcmp(palabra,temporal)==0) { //comprueba si el arreglo temporal y la palabra ingresada son iguales y si ese es el caso termina el jeugo
            Ganado =1;
            break;
            }

        if(oportunidades==5)
            ahorcado[2][2]='O';
        if(oportunidades==4)
            ahorcado[3][2]='|';
        if(oportunidades==3)
            ahorcado[3][1]='/';
        if(oportunidades==2)
            ahorcado[3][3]=92;
        if(oportunidades==1)
            ahorcado[4][1]='/';
        if(oportunidades==0)
            ahorcado[4][3]=92;

        for(x=0;x<7;x++){ //imprime la imagen de ahorcado
            printf("\t");
            for(i=0;i<9;i++){
                printf("%c", ahorcado[x][i]);
                }
            printf("\n");
            }

        printf("\n\n Letras Correctas %d\n\n",correcto);
        printf(" Oportunidades restantes %d\n\n",oportunidades);
        rep[j]=pal; //guarda la letra intentada en rep
        j++;

        if(oportunidades==0) { // termina el juego si se acaban las oportunidades
            break;
            }

        printf("Introduzca una letra:");
        scanf("\n%c",&pal);
        repe=0;
        system("cls");
    } while (oportunidades !=0);

    if (Ganado){     // verifica si ganaste o perdiste
    printf("\n\nGanaste\n");
    }
    else{          // si perdiste imprime a el ahorcado y da la palabra que debia ser adivinada
        system("cls");
        printf("\n");
        for(x=0;x<7;x++){
            printf("\t");
            for(i=0;i<9;i++){
                printf("%c", ahorcado[x][i]);
                }
            printf("\n");
            }
        printf("\n Perdiste, la palabra era: %s \n", palabra);
        }

    printf("\nQuieres volver a jugar? Si(1), No(2)\n"); //pregunta si quieres volver a jugar
    scanf("%d",&salir);
    getchar();
    }
    return 0;
}
