#include "logger.h"
#include "list.h"
#include "type_convs.h"

int main(){
    struct logger* log = create_logger("INFO");
    list* list = create_list();
    // funziona con char* ma non con int*. ||| problema in list->data** ???
    char* n; n = "yoslime";
    char* x; x = "yoslatt";
    char* a; a = "yogwassup";

    // int** n; *n = 3;
    // int** x; *x = 3;
    // int** a; *a = 3;

    append(list, a);
    // list_to_str(list);

    append(list, n);
    append(list, x);

    print_list(list);

    remove_index(list, 0);

    print_list(list);

    list = reset_list(list);

    print_list(list);

    // res = str_list_to_str(list);

    log_mex(log, "INFO", int_to_str(len(list)));

    // log_mex(log, "INFO", res);

    log_mex(log, "INFO", list->data[0]);

    destroy_list(list);
    destroy_logger(log);        

    return 0;
}