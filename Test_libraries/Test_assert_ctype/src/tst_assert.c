#include <assert.h>
#include <stdio.h>


void test_assert(){
    
    int a ;
    char str[50];

    printf("Inserire un numero intero:");
    scanf("%d",&a);
    assert(a>=10);                          // se valore minore di 10 salta il programma xchè nn gestisco l'asserzione
    printf("Il valore inserito è: %d\n", a);

    printf("Inserire una stringa:");
    scanf("%s",str);
    assert(str != NULL);
    printf("La stringa inserita è:%s",str);

}