#include <stdio.h>
#include <string.h>

void printd_w(int n); //十进制数 → 字符串
void reverse_w(char s[]); //字符串倒置
void reverser_w(char s[], int i, int len); //递归实现

int main() {
    int i;
    int n[3] = {123, 456, 789};
    i = 0;
    while (i < 3) {
        printd_w(n[i++]);
    }
    printf("\n---\n");
    char line[] = "aabbccdd";
    reverse_w(line);
    printf("%s\n", line);
    return 0;
}

void printd_w(int n) {
    if (n < 0) {
        n = -n;
        putchar('-');
    }
    if (n / 10) {
        printd_w(n / 10);
    }
    putchar(n % 10 + '0');
}

void reverse_w(char s[]) {
    // void reverser_w(char s[], int i, int len);
    reverser_w(s, 0, strlen(s));
}

void reverser_w(char s[], int i, int len) {
    int c, j;

    j = len - (i + 1);
    if (i < j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        reverser_w(s, ++i, len);
    }

}
/*void reverse_w(char s[]) {
    char ct, i, j, k;
    char t[strlen(s)];

    t[0] = s[0];
    t[strlen(s) - 2] = s[strlen(s) - 2];

    i = 1;
    j = 0;
    k = strlen(s) - 3;
    while (k > 0) {
        s[j++] = s[i++];
        k--;
    }
    s[j] = '\0';
    reverse_w(s);
    printf("%s\n", t);
}*/