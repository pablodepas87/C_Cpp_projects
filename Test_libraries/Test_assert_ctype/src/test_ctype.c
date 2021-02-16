/* ctype.h
*
* dichiara diverse funzioni utili per testare e mappare i caratteri.
* Tutte le funzioni accettano int come parametro, il cui valore deve essere EOF o rappresentabile come un carattere senza segno.
* Tutte le funzioni restituiscono un valore diverso da zero (vero) se l'argomento c soddisfa la condizione descritta 
* e zero (falso) in caso contrario. 
* Alcune funzioni sono: int isalnum(int c) , int isalpha(int c) , int iscntrl(int c) ecc... 
*/
#include <ctype.h>
#include <stdio.h>  

void test_ctype() {

    printf("\n\nTest libreria ctype\n");

    tst_isalnum();
    tst_isalpha();
    tst_iscntrl();
    tst_isdigit();
    tst_isgraph();
    tst_isupper();
    tst_islower();
    tst_isprint();
    tst_ispunct();
    tst_isspace();
    tst_isxdigit();
    tst_tolower();
    tst_toupper();

}

void tst_isalnum(){

    /* La funzione di libreria C int isalnum (int c) controlla se il carattere passato è alfanumerico. */
    int var1 = 'f';
    int var2 = '2';
    int var3 = ' ';

    printf("\nTest caratteri alfanumerici\n");
    isalnum(var1) ? printf("%c è alfanumerico\n",var1) : printf("%c non è alfanumerico\n",var1) ;
    isalnum(var2) ? printf("%c è alfanumerico\n",var2) : printf("%c non è alfanumerico\n",var2) ;
    isalnum(var3) ? printf("%c è alfanumerico\n",var3) : printf("%c non è alfanumerico\n",var3) ;
    
}

void tst_isalpha() {

    /* La funzione di libreria C int isalpha (int c) controlla se il carattere passato è alfabetico */
    int var1 = 'f';
    int var2 = '2';
    int var3 = ' ';

    printf("\nTest caratteri alfabetici\n");
    isalpha(var1) ? printf("%c è alfabetico\n",var1) : printf("%c non è alfabetico\n",var1) ;
    isalpha(var2) ? printf("%c è alfabetico\n",var2) : printf("%c non è alfabetico\n",var2) ;
    isalpha(var3) ? printf("%c è alfabetico\n",var3) : printf("%c non è alfabetico\n",var3) ;
   
}

void tst_iscntrl(){
    
    /* La funzione di libreria C int iscntrl (int c) controlla se il carattere passato è un carattere di controllo. 
    *  In base al set di caratteri ASCII standard, i caratteri di controllo sono compresi tra i codici ASCII 0x00 (NUL), 
    *  0x1f (US) e 0x7f (DEL). Le implementazioni specifiche del compilatore per determinate piattaforme possono definire 
    *  caratteri di controllo aggiuntivi nel set di caratteri esteso (sopra 0x7f). 
    */
    int  i = 0 , j = 0 ;
    char str1[] = "all \a about \t programming";
    char str2[] = "tutorials \n point";
    
    printf("\nTest caratteri alfabetico\n");

    while (!iscntrl(str1[i]))
    {
        putchar(str1[i]);
        i++;
    }
    
    while (!iscntrl(str2[i]))
    {
        putchar(str2[i]);
        i++;
    }
    
}

void tst_isdigit() {
    /*
     La funzione di libreria C int isdigit (int c) controlla se il carattere passato è un carattere cifra decimale.
     Le cifre decimali sono (numeri) - 0 1 2 3 4 5 6 7 8 9. 
    */
     
    int var1 = 'h';
    int var2 = '2';
    
    printf("\nTest caratteri numerici\n");
    
    isdigit(var1) ? printf("%c è numerico\n",var1) : printf("%c non è numerico\n",var1) ;
    isdigit(var2) ? printf("%c è numerico\n",var2) : printf("%c non è numerico\n",var2) ;

}

void tst_isgraph() {
    /*
    * La funzione di libreria C int isgraph (int c) controlla se il carattere ha una rappresentazione grafica.
    * I caratteri con rappresentazioni grafiche sono tutti quei caratteri che possono essere stampati 
    * ad eccezione dei caratteri di spazio (come ""), che non sono considerati caratteri isgraph. 
    */
    int var1 = '3';
    int var2 = 'm';
    int var3 = ' ';

    printf("\nTest caratteri rappresentabili\n");
    
    isgraph(var1) ? printf("%c è rappresentabile\n",var1) : printf("%c non è rappresentabile\n",var1) ;
    isgraph(var2) ? printf("%c è rappresentabile\n",var2) : printf("%c non è rappresentabile\n",var2) ;
    isgraph(var3) ? printf("%c è rappresentabile\n",var3) : printf("%c non è rappresentabile\n",var3) ;

}

