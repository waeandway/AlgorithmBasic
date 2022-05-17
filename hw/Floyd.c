#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INF 999
#define ROW 5
#define COL 5
#define VERT 5   //  vertex

/* ----------------- Function ~ Prototype ----------------- */
void floyd2(const int W[][VERT], int D[][VERT], int P[][VERT]);
void path(int q, int r);
void print_distance(int D[][VERT]);

/* -------------------- Array ~ GlobalVar -------------------- */
int D[ROW][COL];   //  Distance
int P[ROW][COL];   //   Path Index
const int W[ROW][COL] = {  //  Weight
	{0, 3, 6, INF, INF},
	{4, 0, 2, 3, 1},
	{INF, INF, 0, 1, INF},
	{INF, INF, 5, 0, 2},
	{INF, 7, INF, INF, 0}
};
/* ------------------------------- function ------------------------------- */
int main()
{
	floyd2(W, D, P);
	print_distance(D);
	path(1, 5);
}
/* ----------------------------------------------------------------------- */
void floyd2(const int W[][VERT], int D[][VERT], int P[][VERT])
{
	int i, j, k;
	for (i = 0; i < VERT; i++)
		for (j = 0; j < VERT; j++) {
			P[i][j] = 0;
			D[i][j] = W[i][j];
		}
	for (k = 0; k < VERT; k++)
		for (i = 0; i < VERT; i++)
			for (j = 0; j < VERT; j++)
				if (D[i][k] + D[k][j] < D[i][j]) {
					P[i][j] = k;
					D[i][j] = D[i][k] + D[k][j];
				}
}
/* ----------------------------------------------------------------------- */
void path(int q, int r)
{
	if (P[q][r] != 0) {
		path(q, P[q][r]);
		printf("%d ~ %d : %d ", q, r, P[q][r]);
		path(P[q][r], r);
	}
}
/* ----------------------------------------------------------------------- */
void print_distance(int D[][VERT])
{
	printf("--------------  D ---------------\n");
	printf("     %5d%5d%5d%5d%5d\n", 1, 2, 3, 4, 5);
	for (int i = 0; i < ROW; i++) {
		printf("%5d", i + 1);
		for (int j = 0; j < COL; j++) {
			if (D[i][j] == INF)
				printf("%5s", "oo");
			else
				printf("%5d", D[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}