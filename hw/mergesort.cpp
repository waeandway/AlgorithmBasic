#include <stdio.h>

void mergesort(int A[], int p, int r);
void merge(int B[], int p, int q, int r);


int main()
{
    int S[8] = { 27, 10, 12, 20, 25, 12, 15, 22 };
    printf("<���� ��>\n");
    for (int i = 0; i < 8; i++)
        printf("%d ", S[i]);

    printf("\n<�߰� ����>");
    mergesort(S, 0, 7);

    printf("\n<���� ��>\n");
    for (int i = 0; i < 8; i++)
        printf("%d ", S[i]);

    return 0;
}

void merge(int B[], int p, int q, int r)
{
    int i = p, j = q + 1, k = p;
    int temp[8];
    while (i <= q && j <= r) {
        if (B[i] <= B[j])
            temp[k++] = B[i++];
        else
            temp[k++] = B[j++];
    }
    while (i <= q)
        temp[k++] = B[i++];
    while (j <= r)
        temp[k++] = B[j++];
    for (int i = p; i <= r; i++)
        B[i] = temp[i];

    printf("\n�պ� : ");
    for (int i = p; i <= r; i++)
        printf("%d ", temp[i]);
}

void mergesort(int A[], int p, int r)
{
    printf("\n���� : ");
    for (int i = p; i <= r; i++)
        printf("%d ", A[i]);
    if (p < r) {
        int q = (p + r) / 2;
        mergesort(A, p, q);
        mergesort(A, q + 1, r);
        merge(A, p, q, r);
    }
}
