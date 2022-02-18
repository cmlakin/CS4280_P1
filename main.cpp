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


int main(int argc, char * argv[]) {

  char* filenameIn;
  ifstream inFile;
  ofstream outFile;
  string userWord;

  // parse commandline arguements
  if (argc == 2) {
    filenameIn = argv[1];

    inFile.open(filenameIn);
    scan(inFile);
    inFile.close();
  }
  else {
    scan(cin);
  }

  return 0;
}

// scan file for content

void scan(istream& in) {
  string element;
  in >> element;
  if (in.eof()) {
    cout << "Error: Empty file, no content.\n";
    cout << "Exiting program.\n";
  }
  while(!in.eof()) {

    char first = element.front();
    in >> userWord;
  }
}
