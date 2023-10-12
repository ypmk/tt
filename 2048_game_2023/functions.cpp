

#pragma warning(disable:4996)//��������� �������������� ����������� ����� ������������ getch()
#include "pch.h"
#include "functions.h"


int board[4][4]; //������� ������� ��� ���� ����
int dirLine[] = { 1,0,-1,0 }; //���� �� ������
int dirColumn[] = { 0,1,0,-1 }; //���� �� �������



//���� ��������� �������� ������� �� ����
pair<int, int>generateUnoccupiedPosition() {
	int occupied = 1, line, column;
	while (occupied) {
		line = rand() % 4;
		column = rand() % 4;
		if (board[line][column] == 0) {
			occupied = 0;
		}
	}
	return make_pair(line, column);
}


//��������� ������� �� ��������� ��������� �������
void addPiece() {
	pair<int, int> pos = generateUnoccupiedPosition();
	board[pos.first][pos.second] = 2;
}


//������ ����� ����, �� ���� �������� ���� � ���������� ������ ��������, ������� 2
void newGame() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			board[i][j] = 0;
		}
	}
	addPiece();
}


//������������� ����� �������� ���������, ����������� �� ����, �� ���� ��������� ����� �� ����
int score(int board[4][4]) {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			sum += board[i][j];
		}
	}
	return sum;

}


//������� ������ �� ����
//����� ������ ������� ��� ����� �������, ����������� ������� ������ ����� �� ����
void exit_game(string s) {
	if (s == "fast") {
		system("cls"); //������� �����
		ifstream file_exit_fast("exit_fast.txt"); //��������� ��������� �������� �������� ������
		string str;
		while (!file_exit_fast.eof()) {
			getline(file_exit_fast, str);
			cout << str << endl;
		}
		file_exit_fast.close();
		while (1 == 1) {
			int key = getch(); //�� ��������� �� ����� ������� ������, ���� ���������, �������� ������ ������ ���� ����� �� �������
			continue;
		}
	}
	else if (s == "ask") {
		system("cls"); //������� �����
		ifstream file_exit_ask("exit_ask.txt"); //��������� ��������� ������ � ���������� ��������
		string str;
		while (!file_exit_ask.eof()) {
			getline(file_exit_ask, str);
			cout << str << endl;

		}
		file_exit_ask.close();

		while (1 == 1) {
			int key = getch(); //��������� ������� �������� �������������
			if (key == 27) { //���� ������������� ����� esc
				exit_game("fast"); // ��������� ������� �������� ������ �� ����
				break;

			}
			else if (key == 75) { //������������ ����� ��������� �����, �� ���� �� ����� ��������� � ��������
				rules(); //��������� �������� � ���������
				break;
			}
			else {
				continue; //������ ������� ������ ������������
			}
		}

	}

}


//�������, ����������� �� ����� �������� ����, �� ������� ��������� ������� ����
void rules() {
	system("cls"); //������� �����
	ifstream file_rules("rules.txt"); //��������� ��������� � ���������(������� �����)
	string str;
	while (!file_rules.eof()) {
		getline(file_rules, str);
		cout << str << endl;

	}
	file_rules.close();
	while (1 == 1) {
		int key = getch();  //��������� ������� �������� �������������
		if (key == 75) {//������������ ����� ��������� �����, �� ���� �� ����� ��������� � ������� ����
			printUI_first(); //��������� �������� � ������� ����
			break;
		}
		else if (key == 27) { //���� ������������� ����� esc
			exit_game("ask"); //��������� ������� ������� ������, �� ���� ����� � ���������� ��������
			break;
		}
		else {
			continue; //������ ������� ������ ������������
		}
	}

}


//�������, ���������� �� ������ ��������, ������� ����� ������������ ��� ������ ����
void printUI_first() {
	system("cls"); //������� �����
	ifstream file_first("first.txt"); //������� ��������� ��������
	string str;
	while (!file_first.eof()) {
		getline(file_first, str);
		cout << str << endl;

	}
	file_first.close();
	cout << "\t \t \t";
	while (1 == 1) {
		int key = getch();//��������� ������� �������� �������������
		if (key == 49) { //������������ ����� 1, �� ���� ����� ��������� �������
			rules(); //��������� �� �������� � ���������
			break;
		}
		else if (key == 50) { //������������ ����� 2, �� ���� ����� ������ ����� ����
			newGame(); //������� ������� ����� ����
			game_all();//������� � ��������� ���������� ����
			break;
		}
		else {
			continue;//������ ������� ������ ������������
		}
	}
}

