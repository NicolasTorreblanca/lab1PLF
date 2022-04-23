//----LIBRERIAS----
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>

//Autor: Nicolas Torreblanca
// Laboratorio 1 Procesamiento de Lenguajes Fomales


int
main(int argc, char **argv)
{
  FILE *archivoentrada;
  FILE *archivosalida;
  int ch;
  char charValue[5];
  int cantidadcaracteres = 0;
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

  /* Reconocimiento de no terminales en la gramatica*/
  //Se revisa cada uno de los caracteres del archivo de entrada
  // Luego se revisa si aquel caracter pertenece a la gramatica
  // Finalmente, si pertenece se escribe en el archivo de salida.
  // No terminales : 0,1,2,3,4,5,6,7,8,9, +,-,/,*,%,^,(,),.,logdec

  do {
    ch = fgetc(archivoentrada);
    if (ch != EOF) {
          cantidadcaracteres = cantidadcaracteres +1;
    }
    
  } while (ch != EOF);

  rewind(archivoentrada);
  printf("cantidad caracters: %d \n",cantidadcaracteres);
  
  char * arreglo = (char*)malloc(cantidadcaracteres*sizeof(char)); 

  for(int i = 0; i < cantidadcaracteres; i++){
      fscanf(archivoentrada,"%c",&arreglo[i]);
  }




  

        
      /*
      
      if(ch =='.'){
          char mensaje[50] = ".    PuntoDecimal\n";
          fprintf(archivosalida,"%s",mensaje);
      }
      if(ch =='0'){
          char mensaje[50] = "0     Numero\n";
          fprintf(archivosalida,"%s",mensaje);
      }
      if(ch =='1'){
          char mensaje[50] = "1      Numero\n";
          fprintf(archivosalida,"%s",mensaje);
      }
      if(ch =='2'){
          char mensaje[50] = "2      Numero\n";
          fprintf(archivosalida,"%s",mensaje);
      }
      if(ch =='3'){
          char mensaje[50] = "3      Numero\n";
          fprintf(archivosalida,"%s",mensaje);
      }
      if(ch =='4'){
          char mensaje[50] = "4      Numero\n";
          fprintf(archivosalida,"%s",mensaje);
      }
      if(ch =='5'){
          char mensaje[50] = "5      Numero\n";
          fprintf(archivosalida,"%s",mensaje);
      }
      if(ch =='6'){
          char mensaje[50] = "6      Numero\n";
          fprintf(archivosalida,"%s",mensaje);
      }
      if(ch =='7'){
          char mensaje[50] = "7      Numero\n";
          fprintf(archivosalida,"%s",mensaje);
      }
      if(ch =='8'){
          char mensaje[50] = "8      Numero\n";
          fprintf(archivosalida,"%s",mensaje);
      }
      if(ch =='9'){
          char mensaje[50] = "9      Numero\n";
          fprintf(archivosalida,"%s",mensaje);
      }
      if(arreglo[j]!=' '||arreglo[j]!='\n'){
    */ 

  for(int j = 0;j < cantidadcaracteres;j++){
    printf("%c",arreglo[j]);
      if(arreglo[j] =='+'){
          char mensaje[50] = "+ \n";
          fprintf(archivosalida,"%s",mensaje);
      }
      if(arreglo[j] =='-'){
          char mensaje[50] = "- \n";
          fprintf(archivosalida,"%s",mensaje);
      }
      if(arreglo[j] =='%'){
          char mensaje[50] = "%\n";
          fprintf(archivosalida,"%s",mensaje);
      }
      if(arreglo[j] =='/'){
          char mensaje[50] = "/\n";
          fprintf(archivosalida,"%s",mensaje);
      }
      if(arreglo[j] =='*'){
          char mensaje[50] = "*\n";
          fprintf(archivosalida,"%s",mensaje);
      }
      if(arreglo[j] =='('){
          char mensaje[50] = "( \n";
          fprintf(archivosalida,"%s",mensaje);
      }
      if(arreglo[j] ==')'){
          char mensaje[50] = ") \n";
          fprintf(archivosalida,"%s",mensaje);
      }

      if(arreglo[j] =='^'){
          char mensaje[50] = "^ \n";
          fprintf(archivosalida,"%s",mensaje);
      }

  } 




  /* cerrando los archivos */

  fclose(archivoentrada);
  fclose(archivosalida);

  return 0;
}
