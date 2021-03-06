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

#include <stdio.h>

#include "../core/api.h"
#include "lcdctrl.h"

using namespace SplendidMines;


API::Bitmap* LcdCtrl::s_minus_bmp      = 0;
API::Bitmap* LcdCtrl::s_digit_bmps[10] = { 0 };

//******************************************************************************
LcdCtrl::LcdCtrl(Ctrl* parent)
//------------------------------------------------------------------------------
: Ctrl(parent), m_val(1000)
{
  // nocht nicht initialisiert?
  if (s_minus_bmp == 0)
  {
    char      buf[20];
    unsigned  i;  // visual studio

    // initialisieren
    s_minus_bmp = API::CreateBitmap ("lcd", "-");

    for (i = 0; i < sizeof (s_digit_bmps) / sizeof (*s_digit_bmps); i++)
    {
      sprintf (buf, "%i", i);
      s_digit_bmps[i] = API::CreateBitmap ("lcd", buf);
    }

    // check size
    for (i = 0; i < sizeof (s_digit_bmps) / sizeof (*s_digit_bmps); i++)
      ASSERT (s_minus_bmp->getSize() == s_digit_bmps[i]->getSize());
  }

  setSize(Point(3 * s_minus_bmp->getSize().x, s_minus_bmp->getSize().y));
}

//******************************************************************************
void LcdCtrl::setVal (int val)
//------------------------------------------------------------------------------
{
  if      (val < -99)  val = -99;
  else if (val > 999)  val = 999;

  setElem (m_val, val);
}

//******************************************************************************
void LcdCtrl::draw()
//------------------------------------------------------------------------------
{
  Point pos = getAbsPos();

  // 1. Ziffer
  if (m_val < 0)
    API::WinDrawBitmap (s_minus_bmp, pos);
  else
    API::WinDrawBitmap (s_digit_bmps[m_val / 100], pos);

  // 2. Ziffer
  API::WinDrawBitmap (s_digit_bmps[(abs(m_val) / 10) % 10],
                 Point (pos.x + getSize().x / 3, pos.y));

  // 3. Ziffer
  API::WinDrawBitmap (s_digit_bmps[abs(m_val) % 10],
                 Point (pos.x + 2 * getSize().x / 3, pos.y));
}
