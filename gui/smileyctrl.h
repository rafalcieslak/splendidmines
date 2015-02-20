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

#ifndef SMILEYCTRL_H
#define SMILEYCTRL_H

#include "../core/api.h"
#include "buttonctrl.h"

namespace SplendidMines {

class GameCtrl;

//******************************************************************************
class SmileyCtrl : public ButtonCtrl
//------------------------------------------------------------------------------
{
  public:

    SmileyCtrl (Ctrl* parent, GameCtrl* game);

    void  act();
    void  draw() { ButtonCtrl::draw(); }
    void  onClick();

  private:

    GameCtrl*  m_game;

    static API::Bitmap*  s_smiley_happy_bmp;
    static API::Bitmap*  s_smiley_1eye_bmp;
    static API::Bitmap*  s_smiley_2eyes_bmp;
    static API::Bitmap*  s_smiley_3eyes_bmp;
    static API::Bitmap*  s_smiley_4eyes_bmp;
    static API::Bitmap*  s_smiley_norm_bmp;
    static API::Bitmap*  s_smiley_ooh_bmp;
    static API::Bitmap*  s_smiley_worry_bmp;
    static API::Bitmap*  s_smiley_sunglass_bmp;
};


} // namespace SplendidMines

#endif
