#include "Headers/rook.h"

Rook::Rook(Color color) : Piece(color) {
	this->color = color;
}

PieceChar Rook::getPieceChar() {
	if(this->color == Color::White)
		return PieceChar::RookWhite;
	else
		return PieceChar::RookBlack;
}

std::vector<Move> Rook::getPossibleMoves(Board board) {
	std::vector<Move> moves;

	std::vector<Move>::iterator it;
	it = moves.begin();
	std::vector<Move> tempMoveList;

	for(int i = 0; i < 4; i++) {

		Direction dir = Direction::West;
		switch(i) {
			case 0:
			dir = Direction::North;
			break;

			case 1:
			dir = Direction::East;
			break;

			case 2:
			dir = Direction::South;
			break;
		}
		tempMoveList = this->getPossibleMovesInDirection(board, dir, 8);
		moves.insert(it, tempMoveList.begin(), tempMoveList.end());
		it = moves.begin();
	}

	return moves;
}

// does not check for castling
Move Rook::getMoveIfPossible(Board board, Point endPos) {
	std::vector<Move> moves;

	for(int i = 0; i < 4; i++) {

		Direction dir = Direction::West;
		switch(i) {
			case 0:
			dir = Direction::North;
			break;

			case 1:
			dir = Direction::East;
			break;

			case 2:
			dir = Direction::South;
			break;
		}
		moves = this->getPossibleMovesInDirection(board, dir, 8);
		for(int i = 0; i < static_cast<int>(moves.size()); i++) {
			if(moves[i].endX == endPos.x && moves[i].endY == endPos.y)
				return moves[i];
		}
	}

	return Move(-1, -1, -1, -1);
}

int Rook::getValue() {
	return static_cast<int>(Value::Rook) + ValueRookPos[x][(this->color == Color::White) ? y : HEIGHT - 1];
}

int Rook::getIndex() {
	return static_cast<int>(PieceIndex::Rook);
}

bool Rook::checkIfPosPossible(Board board, Point pos) {
	int xDir;
	int yDir;
	if(x > pos.x)
		xDir = -1;
	else if(x < pos.x)
		xDir = 1;
	else
		xDir = 0;
	if(y > pos.y)
		yDir = -1;
	else if(y < pos.y)
		yDir = 1;
	else
		yDir = 0;

	if(xDir != 0 && yDir != 0)
		return false;


	for(int i = 1; i < 8; i++) {
		int newX = x + i * xDir;
		int newY = y + i * yDir;
		if(pos.x == newX && pos.y == newY)
			return true;
		else if(board.getPiece(newX, newY) != NULL)
			return false;
	}

	return false;
}
