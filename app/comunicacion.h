#ifndef COMUNICACION_H
#define COMUNICACION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    /* 
     * libcurl (http://curl.haxx.se/libcurl/c) 
     */
#include <curl/curl.h>

    typedef struct curl_fetch_st {
        char *cuerpo;
        size_t tamano;
    } mensaje;

    /**
     * Función usada por CURL para almacenar la información obtenida desde la URL.
     * 
     * @param contenido Datos del contenido
     * @param largo Largo del contenido
     * @param largoBuffer largo de buffer
     * @param punteroUsuario buffer
     * @return el tamaño de los datos obtenidos
     */
    size_t curl_callback(void *contenido, size_t largo, size_t largoBuffer, void *punteroUsuario);

    /**
     * Realiza una operación GET.
     * 
     * @param url URL a obtener
     * @param datos puntero a los datos usados para el procesamiento
     * @return Código de salida de CURL
     */
    CURLcode curl_get(char *url, mensaje *datos);

#ifdef __cplusplus
}
#endif

#endif /* COMUNICACION_H */

