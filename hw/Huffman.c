#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 6 // 문자 총 개수
/*----------------------------- Struct -------------------------------------*/
typedef struct nodetype
{
	char* symbol; // 문자값
	int frequency; // 문자의 빈도수
	struct node* left;
	struct node* right;
}node;
/*--------------------------- Prototype -----------------------------------*/
void Array_PQ(node* P[]);
void Print_PQ(node* P[]);
/*--------------------------- Function ------------------------------------*/
int main()
{
	node* PQ[N] = { NULL };
	PQ[0] = (node*)malloc(sizeof(node));

	for (int i = 0; i < N; i++) {  // PQ 레코드 생성
		PQ[i] = (node*)malloc(sizeof(node));
		PQ[i]->left = NULL, PQ[i]->right = NULL;
		printf("%d번 째 문자 입력 : ", i+1);
		scanf("%s", &(PQ[i]->symbol));
		printf("빈도수 입력 : ");
		scanf("%d", &(PQ[i]->frequency));
	}
	printf("---- PQ 레코드 출력 ----\n");
	Print_PQ(PQ);
	printf("---- PQ 오름차순 정렬 후 레코드 출력 ----\n");
	Array_PQ(PQ);
	Print_PQ(PQ);

}
/*--------------------------------------------------------------------------*/
void Array_PQ(node* P[]) // 오름차순 정렬 (빈도수가 가장 낮은 문자가 우선순위가 높음)
{
	int tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (P[j]->frequency > P[j+1]->frequency) {
				tmp = P[j]->frequency;
				P[j]->frequency = P[j+1]->frequency;
				P[j+1]->frequency = tmp;
			}
		}
	}
}
/*--------------------------------------------------------------------------*/
void Print_PQ(node* P[])
{
	for (int i = 0; i < N; i++) {
		printf("문자 : %c\n", P[i]->symbol);
		printf("문자의 빈도수 : %d\n", P[i]->frequency);
		if (P[i]->left == NULL)
			printf("P[%d]->left : NULL\n", i);
		else printf("P[%d]->left : %d\n", i, P[i]->left);
		if (P[i]->right == NULL)
			printf("P[%d]->right : NULL\n", i);
		else printf("P[%d]->right : %d\n", i, P[i]->right);
		printf("\n");
	}
}
