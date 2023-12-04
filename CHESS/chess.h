#pragma once
#include <iostream>
using namespace std;

enum Piece { KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, EMPTY };
enum Color { WHITE, BLACK, NONE };

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
	
	void setSpace(Square*);
	void setEmpty();
	void setPieceAndColor(Piece, Color);  
	
	
	Square();
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
	bool makeMove(int x1, int y1, int x2, int y2);
	void printBoard();
public:
	void setBoard();  
	bool playGame();
	bool doMove();

	Square* getSquare(int x, int y) {
		return &square[x][y];
	}
	void setSquare(Square* s, int x, int y) {
		square[x][y] = *s;
	}
	

	
};
