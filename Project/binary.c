#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100

int bin(int n, int k);

int main()
{
	int n = 0, k = 0;
	printf("Combination n = ");
	scanf("%d", &n);
	printf("Combination k = ");
	scanf("%d", &k);
	printf("%dc%d : %d", n, k, bin(n, k));
}

int bin(int n, int k)
{
	int B[MAX][MAX];
	int i = 0, j = 0, m = 0;
	for (i = 0; i <= n; i++) {
		m = (i < k) ? i : k;
		for (j = 0; j <= m; j++) {
			if (j == 0 || j == i)
				B[i][j] = 1;
			else
				B[i][j] = B[i - 1][j - 1] + B[i - 1][j];
		}
	}
	return B[n][k];
}