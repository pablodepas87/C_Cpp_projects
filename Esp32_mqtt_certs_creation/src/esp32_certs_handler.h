#ifndef ESP32_CERTS_HANDLER
#define ESP32_CERTS_HANDLER

// enum che definisce i 3 tipi di certificati da creare
typedef enum {
    CA_CERTS = 0x01,
    CLIENT_CERTS,
    CLIENT_PV_KEY
} certs_type;

/*

    devo creare questa struttura nel nostro caso list items è formato da un unico certificato
        | <- 2 bytes -> | <- 2 bytes -> | <- 4 bytes -> | <- total length -> |
        +---------------+---------------+---------------+--------------------+
        |   magic code  |  list size    |     length    |    list items      |
        +---------------+---------------+---------------+--------------------+

        magic code: 0xF1F1
        list size: count of total items
        length: total length of list items
        item cert: cert item

*/

char *create_bin_data( char *pki_item );

/* routine x creare il contenuto di un PKI (public key infrastructure)

       PKI item:

       | <- 1 byte -> | <- 1 byte -> | <- 2 bytes -> | <- content len -> | <- (4-len%4) % 4 bytes -> |
       +--------------+--------------+---------------+-------------------+---------------------------+
       |     type     |     ID       | content len   |    raw data       | padding for 4 bytes align |
       +--------------+--------------+---------------+-------------------+---------------------------+

       type: item type
           0x01: CA
           0x02: certificate
           0x03: key
       ID: used to match cert and key.
       content len: raw data length
*/
char *create_pki_esp32_item(char *certificate_data, certs_type type_of_cert);

// routine di conversione in char dei valori che rappresentano i campi del certificato come nello schema su

char *create_pki_item_field(int value, int size_of_register);



#endif