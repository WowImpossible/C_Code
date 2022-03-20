#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//辗转相除法（求两个数的最大的公约数）：m和n相除的余数，如果余数是0，则结束
//此时最大的公约数就是被除数；如果余数不为0，则将原来的被除数作为新的除数，余数
//作为新的被除数，以此类推得到最后余数为0，结束。
int main()
{
	int m, n,w;
	scanf_s("%d,%d", &m, &n);
	while (m % n)
	{
		w = m % n;
		m = n;
		n = w;
	}
	printf("%d\n", n);

	return 0;
}