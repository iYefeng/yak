/************************************************************
 * Use of this source code is governed by a BSD-style license
 * that can be found in the License file.
 * 
 * Author        : yefeng
 * Email         : yefeng38083120@126.com
 * Create time   : 2016-12-04 10:51
 * Last modified : 2016-12-04 16:38
 * Filename      : Lex.h
 * Description   : 
 * *********************************************************/

#ifndef LEX_H_
#define LEX_H_

#include "Token.h"

#include <map>
#include <vector>
#include <pthread.h>

using namespace std;

class Lex{
public:
  static Lex& instance();

protected:
  Lex(){}
  ~Lex(){}

private:
  static void init();
  static void destroy();
  static Lex* instance_;
  static pthread_once_t ponce_;
  
  TkTable tkTable_;
};


#endif // LEX_H_
