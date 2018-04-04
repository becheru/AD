#include "log_entry.h"

const int LE_DATE_SIZE = 11;
const int LE_MSG_SIZE = 1024;

log_entry_t *mk_log_entry(char *date, log_level_t level, char *msg, log_err_t *err)
{
    log_entry_t *entry = (log_entry_t *) malloc(sizeof(log_level_t));
    if (!entry)
    {
        perror("malloc");
        *err = LE_MEM;
        return NULL;
    }
    entry->date = (char *) malloc(11);
    if (!entry->date)
    {
        perror("malloc");
        *err = LE_MEM;
        return NULL;
    }

    if (strlen(date) >= LE_DATE_SIZE)
    {
        *err = LE_DATE;
        return NULL;
    }

    strcpy(entry->date, date);

    entry->msg = (char *) malloc(1024);
    if (!entry->msg)
    {
        perror("malloc");
        *err = LE_MEM;
        return NULL;
    }

    if (strlen(msg) >= LE_MSG_SIZE)
    {
        *err = LE_MSG;
        return NULL;
    }

    strcpy(entry->msg, msg);

    entry->level = level;
    return entry;
}
