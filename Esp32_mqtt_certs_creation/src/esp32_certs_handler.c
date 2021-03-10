#include "esp32_certs_handler.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#define MAGIC_CODE              0xF1F1                                // CODICE INIZIALE
#define HEADER_BYTES_COUNT      8                                     // NUM TOTALE DEI BYTES DELL'HEADER PRIMA DI PKI ITEM 
#define PKI_ITEM_LENGTH_FIELDS  4                                     // NUM TOTALE DEI BYTES DEI CAMPI PRIMA DEL CERT.
#define PADDING_PKI_ITEM_LENGTH 4                                     // LENGTH PADDING


char *create_pki_esp32_item(char *certificate_data, certs_type type_of_cert)
{

  char *pki_item; 
  char *certs;
  int  length_pki_item = PKI_ITEM_LENGTH_FIELDS + (int)strlen(certificate_data) + PADDING_PKI_ITEM_LENGTH;
  int  padding_field_size;

  certs = malloc(length_pki_item);
  pki_item = malloc(PKI_ITEM_LENGTH_FIELDS);

  pki_item = create_pki_item_field((int)type_of_cert,1);                       // aggiungo il valore di type_certs
  strcat(pki_item,create_pki_item_field(0,1));                                 // aggiungo il valore dell'id è sempre 0 xchè abbiamo un solo cert
  strcat(pki_item,create_pki_item_field((int)strlen(certificate_data),2));     // creo il campo size of string cert

  sprintf(certs,"%s%s",pki_item,certificate_data);
  padding_field_size = ((4 - ((int)strlen(certificate_data) % 4)) % 4);        // in base alla length devo inserire n 0xFF come padding
  for ( int i=0;i<padding_field_size;i++){
    strcat(certs,create_pki_item_field(0xFF,1));
  }        

  return certs;

}

char *create_pki_item_field(int value, int size_of_register)
{
  
  char *tmpchar;
  char *field_string;
  
  tmpchar = malloc(1);
  field_string = malloc(size_of_register);
  
  for( int i = 0; i< size_of_register; i++ ){
    sprintf(tmpchar,"%x",((value >> (i * 8)) & 0xFF));
    strcat(field_string,tmpchar);   
  }
     
  return field_string;
} 

char *create_bin_data( char *pki_item )
{
  char *bin_data;
  int length_bin = HEADER_BYTES_COUNT + (int)strlen(pki_item); 
  
  bin_data = malloc(length_bin);
  
  strcat(bin_data,create_pki_item_field(MAGIC_CODE,2));              // magic code
  strcat(bin_data,create_pki_item_field(1,2));                       // count of list item 
  strcat(bin_data,create_pki_item_field((int)strlen(pki_item),4));   // lenght of list item
  strcat(bin_data,pki_item);                                         // pki item  
       
  return bin_data;
}

