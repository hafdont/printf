#include "main.h"

int main()
{
    const char *formats[] =
    {
        "%hd",
        "%ld",
        "%hhc",
        "%jd",
        "%zd",
        "%td",
        "%hhld",
        "%zlt",
        NULL
    };

    int index;
    for (int i = 0; formats[i] != NULL; i++) {
        index = 0;
        const char *size = get_size(formats[i], &index);
        
        if (size != NULL) {
            printf("Format: %s\nSize Specifier: %s\n\n", formats[i], size);
            free((char *)size); // Free the dynamically allocated memory
        } else {
            printf("Format: %s\nNo Size Specifier\n\n", formats[i]);
        }
    }

    return 0;
}
