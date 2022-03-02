// scan in and return one token
#include "scanner.h"

// store string and call getchar();
// declare FSA table here
const int statesRow = 9;
const int tokensCol = 8;
const int table[statesRow][tokensCol];
// string variable
// static string fileString;
// nextChar variable
static char nextChar;
static char lookAhead;
static int fsaCol;
// // use this to look at the upcoming nextChar
// static int lineN;

// pass 2 arguemnts - string and line number
void scanner(const string& fileString, Token token)  {


  // TODO change error codes so they mean something different
  // initialize FSA table here         0id   1kw  2op1  3op2  4op3  5dig  6cmt  7eof
  table[statesRow][tokensCol] = { {   1,    3,    4,    5,   -1,    6,    7, 1000},  //0(s1)
                                  {   2,    2,   -1,   -1,   -1,    2,   -1,   -1},  //1(s2)
                                  {   2,    2, 1001, 1001, 1001,    2, 1001, 1001},  //2(s3)
                                  {   3, 1002, 1002, 1002, 1002, 1002, 1002, 1002},  //3(s4)
                                  {1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004},  //4(s5)
                                  {  -1,   -1,   -1,    4,    4,   -1,   -1,   -1},  //5(s6)
                                  {1003, 1003, 1003, 1003, 1003,    6, 1003, 1003},  //6(s7)
                                  {   7,    7,    7,    7,    7,    7,    8,   -1},  //7(s8)
                                  {1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005}}; //8(s9)

  string chars = fileString;
  while(chars.length() > 1) {
    cout << "***in scanner string = " << chars << endl;
    cout << "***char.length() = " << chars.length() << endl;
    getChar(chars);
  }



}

// site for string.at() https://www.geeksforgeeks.org/string-at-in-cpp/
// stie for string.end() https://www.javatpoint.com/cpp-string-end-function
void getChar(string& str) {
  // parse string for nextChar
  nextChar = str.at(0);
  cout << "nextChar = " << nextChar << endl;
  lookAhead = str.at(1);
  cout << "lookAhead = " << lookAhead << endl;

  str.erase(0, 1);
  cout << "string = " << s << endl;

  getCol(nextChar, lookAhead);

  // if(s.end()){
  //   // do something here
  //   cout << "end of string\n";
  //   return;
  // }
  // else {
  //
  // }
}

void getCol(char first, char second){
  // find FSA column
  if (isalpha(nextChar)){
    if (isupper(nextChar)){
      fsaCol = 1;
    }
    else {
      fsaCol = 0;
    }
  }
  else if (isdigit(nextChar)){
    fsaCol = 5;
  }
  else {
    for(int i = 0; i <= 7; i++){
      if (nextChar == operator1(i) {
        fsaCol = 2;
      }
      else if(nextChar == operator2){
        fsaCol = 3;
      }
      else if (nextChar == operator3) {
        fsaCol = 4;
      }
      else if (nextCßhar == comment){
        fsaCol = 6;
      }
      else if (nextChar == "EOF") {
        fsaCol = 7;
      }
      else {
        //error - unknown character error
      }
    }
  }

  cout << "fsaCol = " << fsaCol << endl;

}

// tokenType FSDriver() // assume nextChar set, and used as column index
// {
//   state_t state = INITIAL; // (0 = S1 here)
//   state_t nextState;
//   tokenType token;
//   string s = NULL;
//
//   while (state != FINAL) {
//     nextState = table[state][fsaCol];
//     if (nextState == Error) {
//       Error(); // report error and exit
//     }
//     if (nextState == FINAL) { // put switch here instead of if statement
//       if (token(state) == ERR){
//         //error
//       }
//       else if (token(state) == KW) { // need reserved keyword loop
//         if (S in Keywords){
//           return (KW_tk, S); // or specific keyword
//         }
//         else {
//           //error
//         }
//       }
//       else if (token(state) >= ID && token(state) <= CMT){
//         // return which token type and string
//       }
//       // add additional states
//       else {  // not FINAL  // this would be the default statement in switch
//         state := nextState;
//         append(S, nextChar);
//         nextChar = getChar(); // something to see if finished with line
//       }
//     }
//   }
//
// }
