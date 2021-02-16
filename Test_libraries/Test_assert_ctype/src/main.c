/* assert.h 
* può essere utilizzata per verificare le ipotesi fatte dal programma e 
* stampare un messaggio diagnostico se questa ipotesi è falsa.
* La macro assert definita fa riferimento a un'altra macro NDEBUG che non fa parte di <assert.h>. 
* Se NDEBUG è definito come un nome di macro nel file di origine, nel punto in cui è incluso <assert.h>, 
* la macro assert è definita come segue: 
*
*  #define assert(ignore) ((void)0)
*  void assert(int expression)
*
*  Questa è in realtà una macro e non una funzione, che può essere utilizzata per aggiungere la diagnostica nel programma C. 
*/
#include <assert.h>
/* ctype.h
*
* dichiara diverse funzioni utili per testare e mappare i caratteri.
* Tutte le funzioni accettano int come parametro, il cui valore deve essere EOF o rappresentabile come un carattere senza segno.
* Tutte le funzioni restituiscono un valore diverso da zero (vero) se l'argomento c soddisfa la condizione descritta 
* e zero (falso) in caso contrario. 
* Alcune funzioni sono: int isalnum(int c) , int isalpha(int c) , int iscntrl(int c) ecc... 
*/
#include <ctype.h> 

extern void test_assert();
extern void test_ctype();
int main()
{
	test_assert();
	test_ctype();
	return (0);
}