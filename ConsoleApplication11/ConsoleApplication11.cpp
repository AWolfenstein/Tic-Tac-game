// ConsoleApplication11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>


#define DRAW '0'
#define EMPTY ' '
#define COMPUTER 'O'
#define USER 'X'
using namespace std;

char matrix[3][3] = {
{EMPTY, EMPTY, EMPTY},
{EMPTY, EMPTY, EMPTY},
{EMPTY, EMPTY, EMPTY}
};

void  get_player_move();
void disp_matrix();
void ai_smart();
void ai_random();
void ai_genious();
int charToIntLogic(char s);
void playerCanWin(char board[3][3], char which, int& x, int& y);
char check();
void returnToMenu();
void startProgramm();
void startGame(void level(), char& done);

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
		startGame(ai_random, done);
		break;
	case 2:
		system("cls");
		startGame(ai_smart, done);
		break;
	case 3:
		system("cls");
		startGame(ai_genious, done);
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

void startGame(void level(), char& done) {
	do {
		disp_matrix();
		get_player_move();
		done = check();
		if (done != EMPTY || done == DRAW) { break; }
		else {
			level();
			done = check();
			if (done == COMPUTER) { break; }
			system("cls");
		}
	} while (done == EMPTY || done != DRAW);
}

void returnToMenu() {
	int retry;
	cout << "\n\n" << endl;
	cout << "Return to the main menu?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No,Exit" << endl;
	cout << "Your choice: ";
	cin >> retry;
	cin.clear();
	fflush(stdin);

	switch (retry) {

	case 1:
		system("cls");
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				matrix[i][j] = EMPTY;
			}
		}
		startProgramm();

		break;
	case 2:
		system("cls");
		break;
	default:
		cout << "Error, bad input, repeat\n";
		returnToMenu();
		break;
	}
}
void get_player_move()
{
	int x, y;
	cout << "Enter coordinates for your X.\n";
	cout << "Row? ";
	cin >> x;
	cout << "Column? ";
	cin >> y;
	x--;
	y--;
	if (x < 0 || y < 0 || x>2 || y>2 || matrix[x][y] != EMPTY)
	{
		cout << "Invalid move, try again.\n";
		get_player_move();
	}
	else { matrix[x][y] = USER; }
}

void ai_random() {
	int row, col;
	do {
		row = rand() % 3;
		col = rand() % 3;
	} while (matrix[row][col] != EMPTY && matrix[row][col] != USER);
	if (matrix[row][col] == EMPTY && matrix[row][col] != USER) {
		matrix[row][col] = COMPUTER;
	}
	else {
		ai_random();
	}
}


void ai_smart() {
	int row, col;

	if (matrix[1][1] == EMPTY) { row = 1; col = 1; }
	else {
		if (matrix[0][0] == EMPTY) { row = 0; col = 0; }
		else if (matrix[0][2] == EMPTY) { row = 0; col = 2; }
		else if (matrix[2][0] == EMPTY) { row = 2; col = 0; }
		else if (matrix[2][2] == EMPTY) { row = 2; col = 2; }
		else {
			ai_random();
			row = -1;
			col = -1; // set to prevent later logic
		}
	}

	if (row >= 0 && col >= 0) {
		matrix[row][col] = COMPUTER;
	}
}
int charToIntLogic(char s) {
	if (s == USER) {
		return 2;
	}
	else  if (s == COMPUTER) {
		return 3;
	}
	else {
		return 0;
	}
}
void playerCanWin(char board[3][3], char which, int& x, int& y) {
	// Target sum depends on which player we're calculating for
	int target = which == USER ? 4 : 6;
	// Iterate through the 8 possible winning axes:
	// Rows:
	for (int r = 0; r < 3; r++) {

		int sum = charToIntLogic(board[r][0]) + charToIntLogic(board[r][1]) + charToIntLogic(board[r][2]);
		if (sum == target) {
			for (int c = 0; c < 3; c++) {
				if (board[r][c] == EMPTY) {
					x = r;
					y = c;
					return;
				}
			}
		}
	}

	// Columns:
	for (int c = 0; c < 3; c++) {
		int sum = charToIntLogic(board[0][c]) + charToIntLogic(board[1][c]) + charToIntLogic(board[2][c]);
		if (sum == target) {
			for (int r = 0; r < 3; r++) {
				if (board[r][c] == EMPTY) {
					x = r;
					y = c;
					return;
				}
			}
		}
	}

	// Diagonals:
	int sum_ltr = charToIntLogic(board[0][0]) + charToIntLogic(board[1][1]) + charToIntLogic(board[2][2]);
	if (sum_ltr == target) {
		if (board[0][0] == EMPTY) {
			x = 0; y = 0; return;
		}
		if (board[1][1] == EMPTY) {
			x = 1; y = 1; return;
		}
		if (board[2][2] == EMPTY) {
			x = 2; y = 2; return;
		}
	}
	int sum_rtl = charToIntLogic(board[0][2]) + charToIntLogic(board[1][1]) + charToIntLogic(board[2][0]);
	if (sum_rtl == target) {
		if (board[0][2] == EMPTY) {
			x = 0; y = 2; return;
		}
		if (board[1][1] == EMPTY) {
			x = 1; y = 1; return;
		}
		if (board[2][0] == EMPTY) {
			x = 2; y = 0; return;
		}
	}
	// No possible win 
	x = -1;
	y = -1;
	return;
}
void ai_genious() {

	if (matrix[1][1] == EMPTY) {
		matrix[1][1] = COMPUTER;
	}
	else {
		int x = 0, y = 0;
		playerCanWin(matrix, COMPUTER, x, y);
		if (x >= 0 && y >= 0) {
			matrix[x][y] = COMPUTER;
		}
		else {

			int xU = 0, yU = 0;
			playerCanWin(matrix, USER, xU, yU);

			if (xU >= 0 && yU >= 0) {
				matrix[xU][yU] = COMPUTER;
			}
			else {
				ai_smart();
			}
		}
	}
}


void disp_matrix(void)
{
	int t;
	for (t = 0; t < 3; t++)
	{
		cout << matrix[t][0] << "|" << matrix[t][1] << "|" << matrix[t][2];
		if (t != 2) cout << "\n-|-|-\n";
	}
	cout << ("\n");
}

char check()
{
	int t;
	char* p;

	for (t = 0; t < 3; t++) {
		p = &matrix[t][0];
		if (*p == *(p + 1) && *(p + 1) == *(p + 2)) { return *p; }
	}
	for (t = 0; t < 3; t++) {
		p = &matrix[0][t];
		if (*p == *(p + 3) && *(p + 3) == *(p + 6)) { return *p; }
	}

	if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
	{
		return matrix[0][0];
	}
	if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
	{
		return matrix[0][2];
	}

	p = (char*)matrix;
	for (t = 0; *p != EMPTY && t < 9; ++t) { p++; }

	if (t == 9)
	{
		return DRAW;
	}


	return EMPTY;
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
