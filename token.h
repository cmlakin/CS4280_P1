
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

const int EOF_tk = 1000;
const int ID_tk = 1001;
const int KW_tk = 1002;
const int NUM_tk = 1003;
const int OP_tk = 1004;
const int CMT_tk = 1005;
const int error = -1;

cosnt int statesRow = 9;
cosnt int tokensCol = 8;
const int Table[statesRow][tokensCol] = { {1, 3, 4, 5, -1, 6, 7, 1000},
                                          {2, 2, -1, -1, -1, 2, -1, -1},
                                          {2, 2, 1001, 1001, 1001, 2, 1001, 1001},
                                          {3, 1002, 1002, 1002, 1002, 1002, 1002, 1002},
                                          {1004, 1004, 1004, 1004, 004, 1004, 1004, 1004},
                                          {-1, -1, -1, 4, 4, -1, -1, -1},
                                          {1003, 1003, 1003, 1003, 1003, 6, 1003, 1003},
                                          {7, 7, 7, 7, 7, 7, 8, -1},
                                          {1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005}};
