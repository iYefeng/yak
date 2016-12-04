/************************************************************
 * Use of this source code is governed by a BSD-style license
 * that can be found in the License file.
 * 
 * Author        : yefeng
 * Email         : yefeng38083120@126.com
 * Create time   : 2016-12-04 10:51
 * Last modified : 2016-12-04 16:38
 * Filename      : Lex.cc
 * Description   : 
 * *********************************************************/

#include "Lex.h"

#include <stdlib.h>

Lex* Lex::instance_ = NULL;
pthread_once_t Lex::ponce_ = PTHREAD_ONCE_INIT;

Lex& Lex::instance()
{
  ::pthread_once(&ponce_, init);
  return *instance_;
}

void Lex::init()
{
  instance_ = new Lex();
  ::atexit(destroy);
}

void Lex::destroy()
{
  delete instance_;
  instance_ = NULL;
}

