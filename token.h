

enum class tokenId {EOF_tk, ID_tk, KW_tk, NUM_tk, OP_tk, CMT_tk, ERROR_tk}

string tokenNames[] = {"EOF", "Identifier", "Keyword", "Number", "Operator",
                        "Comment", "Error"}

struct token {
  tokenID;  // type of token
  string;   // characters in token
  int;      // line number
}
