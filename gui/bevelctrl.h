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

#ifndef BEVELCTRL_H
#define BEVELCTRL_H

#include "../core/utils.h"
#include "ctrl.h"

//******************************************************************************
class BevelCtrl : public Ctrl
//------------------------------------------------------------------------------
{
  public:
    BevelCtrl(Ctrl* parent, int thickness = 0, bool raised = false);

    virtual void draw();

    Point getContPos();
    Point getContSize();
    void  setContSize (Point s);

    int   getThickness() const { return m_thickness; }
    bool  isRaised()     const { return m_raised; }

    void  setThickness (int thickness) { setElem (m_thickness, thickness); }
    void  setRaised    (bool raised)   { setElem (m_raised,    raised);    }

  private:
    int  m_thickness;
    bool m_raised;
};

#endif
