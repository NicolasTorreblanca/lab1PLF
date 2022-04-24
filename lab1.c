//----LIBRERIAS----
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>

//Autor: Nicolas Torreblanca
// Laboratorio 1 Procesamiento de Lenguajes Fomales


//Declaracion de funciones

// Entradas:
// Salidas:
// Funcionamiento : 


int esnumero(char *arreglo, int j){
    
    if(arreglo[j] =='0'||arreglo[j] =='1'||arreglo[j] =='2'||arreglo[j] =='3'||arreglo[j] =='4'||arreglo[j] =='5'||arreglo[j] =='6'||arreglo[j] =='7'||arreglo[j] =='8'||arreglo[j] =='9'){
          return 1;
        }
       else{
           return 0;
       }    
}

// Entradas:
// Salidas:
// Funcionamiento : 


int revisarSiguientes(char *arreglo, int j){
       
    if(arreglo[j] =='.'){
          return 1;
    }
    else if(arreglo[j] =='^'){
          return 2 ;
    }
    else{
        return 0;
    }  



}


// Bloque principal


int main(int argc, char **argv)
{
  FILE *archivoentrada;
  FILE *archivosalida;
  int caracterEnArchivo;
  int cantidadcaracteres = 0;
  int revisionSalida;
  int cantidadcaracteresSalida = 0;
  char mensaje[50];


  /*indicaciones de la compilacion*/

  if (argc != 3) {
    fprintf(stderr, "Compilacion ejecutado de la manera incorrecta\n");
    fprintf(stderr, "Ejemplo utilizacion : archivo.exe entrada.txt salida.txt\n");
    return 1;
  }

  /* se abre el archivo de entrada */

  archivoentrada = fopen(argv[1], "r");
  if (archivoentrada == NULL) {
    fprintf(stderr, "No se pudo abrir el archivo para lectura: %s\n", argv[1]);
    return 2;
  }

  /*se abre el archivo de salida */

  archivosalida = fopen(argv[2], "w");
  if (archivosalida == NULL) {
    fprintf(stderr, "No se pudo abrir el archivo para escritura: %s\n", argv[2]);
    fclose(archivoentrada);
    return 3;
  }

  /*
    do{
    revisionSalida = fgetc(archivosalida);
    if (revisionSalida != EOF) {
          cantidadcaracteresSalida = cantidadcaracteresSalida +1;
    }
    }while (revisionSalida != EOF);

    printf("caracteres salida : %d \n",cantidadcaracteresSalida);

    if (cantidadcaracteresSalida != 0) {
        printf("Se necesita un archivo vacio en el cual realizar la escritura!");
        fclose(archivoentrada);
        fclose(archivosalida);
        return 1;
    }

    */

  

  /* Reconocimiento de no terminales en la gramatica*/
  //Se revisa cada uno de los caracteres del archivo de entrada
  // Luego se revisa si aquel caracter pertenece a la gramatica
  // Finalmente, si pertenece se escribe en el archivo de salida.
  // No terminales : 0,1,2,3,4,5,6,7,8,9, +,-,/,*,%,^,(,),.,logdec

  do {
    caracterEnArchivo = fgetc(archivoentrada);
    if (caracterEnArchivo != EOF) {
          cantidadcaracteres = cantidadcaracteres +1;
    }
    
  } while (caracterEnArchivo != EOF);

  rewind(archivoentrada);

//  printf("cantidad caracters: %d \n",cantidadcaracteres);
  
  char * arreglo = (char*)malloc(cantidadcaracteres*sizeof(char)); 

  for(int i = 0; i < cantidadcaracteres; i++){
      fscanf(archivoentrada,"%c",&arreglo[i]);
  }



  for(int j = 0;j < cantidadcaracteres;j++){
      if(arreglo[j] =='+'){
          char mensaje[50] = "+ \n";
          fprintf(archivosalida,"%s",mensaje);
      }
      else if(arreglo[j] =='-'){
          char mensaje[50] = "- \n";
          fprintf(archivosalida,"%s",mensaje);
      }
      else if(arreglo[j] =='%'){
          char mensaje[50] = "%\n";
          fprintf(archivosalida,"%s",mensaje);
      }
      else if(arreglo[j] =='/'){
          char mensaje[50] = "/\n";
          fprintf(archivosalida,"%s",mensaje);
      }
      else if(arreglo[j] =='*'){
          char mensaje[50] = "*\n";
          fprintf(archivosalida,"%s",mensaje);
      }
      else if(arreglo[j] =='('){
          char mensaje[50] = "( \n";
          fprintf(archivosalida,"%s",mensaje);
      }
      else if(arreglo[j] ==')'){
          char mensaje[50] = ") \n";
          fprintf(archivosalida,"%s",mensaje);
      }else if(arreglo[j] =='^'){
           char mensaje[50] = "^ \n";
           fprintf(archivosalida,"%s",mensaje);
      }else if(arreglo[j] == 'l' && arreglo[j+1] == 'o' && arreglo[j+2] == 'g' && arreglo[j+3] == 'd' && arreglo[j+4] == 'e' && arreglo[j+5] == 'c'){
           char mensaje[50] = "logaritmo decimal \n";
           fprintf(archivosalida,"%s",mensaje); 
      }
      else if((esnumero(arreglo,j) == 1)){

            do{
              j = j+1;
            }while((esnumero(arreglo,j) == 1));
        
            if((revisarSiguientes(arreglo,j))==1){

            do{
              j = j+1;
            }while((esnumero(arreglo,j) == 1));
                char mensaje[50] = "Decimal \n";
                fprintf(archivosalida,"%s",mensaje);
            }
            else if((revisarSiguientes(arreglo,j))==2){

            do{
              j = j+1;
            }while((esnumero(arreglo,j) == 1));
                char mensaje[50] = "Exponencial \n";
                fprintf(archivosalida,"%s",mensaje);
            }else{

                char mensaje[50] = "Entero \n";
                fprintf(archivosalida,"%s",mensaje);

                if(arreglo[j] =='+'){
                    char mensaje[50] = "+ \n";
                    fprintf(archivosalida,"%s",mensaje);
                }
                else if(arreglo[j] =='-'){
                    char mensaje[50] = "- \n";
                    fprintf(archivosalida,"%s",mensaje);
                }
                else if(arreglo[j] =='%'){
                    char mensaje[50] = "%\n";
                    fprintf(archivosalida,"%s",mensaje);
                }
                else if(arreglo[j] =='/'){
                    char mensaje[50] = "/\n";
                    fprintf(archivosalida,"%s",mensaje);
                }
                else if(arreglo[j] =='*'){
                    char mensaje[50] = "*\n";
                    fprintf(archivosalida,"%s",mensaje);
                }
                else if(arreglo[j] =='^'){
                    char mensaje[50] = "^ \n";
                    fprintf(archivosalida,"%s",mensaje);
                }
                else if(arreglo[j] =='('){
                    char mensaje[50] = "( \n";
                    fprintf(archivosalida,"%s",mensaje);
                }
                else if(arreglo[j] ==')'){
                    char mensaje[50] = ") \n";
                    fprintf(archivosalida,"%s",mensaje);
 
                }
            }

      }

    }  
  /* cerrando los archivos */

  fclose(archivoentrada);
  fclose(archivosalida);

  return 0;
}
