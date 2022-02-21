// scan in and return one token

// declare FSA table here
cosnt int statesRow = 9;
cosnt int tokensCol = 8;
const int Table[statesRow][tokensCol];

const int EOF_tk = 1000;
const int ID_tk = 1001;
const int KW_tk = 1002;
const int NUM_tk = 1003;
const int OP_tk = 1004;
const int CMT_tk = 1005;
const int error = -1;

void scanner()  {

  // initialize FSA table here
  Table[statesRow][tokensCol] = { {1, 3, 4, 5, -1, 6, 7, 1000},
                                  {2, 2, -1, -1, -1, 2, -1, -1},
                                  {2, 2, 1001, 1001, 1001, 2, 1001, 1001},
                                  {3, 1002, 1002, 1002, 1002, 1002, 1002, 1002},
                                  {1004, 1004, 1004, 1004, 004, 1004, 1004, 1004},
                                  {-1, -1, -1, 4, 4, -1, -1, -1},
                                  {1003, 1003, 1003, 1003, 1003, 6, 1003, 1003},
                                  {7, 7, 7, 7, 7, 7, 8, -1},
                                  {1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005}};
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

}

char getChar() {
  // assign  next char
}

tokenType FSDriver() // assume nextChar set, and used as column index
{
  state_t state = INITIAL // (0 = S1 here)
  nextState;
  tokenType token;
  string s = NULL;

  while (state != FINAL) {
    nextState = Table[state][nextChar];
    if (nextState == Error) {
      Error(); // report error and exit
    }
    if (nextState == FINAL) {
      if (token(state) == ID) { // need reserved keyword loop
        if (S in Keywords){
          return (KWtk, S); // or specific keyword
        }
        else {
          return (IDtk, S);
        }
      }
      else {  // not FINAL
        state := nextState;
        append(S, nextChar);
        nextChar = getChar();
      }
    }
  }

}
