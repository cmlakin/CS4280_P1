#ifndef TOKEN_h
#define TOKEN_h
// enum is going to return a value
enum tokenId {KW_tk, ID_tk, EOF_tk, NUM_tk, OP_tk, CMT_tk};

// tokenNames[EOF_tk] -> this will print EOF
string tokenNames[] = {"Keyword", "Identifier", "EOF", "Number", "Operator",
                        "Comment"};

struct token {
  tokenId tokenID;  // type of token
  string chars;   // characters in token
  int line;      // line number
}


const vector<std::string> keyword{"Again", "If", "Assign", "Move", "Show",
                                  "Flip", "Name", "Home", "Do", "Spot",
                                  "Place", "Here", "There"};
const vector<std::string> operator1{"&", "+", "/", "%", ".", "{", "}"};
const vector<std::string> operator2{"<"};
const vector<std::string> operator3{"-"};
const vector<std::string> comment{"*"};


#endif 
