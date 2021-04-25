#include <stdio.h>
#include <stdlib.h>
#include "comunicacion.h"
#include "parseador.h"

/**
 * Este programa busca obtener los indicadores económicos de la uf, usando 
 * los datos de https://mindicador.cl/
 * 
 * @param argc Cantidad de argumentos procesados por la línea de comandos.
 * @param argv Matriz asociativa con los argumentos.
 * @return El código de salida
 */
int main(int argc, char** argv) {

    if (argc < 4) {
        fprintf(stdout, "\nArgumentos insuficientes, se debe ejecutar: %s AAAA MM DD", argv[0]);
        fprintf(stdout, "\nEjemplo: \t%s 2021 03 13\n", argv[0]);
        return (EXIT_FAILURE);
    }

    int anio = atoi(argv[1]);
    int mes = atoi(argv[2]);
    int dia = atoi(argv[3]);

    /*
     * Calcularemos el largo de la url
     * "https://mindicador.cl/api/uf/" (Por profilaxis dejaremos una base 40)
     * los 3 corresponde a los caracteres para construir la fecha
     */
    int largo = 40 + strlen(argv[1]) + strlen(argv[2]) + strlen(argv[3]) + 3;
    char* url = (char *) calloc(largo, sizeof (char));
    snprintf(url, largo, "https://mindicador.cl/api/uf/%d-%d-%d", dia, mes, anio);

    /*
     * Mensaje procesado
     */
    mensaje datos;
    CURLcode codigo = curl_get(url, &datos);
    if (CURLE_OK == codigo) {
        int indicador = obtenerIndicador(datos.cuerpo);
        fprintf(stderr, "\n$ %d\n", indicador);
    } else {
        fprintf(stderr, "\n%s\n", datos.cuerpo);
    }

    /*
     * Liberamos la memoria
     */
    free(datos.cuerpo);
    free(url);

    return (EXIT_SUCCESS);
}

