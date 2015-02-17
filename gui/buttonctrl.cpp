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

#include "buttonctrl.h"

API::Bitmap* ButtonCtrl::s_button_up_bmp   = 0;
API::Bitmap* ButtonCtrl::s_button_down_bmp = 0;

//******************************************************************************
ButtonCtrl::ButtonCtrl(Ctrl* parent) : Ctrl(parent)
//------------------------------------------------------------------------------
{
  m_is_pushed  = false;

  // statische Elemente initialisieren
  if (s_button_up_bmp == 0)
  {
    s_button_up_bmp   = API::CreateBitmap ("button", "up"  );
    s_button_down_bmp = API::CreateBitmap ("button", "down");

    ASSERT (s_button_up_bmp->getSize() == s_button_down_bmp->getSize());
  }

  setSize(s_button_up_bmp->getSize());
}

//******************************************************************************
void ButtonCtrl::draw()
//------------------------------------------------------------------------------
{
  Point p = getAbsPos();

  // background
  API::WinDrawBitmap (isPushed() ? s_button_down_bmp : s_button_up_bmp, p);

  // smiley
  if (isPushed())
  {
    p.x += (s_button_down_bmp->getSize().x
           - m_symb_down_bmp->getSize().x) / 2 + 1;

    p.y += (s_button_down_bmp->getSize().y
           - m_symb_down_bmp->getSize().y) / 2 + 1;

    API::WinDrawBitmap(m_symb_down_bmp, p);
  }
  else
  {
    p.x += (s_button_up_bmp->getSize().x
           - m_symb_up_bmp->getSize().x) / 2;

    p.y += (s_button_up_bmp->getSize().y
           - m_symb_up_bmp->getSize().y) / 2;

    API::WinDrawBitmap(m_symb_up_bmp, p);
  }
}

//******************************************************************************
void ButtonCtrl::onMouseEvent (const API::MouseEvent& ev)
//------------------------------------------------------------------------------
{
  if (ev.m_type == API::MouseEvent::LEFT_DOWN)
  {
    setPushed(contains(ev.m_pos - getAbsPos()));
  }
  else if (ev.m_type == API::MouseEvent::MOVE)
  {
    if (isPushed() && !contains(ev.m_pos - getAbsPos()))
      setPushed(false);
  }
  else if (ev.m_type == API::MouseEvent::LEFT_UP)
  {
    if (isPushed())
    {
      setPushed(false);
      onClick(); // ruft ueberladene Funktion auf
    }
  }
}
