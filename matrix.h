#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "global.h"  // Include global.h to access global variables
#include "life.h"    // Forward declaration of Life class

class Matrix {
public:
    // Constructor and Destructor
    Matrix();
    ~Matrix();

    // Methods
    void render() const;
    void computeNextState();
    bool initState(Life* life);

private:
    // Private Methods
    void clearScreen() const;
    char nextState(char state, char row, char col, bool toggle) const;

    // Member Variables
    char** grid_1;
    char** grid_2;
    bool toggle;
};

#endif // MATRIX_H
