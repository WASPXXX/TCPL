#include<stdio.h>

#define kj 200
int main() {
	float a;
	a = 30;
	printf("you again!\n");
	printf("kobe's calling.\n"); 
	printf("%6.2f\n", a);
/*	int c = getchar();
	while (c != EOF) {
		putchar(c);
		c = getchar();
	}*/
/*	int c;
	c = (getchar() != EOF);
	printf("%d\n", c);
	printf("%d\n", EOF);
	double nc;
	for (nc = 0; getchar() != EOF; ++nc)
		;
	printf("%.0f\n", nc);*/
	int d;
	d = getchar();
	printf("%d\n", d);
	return 0;
}