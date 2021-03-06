#ifndef King_H
#define King_H

#include "../../Headers/piece.h"
#include "../../Headers/move.h"

class King : public Piece
{
public:
    King(Color color);
    PieceChar getPieceChar();
    std::vector<Move> getPossibleMoves(Board board);
    Move getMoveIfPossible(Board board, Point endPos);
    int getValue();
    int getIndex();
    bool checkIfPosPossible(Board board, Point pos);
    

private:
    bool getCastlingPossibility(Board board, CastlingDirection direction);
    
};

#endif