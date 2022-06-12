#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INF 999
/*--------------------------------------------------------------------------------------------------*/
int F[5] = { 1 };
void prim(int n, const int W[][5]);
/*--------------------------------------------------------------------------------------------------*/
int main()
{
	const int W[5][5] = {
		{0,1,3,INF,INF},
		{1,0,3,6,INF},
		{3,3,0,4,2},
		{INF,6,4,0,5},
		{INF,INF,2,5,0}
	};
	prim(5, W);
	printf("\nF[5] = {%d, %d, %d, %d, %d}", F[0], F[1], F[2], F[3], F[4]);
}
/*--------------------------------------------------------------------------------------------------*/
void prim(int n, const int W[][5])
{
	int vnear = 0;  // vnear : distance[i] ���� �ּҰ� �Ǵ� �ε���
	int index = 1, count = n, min, temp = 0;
	int nearest[4] = { 0 };  // nearest[i] : v(i)�� ���� ����� F�� ���� ������ �ε���
	int distance[4] = { 0 };  // distance[i] : v(i)�� nearest[i]�� �ε����� �� ���� �����ϴ� �������� ����ġ

	printf("�ʱ� distance[4] : ");
	for (int i = 0, j = 1; i < n - 1 && j < n; i++, j++) {  // �ʱ� ����
		nearest[i] = 1;
		distance[i] = W[0][j];
		if (distance[i] == INF)
			printf("oo ");
		else printf("%d ", distance[i]);
	}
	printf("\n");

	while (count > 1) {
		min = INF;
		for (int i = 0; i < n - 1; i++) {
			if (0 <= distance[i] && distance[i] < min) {
				min = distance[i];
				vnear = i;
			}
		}

		F[index] = (vnear + 2);
		index++;
		distance[vnear] = -1;  // v(vnear)�� F�� ���ԵǾ����Ƿ� -1�� ����
		for (int i = 0, j = 1; i < n - 1 && j < n; i++, j++) {
			if (W[j][vnear + 1] < distance[i]) {
				distance[i] = W[j][vnear + 1];
				nearest[i] = vnear + 2;
			}
		}
		printf("distance[4] = ");
		for (int i = 0; i < 4; i++)
			printf("%d ", distance[i]);
		printf("\n");
		printf("F[5]�� ���Ե� vnear�ε��� = ");
		for (int i = 0; i < 5; i++)
			printf("%d ", F[i]);
		printf("\n");
		count--;
	}
}