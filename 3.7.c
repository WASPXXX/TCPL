#include <stdio.h>
#include <string.h>
#define MAXLINE 1000
int getline_new(char s[], int maxline); 
int trim(char s[]); //去除字符串尾部的空格、制表和换行符

int main() {
    char s[MAXLINE];
    int n;

    while ((n = getline_new(s, MAXLINE)) >0) {
        printf("origin:%s\nlength:%lu\n", s, strlen(s));
        // printf("trimed:%s\n", trim(s));
        trim(s);
        printf("trimed:%s\nlength:%lu\n", s, strlen(s));
    }
}

int trim(char s[]) {
    int n;

    for (n = strlen(s)-1; n >= 0; n--) {
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n') {
            break;
        }
    }
    s[++n] = '\0';
    return n; 
}

int getline_new(char s[], int maxline) {
    int c, i;

    for (i=0; i<maxline-1 && (c = getchar())!=EOF && c!='\n'; i++) {
        s[i] = c;
    }
    if(c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

