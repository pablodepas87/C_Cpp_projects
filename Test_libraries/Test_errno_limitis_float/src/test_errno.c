#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <math.h>
 
/*
  Il file di intestazione errno.h della libreria standard C definisce la variabile intera errno, 
  che viene impostata dalle chiamate di sistema e da alcune funzioni di libreria in caso di errore per indicare cosa è andato storto. 
  Questa macro si espande in un valore modificabile di tipo int, quindi può essere sia letta che modificata da un programma.

  L'errno è impostato su zero all'avvio del programma. Alcune funzioni della libreria C standard 
  modificano il proprio valore su un valore diverso da zero per segnalare alcuni tipi di errore. 
  Puoi anche modificarne il valore o reimpostarlo a zero a tuo piacimento.

  Il file di intestazione errno.h definisce anche un elenco di macro che indicano diversi codici di errore, 
  che si espanderà in espressioni costanti intere con tipo int. 

*/

/*
    The C library macro extern int errno is set by system calls 
    and some library functions in the event of an error to indicate if anything went wrong.
*/

extern int errno;

void test_extern_errno(){

   FILE *fp;

   fp = fopen("file.txt", "r");
   if( fp == NULL ) {
      fprintf(stderr, "Value of errno: %d\n", errno);
      fprintf(stderr, "Error opening file: %s\n", strerror(errno));
   } else {
      fclose(fp);
   }
}

/*
    la macro della libreria C EDOM rappresenta un errore di dominio, che si verifica se un argomento di input è esterno al dominio, 
    sul quale è definita la funzione matematica e errno è impostato su EDOM. 
*/

#define EDOM 10

void test_define_errno(){
    double val;

   errno = 0;
   val = sqrt(-10);
   
   if(errno == EDOM) {
      printf("Invalid value \n");
   } else {
      printf("Valid value\n");
   }
   
   errno = 0;
   val = sqrt(10);
   
   if(errno == EDOM) {
      printf("Invalid value\n");
   } else {
      printf("Valid value\n");
   }
}

/*
La macro della libreria C ERANGE rappresenta un errore di intervallo, che si verifica se un argomento di input è al di fuori dell'intervallo, 
oltre il quale è definita la funzione matematica e errno è impostato su ERANGE.
*/ 

#define ERANGE 15

void test_range_errno(){

   double x;
   double value;

   x = 2.000000;
   value = log(x);
   
   if( errno == ERANGE ) {
      printf("Log(%f) is out of range\n", x);
   } else {
      printf("Log(%f) = %f\n", x, value);
   }

   x = 1.000000;
   value = log(x);
   
   if( errno == ERANGE ) {
      printf("Log(%f) is out of range\n", x);
   } else {
      printf("Log(%f) = %f\n", x, value);
   }
   
   x = 0.000000;
   value = log(x);
   
   if( errno == ERANGE ) {
      printf("Log(%f) is out of range\n", x);
   } else {
      printf("Log(%f) = %f\n", x, value);
   }
}