#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

int getline_new(char line[], int max);
double atof_new(char s[]);
int testing(void);

int main() {
    char line[MAXLINE];
    testing();
    while (getline_new(line, MAXLINE) > 0) {
        printf("%f\n", atof_new(line));
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

double atof_new(char s[]) {
    double val, power;
    int i, sign;

    i = 0;

/*    for (i = 0; isspace(s[i]); i++) {
        ;
    }*/

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.') {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    return sign * val / power;
}

int testing() {
    printf("sup\n");
    return 0;
}

