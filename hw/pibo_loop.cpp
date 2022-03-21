#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <windows.h>

float call = 0; // �Լ�ȣ��Ƚ�� ����

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
	clock_t start, finish; // �ð� ���� ����
	double duration; // �ð� ���� ���� (start-finish)
	int n = 0;

	for (int i = 1; i <= 5; i++) {
		printf("n��° �Ǻ���ġ �� �Է� : ");
		scanf("%d", &n);
		start = clock(); // ���۽ð� ���

		printf("%d��° �Ǻ���ġ �� : %.f\n", n, fib(n));
		Sleep(100);
		finish = clock(); // ����ð� ���
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("�ҿ�� �ð� : %.3f��\n", duration);
		printf("�Լ�ȣ��Ƚ�� : %.f��\n", call);
		printf("\n");

	}
}
