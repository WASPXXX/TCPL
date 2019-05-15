#include <stdio.h>

int main() {  /*统计各个数字、空白符和其他字符出现的次数*/
    int i, c;
    int nwhite, nother, ndigits[10];

    nwhite = nother = 0;
    for (i = 0; i<10; i++) {
        ndigits[i] = 0;
    }
    while ((c = getchar()) != EOF) {
        switch(c) {
            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                ndigits[c - '0']++;
                break;
            case ' ': case '\n': case '\t': 
                nwhite++;
                break;
            default:
                nother++;
                break;  
        }
    }

    printf("digits(0-9):");
    for (i = 0; i < 10; i++) {
        printf(" %d", ndigits[i]);
    }
    printf("\nwhite space: %d\nother = %d\n", nwhite, nother);
    return 0;
}