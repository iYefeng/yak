/************************************************************
 * Use of this source code is governed by a BSD-style license
 * that can be found in the License file.
 * 
 * Author        : yefeng
 * Email         : yefeng38083120@126.com
 * Create time   : 2016-11-20 09:33
 * Last modified : 2016-12-04 16:38
 * Filename      : Token.cc
 * Description   : 
 * *********************************************************/

#include "Token.h"

TkTable::TkTable() : tkIdentIdx_(TK_IDENT)
{
  TkWord* tp;
  for(tp = &keywords[0]; tp->spelling != ""; tp++) {
    tkWordDirectInsert(tp);
  }
}

TkTable::~TkTable()
{
  for(vector<TkWord*>::iterator it = tkArray_.begin(); it != tkArray_.end(); it++) {
    delete (*it);
  }
  tkWordDict_.clear();
  tkArray_.clear();
}

TkWord* TkTable::tkWordDirectInsert(TkWord* tp)
{
  tkWordDict_.insert(make_pair(tp->spelling, tp));
  tkArray_.push_back(tp);
  return tp;
}

TkWord* TkTable::tkWordFind(const string& spelling)
{
  map<string, TkWord*>::iterator it = tkWordDict_.find(spelling);
  if (it == tkWordDict_.end()) {
    return NULL;
  }
  return it->second;
}

TkWord* TkTable::tkWordInsert(const string& spelling)
{
  TkWord* tp;
  tp = tkWordFind(spelling);
  if (tp == NULL) {
    tp = new TkWord();
    tp->tkcode = tkIdentIdx_ ++;
    tp->spelling = spelling;
    tkWordDirectInsert(tp);
  }
  return tp;
}
