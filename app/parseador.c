#include "parseador.h"

int obtenerIndicador(char* texto) {
    int resultado = 0;

    /*
     * Parseo de error
     */
    enum json_tokener_error jerr = json_tokener_success;

    /*
     * Objeto JSON
     */
    json_object *json = json_object_new_object();
    json = json_tokener_parse_verbose(texto, &jerr);

    json_object *serie = json_object_object_get(json, "serie");
    if (serie != NULL) {
        json_object *valor = json_object_array_get_idx(serie, 0);
        json_object *uf = json_object_object_get(valor, "valor");

        char* numero = (char *) json_object_to_json_string_ext(uf, JSON_C_TO_STRING_SPACED | JSON_C_TO_STRING_PRETTY);
        resultado = (int) atof(numero);
    }

    /*
     * Liberamos la memoria
     */
    json_object_put(json);

    return resultado;
}

