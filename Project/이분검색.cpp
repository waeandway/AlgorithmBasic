#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int matrixmult(int n, int find, const int S[])
{
	int low = 1, high = n, mid;
	int location = 0;

	while (low <= high && location == 0) {
		mid = (low + high) / 2;
		if (find == S[mid])
			location = mid;
		else if (find < S[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return location;
}

int main(void)
{
	int arr[] = { 6, 5, 4, 3, 2, 1 };

	int location_key = matrixmult(6, 3, arr);
	printf("%d", arr[location_key]);
}