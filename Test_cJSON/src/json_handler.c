#include <stdio.h> 
#include "../include/cJSON.h"
#include <stdlib.h>
void createJson() {
    FILE  *fp; 
    char  *json_string = NULL;
    cJSON *studente = cJSON_CreateObject();
    cJSON *nomeStudente =NULL;
    
    nomeStudente = cJSON_CreateString("Fabio");
    /* Esempio usando cJSON_AddItemToObject che vuolr in ingresso l'oggetto , nome della chiave e l'elemento CJSON */
    cJSON_AddItemToObject(studente,"nome",nomeStudente); 
    /* ora utilizzo cJSON_AddStringToObject che prende in ingresso oggetto, , stringa key , stringa valore */
    cJSON_AddStringToObject(studente,"cognome","Rapicano");
    /* ora aggiungo l'età che è un numero con cJSON_AddNumberToObject */
    cJSON_AddNumberToObject(studente,"età",33) ;

    fp = fopen("studente.json","w");
    json_string = cJSON_Print(studente);
    fprintf(fp,json_string);
    fclose(fp);
}

char *parseJson() {
    FILE *fp;
    char *buffer;
    long fileSize;
    if ((fp = fopen("studente.json","r"))== NULL){
        printf("Open file Error");
    }
    
    fseek(fp,0L,SEEK_END);  // mi posiziono alla fine del file in modo da conoscere quanti char ho
    fileSize = ftell(fp);   // restituisce i byte dalla posizione del puntatore del file
    rewind(fp);             // mi rimetto alla posizione 0 

    buffer = calloc(1,fileSize+1); // Allocates the requested memory and returns a pointer to it.

    fread(buffer,fileSize,1,fp);   // copio tutto il file nel buffer ottenendo una stringa

    //printf("%s",buffer);
    return buffer;
}