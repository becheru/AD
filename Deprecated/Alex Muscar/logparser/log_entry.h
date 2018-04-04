#ifndef __LOG_ENTRY_H__
#define __LOG_ENTRY_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    LE_DATE,
    LE_MSG,
    LE_MEM
} log_err_t;

typedef enum
{
    Info,
    Warning,
    Error
} log_level_t;

typedef struct 
{
    char *date;
    log_level_t level;
    char *msg;
} log_entry_t;

log_entry_t *mk_log_entry(char *date, log_level_t level, char *msg);

#endif
