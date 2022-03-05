// scan in and return one token
#include "scanner.h"

// store string and call getchar();
string tokenNames[] = {"Keyword", "Identifier", "EOF", "Number", "Operator",
                        "Comment"};

// declare FSA table here
const int statesRow = 9;
const int tokensCol = 8;
const int table[statesRow][tokensCol] = { {   1,    3,    4,    5,   -1,    6,    7, 1001},  //0(s1)
                                          {   2,    2,   -1,   -1,   -1,    2,   -1,   -1},  //1(s2)
                                          {   2,    2, 1002, 1002, 1002,    2, 1002, 1002},  //2(s3)
                                          {   3, 1003, 1003, 1003, 1003, 1003, 1003, 1003},  //3(s4)
                                          {1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005},  //4(s5)
                                          {  -1,   -1,   -1,    4,    4,   -1,   -1,   -1},  //5(s6)
                                          {1004, 1004, 1004, 1004, 1004,    6, 1004, 1004},  //6(s7)
                                          {   7,    7,    7,    7,    7,    7,    8,   -1},  //7(s8)
                                          {1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006}}; //8(s9)


// string variable
// static string fileString;
// nextChar variable
// static char nextChar;
// static int fsaCol;
// // use this to look at the upcoming nextChar
// static int lineN;

// pass 2 arguemnts - string and line number
Token scanner(string& fileString, int lineN)  {
  cout << "*** In scanner.cpp *** \n";
  Token temp;

  //temp = FSDriver(fileString, lineN);

  cout << "*** In scanner.cpp after FSDriver call *** \n";

  return temp;

}

char look(string& str){
  cout << "--- in look\n";
  char lookAhead = '\0';

  if(str.length() > 1) {
    lookAhead = str.at(0);
    cout << "lookAhead = " << lookAhead << endl;
  }
  else {
    // do something here
  }

  return lookAhead;
}

// site for string.at() https://www.geeksforgeeks.org/string-at-in-cpp/
// stie for string.end() https://www.javatpoint.com/cpp-string-end-function
char getChar(string& str) {
  cout << "--- in getCahr\n";
  char next = '\0';
  // parse string for nextChar
  next = str.at(0);
  str.erase(0, 1);
  cout << "string = " << str << endl;

  return next;
}

int getCol(char currentChar){
  cout << "--- in get col\n";
  int colNum = 0;
  // find FSA column
  if (isalpha(currentChar)){
    if (isupper(currentChar)){
      colNum = 1;
    }
    else {
      colNum = 0;
    }
  }
  else if (isdigit(currentChar)){
    colNum = 5;
  }
  else {
    for(int i = 0; i <= 7; i++){
      if (currentChar == operator1[i].at(0)) {
        colNum = 2;
      }
      else if(currentChar == operator2){
        colNum = 3;
      }
      else if (currentChar == operator3) {
        colNum = 4;
      }
      else if (currentChar == comment){
        colNum = 6;
      }
      else if (currentChar == '\0') {
        colNum = 7;
      }
      else {
        //error - unknown character error
      }
    }
  }
  cout << "current Char = " << currentChar << endl;
  cout << "colNum = " << colNum << endl;
  return colNum;

}

bool kwCheck(string& str) {
  int counter = 0;
  for (int i = 0; i < 14; i++){
    if (str == keyword[i]) {
      return true;
    }
    else {
      counter++;
    }
  }
  if (counter == 13){
    return false;
  }
}

Token FSDriver(string& fileString, int line) // assume nextChar set, and used as column index
{
  cout << "--- in FSDriver\n";
  // state_t state = INITIAL; // (0 = S1 here)
  // state_t nextState;
  int state = 0; //INITIAL; // (0 = S1 here)
  int nextState;
  Token token;
  string s = "";
  char nextChar = '\0';
  int fsaCol = 0;

  while (state == 0) {

    nextChar = look(fileString);
    fsaCol = getCol(nextChar);
    nextState = table[state][fsaCol];
    if (nextState == -5) {
      //Error(); // report error and exit
    }
    if (nextState != 0) { // put switch here instead of if statement
      if (tokenId(state) < 0){
        //error
        cout << "Error: " << state << endl;
      }
      else if (tokenId(state) == KW_tk) { // need reserved keyword loop
        int check = kwCheck(s);
        if (check) {
          cout << "KW_TK\n";
          token.tokenID = tokenId(state);
          return token; // or specific keyword
        }
        else {
          //error
          cout << "Error: string not keyword\n";
        }

      }
      else if (tokenId(state) >= ID_tk && tokenId(state) <= CMT_tk){
        // return which token type and string
        cout << "ID - CMT token\n";
      }
      // add additional states
      else {  // not FINAL  // this would be the default statement in switch
        token.line = line;
        state = nextState;
        char addChar = getChar(fileString);
        s.append(addChar, 1);
        nextChar = look(fileString); // something to see if finished with line
      }
    }
  }
  return token;

}
