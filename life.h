#ifndef life_h
#define life_h

class Matrix;       // Forward declaration of Matrix class
class Simulation;   // Forward declaration of Simulation class

class Life {
public:
    // Public member functions
    int getCol() const;
    int getRow() const;
    int getHeight() const;
    int getWidth() const;
    char getFigure(int r, int c) const;

protected:
    // Protected member variables
    int col;
    int row;
    int height;
    int width;
    char** sprite;
    Matrix* matrix;
    Simulation* simulation;
};

#endif // LIFE_H
