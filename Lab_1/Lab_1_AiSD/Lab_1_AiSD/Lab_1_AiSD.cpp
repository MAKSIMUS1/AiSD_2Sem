#include <iostream>
#include <ctime>
using namespace std;
int fibonacci(int index)
{
    if (index == 0)
        return 0;
    if (index == 1)
        return 1;
    return fibonacci(index - 1) + fibonacci(index - 2);
}


int main()
{
    setlocale(LC_ALL, "rus");
    int N;
    printf("Введи количество чисел: ");
    scanf_s("%d", &N);
    unsigned int start = clock();
    int count;
    for (count = 0; count < N; ++count)
        printf("%d ", fibonacci(count));
    printf("\n%d-ое число Фибоначчи: %d", N, fibonacci(count - 1));
    unsigned int stop = clock();
    unsigned int time = stop - start;
    printf("\nВремя прохождения: %d мс.\n", time);
    return 0;
}