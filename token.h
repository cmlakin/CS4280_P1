
// enum is going to return a value
enum tokenId {EOF_tk, ID_tk, KW_tk, NUM_tk, OP_tk, CMT_tk, ERROR_tk};

// tokenNames[EOF_tk] -> this will print EOF
string tokenNames[] = {"EOF", "Identifier", "Keyword", "Number", "Operator",
                        "Comment", "Error"};

struct token {
  tokenID;  // type of token
  string;   // characters in token
  int;      // line number
}


const vector<std::string> keyword{"Again", "If", "Assign", "Move", "Show",
                                  "Flip", "Name", "Home", "Do", "Spot",
                                  "Place", "Here", "There"};
const vector<std::string> operator1{"&", "+", "/", "%", ".", "{", "}"};
const vector<std::string> operator2{"<"};
const vector<std::string> operator3{"-"};
const vector<std::string> comment{"*"};
