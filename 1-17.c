#include <stdio.h>

#define MAXLINE 1000
#define TARGETLINE 10
int getline_new(char s[], int maxline);

/*打印长度超过10字符的所有输入行*/

int main() {
	int len;
	char line[MAXLINE];

	while ((len = getline_new(line, MAXLINE)) > 0) {
		if (len > TARGETLINE) {
			printf("-->%s", line);
			printf("count = %d\n", len);
		}
	}
	return 0;
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