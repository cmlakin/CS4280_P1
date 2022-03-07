// call scanner and  print  token until scaner returns EOF
//#include "token.h"
#include "scanner.h"
#include "testScanner.h"

using namespace std;

void testScanner(istream& in) {

  Token token;
  string fileLine;
  int lineNum = 0;

  if (in.eof()) {
    cout << "Error: Empty file, no content.\n";
    cout << "Exiting program.\n";
  }
  else if(!in.eof()) {

    while(getline(in, fileLine)) {

      lineNum++;

      while (fileLine.length() > 0) {

        // pass line and line number to scanner
        token = scanner(fileLine, lineNum);
        //scanner returns token info - print info
        if (token.tokenID == -1) {
          cout << "ERROR: Invalid character: " << token.chars << endl;
          cout << "Exiting program.\n\n";
          return;
        }
        else if (token.tokenID == -2) {
          cout << "ERROR: Invalid character on line #: "<< token.line << endl;
          cout << "String not keyword: " << token.chars << endl;
          cout << "Exiting program.\n\n";
          return;
        }
        else if (token.tokenID == 500) {
          continue;
        }
        else {
          printTokenType(token.tokenID, token.line, token.chars);
        }
      }
    }

    // // set when the end of the file has been reached.
    token.line = lineNum;
    token.tokenID = 1003;
    token.chars = "EOF";
    printTokenType(token.tokenID, token.line, token.chars);
  }

  return;
}

void printTokenType(int tkId, int tkLn, string tkStr) {
  int index = tkId - 1001;
  cout << "Line number: " << tkLn << endl;
  cout << tokenNames[index] << ": " << tkStr <<endl;


  switch(index) {
    case 0:  cout << "KW_tk\n\n";
    break;
    case 1:  cout << "ID_tk\n\n";
    break;
    case 2:  cout << "EOF_tk\n\n";
    break;
    case 3:  cout << "NUM_tk\n\n";
    break;
    case 4:  cout << "OP_tk\n\n";
    break;
    case 5:  cout << "CMT_tk\n\n";
    break;

  }
}
