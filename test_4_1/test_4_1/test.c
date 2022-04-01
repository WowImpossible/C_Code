#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//int main()
//{
//	int arr[8] = { 36,25,48,14,55,40,50,24 };
//	int b1, b2, i;
//	b1 = b2 = arr[0];
//	for (i = 1; i < 8; i++)
//	{
//		if (arr[i] > b1) { b2 = b1; b1 = arr[i]; }
//		else if (arr[i] > b2) b2 = arr[i];
//	}
//	printf("b1=%d,b2=%d", b1, b2);
//	return 0;
//}


//ÎÄ¼þ²Ù×÷
//int main()
//{
//	FILE* fp = fopen("text.txt", "w");
//	int a[10] = { 1,2,3,4}, i, n;
//	for (i = 0; i < 4; i++)
//		fprintf(fp, "%d", a[i]);
//	fprintf(fp, "n");
//	//fprintf(fp, "n");
//	fclose(fp);
//	fp = fopen("text.txt", "r");
//	fscanf(fp, "%d", &n);
//	//if (!fp)
//	//{
//	//	printf("%s", strerror(errno));
//	//	return 0;
//	//}
//	//fprintf(fp, "abc");
//
//	fclose(fp);
//	fp = NULL;
//	printf("%d", n);
//
//	return 0;
//}

void rest(int a[], int n)
{
	int i, low, high, t;
	for (i = 0, low = 0, high = n - 1; i <= high;)
	{
		if (a[i] > 0)
		{
			t = a[i];
			a[i] = a[high];
			a[high] = t;
			high--;
		}
		else if (a[i] == 0)
		{
			i++;
		}
		else
		{
			t = a[i];
			a[i] = a[low];
			a[low] = t;
			low++;
			i++;
		}
	}
}


int main()
{
	int s[7] = { 8,4,0,-1,6,0,-5 };
	int i = 0;
	rest(s, sizeof(s) / sizeof(s[0]));
	for (i = 0; i < 7; i++)
	{
		printf("%4d", s[i]);
	}
	return 0;
}
