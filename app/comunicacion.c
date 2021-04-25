#include "comunicacion.h"

size_t curl_callback(void *contenido, size_t largo, size_t largoBuffer, void *punteroUsuario) {
    /*
     * Calcula el largo real.
     */
    size_t largoReal = largo * largoBuffer;
    /*
     * Casteamos el puntero de usuario al tipo mensaje para manejar los datos
     */
    mensaje *datos = (mensaje *) punteroUsuario;

    /*
     * Se expande la memoria en función del tamaño real más el fin de linea
     */
    char * temp = realloc(datos->cuerpo, datos->tamano + largoReal + 1);

    /*
     * Comprobamos la memoria
     */
    if (temp == NULL) {
        /*
         * MALA COSA...
         */
        fprintf(stderr, "ERROR: No fue posible obtener la memoria necesaria");
        /* 
         * Liberamos el buffer 
         */
        free(datos->cuerpo);
        /* 
         * terminamos el programa 
         */
        return 1;
    }

    /* 
     * asignamos los datos temporales al cuerpo del mensaje 
     */
    datos->cuerpo = temp;

    /* 
     * copiamos el contenido del buffer 
     */
    memcpy(&(datos->cuerpo[datos->tamano]), contenido, largoReal);

    /* 
     * Asignamos el nuevo tamaño 
     */
    datos->tamano += largoReal;

    /* 
     * Colocamos el fin de linea 
     */
    datos->cuerpo[datos->tamano] = '\0';

    /* retornamos el largo final */
    return largoReal;
}

CURLcode curl_get(char *url, mensaje *datos) {
    CURLcode codigo;

    /* 
     * instanciamos los datos de la estructura 
     */
    datos->cuerpo = (char *) calloc(1, sizeof (datos->cuerpo));

    /*
     * Revisamos el cuerpo 
     */
    if (datos->cuerpo == NULL) {
        /* 
         * Mala cosa
         */
        fprintf(stderr, "ERROR: No hay memoria para procesar");
        /*
         * Terminamos el programa con el código de salida adecuado 
         */
        return CURLE_FAILED_INIT;
    }

    /* 
     * Instanciamos el tamaño mínimo
     */
    datos->tamano = 0;

    /*
     * Creamos la variable curl
     */
    CURL *curl = curl_easy_init();

    /* Definimos la url a obtener */
    curl_easy_setopt(curl, CURLOPT_URL, url);

    /* Definimos la función para almacenar los datos */
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_callback);

    /* Pasamos la estructura donde almacenar la información */
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) datos);

    /* Opcional: Colocamos el agente de usuario */
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "UTEM/1.0");

    /* Definimos un TimeOut */
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 15);

    /* Permitimos la redirección si corresponde */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);

    /* Definimos la cantidad máxima de redirecciones */
    curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 1);

    /* Obtenemos la infomación */
    codigo = curl_easy_perform(curl);

    /* Limpiamos el puntero */
    curl_easy_cleanup(curl);

    /* retornamos el código */
    return codigo;
}
