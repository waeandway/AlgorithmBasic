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
	clock_t start, finish; // 시간 측정 변수
	double time; // 시간 측정 변수 (start-finish)
	int n = 0;

	for (int i = 1; i <= 5; i++) {
		printf("n번째 피보나치 수 입력 : ");
		scanf("%d", &n);
		start = clock(); // 시작시간 계산

		printf("%d번째 피보나치 수 : %d\n", n, fib(n));
		finish = clock(); // 종료시간 계산
		time = (double)(finish - start);
		printf("소요된 시간 : %f\n", time);
		printf("\n");

	}
}