#include <stdio.h>

#define MAXLINE 1000
int getline_new(char line[], int maxline);
void reverse_new(char s[]);

int main() {
	char line[MAXLINE];

	while(getline_new(line, MAXLINE) > 0) {
		reverse_new(line);
		printf("%s\n", line);
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

void reverse_new(char s[]) {
	int i,k;
	char tmp;

	i = 0;
	while (s[i] != '\0') {
		++i;
	}
	--i;
	if (s[i] == '\n') {
		--i;
	}
	// printf("%d\n", i);
	for (k=0; k<i; ++k) {
		tmp = s[k];
		s[k] = s[i];
		s[i] = tmp;
		--i;
		// printf("%c\n", s[k]);
		// printf("%c %c\n", s[k], s[i-k]);
	}
	// s[i] = '\n';
}