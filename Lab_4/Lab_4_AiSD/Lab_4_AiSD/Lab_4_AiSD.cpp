#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int min = INT_MAX;
	int size;
	printf("Введите кол-во товаров: ");
	scanf_s("%d", &size);
	int* arr = new int[size];
	int buff;
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 100 + 1;
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);

	for (int i = 0; i < size - 1; i++)
		for (int k = 0; k < size - i - 1; k++)
			if (arr[k] > arr[k + 1]) {
				buff = arr[k];
				arr[k] = arr[k + 1];
				arr[k + 1] = buff;
			}
	int zena = 0;
	//	8 7 2 6 9 // 8 7 6 9
	//	0 1 2 3 4 // 0 1 2 3
	//	   5	  //    4
	printf("\n---------------------------\n");
	for (int i = 0, j = size - 1; i < (size / 2); i++, j--)
		printf("%d %d ", arr[j], arr[i]);
	if (size % 2 == 1)
		printf("%d", arr[size / 2]);
	for (int i = (size / 2); i < size; i++)
		zena += arr[i];
	printf("\n---------------------------\n");
	printf("\nМаксимальная сумма чека: %d\n", zena);
	delete[] arr;

	printf("\n----------------------------------------------------------------------------------------------------\n");
	int N, pr = 0, sum = 0, max_buff = 101;
	printf("Введите кол-во призеров: ");
	scanf_s("%d", &N);
	int* arr2 = new int[N];
	for (int i = 0; i < N; i++) {
		arr2[i] = rand() % 15;
		printf("%d ", arr2[i]);
	}
	for (int i = 0; i < N - 1; i++)
		for (int k = 0; k < N - i - 1; k++)
			if (arr2[k] > arr2[k + 1]) {
				buff = arr2[k];
				arr2[k] = arr2[k + 1];
				arr2[k + 1] = buff;
			}
	while (pr < 3)
	{
		int max = 0;
		for (int i = 0; i < N; i++)
			if (arr2[i] > max && arr2[i] < max_buff)
				max = arr2[i];
		for (int i = 0; i < N; i++)
			if (arr2[i] == max)
				sum++;
		max_buff = max;
		pr++;
	}
	printf("\nЧисло призеров = %d\n", sum);
	delete[] arr2;
}