void tst_islower() {
    /*
     La funzione di libreria C int islower (int c) controlla se il carattere passato è una lettera minuscola. 
    */
   int var1 = 'F';
   int var2 = 'c';

   printf("\nTest carattere minuscolo\n");

   islower(var1) ? printf("%c è minuscolo\n",var1) : printf("%c è maiuscolo\n",var1);
   islower(var2) ? printf("%c è minuscolo\n",var2) : printf("%c è minuscolo\n",var2);
}

void tst_isupper() {
     /*
     La funzione di libreria C int isupper (int c) controlla se il carattere passato è una lettera maiuscola. 
    */
    int var1 = 'F';
    int var2 = 'c';

    printf("\nTest carattere maiuscolo\n");
    
    isupper(var1) ? printf("%c è maiuscolo\n",var1) : printf("%c è maiuscolo\n",var1);
    isupper(var2) ? printf("%c è maiuscolo\n",var2) : printf("%c è maiuscolo\n",var2);
}

void tst_isprint(){
    /*
    La funzione di libreria C int isprint (int c) controlla se il carattere passato è stampabile. 
    Un carattere stampabile è un carattere che non è un carattere di controllo. 
    */
    
    int var1 = 'T';
    int var2 = '\t';

    printf("\nTest carattere stampabile\n");

    isprint(var1) ? printf("%c è stampabile\n",var1) : printf("%c non è stampabile\n",var1);
    isprint(var2) ? printf("%c è stampabile\n",var2) : printf("%c non è stampabile\n",var2);
    
}

void tst_ispunct(){
    /*
    La funzione di libreria C int isprint (int c) controlla se il carattere passato è stampabile. 
    Un carattere stampabile è un carattere che non è un carattere di controllo. 
    */
    
    int var1 = 'T';
    int var2 = '\t';

    printf("\nTest carattere di controllo\n");

    isprint(var1) ? printf("%c è stampabile\n",var1) : printf("%c non è stampabile\n",var1);
    isprint(var2) ? printf("%c è stampabile\n",var2) : printf("%c non è stampabile\n",var2);
   
}

void tst_isspace(){
    /*
    La funzione di libreria C int isspace (char c) controlla se il carattere passato è uno spazio vuoto.
    ' '  (0x20)	space (SPC)
    '\t' (0x09)	horizontal tab (TAB)
    '\n' (0x0a)	newline (LF)
    '\v' (0x0b)	vertical tab (VT)
    '\f' (0x0c)	feed (FF)
    '\r  (0x0d)	carriage return (CR) 
    */
     
   int var1 = 't';
   int var2 = '1';
   int var3 = ' ';

   printf("\nTest spazi bianchi\n");

   isprint(var1) ? printf("%c è uno spazio bianco\n",var1) : printf("%c non è uno spazio bianco\n",var1);
   isprint(var2) ? printf("%c è uno spazio bianco\n",var2) : printf("%c non è uno spazio bianco\n",var2);  
   isprint(var3) ? printf("%c è uno spazio bianco\n",var3) : printf("%c non è uno spazio bianco\n",var3);   
   

}

void tst_isxdigit() {
    /*
    La funzione di libreria C int isxdigit (int c) controlla se il carattere passato è una cifra esadecimale. 
    */

    char var1[] = "tuts";
    char var2[] = "0xE";

    printf("\nTest caratteri esadecimali");

    isxdigit(var1[0]) ? printf("%s è un carattere esadecimale\n",var1) : printf("%s non è un carattere esadecimale\n",var1);
    isxdigit(var2[0]) ? printf("%s è un carattere esadecimale\n",var2) : printf("%s non è un carattere esadecimale\n",var2); 
}

void tst_tolower(){
    /*
    La funzione di libreria C int tolower (int c) converte una data lettera in minuscolo. 
    */

    int i = 0;
   
    char str[] = "CIAO MONDO!";

    printf("\nTest conversione %s in minuscolo\n",str);

    while(str[i])
    {
        putchar(tolower(str[i]));
        i++;
    }
    
}

void tst_toupper(){
    /*
    La funzione di libreria C int toupper (int c) converte le lettere minuscole in maiuscole. 
    */

    int i = 0;
    char str[] = "ciao fabio!";

    printf("\nTest conversione %s in maiuscolo\n",str);

    while(str[i])
    {
        putchar(toupper(str[i]));
        i++;
    }

}