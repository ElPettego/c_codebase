#ifndef REQUESTS_H
#define REQUESTS_H

#include "curl/curl.h"

const char* get(char* url){
    CURL* curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl){
        curl_easy_setopt(curl, CURLOPT_URL, url);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK){
            curl_easy_cleanup(curl);
            return curl_easy_strerror(res);
        }
        return res;
    }

}

#endif