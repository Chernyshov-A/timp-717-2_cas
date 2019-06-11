#include "stdio.h"
int main()
{
	unsigned n;
	int count = 0;
	int number;
	scanf("%u", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &number);
		if (number < 0) { count++; }			
	}
	printf("%d",count);
}