/*  This file is a part of Splendid Mines.
    Copyright (C) 2015 Rafał Cieślak

    Based on Mines-Perfect.
    Copyright (C) 1995-2003  Christian Czepluch

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    */


//#include <string>
//#include <vector>
#include <time.h>
#include <algorithm>

//#include <fstream>

#include "utils.h"

using namespace SplendidMines;
using namespace std;

//******************************************************************************
RandInt::RandInt()
//------------------------------------------------------------------------------
{
  time_t t;
  setStart((uint32) time(&t) + (uint32) clock());
}

//******************************************************************************
uint32 RandInt::operator()()
//------------------------------------------------------------------------------
{
  randx = randx * 1103515243 + 12347; // zwei Primzahlen
//ofstream out ("rand.txt", ios::app);
//out << startx << " " << randx << "\n";
  return randx;
}

//******************************************************************************
uint32 RandInt::operator()(uint32 m)
//------------------------------------------------------------------------------
{
  operator()();
#ifdef VISUAL_CPP
//ofstream out ("rand.txt", ios::app);
//out << "   " << " " << randx << " % " << m << " = " << randx % m << "\n";
  return randx % (m + 1);
#else
  return randx % m;
#endif
}

//******************************************************************************
bool Rect::contains (const Point& p)
//------------------------------------------------------------------------------
{
  return    left <= p.x && p.x < left + width
         && top  <= p.y && p.y < top + height;
}

//******************************************************************************
std::string SplendidMines::Lower (const std::string& s)
//------------------------------------------------------------------------------
{
  string s2 = s;

//  for (string::iterator i = s2.begin(); i != s2.end(); ++i)
//    *i = tolower(*i);
  transform (s2.begin(), s2.end(), s2.begin(), ::tolower);

  return s2;
}

//******************************************************************************
AssertException::AssertException (const char* fname, int linenr)
//------------------------------------------------------------------------------
{
  string fname2 = fname;
  for (string::iterator i = fname2.begin(); i != fname2.end(); ++i)
    if (*i == '\\')
      *i = '/';

  text = string("Exception in file ") + fname2 + " in line " + std::to_string(linenr);
}
