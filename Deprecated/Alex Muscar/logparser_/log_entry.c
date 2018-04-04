#include "log_entry.h"

const int LE_DATE_LEN = 11;
const int LE_MSG_LEN = 1024;

log_entry_t *mk_log_entry(const char *date, log_level_t level, const char *msg)
{
    log_entry_t *entry = (log_entry_t *) malloc(sizeof(log_entry_t));

    if (!entry)
    {
        perror("entry");
        return NULL;
    }

    if (strlen(date) >= LE_DATE_LEN)
    {
        return NULL;
    }

    entry->date = (char *) malloc(strlen(date) + 1);

    if (!entry->date)
    {
        perror("date");
        return NULL;
    }

    strcpy(entry->date, date);
    entry->level = level;

    if (strlen(msg) >= LE_MSG_LEN)
    {
        return NULL;
    }

    entry->msg = (char *) malloc(strlen(msg) + 1);

    if (!entry->msg)
    {
        perror("msg");
        return NULL;
    }

    strcpy(entry->msg, msg);
    return entry;
}
