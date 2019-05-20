#include <stdio.h>
#define MAXLINE 1000
int getline_new(char s[], int maxline); 
void escape_new(char s[], char t[]); /*字符串t复制到字符串s中，并将换行符、制表符等不可见字符转换为可见的转义字符*/
void unescape_new(char s[], char t[]); /*相反*/

int main() {
    char line[MAXLINE], cline[MAXLINE];
    while (getline_new(line, MAXLINE) > 0) {
        printf("input:\t %s", line);
        unescape_new(cline, line);
        printf("output:\t %s", cline);
        printf("dd\n");
    }
}

void escape_new(char s[], char t[]) {
    int i, j;
    i = j = 0;

    while (t[i] != '\0') {
        switch(t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                i++;
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                i++;
                break;
            default:
                s[j++] = t[i++];
                break;
        }
    }
    s[j] = '\0';
}

void unescape_new(char s[], char t[]) {
    int i, j;
    i = j = 0;

    while (t[i] != '\0') {
        switch(t[i]) {
            case '\\':
                switch(t[++i]) { 		//注意这里i++和++i使用的区别
                    case 'n':
                        s[j++] = '\n';
                        break;
                    case 't':
                        s[j++] = '\t';
                        break;
                    default:
                        s[j++] = '\\';
                        s[j++] = t[i];
                        break;
                }
                i++;
                break;
            default:
                s[j++] = t[i++];
                break;
        }
    }
    s[j] = '\0';
}

int getline_new(char s[], int lim) {
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i; //i即是含换行符的字符串长度
}