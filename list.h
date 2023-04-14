#ifndef LIST_H
#define LIST_H

#define INIT_CAP 1

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

typedef struct {
    int size;
    int cap;
    void** data;    
} list;

// Destroys list object
void destroy_list(list* _list){
    free(_list->data);
    free(_list);
}

// Creates list object
list* create_list(){
    list* _list = (list*)malloc(sizeof(list));
    _list->cap = INIT_CAP;
    _list->size = 0;
    _list->data = (void*)malloc(INIT_CAP * sizeof(void*)); 
    return _list;
}

// Destroys the list passed as parameters and returns a new empty list
list* reset_list(list* _list){
    destroy_list(_list);
    return create_list();
}

// Returns length of list
int len(list* _list){
    return _list->size;
}

// Appends element at the end of a list
void append(list* _list, void* element){
    _list->size++;
    if (_list->size == _list->cap){
        _list->cap ++;
        _list->data = (void*) realloc(_list->data, _list->cap*sizeof(void*));
    }
    _list->data[_list->size-1] = element;
}

// Removes element at specified index
void remove_index(list* _list, int index){
    if (index >= 0 && index < _list->size) {
        for (int i = index + 1; i < _list->size; i++) {
            _list->data[i - 1] = _list->data[i];
        }
        _list->size--;
    }

}

// Prints list to stdout
void print_list(list* _list){
    printf("[");
    for (int i = 0; i < _list->size; i++){
        int end = i == _list->size-1;
        printf("%s", (char*)_list->data[i]);
        if (end == 0){
            printf(", ");
        }
    }
    printf("]\n"); 

}

#endif