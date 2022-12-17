#include <iostream>
#include <ctime>

using namespace std;

void sort_puzyrgatauya(int*, int);
void sort_vstavki(int*, int);
void sort_vyborochnuy(int*, int);
void sort_bystray(int*, int);

void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int massiv_0[5000];
	int size;
	printf("Кол-во: ");
	scanf_s("%d", &size);
	for (int i = 0; i < size; i++)
	{
		massiv_0[i] = rand() % 125 - 25;
		printf("%d ", massiv_0[i]);
	}
	printf("\n");

	int* massiv_1 = new int[size];
	for (int i = 0; i < size; i++)
		massiv_1[i] = massiv_0[i];
	clock_t start = clock();
	sort_puzyrgatauya(massiv_1, size);
	clock_t stop = clock();
	for (int i = 0; i < size; i++)
		printf("%d ", massiv_1[i]);
	printf("\n");
	double time = (double)stop - (double)start / CLOCKS_PER_SEC;
	printf("\n---------------------------------------------------------------\n");
	printf("Время выполнения в тиках: %0.2f тиков", time);
	printf("\n---------------------------------------------------------------\n");
	delete[] massiv_1;

	int* massiv_2 = new int[size];
	for (int i = 0; i < size; i++)
		massiv_2[i] = massiv_0[i];
	clock_t start_2 = clock();
	sort_vstavki(massiv_2, size);
	clock_t stop_2 = clock();
	for (int i = 0; i < size; i++)
		printf("%d ", massiv_2[i]);
	printf("\n");
	time = (double)stop_2 - (double)start_2 / CLOCKS_PER_SEC;
	printf("\n---------------------------------------------------------------\n");
	printf("Время выполнения в тиках: %0.2f тиков", time);
	printf("\n---------------------------------------------------------------\n");
	delete[] massiv_2;

	int* massiv_3 = new int[size];
	for (int i = 0; i < size; i++)
		massiv_3[i] = massiv_0[i];
	clock_t start_3 = clock();
	sort_vyborochnuy(massiv_3, size);
	clock_t stop_3 = clock();
	time = (double)stop_3 - (double)start_3 / CLOCKS_PER_SEC;
	for (int i = 0; i < size; i++)
		printf("%d ", massiv_3[i]);
	printf("\n");
	printf("\n---------------------------------------------------------------\n");
	printf("Время выполнения в тиках: %0.2f тиков", time);
	printf("\n---------------------------------------------------------------\n");
	delete[] massiv_3;

	int* massiv_4 = new int[size];
	for (int i = 0; i < size; i++)
		massiv_4[i] = massiv_0[i];
	clock_t start_4 = clock();
	sort_bystray(massiv_4, size);
	clock_t stop_4 = clock();
	for (int i = 0; i < size; i++)
		printf("%d ", massiv_4[i]);
	printf("\n");
	time = (double)stop_4 - (double)start_4 / CLOCKS_PER_SEC;
	printf("\n---------------------------------------------------------------\n");
	printf("Время выполнения в тиках: %0.2f тиков", time);
	printf("\n---------------------------------------------------------------\n");
	delete[] massiv_4;
}

void sort_puzyrgatauya(int* A, int size)
{
	int buffer;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - 1; j++)
			if (A[j] > A[j + 1])
			{
				buffer = A[j];
				A[j] = A[j + 1];
				A[j + 1] = buffer;
			}
}


void sort_vstavki(int* A, int size)
{
	int buffer;
	for (int i = 1; i < size; i++)
		for (int j = i; j > 0 && A[j - 1] > A[j]; j--)
		{
			buffer = A[j];
			A[j] = A[j - 1];
			A[j - 1] = buffer;
		}
}


void sort_vyborochnuy(int* A, int size)
{
	int min = 99, buffer, number = 0;
	for (int i = 0; i < size; i++)
	{
		buffer = A[i];
		min = 99;
		for (int j = i + 1; j < size; j++)
		{
			if (A[j] < min)
			{
				min = A[j];
				number = j;
			}
		}
		A[i] = min;
		A[number] = buffer;
	}
}


void sort_bystray(int* A, int size)
{
	int i = 0;
	int j = size - 1;
	int buffer;
	int mid = A[size / 2];//Центр.элем.масс.
	do {
		while (A[i] < mid)
			i++;
		while (A[j] > mid)
			j--;
		if (i <= j) {
			buffer = A[i];
			A[i] = A[j];
			A[j] = buffer;

			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0)
		sort_bystray(A, j + 1);
	if (i < size)
		sort_bystray(&A[i], size - i);
}
