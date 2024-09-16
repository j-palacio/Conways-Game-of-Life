#include "life.h"

///////////////////////////////////////////////////////////////////////////
// Life Implemention
///////////////////////////////////////////////////////////////////////////


int Life::getCol() const {
    return col;
}

int Life::getRow() const {
    return row;
}

int Life::getHeight() const {
    return height;
}

int Life::getWidth() const {
    return width;
}

char Life::getFigure(int r, int c) const {
    return sprite[r][c];
}


