#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <Windows.h>

float call = 0; // 함수호출횟수 변수

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
	clock_t start, finish; // 시간 측정 변수
	double duration = 0;
	int n = 0;

	for (int i = 1; i <= 5; i++) {
		printf("n번 째 피보나치 수 입력 : ");
		scanf("%d", &n);
		start = clock();

		printf("%d번 째 피보나치 수 : %.f\n", n, fib(n));
		Sleep(100);
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("소요된 시간 : %.3f초\n", duration);
		printf("함수호출횟수 : %.f번\n", call);
		printf("\n");
	}
	return 0;
}