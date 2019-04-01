#include <stdio.h>

#define TABSTOP 8

/*detab 制表符替换为适当数目的空格*/
int main() {
	int c, nb, pos;

	nb = 0;
	pos = 1;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			nb = TABSTOP - (pos - 1) % TABSTOP;
			while (nb > 0) {
				putchar('*');
				++pos;
				--nb;
			}
		}
		else if (c == '\n') {
			putchar(c);
			pos = 1;
		}
		else {
			putchar(c);
			++pos;
		}
	}
	return 0;
}