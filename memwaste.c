#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    const int mb = 1024 * 1024;

    int megs = 0;
    int wasted = 0;
    char **wastep = NULL, *tempp = NULL;
    int i = 0, j = 0;

    if (argc < 2) {
        printf("usage: %s [n megabytes]\n", argv[0]);
        return 1;
    }

    megs = atoi(argv[1]);
    if (megs < 1) {
        printf("positive megabytes indication needed, got %d\n", megs);
        return 1;
    }

    wastep = malloc(sizeof(int *) * megs);
    if (wastep == NULL) {
        puts("memory allocation error");
        return 1;
    }
    while (wasted < megs) {
        tempp = malloc(sizeof(char) * 1024 * 1024);
        if (tempp == NULL) {
            puts("memory allocation error");
            return 1;
        }
        for (j = 0; j < mb; j++) {
            tempp[j] = 'X';
        }
        wasted++;
        wastep[i++] = tempp;
    }
    printf("holding %dM, press [Return] to release", megs);
    getchar();

    for (i = 0; i < megs; i++) {
        free(wastep[i]);
    }
    free(wastep);

    printf("released %dM, press [Return] to exit", megs);
    getchar();

    return 0;
}
