#include <stdio.h>
#include "main.h"

int main() {
    const char *formats[] = {
        "%d",
        "%-10s",
        "%+08x",
        "%#o",
        "% 10.2f",
        "%#x",
        "%-#12.5f",
        "%0",
        NULL
    };

    int index;
    for (int i = 0; formats[i] != NULL; i++) {
        index = 0;
        int flags = get_flags(formats[i], &index);
        printf("Format: %s\nFlags: %d\n\n", formats[i], flags);
    }

    return 0;
}
