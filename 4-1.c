#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline_new(char line[], int max);
int strrindex(char src[], char pattern[]); // 返回字符串p在s中最右边出现的位置

char pattern[] = "wasp";

int main() {
    char line[MAXLINE];
    while (getline_new(line, MAXLINE) > 0) {
        printf("%d\n", strrindex(line, pattern));
    }
}

int getline_new(char line[], int max) {
    int c, i;
    i = 0;

    while (--max > 0 && (c=getchar()) != EOF && c != '\n') {
        line[i++] = c;
    }
    if (c == '\n') {
        line[i++] = c;
    }
    line[i] = '\0';
    return i;
}

int strrindex(char s[], char t[]) {
    int i, j, k;

    for (i = strlen(s); i >= (strlen(s) - strlen(t)); i--) {
        for (j=i-1, k=strlen(t)-1; s[j] == t[k]; j--, k--) {
            if (t[k] == t[0]) {
                return j;
            }
        }
    }
/*    for (i = strlen(s) - strlen(t); i >= 0; i--) {
        for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
            ;
        }
        if (k>0 && t[k] == '\0') {
            return i;
        }
    }*/
    return -1;
}