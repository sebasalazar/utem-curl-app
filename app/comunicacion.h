#ifndef COMUNICACION_H
#define COMUNICACION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

    typedef struct {
        char *data;
        int body_size;
        int body_pos;
    } postdata;

    int enviar_post(char* servidor, int puerto, char* url, char* post, int desarrollo);

#ifdef __cplusplus
}
#endif

#endif /* COMUNICACION_H */

