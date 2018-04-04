#include <stdio.h>
#include <string.h>
#include <limits.h>

int edit(const char *s1, const char *s2)
{
    int a[100][100];
    int m = strlen(s1);
    int n = strlen(s2);

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            a[i][j] = INT_MIN;

    while (*s1 && *s2) {
        if 
    }

    return 0;
}

int main(int argc, const char *argv[])
{
    return 0;
}
