#include <iostream>
#include <vector>
#include "Header.h"
#include <algorithm>
#include <array>

using namespace std;

struct datas {
	int number;
	string name;
} temp;

const int SIZE = 32;

struct HT {
	array<vector<datas>, SIZE> table;
	int hash(int key)
	{
		return key % SIZE;
	}
	int cnt() {
		int cnt = 0;
		for (auto i : table)
			cnt += i.size();
		return cnt;
	}
	bool add(int number, string name)
	{
		if (cnt() == 32)
			return false;
		int place = hash(number);
		for (auto& i : table[place])
		{
			if (i.number == number)
			{
				i.name = name;
				cout << i.name << endl;
				return true;
			}
		}
		temp = { number, name };
		table[place].push_back(temp);
		return true;
	}
	string operator[](int num)
	{
		int place = hash(num);
		for (auto& i : table[place])
		{
			if (i.number == num)
			{
				return i.name;
			}
		}
		return "none";
	}
	bool del(int num)
	{
		int place = hash(num);
		short j = 0;
		for (auto i : table[place])
		{
			if (i.number == num)
			{
				table[place].erase(table[place].begin() + j);
				return true;
			}
			j += 1;
		}
		return false;
	}
	void print()
	{
		for (auto i : table)
		{
			for (auto j : i)
			{
				cout << j.number << " --> ";
				cout << j.name << endl;
			}
		}
	}
};

void main()
{
	setlocale(LC_ALL, "ru");
	HT table;
	string check;
	string name;
	int number, N;
	bool isExit = false;
	while (!isExit)
	{
		do {
			cout << "------------------------\n";
			cout << "1 - Добавить человека!\n"
				<< "2 - Удалить человека!\n"
				<< "3 - Поиск человека!\n"
				<< "4 - Вывести таблицу!\n";
			cout << "------------------------\n";
			gl(check);
		} while (!isProved(check, 1, 4));
		N = stoi(check);
		switch (N)
		{
		case 1:
			do {
				cout << "Введите номер телефона: ";
				gl(check);
				ent;
			} while (!isProved(check, 100000, 999999));
			number = stoi(check);
			cout << "Введите имя: ";
			gl(name);
			table.add(number, name);
			break;
		case 2:
			do {
				cout << "Введите номер телефона: ";
				gl(check);
				ent;
			} while (!isProved(check, 100000, 999999));
			number = stoi(check);
			if (table.del(number))
				cout << "Удалено!\n";
			else
				cout << "Нет такого человека!\n";
			break;
		case 3:
			do {
				cout << "Введите номер телефона: ";
				gl(check);
				ent;
			} while (!isProved(check, 100000, 999999));
			number = stoi(check);
			cout << table[number] << endl;
			break;
		case 4:
			table.print();
			break;
		}
	}
}