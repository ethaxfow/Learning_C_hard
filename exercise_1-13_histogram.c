#include <stdio.h>

#define IN 1            /* inside a word */
#define OUT 0           /* outside a word */
#define MAX_LENGTH 100

int main() {
    char c;
    int i, j, k, status, length, max_wl, show_times;
    int word[MAX_LENGTH];
    i = j = k = show_times = length = max_wl = 0;
    status = OUT;

    for(i = 1; i <= MAX_LENGTH; i++)
        word[i] = 0;

    while((c = getchar()) != EOF) {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            if(status == OUT) {
                status = IN;
                ++ word[length];
                length = 1;
            } else {
                ++ length;
            }
        else {
            status = OUT;
        }
    }
    ++ word[length];
    printf("\n");

    for(i = 1; i < MAX_LENGTH; i++) {
        if (word[i] > max_wl)
            max_wl = word[i];
        if (word[i] && i > show_times)
            show_times = i;

    }

    for(i = 0; i < 60; i++)
        printf("=");
    printf("\n");
    /* horizontal histogram */

    printf("\nhorizontal histogram\n\n");
    printf("length | times\n");
    for(i = 1; i <= show_times; i++) {
        printf("%6d | ", i);
        for(j = 1; j <= word[i]; j++)
            printf("*");
        printf("\n");
    }
    printf("\n");
    for(i = 0; i < 60; i++)
        printf("+");
    printf("\n");

    /* vertical histogram */
    printf("\nhorizontal histogram\n");
    printf("\ntimes|\n");
    for(k = max_wl; k > 0; k--) {
        printf("%4d |    ", k);
        for(i = 1; i <= show_times; i++) {
            if(word[i] < k)
                printf("    ");
            else
                printf("*   ");
        }
        printf("\n");    
    }
    printf("      ");
    for(i = 1; i <= show_times; i++)
        printf("-----");
    printf("\n       ");
    for(i = 1; i <= show_times; i++)
        printf("%4d", i);
    printf("   length\n");
    printf("\n");

    return 0;
}
