#pragma once
#include <iostream>
using namespace std;

enum Piece { KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, EMPTY }; //перелік фігур
enum Color { WHITE, BLACK, NONE }; //перелік кольорів

class Square 
{
private:
	Piece piece;
	Color color;
	int x, y;
public:
	Piece getPiece();
	Color getColor();

	void setX(int X) { x = X; }
	void setY(int Y) { y = Y; }
	int getX() { return x; }
	int getY() { return y; }
	
	void setSpace(Square*); //встановлення кольору і фігури в поточній клітинці, використовуючи інформацію з іншої
	void setEmpty(); //встановлення кольору та фігури в пусті місця
	void setPieceAndColor(Piece, Color);  //встановлення фігури та кольору в поточній клітинки
	
	
	Square();//конструктор
};

class Board 
{
private:
	Square square[8][8];
	Color side = WHITE;
	bool moveKing(Square* thisKing, Square* tuda);
	bool moveQueen(Square* thisQueen, Square* tuda);
	bool movePawn(Square* thisPawn, Square* tuda);
	bool moveRook(Square* thisRook, Square* tuda);
	bool moveBishop(Square* thisBishop, Square* tuda);
	bool moveKnight(Square* thisKnight, Square* tuda);
	bool makeMove(int x1, int y1, int x2, int y2); //перевірка і виконання ходу
	void printBoard(); //виведення поточного стану дошки
public:
	void setBoard();  //заповнення дошки фігурами та пешками
	bool playGame(); //початок гри та визов методу doMove()
	bool doMove(); //запит на хід та його виконання

	Square* getSquare(int x, int y) {
		return &square[x][y];
	}
	void setSquare(Square* s, int x, int y) {
		square[x][y] = *s;
	}	
};
