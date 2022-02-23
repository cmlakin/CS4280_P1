// scan in and return one token
#include "scanner.h"

// store string and call getchar();
// declare FSA table here
// cosnt int statesRow = 9;
// cosnt int tokensCol = 8;
// const int table[statesRow][tokensCol];
// string variable
// static string fileString;
// // nextChar variable
// static char nextChar;
// // use this to look at the upcoming nextChar
// static int lineN;

// pass 2 arguemnts - string and line number
void scanner(const string& fileString, int lineN)  {
  
  string chars = fileString;
  cout << lineN << " " << chars << endl;

  // initialize FSA table here
  // table[statesRow][tokensCol] = { {1, 3, 4, 5, -1, 6, 7, 1000},
  //                                 {2, 2, -1, -1, -1, 2, -1, -1},
  //                                 {2, 2, 1001, 1001, 1001, 2, 1001, 1001},
  //                                 {3, 1002, 1002, 1002, 1002, 1002, 1002, 1002},
  //                                 {1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004},
  //                                 {-1, -1, -1, 4, 4, -1, -1, -1},
  //                                 {1003, 1003, 1003, 1003, 1003, 6, 1003, 1003},
  //                                 {7, 7, 7, 7, 7, 7, 8, -1},
  //                                 {1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005}};
  // set up as switch statement
    /* cases:
        -is alpha
            - is upper
            - is lower
        -is digit
        -is operator
        -is Comment
        -is EOF
        */

  // switch(value){
  //   case KW:
  //
  //   case ID:
  //
  //   case EOF:
  //
  //   case NUM:
  //
  //   case OP:
  //
  //   case CMT:
  //
  //   default:
  //     // error
  // }



}

// site for string.at() https://www.geeksforgeeks.org/string-at-in-cpp/
// stie for string.end() https://www.javatpoint.com/cpp-string-end-function
// char getChar(string s, int lineN) {
//   string s;
//   int lNum, i;
//   // parse string for nextChar
//   nextChar = s.at(0);
//   peek = s.at(1);
//   // if end of string - return null
//   if(s = str.end()){
//     s = NULL;
//     return s;
//   }
// }

// tokenType FSDriver() // assume nextChar set, and used as column index
// {
//   state_t state = INITIAL; // (0 = S1 here)
//   state_t nextState;
//   tokenType token;
//   string s = NULL;
//
//   while (state != FINAL) {
//     nextState = Table[state][nextChar];
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
