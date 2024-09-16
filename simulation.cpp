#include "simulation.h"

// Constructor for Simulation
Simulation::Simulation(Life** life, int numLife) {
    watchme = 1;
    steps = 0;
    automate = false;
    matrix = new Matrix();

    if (life != nullptr) {
        for (int i = 0; i < numLife; i++) {
            if (life[i] != nullptr) {
                bool success = matrix->initState(life[i]);
                if (!success) {
                    std::cout << "Failed to add life to the matrix" << std::endl;
                }
            }
        }
    }
}

// Destructor for Simulation
Simulation::~Simulation() {
    delete matrix;
}

// Method to run the simulation
void Simulation::simulate() {
    while (true) {
        matrix->render();

        if (!automate) {
            std::cout << "command (<space> to step, <a> to automate, <q> to quit): ";

            std::string action;
            std::getline(std::cin, action);

            switch (action[0]) {
            default:
                std::cout << '\a' << std::endl;  // beep
                continue;
            case 'q':
                std::cout << "Quitting Game." << std::endl;
                return;
            case ' ':
                break;
            case 'a':
                automate = true;
                break;
            }
        }
        else {
            if (steps >= MAX_STEPS) {
                std::cout << "Reached max steps, quitting." << std::endl;
                return;
            }
            delay(300);
        }
        steps++;
        matrix->computeNextState();
    }
}

// Method to report status
void Simulation::report() {
    std::string msg = "Hello World!"; // Replace Hello World with your answer.
    std::cout << msg << std::endl;
}

// Method for 'two' operation
int Simulation::two(int u) {
    return (u << 2) % 10;
}

// Method for 'three' operation
int Simulation::three(int x) {
    if (x % 2 == 0)
        return 5;
    else
        return 3;
}

// Method for 'one' operation
void Simulation::one(int t) {
    int i = 0;
    int k = watchme;
    while (++i < t) {
        if (i == 0)
            k = 2;
        else if (i == 1)
            k = 7;
        else if (i == 4)
            k = 8;
        else if (i == 5)
            k = 5;
        else
            k = two(watchme);
        watchme = k;
    }
    k = three(watchme);
    watchme = k;
}

// Private method for delay
void Simulation::delay(int ms) const {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
