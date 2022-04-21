//----LIBRERIAS----
#include "funciones.h"
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>

#define LECTURA 0
#define ESCRITURA 1

extern void niceprint(int N, float *Energy, float Maximum);

//Autor: Nicolas Torreblanca

int main(int argc, char ** argv){


    //Declaracion de variables para lectura de archivos
    char * nombreEntrada = NULL;
    char * nombreSalida = NULL;
    int cantidadCeldas;
    //cantidadLineas = cantidadParticulas
    int cantidadParticulas;
    int bandera = 0;
    int buffer;
    int cantidadHebras;

    //El siguiente ciclo se utiliza para recibir los parametros de entrada usando getopt
    // N = cantidadCeldas
    // c = cantidadLineas archivo
    // i = archivoEntrada
    // o = archivoSalida
    // b = Tamanho buffer hebra productora
    // h = Numero de Hebras
    // D = bandera grafico


    int z;

    int entradas = 0;
    while ((z = getopt (argc, argv, "N:c:i:o:b:h:D")) != -1)
    {
        switch (z)
        {
        case 'N':
            sscanf(optarg, "%d", &cantidadCeldas);
            entradas = entradas +1;

            break;
        case 'c':
            sscanf(optarg, "%d", &cantidadParticulas);
            entradas = entradas +1;

            break;    
        case 'i':
            nombreEntrada = optarg;
            entradas = entradas +1;

            break;
        case 'o':
            nombreSalida = optarg;
            entradas = entradas +1;

            break;
        case 'b':
            sscanf(optarg, "%d", &buffer);
            entradas = entradas +1;

            break;
        case 'h':
            sscanf(optarg, "%d", &cantidadHebras);
            entradas = entradas +1;

            break;
        
        case 'D':
            bandera = 1;
            entradas = entradas +1;

            break;
        case '?':
            if (optopt == 'N'){
                fprintf (stderr, "Opcion -%c requiere un argumento.\n", optopt);
            }else if (optopt == 'p'){
                fprintf (stderr, "Opcion -%c requiere un argumento.\n", optopt);
            }else if (optopt == 'c'){
                fprintf (stderr, "Opcion -%c requiere un argumento.\n", optopt);
            }else if (optopt == 'i'){
                fprintf (stderr, "Opcion -%c requiere un argumento.\n", optopt);
            }else if (optopt == 'o'){
                fprintf (stderr, "Opcion -%c requiere un argumento.\n", optopt);
            }else if (optopt == 'b'){
                fprintf (stderr, "Opcion -%c requiere un argumento.\n", optopt);
            }else if (optopt == 'h'){
                fprintf (stderr, "Opcion -%c requiere un argumento.\n", optopt);
            }else if (isprint(optopt))
            {
                fprintf (stderr, "Opcion desconocida `-%c'.\n", optopt);
            }else if (cantidadHebras > cantidadParticulas){
                printf ("Mas hebras que particulas!.\n");
            }else{
                fprintf (stderr,
                "Opcion con caracter desconocido `\\x%x'.\n",
                optopt);
            }  
            return 1;
            
          default:
            abort ();
          } 

    }

    if(bandera = 1){
      if(entradas != 7){
          printf("Falta una o mas entradas por ingresar! , %d entradas\n" ,entradas);
           return 1;
        }
    }else{
          if(entradas != 6){
                printf("Falta una o mas entradas por ingresar! %d entradas \n",entradas);
                return 1;
            }      
    } 

    printf("Sin problemas en las entradas! \n");
        
  
    

    //Se obtiene la cantidad de particulas en el archivo de entrada
    //int cantidadParticulas = lecturaCan(nombreEntrada);
    //Se reserva memoria para los arreglos dinamicos
    float * arregloCeldas = (float*)malloc(cantidadCeldas*sizeof(float));
    int * arregloPos = (int*)malloc(cantidadParticulas*sizeof(int));
    int * arregloEn = (int*)malloc(cantidadParticulas*sizeof(int));

    //Se calcula la cantidad particulas que procesara cada hebra

    int n  = calcular_N(cantidadParticulas,cantidadHebras);
    int * arreglo = (int*)malloc(n*sizeof(int));

    bandera = 0;

    nombreEntrada = "a";
    nombreSalida = "b";

    //Se le asigna a cada hebra una cantidad de particulas

    asignar_Particulas(cantidadParticulas,cantidadHebras,n,arreglo);
  
    //Liberacion de memoria
    free(arregloCeldas);
    free(arregloPos);
    free(arregloEn);

    return 0;
}
