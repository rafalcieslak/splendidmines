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

#ifndef BUTTONCTRL_H
#define BUTTONCTRL_H

#include "../core/utils.h"
#include "../core/api.h"
#include "ctrl.h"

//******************************************************************************
class ButtonCtrl : public Ctrl
//------------------------------------------------------------------------------
{
  public:

    ButtonCtrl(Ctrl* parent);

    bool isPushed() const { return m_is_pushed; }
    virtual void draw();
    void setUpBitmap   (const API::Bitmap* b) { setElem(m_symb_up_bmp, b); }
    void setDownBitmap (const API::Bitmap* b) { setElem(m_symb_down_bmp, b); }
    void setPushed     (bool pushed)     { setElem(m_is_pushed, pushed); }

    void onMouseEvent(const API::MouseEvent& ev);

    virtual void onClick() = 0; // need not virtual (only for testing)

  protected:

    const API::Bitmap*  m_symb_up_bmp;
    const API::Bitmap*  m_symb_down_bmp;

    static API::Bitmap*  s_button_up_bmp;
    static API::Bitmap*  s_button_down_bmp;

  private:

    bool m_is_pushed;
};

#endif
