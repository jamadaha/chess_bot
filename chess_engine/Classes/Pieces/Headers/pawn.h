#ifndef Pawn_H
#define Pawn_H

#include "../../Headers/piece.h"
#include "../../Headers/move.h"

class Pawn : public Piece
{
public:
    Pawn(Color color);
    PieceChar getPieceChar();
    std::vector<Move> getPossibleMoves(Board board);
    int getValue();
    int getIndex();

private:
};

#endif