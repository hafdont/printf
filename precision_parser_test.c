#include <stdio.h>
#include "precision_parser.c"

int main()
{
    const char *formats[] = {
        "Precision: %.3f",
        "No precision here",
        "Another: %.0s",
        NULL
    };

    int index;
    for (int i = 0; formats[i] != NULL; i++) {
        index = 0;
        int precision = precision_parser(formats[i], &index);
        printf("Format: %s\nPrecision: %d\n\n", formats[i], precision);
    }

    return 0;
}

