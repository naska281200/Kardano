// DZ3_Kardano.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
using namespace std;
#include <string>

string Shifr(string stroka, int reshetka[6][6])	//ф-ия шифрования строки решеткой Кардано
{
	int k = 0;	//указатель в строке (изначально показывает на 0 элемент)
	char shifr_Kardano[6][6] = { {' ',' ',' ',' ',' ',' '},
								 {' ',' ',' ',' ',' ',' '},
								 {' ',' ',' ',' ',' ',' '},
								 {' ',' ',' ',' ',' ',' '},
								 {' ',' ',' ',' ',' ',' '},
								 {' ',' ',' ',' ',' ',' '} };//создали массив, в который зашифруем строку от пользователя
	for (int i = 0; i < 6; i++)	//зашифровываем строку при прямом положении решетки
	{
		for (int j = 0; j < 6; j++)
		{
			if (reshetka[i][j] == 1)
			{
				shifr_Kardano[i][j] = stroka[k];
				k += 1;
				if (k >= stroka.length())//когда строка закончилась
					break;
			}
		}
		if (k >= stroka.length())//когда строка закончилась
			break;
	}
	if (k < stroka.length())//когда строка ещё не закончилась
	{
		for (int i = 0; i < 6; i++)//зашифровываем строку при повороте на 90 градусов по часовой стрелке
		{
			for (int j = 0; j < 6; j++)
			{
				if (reshetka[6 - j - 1][i] == 1)
				{
					shifr_Kardano[i][j] = stroka[k];
					k += 1;
					if (k >= stroka.length())//когда строка закончилась
						break;
				}
			}
			if (k >= stroka.length())//когда строка закончилась
				break;
		}
	}
	if (k < stroka.length())//когда строка ещё не закончилась
	{
		for (int i = 0; i < 6; i++)//зашифровываем строку при повороте на 180 градусов по часовой стрелке
		{
			for (int j = 0; j < 6; j++)
			{
				if (reshetka[6 - i - 1][6 - j - 1] == 1)
				{
					shifr_Kardano[i][j] = stroka[k];
					k += 1;
					if (k >= stroka.length())//когда строка закончилась
						break;
				}
			}
			if (k >= stroka.length())//когда строка закончилась
				break;
		}
	}
	if (k < stroka.length())//когда строка ещё не закончилась
	{
		for (int i = 0; i < 6; i++)//зашифровываем строку при повороте на 270 градусов по часовой стрелке
		{
			for (int j = 0; j < 6; j++)
			{
				if (reshetka[j][6 - i - 1] == 1)
				{
					shifr_Kardano[i][j] = stroka[k];
					k += 1;
					if (k >= stroka.length())//когда строка закончилась
						break;
				}
			}
			if (k >= stroka.length())//когда строка закончилась
				break;
		}
	}
	string shifr = "";//пустая строка изначально, записывыем зашифрованную строку
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			shifr += shifr_Kardano[i][j];
		}
	}
	return shifr;
}

string Decode(int reshetka[6][6], string shifr)//ф-ия расшифровки решетки Кардано
{
	string decode_shifr = "";	//изначально пустая строка	
	char shifr_Kardano[6][6];
	for (int i = 0; i < 6; i++)	//заполняем массив, который состоит из строки от пользователя
	{
		for (int j = 0; j < 6; j++)
		{
			shifr_Kardano[i][j] = shifr[j];
		}
		shifr.erase(0, 6);	//удаляем из строки с 0 позиции по 5 включительно
	}
	for (int i = 0; i < 6; i++)	//расшифровываем при прямом положении решетки
	{
		for (int j = 0; j < 6; j++)
		{
			if (reshetka[i][j] == 1)
			{
				decode_shifr += shifr_Kardano[i][j];
			}
		}
	}
	for (int i = 0; i < 6; i++)//расшифровываем при повороте на 90 градусов по часовой стрелки
	{
		for (int j = 0; j < 6; j++)
		{
			if (reshetka[6 - j - 1][i] == 1)
			{
				decode_shifr += shifr_Kardano[i][j];
			}
		}
	}
	for (int i = 0; i < 6; i++)//расшифровываем при повороте на 180 градусов по часовой стрелки
	{
		for (int j = 0; j < 6; j++)
		{
			if (reshetka[6 - i - 1][6 - j - 1] == 1)
			{
				decode_shifr += shifr_Kardano[i][j];
			}
		}
	}
	for (int i = 0; i < 6; i++)//расшифровываем при повороте на 270 градусов по часовой стрелки
	{
		for (int j = 0; j < 6; j++)
		{
			if (reshetka[j][6 - i - 1] == 1)
			{
				decode_shifr += shifr_Kardano[i][j];
			}
		}
	}
	return decode_shifr;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	string stroka;		//переменная для строки от пользователя
	int reshetka[6][6] = { {1,0,0,0,1,0},
						   {0,1,0,0,0,0},
						   {0,0,1,0,1,0},
						   {0,0,0,0,0,1},
						   {1,0,1,0,0,0},
						   {0,0,0,1,0,0} };//решетка Кардано, где 1-отверстия.
	cout << "Введите строку для шифрования: ";
	getline(cin, stroka);		//считываем полностью всю строку
	string shifr= Shifr(stroka, reshetka);
	cout << "\nЗашифрованная строка: " << shifr<<endl;
	cout << "\nРасшифрованная строка: " << Decode(reshetka, shifr) << endl;
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
