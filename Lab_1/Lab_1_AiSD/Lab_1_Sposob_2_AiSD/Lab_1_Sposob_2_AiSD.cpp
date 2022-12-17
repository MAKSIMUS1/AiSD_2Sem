#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int N;
    int b = 1, a = 1, c;
    printf("Введите N-ое число: ");
    scanf_s("%d", &N);
    unsigned int start = clock();
    if (N == 1) {
        printf("0\n");
        printf("1-ое число Фибоначчи: 0");
    }
    else if (N == 2) {
        printf("0 1\n");
        printf("2-ое число Фибоначчи: 1");
    }

    else
    {
        printf("0 1 1 ");
        for (int i = 3; i < N; i++)
        {
            c = a + b;
            a = b;
            b = c;
            printf("%d ", b);
        }
        printf("\n%d-ое число Фибоначчи: %d", N, b);

    }
    unsigned int stop = clock();
    unsigned int time = stop - start;
    printf("\nВремя прохождения цикла: %d мс.\n", time);
}