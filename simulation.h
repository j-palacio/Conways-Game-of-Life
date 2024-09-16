#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "matrix.h" // Assuming Matrix class is defined in matrix.h
#include "life.h"   // Assuming Life class is defined in life.h
#include "global.h"

class Simulation {
public:
    // Constructor and Destructor
    Simulation(Life** life, int numLife);
    ~Simulation();

    // Methods
    void simulate();
    void report();
    int two(int u);
    int three(int x);
    void one(int t);

private:
    // Private Methods
    void delay(int ms) const;

    // Member Variables
    int watchme;
    Matrix* matrix;
    int steps;
    bool automate;
};

#endif // SIMULATION_H


