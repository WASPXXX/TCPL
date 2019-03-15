#include <stdio.h>

#define MAXLINE 1000
int getline_new(char s[], int maxline);
int remove_new(char s[]);

/*删除每个输入行末尾的空格和制表符、删除完全是空格的行*/
int main() {
	char line[MAXLINE];
	int nlen;

	while(getline_new(line, MAXLINE) > 0) {
		if ((nlen = remove_new(line)) > 0) {
			printf("%s\n", line);
			printf("new count = %d\n", nlen);
		}
	}
	return 0;
}

/*删除末尾的空格和制表符，返回新的长度*/
int remove_new(char s[]) {
	int i;

	i = 0;
	while (s[i] != '\n') { /*获取s的长度*/
		++i;
	}
	printf("count = %d\n", i+1);
	--i; /*回退*/
	while (i >= 0 && (s[i] == ' ' || s[i] == '\t')) {
		--i;
	}
	if (i >= 0) {
		++i;
		s[i] = '\n';
		++i;
		s[i] = '\0';
	}
	return i;
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