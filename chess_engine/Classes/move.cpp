#include "Headers/move.h"

Move::Move() {
    this->startX = -1;
    this->startY = -1;
    this->endX = -1;
    this->endY = -1;
    setTarget(NULL);
}

Move::Move(int startX, int startY, int endX, int endY) {
    this->startX = startX;
    this->startY = startY;
    this->endX = endX;
    this->endY = endY;
    setTarget(NULL);
}

Move::Move(std::string move) {
    this->startX = (int)move[0] - 97;
    this->startY = move[1] - '0' - 1;
    this->endX = (int)move[3] - 97;
    this->endY = move[4] - '0' - 1;
    setTarget(NULL);
}

std::string Move::getMoveAsString() {
    if (castling) {
        if (this->endX == 6)
            return "O-O";
        else
            return "O-O-O";
    }

    return (char)(this->startX + 97)
    + std::to_string(this->startY + 1) 
    + "-"
    + (char)(this->endX + 97)
    + std::to_string(this->endY + 1);
}

void Move::setTarget(Piece *target) {
    this->target = target;
}