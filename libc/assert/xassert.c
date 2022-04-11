#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void _Assert(char *msg)
    {
        fputs(msg, stderr);
        fputs(" -- assertion failed\n", stderr);
        fputs("Continue (y/n)? ", stderr);
        abort();
    }