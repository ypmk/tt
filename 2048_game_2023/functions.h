#pragma once

#include "pch.h"
#include<iostream>  //подключаем необходимые библиотеки
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

//прописываем прототипы функций чтобы использовать их и не думать о их расположении в файле
pair<int, int>generateUnoccupiedPosition();
void addPiece();
void newGame();
int score(int board[4][4]);
void exit_game(string s);
void rules();
void printUI_first();
void printUI_game();
bool canDoMove(int line, int column, int nextLine, int nextColumn);
bool isWin(int board[4][4]);
bool canAddPiece(int board[4][4]);
void applyMove(int direction);
bool isOver();
void over();
void game_all();
void Win();

