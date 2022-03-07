// call scanner and  print  token until scaner returns EOF
//#include "token.h"
#include "scanner.h"
#include "testScanner.h"

using namespace std;

void testScanner(istream& in) {
  // cout << "*** In testScanner.cpp *** \n";
  Token token;
  string fileLine;
  int lineNum = 0;
  // create a variable to store token sent back from scanner



  if (in.eof()) {
    cout << "Error: Empty file, no content.\n";
    cout << "Exiting program.\n";
  }
  else if(!in.eof()) {
    // cout << "--- in testScanner !eof while loop\n";
    while(getline(in, fileLine)) {
      // cout << "--- in testScanner geline loop\n";
      cout << "fileLine = " << fileLine << endl;
      lineNum++;
      // not sure if I should do this here, or if it should be done below
      //cout << "*** In testScanner.cpp before scanner call *** \n";

      while (fileLine.length() > 0) {

        // pass line and line number to scanner
        token = scanner(fileLine, lineNum);
        //scanner returns token info - print info
        if (token.tokenID == -1) {
          cout << "ERROR: Invalid character: " << token.chars << endl;
          cout << "Exiting program.\n";
          return;
        }
        else if (token.tokenID == -2) {
          cout << "Error: string not keyword. Invalid token: " << token.chars << endl;
          cout << "Exiting program.\n";
          return;
        }
        else if (token.tokenID == 500) {
          continue;
        }
        else {
          cout << "Token line number: " << token.line << endl;
          cout << "Token type: " << token.tokenID << endl;
          cout << "Token : " << token.chars << endl;
        //return;
        }
      }
    }
  }
  return;
}

//create a print function to print contents of token passed back from scanner
