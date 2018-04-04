#ifndef __LOG_ENTRY_H__
#define __LOG_ENTRY_H__

#include <stdlib.h>
#include <string.h>

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

log_entry_t *mk_log_entry(const char *date, log_level_t level, const char *msg);

#endif
