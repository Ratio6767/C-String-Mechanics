#include <stdio.h>
#include <string.h>

void printLatinWord(char *w) {
    int len = strlen(w);
    char first = w[0];
    for (int i = 1; i < len; i++) putchar(w[i]);
    putchar(first);
    printf("ay");
}

int main() {
    char s[300];
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    char *t = strtok(s, " ");
    int first = 1;

    while (t != NULL) {
        if (!first) printf(" ");
        printLatinWord(t);
        first = 0;
        t = strtok(NULL, " ");
    }

    return 0;
}
