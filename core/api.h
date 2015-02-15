// Mines-Perfect: a minesweeper clone
// Copyright (C) 1995-2003  Christian Czepluch
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef API_H
#define API_H

#include <vector>   // fuer Color ?!
#include <string>
#include <time.h>

using namespace std;

#include "../core/utils.h"


namespace MinesPerfect {

class Options;

namespace API{

//******************************************************************************
// Types
//------------------------------------------------------------------------------
struct MouseEvent
{
  enum Type { LEFT_DOWN, LEFT_UP, RIGHT_DOWN, RIGHT_UP,  MOVE };

  Type   m_type;
  Point  m_pos;
  Point  m_prev_pos;
  bool   m_left_is_down;
  bool   m_right_is_down;
};

//******************************************************************************
class Bitmap
//------------------------------------------------------------------------------
{
public:
  virtual Point  getSize() const = 0;
  virtual bool   pointIsTransparent (const Point& p) const = 0;

  virtual ~Bitmap() { };
};

Bitmap* CreateBitmap (const string& kind, const string& spec);
Bitmap* CreateBitmap (const Bitmap* from, const Rect& rect);

//******************************************************************************
class Sound
//------------------------------------------------------------------------------
{
public:
  virtual void play() = 0;
  virtual bool isOk() = 0;

  virtual ~Sound() { }
};

API::Sound* CreateSound (const string& name);

//******************************************************************************
class Timer // : protected TTimer
//------------------------------------------------------------------------------
{
public:
  virtual int      getMSecs()  const = 0;
  virtual bool     isRunning() const = 0;
  virtual clock_t  start()           = 0;
  virtual void     stop()            = 0;
  virtual void     reset()           = 0;
  virtual ~Timer() { }
};

Timer* CreateTimer();

//******************************************************************************
// Functions
//------------------------------------------------------------------------------
void Init();

void WinSetSize    (const Point& sz);                    // alternativ
void WinDrawBitmap (const Bitmap* bmp, const Point& p);  //     "
void WinDrawBevel  (const Rect& rect, int thickness, bool raised);

void DlgNewRecord (Options* options, int num_msecs, bool certified_board);
void FindFiles (vector<string>& files, const string& pattern);
bool FileExist (const string& fname);
void ShowMessageDlg (const string& text, const string& title);

} // namespace API
} // namespace MinesPerfect

#endif
