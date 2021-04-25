#ifndef PARSEADOR_H
#define PARSEADOR_H

#ifdef __cplusplus
extern "C" {
#endif

    /*
     * json-c (https://github.com/json-c/json-c) 
     */
#include <json-c/json.h>

    /**
     * Procesa un texto json especifico del API.
     * 
     * @param texto Datos del JSON
     * @return El monto de la UF
     */
    int obtenerIndicador(char* texto);


#ifdef __cplusplus
}
#endif

#endif /* PARSEADOR_H */

