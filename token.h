

enum class tokenId {EOF_tk, ID_tk, KW_tk, NUM_tk, OP_tk, CMT_tk, ERROR_tk}

string tokenNames[] = {"EOF", "Identifier", "Keyword", "Number", "Operator",
                        "Comment", "Error"}

struct token {
  tokenID;  // type of token
  string;   // characters in token
  int;      // line number
}


const vector<std::string> keyword{"Again", "If", "Assign", "Move", "Show",
                                  "Flip", "Name", "Home", "Do", "Spot",
                                  "Place", "Here", "There"};
const vector<std::string> operator{"&", "+", "/", "%", ".", "{", "}", "<", "-"};
const vector<std::string> comment{"*"};
