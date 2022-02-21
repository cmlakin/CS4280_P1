


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
