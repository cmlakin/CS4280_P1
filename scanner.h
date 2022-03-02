#ifndef SCANNER_h
#define SCANNER_h

#include <iostream>
#include <stdlib.h>
#include <string>
#include "token.h"

using namespace std;

// #define KW 1000;
// #define ID 1001;
// #define EOF 1002;
// #define NUM 1003;
// #define OP 1004;
// #define CMT 1005;
// #define ERR -1;

void scanner(const string&, Token);
void getChar(string&);
void getCol(char, char);
// tokenType FSDriver();

#endif
