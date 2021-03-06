#include "Headers/queen.h"

Queen::Queen(Color color) : Piece(color)
{
    this->color = color;
}

PieceChar Queen::getPieceChar()
{
    if (this->color == WHITE)
        return QUEENWHITE;
    else
        return QUEENBLACK;
}

std::vector<Move> Queen::getPossibleMoves(Board board)
{
    std::vector<Move> moves;

    std::vector<Move>::iterator it;
    it = moves.begin();
    std::vector<Move> tempMoveList;

    for (int i = 1; i <= 9; i++)
    {
        if (i == 5)
            continue;
        tempMoveList = this->getPossibleMovesInDirection(board, static_cast<Direction>(i), 8);
        moves.insert(it, tempMoveList.begin(), tempMoveList.end());
        it = moves.begin();
    }

    return moves;
}

// does not check for castling
Move Queen::getMoveIfPossible(Board board, Point endPos)
{
    std::vector<Move> moves;

    for (int i = 1; i <= 9; i++)
    {
        if (i == 5)
            continue;
        moves = this->getPossibleMovesInDirection(board, static_cast<Direction>(i), 8);
        for (int i = 0; i < static_cast<int>(moves.size()); i++) {
            if (moves[i].endX == endPos.x && moves[i].endY == endPos.y)
                return moves[i];
        }
    }

    return Move(-1, -1, -1, -1);
}

int Queen::getValue()
{
    return VALUEQUEEN + VALUEQUEENPOS[x][(this->color == WHITE) ? y : HEIGHT - 1];
}

int Queen::getIndex() {
    return QUEENINDEX;
}

bool Queen::checkIfPosPossible(Board board, Point pos)
{
    int xDir;
    int yDir;
    if (x > pos.x)
        xDir = -1;
    else if (x < pos.x)
        xDir = 1;
    else
        xDir = 0;
    if (y > pos.y)
        yDir = -1;
    else if (y < pos.y)
        yDir = 1;
    else
        yDir = 0;

    for (int i = 1; i < 8; i++) {
        int newX = x + i * xDir;
        int newY = y + i * yDir;
        if (pos.x == newX && pos.y == newY)
            return true;
        else if (board.getPiece(newX, newY) != NULL)
            return false;
    }

    return false;
}
