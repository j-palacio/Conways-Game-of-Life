#ifndef global_h
#define global_h

#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>

#ifdef _MSC_VER  // DO NOT BREAK APART THE IF PREPROCESSOR DIRECTIVES
#include <windows.h> 
#else			
#include <iostream>
#include <cstring>
#include <cstdlib>
#endif		

///////////////////////////////////////////////////////////////////////////
// Global constants
///////////////////////////////////////////////////////////////////////////

const int CANVAS_ROW = 24;
const int CANVAS_COL = 24;

const int BOX_SIZE = 2;
const int SNAKE_SIZE = 4;
const int BIGBLINK_SIZE = 9;
const int BOAT_SIZE = 3;

const int MAX_STEPS = 30;

const char ALIVE = 'X';
const char DEAD = '.';


///////////////////////////////////////////////////////////////////////////
//  Utility function declarations
///////////////////////////////////////////////////////////////////////////

void clearScreen();
void delay(int ms);

#endif /* global_h */
