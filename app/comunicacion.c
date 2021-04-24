#include "comunicacion.h"

int enviar_post(char* servidor, int puerto, char* url, char* post, int desarrollo) {
    CURL *curl;
    CURLcode res;

    char* conexion = (char *) calloc(strlen(servidor) + strlen(url) + 15, sizeof (char));
    sprintf(conexion, "https://%s:%d%s", servidor, puerto, url);

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Utem/1.0");
        curl_easy_setopt(curl, CURLOPT_URL, conexion);
        curl_easy_setopt(curl, CURLOPT_COOKIEFILE, ""); // memorua
        curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_1);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post);

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return (int) res;
}

