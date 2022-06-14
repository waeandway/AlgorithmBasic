#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 6 // ���� �� ����
/*----------------------------- Struct -------------------------------------*/
typedef struct nodetype
{
	char* symbol; // ���ڰ�
	int frequency; // ������ �󵵼�
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

	for (int i = 0; i < N; i++) {  // PQ ���ڵ� ����
		PQ[i] = (node*)malloc(sizeof(node));
		PQ[i]->left = NULL, PQ[i]->right = NULL;
		printf("%d�� ° ���� �Է� : ", i+1);
		scanf("%s", &(PQ[i]->symbol));
		printf("�󵵼� �Է� : ");
		scanf("%d", &(PQ[i]->frequency));
	}
	printf("---- PQ ���ڵ� ��� ----\n");
	Print_PQ(PQ);
	printf("---- PQ �������� ���� �� ���ڵ� ��� ----\n");
	Array_PQ(PQ);
	Print_PQ(PQ);

}
/*--------------------------------------------------------------------------*/
void Array_PQ(node* P[]) // �������� ���� (�󵵼��� ���� ���� ���ڰ� �켱������ ����)
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
		printf("���� : %c\n", P[i]->symbol);
		printf("������ �󵵼� : %d\n", P[i]->frequency);
		if (P[i]->left == NULL)
			printf("P[%d]->left : NULL\n", i);
		else printf("P[%d]->left : %d\n", i, P[i]->left);
		if (P[i]->right == NULL)
			printf("P[%d]->right : NULL\n", i);
		else printf("P[%d]->right : %d\n", i, P[i]->right);
		printf("\n");
	}
}
