// scan in and return one token
#include "scanner.h"

// store string and call getchar();
string tokenNames[] = {"Keyword", "Identifier", "EOF", "Number", "Operator",
                        "Comment"};

// declare FSA table here
const int statesRow = 9;
const int tokensCol = 8;
const int table[statesRow][tokensCol] = { {   1,    3,    4,    5,   -1,    6,    7, 1000},  //0(s1)
                                  {   2,    2,   -1,   -1,   -1,    2,   -1,   -1},  //1(s2)
                                  {   2,    2, 1001, 1001, 1001,    2, 1001, 1001},  //2(s3)
                                  {   3, 1002, 1002, 1002, 1002, 1002, 1002, 1002},  //3(s4)
                                  {1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004},  //4(s5)
                                  {  -1,   -1,   -1,    4,    4,   -1,   -1,   -1},  //5(s6)
                                  {1003, 1003, 1003, 1003, 1003,    6, 1003, 1003},  //6(s7)
                                  {   7,    7,    7,    7,    7,    7,    8,   -1},  //7(s8)
                                  {1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005}}; //8(s9)


// string variable
// static string fileString;
// nextChar variable
static char nextChar;
static char lookAhead;
static int fsaCol;
// // use this to look at the upcoming nextChar
// static int lineN;

// pass 2 arguemnts - string and line number
Token scanner(const string& fileString, int lineN)  {

  FSDriver(fileString, lineN);




}

char look(string& str){
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
  char next = '\0';
  // parse string for nextChar
  next = str.at(0);
  str.erase(0, 1);
  cout << "string = " << str << endl;

  return next;
}

int getCol(char currentChar){
  // find FSA column
  if (isalpha(currentChar)){
    if (isupper(currentChar)){
      fsaCol = 1;
    }
    else {
      fsaCol = 0;
    }
  }
  else if (isdigit(currentChar)){
    fsaCol = 5;
  }
  else {
    for(int i = 0; i <= 7; i++){
      if (currentChar == operator1[i].at(0)) {
        fsaCol = 2;
      }
      else if(currentChar == operator2){
        fsaCol = 3;
      }
      else if (currentChar == operator3) {
        fsaCol = 4;
      }
      else if (currentChar == comment){
        fsaCol = 6;
      }
      else if (currentChar == '\0') {
        fsaCol = 7;
      }
      else {
        //error - unknown character error
      }
    }
  }
  cout << "current Char = " << currentChar << endl;
  cout << "fsaCol = " << fsaCol << endl;
  return fsaCol;

}

Token FSDriver(string& fileString, int line) // assume nextChar set, and used as column index
{
  // state_t state = INITIAL; // (0 = S1 here)
  // state_t nextState;
  int state = 0; //INITIAL; // (0 = S1 here)
  int nextState;
  Token token;
  string s = NULL;
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
        // if (S in Keywords){
        //   return (KW_tk, S); // or specific keyword
        // }
        // else {
        //   //error
        // }
        cout << "KW_TK\n";
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

}