//�������, ���������� �� ��������� �������� � ����� ����
void printUI_game() {
	system("cls"); //������� �����
	cout << endl << endl << endl << endl;
	cout << endl << "\t \t \t " << "     ����: " << score(board) << endl; //������� �� ����� ����
	for (int i = 0; i < 4; i++) {
		cout << "\t \t \t";
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == 0) {
				cout << setw(4) << "."; //���� ������ ������� ����� ���� ������� �� ���� ���� �����
			}
			else {
				cout << setw(4) << board[i][j]; //����� ������� �������� �������� �������
			}
		}
		cout << "\n";
	}
	cout << endl << endl << endl;
	cout << "\t \t \t �������:" << endl << "\t \t \t esc - ��� ������ �� ����" << endl << "\t \t \t 1 -��������� � ������� ����" << endl << "\t \t \t 2-������ ����� ����" << endl;

}


//�������, �������� ����� �� ��������� �����������
bool canDoMove(int line, int column, int nextLine, int nextColumn) {
	if (nextLine < 0 || nextColumn < 0 || nextLine >= 4 || nextColumn >= 4 || board[line][column] != board[nextLine][nextColumn] && board[nextLine][nextColumn] != 0) {
		return false;
	}
	return true;
}



//�������, �����������, �� ������� �� ������������
bool isWin(int board[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == 32) {
				return true;
			}
		}
	}

	return false;
}

//�������, ����������� ������������ �������� �� ����
void applyMove(int direction) {
	int startLine = 0, startColumn = 0, LineStep = 1, columnStep = 1;

	if (direction == 0) {
		startLine = 3;
		LineStep = -1;
	}
	if (direction == 1) {
		startColumn = 3;
		columnStep = -1;
	}
	bool stop = false;
	int movePossible = 0, canAddPiece = 0;
	do {
		movePossible = 0;
		for (int i = startLine; i >= 0 && i < 4; i += LineStep) {
			for (int j = startColumn; j >= 0 && j < 4; j += columnStep) {
				int nextI = i + dirLine[direction];
				int nextJ = j + dirColumn[direction];
				if (board[i][j] && canDoMove(i, j, nextI, nextJ)) {
					board[nextI][nextJ] += board[i][j];
					board[i][j] = 0;
					movePossible = 1;
					canAddPiece = 1;
				}
			}
		}
		printUI_game();
	} while (movePossible);

	if (canAddPiece) {
		addPiece();
	}
}

//�������, �����������, ���� �� � ������� ������� �������, �� ���� ���� �� �� ���� ������ �����, ����� ��� ��������� ������
bool canAddPiece(int board[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == 0) {
				return true;
			}
		}
	}
	return false;
}


//�������, �����������, �� �������� �� ������
bool isOver() {
	string s;
	if (canAddPiece(board) == false) {
		bool over = true;
		if ((board[0][0] == board[0][1]) || (board[0][0] == board[1][0])) {
			over = false;
		}
		else if ((board[3][0] == board[2][0]) || (board[3][0] == board[3][1])) {
			over = false;
		}
		else if ((board[0][3] == board[0][2]) || (board[0][3] == board[1][3])) {
			over = false;
		}
		else if ((board[3][3] == board[3][2]) || (board[3][3] == board[2][3])) {
			over = false;
		}
		else {
			for (int i = 1; i < 3; i++) {
				for (int j = 1; j < 3; j++) {
					if ((board[i][j] == board[i][j + 1]) || (board[i][j] == board[i][j - 1]) || (board[i][j] == board[i + 1][j]) || (board[i][j] == board[i - 1][j])) {
						over = false;
					}
				}
			}
		}

		return over;
	}
	return false;
}


//�������, ����������� ��������� ��������� � ������ ���������
void over() {
	ifstream file_over("over.txt");
	string str;
	while (!file_over.eof()) {
		getline(file_over, str);
		cout << str << endl;

	}
	file_over.close();
	while (1 == 1) {
		int key = getch();
		if (key == 49) {
			printUI_first();
			break;
		}
		else if (key == 50) {
			newGame();
			game_all();
			break;
		}
		else if (key == 27) {
			exit_game("fast");
			break;
		}
		else {
			continue;
		}
	}
}


