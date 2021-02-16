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

    printf("\nTest libreria ctype\n");

    tst_isalnum();
    tst_isalpha();
    tst_iscntrl();
    tst_isdigit();
    tst_isgraph();
}

void tst_isalnum(){

    /* La funzione di libreria C int isalnum (int c) controlla se il carattere passato è alfanumerico. */
    int var1 = 'f';
    int var2 = '2';
    int var3 = ' ';

    printf("\nTest caratteri alfanumerici\n");
    isalnum(var1) ? printf("%c è alfanumerico",var1) : printf("%c non è alfanumerico",var1) ;
    isalnum(var2) ? printf("%c è alfanumerico",var2) : printf("%c non è alfanumerico",var2) ;
    isalnum(var3) ? printf("%c è alfanumerico",var3) : printf("%c non è alfanumerico",var3) ;
    
}

void tst_isalpha() {

    /* La funzione di libreria C int isalpha (int c) controlla se il carattere passato è alfabetico */
    int var1 = 'f';
    int var2 = '2';
    int var3 = ' ';

    printf("\nTest caratteri alfanumerici\n");
    isalpha(var1) ? printf("%c è alfabetico",var1) : printf("%c non è alfabetico",var1) ;
    isalpha(var2) ? printf("%c è alfabetico",var2) : printf("%c non è alfabetico",var2) ;
    isalpha(var3) ? printf("%c è alfabetico",var3) : printf("%c non è alfabetico",var3) ;
    

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
    
    isdigit(var1) ? printf("%c è numerico",var1) : printf("%c non è numerico",var1) ;
    isdigit(var2) ? printf("%c è numerico",var2) : printf("%c non è numerico",var2) ;

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

    printf("\nTest caratteri stampabili\n");
    
    isgraph(var1) ? printf("%c è stampabile",var1) : printf("%c non è stampabile",var1) ;
    isgraph(var2) ? printf("%c è stampabile",var2) : printf("%c non è stampabile",var2) ;
    isgraph(var3) ? printf("%c è stampabile",var3) : printf("%c non è stampabile",var3) ;

}