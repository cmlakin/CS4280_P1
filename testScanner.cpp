// call scanner and  print  token until scaner returns EOF
#include "scanner.h"
#include "testScanner.h"

using  namespace std;

void testScanner(istream &in) {
  string fileLine;
  int lineNum = 0;
  // create a variable to store token sent back from scanner

  if (in.eof()) {
    cout << "Error: Empty file, no content.\n";
    cout << "Exiting program.\n";
  }
  while(!in.eof()) {
    while(getline(in, fileLine)) {
      lineNum++;

      scanner(fileLine, lineNum);
      // not sure if I should do this here, or if it should be done below
      //cout << lineNum << " " << fileLine << endl;
    }

    // // pass line and line number to scanner
    // scanner(fileLine, lineNum);
    // //scanner returns token info - print info
    // //check if line is empty or not
    // if (fileLine.empty()){
    //   //if empty - get new line
    // }
    // else {
    //   //if not empty - continue
    //   continue;
    // }

  }
}

//create a print function to print contents of token passed back from scanner
