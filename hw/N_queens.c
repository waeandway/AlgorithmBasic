#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*-------------------- Prototype --------------------*/
void queens(int i);
bool promising(int i);
void print_queens();
/*-------------------- Global Var --------------------*/
int n = 0;  // ������� ũ�� n x n
int* col = NULL;  // col[i] = k : ���ո��� ��ġ i�� k��
/*-------------------- Function --------------------*/
int main()
{
	printf("n�� �Է� : ");
	scanf("%d", &n);
	col = (int*)malloc(sizeof(int) * (n + 1));
	queens(0);

	printf("%d �� ���� ���� �����ϴ�.\n", n);
	return 0;
}
/*----------------------------------------------------*/
void queens(int i)
{
	if (promising(i)) {
		if (i == n) {
			print_queens();
			return;
		}
	}
	else {
		for (int j = 1; j <= n; j++) {
			col[i + 1] = j;
			queens(i + 1);
		}
	}
}
/*----------------------------------------------------*/
bool promising(int i)
{
	int k = 1;
	while (k < i) {
		if (col[i] == col[k] || abs(col[i] - col[k]) == abs(i - k))
			return true;
		k++;
	}
	return false;
}
/*----------------------------------------------------*/
void print_queens()
{
	for (int i = 1; i <= n; i++)
		printf("(%d, %d)\n", i, col[i]);
	exit(1);
}