#ifndef BOX_H
#define BOX_H

#include "life.h" // Assuming the Life class is defined in life.h
#include "global.h"

class Box : public Life {
public:
    // Constructor and Destructor
    Box(int r, int c);
    ~Box();
};

#endif // BOX_H
