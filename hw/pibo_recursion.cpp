#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <Windows.h>

float call = 0; // �Լ�ȣ��Ƚ�� ����

float fib(int n)
{
	call++;

	if (n <= 1)
		return n;
	else
		return fib(n - 1) + fib(n - 2);
}

int main(void)
{
	clock_t start, finish; // �ð� ���� ����
	double duration = 0;
	int n = 0;

	for (int i = 1; i <= 5; i++) {
		printf("n�� ° �Ǻ���ġ �� �Է� : ");
		scanf("%d", &n);
		start = clock();

		printf("%d�� ° �Ǻ���ġ �� : %.f\n", n, fib(n));
		Sleep(100);
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("�ҿ�� �ð� : %.3f��\n", duration);
		printf("�Լ�ȣ��Ƚ�� : %.f��\n", call);
		printf("\n");
	}
	return 0;
}