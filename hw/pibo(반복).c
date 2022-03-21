#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

double fib(int n)
{
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;

	int f0 = 0, f1 = 1, f;
	for (int i = 2; i < n; i++) {
		f = f1 + f0;
		f0 = f1;
		f1 = f;
	}
	return f;
}

int main(void)
{
	clock_t start, finish; // �ð� ���� ����
	double time; // �ð� ���� ���� (start-finish)
	int n = 0;

	for (int i = 1; i <= 5; i++) {
		printf("n��° �Ǻ���ġ �� �Է� : ");
		scanf("%d", &n);
		start = clock(); // ���۽ð� ���

		printf("%d��° �Ǻ���ġ �� : %d\n", n, fib(n));
		finish = clock(); // ����ð� ���
		time = (double)(finish - start);
		printf("�ҿ�� �ð� : %f\n", time);
		printf("\n");

	}
}