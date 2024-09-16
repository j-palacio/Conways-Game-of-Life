#ifndef BOAT_H
#define BOAT_H

#include "life.h"


class Boat : public Life {
public:
    // Constructor and destructor
    Boat(int r, int c);
    ~Boat();
};

#endif /* BOAT_H */
