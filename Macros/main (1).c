#include <stdio.h>
#include <stdlib.h>

#define COMMAND(NAME, TYPE) TYPE##_##NAME##_command

#define DEFINE_COMMAND(NAME, TYPE) \
    void COMMAND(NAME, TYPE)() { \
        printf("This is the %s command.\n", #NAME); \
    }

DEFINE_COMMAND(func1, internal)

DEFINE_COMMAND(func2, external)

int main()
{
    internal_func1_command();
    external_func2_command();
}
