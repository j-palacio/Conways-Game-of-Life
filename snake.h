#ifndef SNAKE_H
#define SNAKE_H

#include "life.h"
#include "global.h"

class Snake : public Life {
public:
    // Constructor and destructor
    Snake(int r, int c);
    ~Snake();
};

#endif /* SNAKE_H */

