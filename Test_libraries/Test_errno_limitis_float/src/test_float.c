/*
Il file di intestazione float.h della libreria standard C contiene un insieme di varie costanti 
dipendenti dalla piattaforma relative ai valori in virgola mobile. 
Queste costanti sono proposte da ANSI C. Consentono di creare programmi più portabili. 
Prima di controllare tutte le costanti, è bene capire che il numero in virgola mobile è composto dai seguenti quattro elementi: 
S : segno ( +/- )
b : base o radice della rappresentazione esponente, 2 per binario, 10 per decimale, 16 per esadecimale e così via ... 
e : esponente, un numero intero compreso tra un minimo emin e un massimo emax. 
p : precisione, il numero di cifre in base b nel significato. 

I seguenti valori sono specifici dell'implementazione e definiti con la direttiva #define, 
ma questi valori non possono essere inferiori a quelli forniti qui. 
Notare che in tutti i casi FLT si riferisce al tipo float, DBL si riferisce a double e LDBL si riferisce a long double. 

FLT_ROUNDS : Definisce la modalità di arrotondamento per l'aggiunta in virgola mobile e può avere uno dei seguenti valori: 
    1 − indeterminable ; 0 − towards zero ; 1 − to nearest ; 2 − towards positive infinity ; 3 − towards negative infinity

FLT_RADIX 2: Definisce la rappresentazione della radice di base dell'esponente. Una base-2 è binaria, base-10 è la normale rappresentazione decimale, base-16 è esadecimale. 

FLT_MANT_DIG
DBL_MANT_DIG
LDBL_MANT_DIG: Queste macro definiscono il numero di cifre nel numero (nella base FLT_RADIX). 

FLT_DIG 6
DBL_DIG 10
LDBL_DIG 10: Queste macro definiscono il numero massimo di cifre decimali (base 10) che possono essere rappresentate senza modifiche dopo l'arrotondamento. 

FLT_MIN_EXP
DBL_MIN_EXP
LDBL_MIN_EXP: queste macro definiscono il valore intero negativo minimo per un esponente in base FLT_RADIX. 
 	
FLT_MIN_10_EXP -37
DBL_MIN_10_EXP -37
LDBL_MIN_10_EXP -37: Queste macro definiscono il valore intero negativo minimo per un esponente in base 10. 

FLT_MAX_EXP
DBL_MAX_EXP
LDBL_MAX_EXP: Queste macro definiscono il valore intero massimo per un esponente in base FLT_RADIX. 
 	
FLT_MAX_10_EXP +37
DBL_MAX_10_EXP +37
LDBL_MAX_10_EXP +37:Queste macro definiscono il valore intero massimo per un esponente in base 10. 
 	
FLT_MAX 1E+37
DBL_MAX 1E+37
LDBL_MAX 1E+37:Queste macro definiscono il valore in virgola mobile finito massimo. 

FLT_EPSILON 1E-5
DBL_EPSILON 1E-9
LDBL_EPSILON 1E-9: Queste macro definiscono la cifra meno significativa rappresentabile. 

FLT_MIN 1E-37
DBL_MIN 1E-37
LDBL_MIN 1E-37: Queste macro definiscono i valori in virgola mobile minimi. 

*/
#include <stdio.h>
#include <float.h>
void test_float(){
   printf("The maximum value of float = %.10e\n", FLT_MAX);
   printf("The minimum value of float = %.10e\n", FLT_MIN);

   printf("The number of digits in the number = %.10e\n", FLT_MANT_DIG);
}