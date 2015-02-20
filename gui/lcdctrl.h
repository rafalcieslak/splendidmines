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

#ifndef LCDCTRL_H
#define LCDCTRL_H

#include "../core/api.h"
#include "ctrl.h"

namespace SplendidMines {


//******************************************************************************
class LcdCtrl : public Ctrl // 3 - Ziffrige Lcd anzeige
//------------------------------------------------------------------------------
{
  public:

    LcdCtrl(Ctrl* parent);

    void   draw();
    void   setVal (int val);

  private:

    int   m_val;

    static API::Bitmap*  s_minus_bmp;
    static API::Bitmap*  s_digit_bmps[10];
};


} // namespace SplendidMines

#endif
