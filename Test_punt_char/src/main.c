#include <stdio.h>
#include <string.h>
/* https://www.microchip.com/forums/m955412.aspx 
   x spiegazione sul motivo
*/
typedef struct {
	const char *nome;    // senza const ho un errore di assegnazione
	const char *cognome;
} persona;


int main()
{
	persona alunno;
	const char str1 [] = "Fabio"; 
    const char str2 [] = "Rapicano";
	
	alunno.nome = str1;
	alunno.cognome = str2;

	printf("nome:%s\n",alunno.nome);
	printf("cognome:%s\n",alunno.cognome);

    return (0);
}