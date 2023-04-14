#ifndef TYPE_CONVS_H
#define TYPE_CONVS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "list.h"

// Converts int to string
void* int_to_str(int _int){
    char* str;
    sprintf(str, "%d", _int);
    return str;
}

// Converts list of strings to string
// SEG FAULT !!! DA SISTEMARE
void* str_list_to_str(list* _list){
    char* el;
    char* result = "";
    for (int i = 0; i < _list->size; i++){
        el =  (char*)_list->data[i];
        strcat(el, "\n");
        if (i>= 1){
            strcat(result, el);
        }
    }
    return result;
}


#endif