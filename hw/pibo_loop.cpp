#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <windows.h>

float call = 0; // 함수호출횟수 변수

float fib(int n)
{
	call++;
	float f0 = 0, f1 = 1, fi;

	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else {
		for (int i = 2; i <= n; i++) {
			fi = f0 + f1;
			f0 = f1;
			f1 = fi;
		}
	}
	return fi;
}

int main(void)
{
	clock_t start, finish; // 시간 측정 변수
	double duration; // 시간 측정 변수 (start-finish)
	int n = 0;

	for (int i = 1; i <= 5; i++) {
		printf("n번째 피보나치 수 입력 : ");
		scanf("%d", &n);
		start = clock(); // 시작시간 계산

		printf("%d번째 피보나치 수 : %.f\n", n, fib(n));
		Sleep(100);
		finish = clock(); // 종료시간 계산
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("소요된 시간 : %.3f초\n", duration);
		printf("함수호출횟수 : %.f번\n", call);
		printf("\n");

	}
}
