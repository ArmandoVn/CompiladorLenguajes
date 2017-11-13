#include <stdio.h>
#include <string.h>

typedef struct Codigo{
    int token;
    struct Codigo *sig;
}cod;

FILE *archivo = NULL; //Referencia al archivo de texto.
char *nombreArchivo = "HolaMundo.txt"; //Almacenara el nombre de nuestro archivo.
int caracter; //Almacenara iterara sobre los caracteres del archivo de texto.
int tamanioLista = 0;
cod *primerElemento = NULL;
cod *ultimoElemento = NULL;
char alfa[62] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
                    'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7',
                    '8', '9', '+', '-', '*', '/', '%', '<', '>', '!', '=', ';', ',', '(', ')', 'V', 'F', '"',
                    (char)39, '|', 'Y', 'O', 'N', ' ', '#', (char)10, '@','.'};


void agregarTokenLista(int token){
    cod *aux = malloc(sizeof(cod));
    aux->token = token;
    aux->sig = NULL;
    if(primerElemento == NULL){
        primerElemento = aux;
        ultimoElemento = aux;
    }else{
        ultimoElemento->sig = aux;
        ultimoElemento = aux;
    }
}


void abrirArchivo(){

    int aux = 0;

    archivo = fopen(nombreArchivo, "r"); //Abrimos el archivo de texto.

    if(archivo == NULL){ //Comprobamos que el archivo se alla abierto con exito.
        printf("Error al intentar abrir el archivo.");
        return -1;
    }

    //printf("El contenido del archivo es:\n");
    while((caracter = fgetc(archivo)) != EOF){ //Mostramos el contenido del archivo de texto.
        //printf("%c", caracter);
        agregarTokenLista(caracter);
        //aux++;
    }

    //printf("\nEl numero de caracteres que contiene el archivo fuente es de: %i", aux);
    fclose(archivo);
}

int main(){

    int aux = 0;
    cod *aux1;

    abrirArchivo();

    aux1 = primerElemento;
    while(aux1 != NULL){
        printf("%c", aux1->token);
        aux1 = aux1->sig;
        aux++;
    }

    printf("\nEl numero de caracteres que contiene el archivo fuente es de: %i", aux);


    return 0;
}
