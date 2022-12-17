#include <iostream>

using namespace std;

int Correct_Input_Integer();

int main() {
	setlocale(LC_ALL, "ru");
	int N, a, X, N2;
	bool first_while = false;
	printf("Введите число N: ");
	scanf_s("%d", &N);
	X = N / 2;
	int uN = X;
	printf("X: %d\n", X);	
	printf("1 - мало\n2 - много\n3 - угадал\n");
	while (first_while == false)
	{
		a = Correct_Input_Integer();
		switch (a)
		{
		case 1: {
			uN /= 2;
			if (uN == 0)
				uN++;
			X += uN;
			if (X > N) {
				printf("Вы вышли за предел диапазона!\nКонец програмы.");
				exit(1);
			}
			printf("X: %d\n", X);
			break;
		}
		case 2: {
			uN /= 2;
			if (uN == 0)
				uN++;
			X -= uN;
			printf("X: %d\n", X);
			break;
		}
		case 3: {
			N2 = X;
			int count = 0, uN2 = N;
			first_while = true;
			bool second_while = false;
			printf("start:\nN: %d\n", N);
			while (second_while == false)
			{
				if (N2 < N)
				{
					count++;
					uN2 /= 2;
					if (uN2 == 0)
						uN2++;
					N -= uN2;
					printf("N: %d\n", N);
				}
				if (N2 > N)
				{
					count++;
					uN2 /= 2;
					if (uN2 == 0)
						uN2++;
					N += uN2;
					printf("N: %d\n", N);
				}
				if (N2 == N)
				{
					printf("\nКоличество шагов: %d\n", count);
					second_while = true;
				}
			}
			break;
		}
		}
	}
}

int Correct_Input_Integer() {
	int value, proverka = 0, proverka_2 = 0, proverka_na_minus = 0;
	char ch[11];

	while (proverka != 1) //Если proverka_na_minus = 1, значит первый символ минус. Если proverka_na_minus = 2, значит первый символ число.Если
	{ //Если proverka_2 = 1, значит ввод неверный.
		cin.ignore(cin.rdbuf()->in_avail());
		gets_s(ch);//Если proverka_2 = 0, значит ввод верный и мы заканчиваем цикл и переводим в int.
		if (ch[0] == '-')
			proverka_na_minus = 1;
		else
			if (ch[0] >= '0' && ch[0] <= '9')
				proverka_na_minus = 2;
			else
				proverka_2 = 1;
		if (proverka_na_minus == 1)//Если первый символ минус, то тогда идет проверка каждого символа
			for (int i = 1; i < strlen(ch); i++) {
				if (ch[i] <= '0' || ch[i] >= '9') {
					proverka_2 = 1;
				}
				if (ch[i] >= '0' && ch[i] <= '9' && proverka != 1) {
					proverka_2 = 0;
				}
			}
		if (proverka_na_minus == 2)//Если первый символ число, то тогда проперка всего числа
			for (int i = 0; i < strlen(ch); i++) {
				if (ch[i] <= '0' || ch[i] >= '9') {
					proverka_2 = 1;
				}
				if (ch[i] >= '0' && ch[i] <= '9' && proverka != 1) {
					proverka_2 = 0;
				}
				if (ch[i] == '\n')
					break;
			}
		cin.clear();
		proverka_na_minus = 0;
		if (proverka_2 == 1 || atoi(ch) > 3 || atoi(ch) < 0)
			printf("Неверный ввод!\nВведите ещё раз: ");
		if (proverka_2 == 0 && atoi(ch) <= 3 && atoi(ch) >= 0)
			proverka = 1;
	}
	value = atoi(ch);
	return value;
}