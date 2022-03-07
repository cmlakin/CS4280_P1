/***************************************************************
 * Corrina Lakin
 * CS4280 P1
 * Description:
    Lexical Analyzer
 *************************************************************/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <type_traits>
#include "testScanner.h"

using namespace std;

int main(int argc, char * argv[]) {
  cout << "*** in main\n";
  char* filenameIn;
  ifstream inFile;

  // parse commandline arguements
  if (argc == 2) {
    filenameIn = argv[1];

    inFile.open(filenameIn);
    testScanner(inFile);
    inFile.close();
  }
  // else {
  //   testScanner(cin);
  // }

  cout << "End of program.\n";
  return 0;
}

// scan file for content
