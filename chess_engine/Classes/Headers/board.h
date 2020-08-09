#ifndef Board_H
#define Board_H

class Zobrist;
class Piece;
class Bishop;
class King;
class Knight;
class Pawn;
class Queen;
class Rook;
class Move;

#include <string>
#include <vector>
#include "piece.h"
#include "constants.h"
#include "move.h"
#include "zobrist.h"
#include "point.h"

// used for random taking move
#include <algorithm>
#include <random>



class Board
{
public:
    int turnNumber = 0;
    bool kingAlive[2] = {true, true};
    bool castlingValid[2][2] = {{true, true}, {true, true}};
    Zobrist *zobrist;
    int enPassant;
    Color turn;

    Board();
    Board(Color turn);

    void setStartPos();
    void clearBoard();
    void importFEN(std::string FEN);
    void importPGN(std::string moves, bool exportMovePerHash);
    void importFakePGN(std::string moves);
    void printBoard();
    bool isSquareEmpty(int x, int y);
    bool isSquareEnemy(Color color, int x, int y);
    void placePiece(Piece *piece);
    Piece *getPiece(int x, int y);
    std::vector<Move> getAllMoves(Color side);
    Move getBestMove(int depth);
    int evaluateBoard();
    int evaluateBoard(Color side);
    void commitMove(Move *move);
    void doMove(Move *move);
    void switchTurn();
    std::string getFEN();

private:
    Piece *board[WIDTH][HEIGHT];
    
    

    Move getValidMove(Point endPos);
    Move getValidMove(Point endPos, PieceIndex promotionType);
    Move getValidMove(Point endPos, char pieceChar);
    Move getValidMove(Point endPos, char pieceChar, int column);
    Move getValidMove(Point endPos, char pieceChar, int column, PieceIndex promotionType);
    Move getValidMove(Point endPos, int row, char pieceChar);
    Move getValidMove(Point endPos, int row, char pieceChar, int column);
    void setTurn(Color turn);

    void placePiece(Piece *piece, int x, int y);
    void placePiece(PieceChar piece, int x, int y);
    void removePiece(int x, int y);

    void undoMove(Move *move);

    Piece *getPieceFromChar(PieceChar piece);
    PieceChar getPieceCharFromChar(char piece);
    PieceIndex getPieceIndexFromChar(char piece);
    Move minimax(int depth, bool isMax, Color currentTurn, int a, int b, bool doingHE, int *totalMoves, std::default_random_engine e);
};

#endif