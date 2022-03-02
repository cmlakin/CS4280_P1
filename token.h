#ifndef TOKEN_h
#define TOKEN_h

#include <iostream>
#include <string>

using namespace std;
// enum is going to return a value
enum tokenId {KW_tk = 1000, ID_tk = 1001, EOF_tk = 1002, NUM_tk = 1003,
              OP_tk = 1004, CMT_tk = 1005};

// tokenNames[EOF_tk] -> this will print EOF
string tokenNames[] = {"Keyword", "Identifier", "EOF", "Number", "Operator",
                        "Comment"};

struct Token {
  tokenId tokenID;  // type of token
  string chars;   // characters in token
  int line;      // line number
};


static std::string keyword[] = {"Again", "If", "Assign", "Move", "Show",
                         "Flip", "Name", "Home", "Do", "Spot",
                         "Place", "Here", "There"};
static std::string operator1[] = {"&", "+", "/", "%", ".", "{", "}"};
static std::string operator2{"<"};
static std::string operator3{"-"};
static std::string comment{"*"};


#endif
