#include <stdio.h>
#define MAXLINE 1000

int getline_new(char line[], int max);
int strindex(char src[], char pattern[]); //将输入中包含特定模式的字符串所在行打印出来

char pattern[] = "wasp";

int main() {
    char line[MAXLINE];
    int found = 0;

    while (getline_new(line, MAXLINE) > 0) {
        if (strindex(line, pattern) >= 0) {
            printf("%s\n", line);
            found++;
        }
    }
    return found;
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

int strindex(char s[], char t[]) {
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
            ;
        }
        if (k > 0 && t[k] == '\0') {
            return i;
        }
    }
    return -1;
}