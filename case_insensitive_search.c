#include <stdio.h>
#include <string.h>
#include <ctype.h>

void lower(char *s) {
    for (int i = 0; s[i]; i++) {
        s[i] = tolower((unsigned char)s[i]);
    }
}

int main() {
    char lines[200][300];
    int n = 0;

    while (fgets(lines[n], sizeof(lines[n]), stdin) != NULL) {
        if (lines[n][0] != '\n') n++;
    }

    char search[300];
    strcpy(search, lines[n - 1]);
    search[strcspn(search, "\n")] = '\0';

    char searchLower[300];
    strcpy(searchLower, search);
    lower(searchLower);

    int total = 0;

    for (int i = 0; i < n - 1; i++) {
        char lineCopy[300];
        strcpy(lineCopy, lines[i]);
        lower(lineCopy);

        char *p = lineCopy;
        while ((p = strstr(p, searchLower)) != NULL) {
            total++;
            p++;
        }
    }

    printf("%d\n", total);

    return 0;
}
