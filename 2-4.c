#include <stdio.h>

void squeeze_new(char s[], int c); //从字符串中删除字符
void squeeze_ext(char s1[], char s2[]); //删除s1中与s2中所有匹配字符
int any_new(char s1[], char s2[]); //返回s2中任一字符在s1第一次出现的位置，否则返回-1

int main() {
	char s1[100] = "aabbccddee";
	char c = 'a';
	char s2[100] = "bc";
	char s3[100] = "e";
	squeeze_new(s1, c);
	printf("%s\n", s1);
	squeeze_ext(s1, s2);
	printf("%s\n", s1);
	printf("pos: %d\n", any_new(s1, s3));
	return 0;
}

void squeeze_new(char s[], int c) {
/*	int i, j;
	for (i=j=0; s[i] != '\0'; ++i) {
		if (s[i] == c) {
			;
		}
		else {
			s[j++] = s[i];
		}
	}
	s[j] = '\0';*/

	int i, j;  //cleaner

	for (i=j=0; s[i] != '\0'; ++i) {
		if (s[i] != c) {
			s[j++] = s[i];
		}
	}
	s[j] = '\0';
}

void squeeze_ext(char s1[], char s2[]) {
	int i, j, k;

	for (i=k=0; s1[i] != '\0'; ++i) {
		for (j=0; s2[j] != '\0'; ++j) {
			if (s1[i] == s2[j]) {
				break;
			}
		}
		if (s2[j] == '\0') { 
			s1[k++] = s1[i];
		}
	}
	s1[k] = '\0';
/*	for (i=k=0; s1[i] != '\0'; ++i) {
		for (j=0; s2[j] != '\0' && s2[j] != s1[i]; ++j) { 
			; //s1[i]与s2中每个字符比较，若匹配，不做任何操作，内循环结束，不对s1[i]做任何处理，继续下一个大循环
		}
		if (s2[j] == '\0') {   //内循环完毕s2中字符均未匹配，s1[i]复制到结果字符串中
			s1[k++] = s1[i];
		}
	}
	s1[k] = '\0';*/
}

int any_new(char s1[], char s2[]) {
	int i, j;

	// k = -1;
	for (i=0; s1[i] != '\0'; ++i) {
		for (j=0; s2[j] !='\0'; ++j) {
			if (s1[i] == s2[j]) {
				// k = i;
				return i;
			}
		}
	}
	return -1;
	// return k;
}

