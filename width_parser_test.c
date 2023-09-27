#include <stdio.h>
#include <stdlib.h>

int width_parser(const char *format, int *index);

int main()
{
    const char *formats[] = {
        "Hello, %10s!",
        "Width: %5d",
        "No width here",
        NULL
    };

    int index;
    for (int i = 0; formats[i] != NULL; i++) {
        index = 0;
        int width = width_parser(formats[i], &index);
        printf("Format: %s\nWidth: %d\n\n", formats[i], width);
    }

    return 0;
}

