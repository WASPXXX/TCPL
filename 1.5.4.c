#include <stdio.h>

/*统计输入的行数、单词数、字符数*/

#define IN 1
#define OUT 0

int main() {
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n') {
			++nl;
		}
		if(c == ' ' || c == '\n' || c == '\t') { //判断当前处于单词内还是外
			state = OUT;
		}
		else if(state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d\t%d\t%d\n", nl, nw,nc);
	printf("%d\n", nl);
	return 0;
}
