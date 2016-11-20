/************************************************************
 * Use of this source code is governed by a BSD-style license
 * that can be found in the License file.
 * 
 * Author        : yefeng
 * Email         : yefeng38083120@126.com
 * Create time   : 2016-11-20 09:31
 * Last modified : 2016-11-20 09:33
 * Filename      : Token.h
 * Description   : 
 * *********************************************************/
#include <string>
#include <map>
#include <vector>

using namespace std;

enum TkCode {
  /*operation and separator*/
  TK_PLUS,               // +
  TK_MINUS,              // -
  TK_STAR,               // *
  TK_DIVIDE,             // /
  TK_MOD,                // %
  TK_EQ,                 // ==
  TK_NEQ,                // !=
  TK_LT,                 // <
  TK_LEQ,                // <=
  TK_GT,                 // >
  TK_GEQ,                // >=
  TK_ASSIGN,             // =
  TK_POINTSTO,           // ->
  TK_DOT,                // .
  TK_COMPL,              // ~
  TK_SHIFT_LEFT,         // <<
  TK_SHIFT_RIGHT,        // >>
  TK_AND,                // &
  TK_OR,                 // |
  TK_XOR,                // ^
  TK_LOGICAL_NOT,        // !
  TK_LOGICAL_AND,        // &&
  TK_LOGICAL_OR,         // ||
  
  TK_OPENPA,             // (
  TK_CLOSEPA,            // )
  TK_OPENBR,             // [
  TK_CLOSEBR,            // ]
  TK_BEGIN,              // {
  TK_END,                // }
  TK_SEMICOLON,          // ;
  TK_COMMA,              // ,
  TK_ELLIPSIS,           // ...
  TK_EOF,                // end of file

  /* keyword*/
  KW_CONST,              // const
  KW_SIGNED,             // signed
  KW_UNSIGNED,           // unsigned
  KW_CHAR,               // char
  KW_SHORT,              // short
  KW_INT,                // int
  KW_LONG,               // long
  KW_FLOAT,              // float
  KW_DOUBLE,             // double
  KW_VOID,               // void
  KW_STRUCT,             // struct
  KW_UNION,              // union
  KW_CLASS,              // class
  KW_ENUM,               // enum
  KW_IF,                 // if
  KW_ELSE,               // else
  KW_SWITCH,             // switch
  KW_CASE,               // case
  KW_DEFAULT,            // default
  KW_FOR,                // for
  KW_WHILE,              // while
  KW_CONTINUE,           // continue
  KW_BREAK,              // break
  KW_RETURN,             // return
  KW_SIZEOF,             // sizeof

  KW_ALIGN,              // __align
  KW_CDECL,              // __cdecl
  KW_STDCALL,            // __stdcall

  /* identifer */
  TK_IDENT

};

struct TkWord
{
  int tkcode;              // the code for the token
  TkWord *next;            // the point to the token who has the same hash
  string spelling;         // the spelling of the code
  //Symbol *symStruct;     // 
  //Symbol *symIdentifier; //
};

class TkTable
{
public:
  TkTable();

protected:


private:
  map<string, TkWord> tkWordDict_;
  vector<TkWord> tkTble_;

};
