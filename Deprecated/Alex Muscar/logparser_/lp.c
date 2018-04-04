#include <stdio.h>

#include "log_entry.h"

int main(int argc, const char *argv[])
{
    log_entry_t *entry = mk_log_entry("23/05/2014", Info, "I CAN HAZ LOG!");
    printf("%s\n", entry->msg);
    return 0;
}
