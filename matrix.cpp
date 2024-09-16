#include "matrix.h"
#include "global.h" // Include global.h to access global variables
#include "life.h"   // Include life.h for the Life class

// Constructor for Matrix
Matrix::Matrix() : toggle(true) {
    grid_1 = new char* [CANVAS_ROW];
    grid_2 = new char* [CANVAS_ROW];

    for (int i = 0; i < CANVAS_ROW; i++) {
        grid_1[i] = new char[CANVAS_COL];
        grid_2[i] = new char[CANVAS_COL];
    }

    for (int i = 0; i < CANVAS_ROW; i++) {
        for (int j = 0; j < CANVAS_COL; j++) {
            grid_1[i][j] = DEAD;
        }
    }
}

// Destructor for Matrix
Matrix::~Matrix() {
    for (int i = 0; i < CANVAS_ROW; i++) {
        delete[] grid_1[i];
        delete[] grid_2[i];
    }
    delete[] grid_1;
    delete[] grid_2;
}

// Method to render the matrix
void Matrix::render() const {
    clearScreen();
    char** grid = toggle ? grid_1 : grid_2;
    for (int i = 0; i < CANVAS_ROW; i++) {
        for (int j = 0; j < CANVAS_COL; j++) {
            std::cout << grid[i][j];
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < CANVAS_COL; i++) {
        std::cout << '=';
    }
    std::cout << std::endl;
}

// Method to compute the next state of the matrix
void Matrix::computeNextState() {
    char** currentGrid = toggle ? grid_1 : grid_2;
    char** nextGrid = toggle ? grid_2 : grid_1;

    for (int i = 0; i < CANVAS_ROW; i++) {
        for (int j = 0; j < CANVAS_COL; j++) {
            nextGrid[i][j] = nextState(currentGrid[i][j], i, j, toggle);
        }
    }
    toggle = !toggle;
}

// Method to initialize the state of the matrix with a Life object
bool Matrix::initState(Life* life) {
    if (life == nullptr) {
        std::cout << "Cannot add nullptr life" << std::endl;
        return false;
    }
    int startRow = life->getRow();
    int startCol = life->getCol();
    int height = life->getHeight();
    int width = life->getWidth();

    for (int i = startRow; i - startRow < height; i++) {
        for (int j = startCol; j - startCol < width; j++) {
            if (i < CANVAS_ROW && j < CANVAS_COL) {
                grid_1[i][j] = life->getFigure(i - startRow, j - startCol);
            }
        }
    }
    return true;
}

// Private method to clear the screen
void Matrix::clearScreen() const {
#ifdef _MSC_VER
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft, &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
#else
    static const char* term = getenv("TERM");
    if (term == nullptr || strcmp(term, "dumb") == 0) {
        std::cout << std::endl;
    }
    else {
        static const char* ESC_SEQ = "\x1B[";
        std::cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << std::flush;
    }
#endif
}

// Private method to determine the next state of a cell
char Matrix::nextState(char state, char row, char col, bool toggle) const {
    int neighbors = 0;
    char** currentGrid = toggle ? grid_1 : grid_2;

    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i == row && j == col) continue;
            if (i >= 0 && i < CANVAS_ROW && j >= 0 && j < CANVAS_COL) {
                if (currentGrid[i][j] == ALIVE) {
                    neighbors++;
                }
            }
        }
    }

    if (state == ALIVE) {
        return (neighbors > 1 && neighbors < 4) ? ALIVE : DEAD;
    }
    else {
        return (neighbors == 3) ? ALIVE : DEAD;
    }
}