//�������,���������� �� ��������� ��� ��������, �� ���� �� ��������� ������� � ������������ � ������ ��������
void Win() {
	ifstream file_win("win.txt");
	string str;
	while (!file_win.eof()) {
		getline(file_win, str);
		cout << str << endl;

	}
	file_win.close();

	while (1 == 1) {
		int command = getch(); //������������, ����� ������� ����� ������������,
		//��������� �� ����� ����������� �� ������ ������ ����� ���, ��� ����������� ������������(�� ������ ���������� ����������)
		if (command == 27) { //������������ ����� esc
			exit_game("fast"); //��������� ������� ����� �� ����
			break;
		}
		else if (command == 49) {//������������ ����� 1
			printUI_first(); //��������� ������� ����
			break;
		}
		else if (command == 50) {//������������ ����� 2
			newGame();  //�������� ����� ����
			game_all(); //���������� �������� ����� ����
			break;
		}
		else {
			continue; //������ ������� ������ ������������
		}
	}

}


//�������, ���������� �� ������ ����� ���� 2048
void game_all() {
	int commandToDir[128];
	commandToDir[80] = 0; //����
	commandToDir[77] = 1; //������
	commandToDir[72] = 2; //�����
	commandToDir[75] = 3; //�����
	while (1 == 1) {
		system("cls"); //�������� ������
		cout << endl << endl << endl;
		cout << "\t\t" << "   ������� ����� ��������� ��� ������" << endl;
		cout << endl << "\t \t \t " << "     ����: " << score(board) << endl; //����� �� ����� ����� ������� � ���� ����
		for (int i = 0; i < 4; i++) {
			cout << "\t \t \t";
			for (int j = 0; j < 4; j++) {
				if (board[i][j] == 0) {
					cout << setw(4) << "."; //���� � ������� ������� ����� ����, �� �� ���� ����� � ���� ���� ������������ �����
				}
				else {
					cout << setw(4) << board[i][j]; //����� ������� �������� �������� �������
				}
			}
			cout << "\n";
		}
		ifstream file_game("game.txt"); //���������� ��������� ����
		string str;
		while (!file_game.eof()) {
			getline(file_game, str);
			cout << str << endl;

		}
		file_game.close();

		int command = getch(); //���������� ������� ������ �������������

		if (command == 80 || command == 77 || command == 75 || command == 72) {
			int currentDirection = commandToDir[command];
			applyMove(currentDirection);
			break;
		}
		else if (command == 50) {//������� 2
			newGame();
			game_all();
			break;
		}
		else if (command == 27) {//������� esc
			exit_game("fast");
			break;
		}
		else if (command == 49) {//������� 1
			cout << "\t \t \t ������ ����� ������ �� ����������, �������, ��� ������ ������� � ������� ���� ?" << endl;
			cout << "\t \t \t 1 - �������� ����" << endl << "\t \t \t 2 - ��������" << endl;
			while (1 == 1) {
				int k = getch();
				if (k == 49) { //���� ������������ ����� 1, ������ ����� ��������� � ������� ����
					printUI_first(); //��������� �� �������� �������� ����
					break;
				}
				else if (k == 50) {//���� ������������ ����� 2, �� �� ����� ��������
					break;
				}
				else {
					continue; //������ ������� ������ ������������
				}
			}
		}
		else {
			continue;
		}
	}
	while (true) {
		printUI_game(); //���������� ��������� ����
		if (isWin(board) == true) { //��������, �� ������� �� �����
			Win();
			break;
		}
		if (isOver() == true) {//���������, �� �������� �� ������
			over();
			break;
		}

		int command = getch(); //��������� ������� ������ �������������

		if (command == 80 || command == 77 || command == 75 || command == 72) {
			int currentDirection = commandToDir[command];
			applyMove(currentDirection);
		}
		else if (command == 50) {//n
			newGame();
		}
		else if (command == 27) {//esc
			exit_game("ask");
			break;
		}
		else if (command == 49) {//esc
			cout << "\t \t \t ������ ����� ������ �� ����������, �������, ��� ������ ������� � ������� ���� ?" << endl;
			cout << "\t \t \t 1 - �������� ����" << endl << "\t \t \t 2 - ��������" << endl;
			while (1 == 1) {
				int k = getch(); //��������� ������� ������ �������������
				if (k == 49) { //������������ ����� 1, ������ ����� ��������� � ������� ����
					printUI_first(); //��������� �������� �������� ����
					break;
				}
				else if (k == 50) {//������������ ����� 2, ������ ����� ��������
					break;
				}
				else {
					continue;//������ ������� ������ ������������
				}
			}
		}
		else {
			continue;
		}
	}

	system("pause");
}