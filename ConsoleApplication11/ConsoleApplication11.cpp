// ConsoleApplication11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void startProgramm();


int main()
{
	startProgramm();
	return 0;
}

void startProgramm() {
	int input;
	char done;
	cout << "CHOICE LEVEL:.\n";
	done = EMPTY;
	cout << "1. RANDOM " << endl;
	cout << "2. EASY" << endl;
	cout << "3. EXTREME BOSS MODE" << endl;
	cout << "YOUR CHOICE: ";
	cin >> input;
	cin.clear();
	fflush(stdin);

	switch (input) {

	case 1:
		system("cls");
		//startGame(ai_random, done);
		break;
	case 2:
		system("cls");
		//startGame(ai_smart, done);
		break;
	case 3:
		system("cls");
		//startGame(ai_genious, done);
		break;
	default:
		cout << "Error, bad input, repeat\n";
		startProgramm();
		break;
	}
	if (done == USER) { system("cls"); cout << ("You won!:(\n"); }
	else if (done == COMPUTER) { system("cls"); cout << ("I won!HaAHHA!!!\n"); }
	else { system("cls"); cout << ("DRAW!HaHAHa\n"); }
	disp_matrix();
	returnToMenu();
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
