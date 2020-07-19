#include <stdio.h>
#include <stdlib.h>

int MyCompare( const void *elem1, const void *elem2)
{
	unsigned int *p1, *p2;
	p1 = (unsigned int *) elem1;
	p2 = (unsigned int *) elem2;
	return *p1 - *p2;
}


void swap(int &a, int &b)
{
	int tmp;
	tmp = a; a = b; b = tmp;
}

int n1 = 10, n2 = 5;


#define NUM 5

int main()
{
	printf("%d\n", 34 & 27);
	printf("%x\n",-12 >> 2 );
	printf("%d\n",26 | 14);
	printf("%d\n",18 ^ 22);


	return 0;
}