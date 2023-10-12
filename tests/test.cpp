#include "pch.h"
#include "../2048_game_2023/functions.h"
#include "gtestbdd.h"

//Модульные тесты для функции isWin

//Пользователь выиграл
TEST(IsWinTest, Has2048) {
	//arrange
	int win[4][4] = { {2048, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
	//act
	bool res = isWin(win);
	//assert
	EXPECT_EQ(true, res);
}

//Пользователь не выиграл
TEST(IsWinTest, DoesNotHave2048) {
	//arrange
	int win[4][4] = { {2, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
	//act
	bool res = isWin(win);
	//assert
	EXPECT_EQ(false, res);
}


//Сценарии для функции canAddPiece
FEATURE("Pieces can be added on an empty space") {
	//AS_A developer
	//I_WANT to determine if a piece can be added
	//SO_THAT the game could stop if there aren't any places to add
}
SCENARIO("New piece can be added on a board")
{
	GIVEN("A board with an empty space")
		int board[4][4] = { {2, 2, 2, 2}, {2, 2, 2, 2}, {2, 2, 0, 2}, {2, 2, 2, 2} };
	WHEN("a player made a move")
		bool res = canAddPiece(board);
	THEN("The result should be true")
		ASSERT_EQ(true, res);
}
SCENARIO("New piece cannot be added on a board")
{
	GIVEN("A board without an empty space")
		int board[4][4] = { {2, 2, 2, 2}, {2, 2, 2, 2}, {2, 2, 2, 2}, {2, 2, 2, 2} };
	WHEN("a player made a move")
		bool res = canAddPiece(board);
	THEN("The result should be false")
		ASSERT_EQ(false, res);
}





//Модульные тесты для функции score

//Сумма очков верна
TEST(ScoreTest) {
	//arrange
	int win[4][4] = { {4, 4, 0, 0}, {0, 16, 0, 32}, {0, 64, 0, 0}, {0, 4, 0, 0} };
	//act
	int res = score(win);
	//assert
	EXPECT_EQ(124, res);
}



//Сценарии для функции canDoMove
FEATURE("The move can be made") {
	//AS_A developer
	//I_WANT to determine if a move can be made
	//SO_THAT the game could stop if there aren't any moves left
}
SCENARIO("The move can be made somewhere")
{
	GIVEN("A board with can move right from line 1 column 1 to line 1 column 2")
		int board[4][4] = { {2, 2, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
	WHEN("made a move")
		bool res = canDoMove(1,1,1,2);
	THEN("The result should be true")
		ASSERT_EQ(true, res);
}
SCENARIO("The move can be made somewhere")
{
	GIVEN("A board with cannot move somewhere from line 1 column 1")
		int board[4][4] = { {2, 0, 64, 0}, {0, 128, 0, 0}, {0, 0, 8, 0}, {0, 4, 0, 256} };
	WHEN("made a move to line 2 column 2")
		bool res = canDoMove(1, 1, 2, 2);
	THEN("The result should be false")
		ASSERT_EQ(false, res);
}
