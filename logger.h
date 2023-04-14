#ifndef LOGGER_H
#define LOGGER_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define C_RED     "\x1b[31m"
#define C_GREEN   "\x1b[32m"
#define C_YELLOW  "\x1b[33m"
#define C_BLUE    "\x1b[34m"
#define C_MAGENTA "\x1b[35m"
#define C_CYAN    "\x1b[36m"
#define C_RESET   "\x1b[0m"

#define B_GREY "\x1b[40m"

/*
LOGGER LEVELS
0 -> DEBUG
1 -> INFO
2 -> WARNING
3 -> ERROR
*/

typedef struct logger {
    char level[10];
    int log_lev;
} logger;

// Destroys logger object
void destroy_logger(logger* _logger){
    free(_logger);
}

// Creates logger object
logger* create_logger(char* level){
    logger* logger = malloc(sizeof(logger));
    if (logger != NULL) {
        strcpy(logger->level, level);
        if (level=="DEBUG"){logger->log_lev = 0;}
        if (level=="INFO"){logger->log_lev = 1;}
        if (level=="WARNING"){logger->log_lev = 2;}
        if (level=="ERROR"){logger->log_lev = 3;}
    }
    return logger;
}

// Logs message to stdout
void log_mex(logger* logger, const char* level, const char* message){    
    int log_lev;
    time_t now;
    time(&now);
    char timestamp[20];
    char _timestamp[35];
    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
    sprintf(_timestamp, "%s%s%s%s", B_GREY, C_MAGENTA, timestamp, C_RESET);
    char _level[28];
    if (level == "DEBUG"){sprintf(_level, "%sDEBUG%s", C_CYAN, C_RESET);log_lev = 0;}
    if (level == "INFO"){sprintf(_level, "%sINFO%s", C_GREEN, C_RESET);log_lev = 1;}
    if (level == "WARNING"){sprintf(_level, "%sWARNING%s", C_YELLOW, C_RESET);log_lev = 2;}
    if (level == "ERROR"){sprintf(_level, "%sERROR%s", C_RED, C_RESET);log_lev = 3;}

    int reserved_length = 16;
    int str_len = strlen(_level);
    int padding = reserved_length - str_len;
    int left_padding = padding/2;
    int right_padding = padding - left_padding;
    
    if (logger->log_lev <= log_lev){
        printf("%s - %*s%s%*s - %s\n", _timestamp, left_padding, "", _level, right_padding, "", message);
    }
} 

#endif /* LOGGER_H */