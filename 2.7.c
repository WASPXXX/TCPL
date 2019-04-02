#include <stdio.h>

/*字符串转换为相应的整型数*/
#define TESTLINE 100
int atoi_new(char s[]);
int getline_new(char line[], int maxline);

int main() {
	char c, s[TESTLINE];
	int i, ns;

	while(getline_new(s, TESTLINE) > 0) {
		printf("origin string -> %s\n", s);
		ns = atoi_new(s);
		printf("converted num -> %d\n", ns);
		printf("---end---\n\n\n");
	}
	return 0;
}

int atoi_new(char s[]) {
	int i,k;

	k = 0;
	for(i=0; s[i]>='0' && s[i]<='9'; ++i) {
		k = k * 10 + (s[i] - '0');
	}
	return k;
}

int getline_new(char s[], int lim) {
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
		s[i] = c;
	}
/*	if (c == '\n') {
		s[i] = c;
		++i;
	}*/
	if (c == '\n') {  //cleaner use of ++
		s[i++] = c;
	}
	s[i] = '\0';
	return i; //i即是含换行符的字符串长度
}