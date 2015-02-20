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

#ifndef BOARDCTRL_H
#define BOARDCTRL_H

#include "../core/board.h"
#include "../core/api.h"
#include "bitmapctrl.h"
//#include "cellctrl.h"

namespace SplendidMines {

class GameCtrl;

//******************************************************************************
class BoardCtrl : public Ctrl
//------------------------------------------------------------------------------
{
  public:

    GameCtrl*  m_game;
    Rect       m_rect;
    CellNrs    m_changed_cells;       // -> state

    BoardCtrl (Ctrl* parent, GameCtrl* game);
    ~BoardCtrl();

    void setBoard (BoardNr nr);
    void setLevel (const Level& lvl); // oder so aehnlich
    void drawFrames();
    void actAllCells();
    void actCurCells (bool left_is_down, bool right_is_down);
    void actChangedCells();
    void setCellsDirty();
    void onMouseEvent (const API::MouseEvent& ev);

  private: //-------------------------------------------------------------------

    void initStatic();

    CellNr       m_cur_cell;            // -> state
    set<CellNr>  m_cur_cells;

    // bitmaps
    API::Bitmap*   m_source_bmp; // (->board_cur_bmp)?, aus <board>.bmp

    static API::Bitmap*   s_board_square_bmp;
    static API::Bitmap*   s_board_triangle_bmp;
    static API::Bitmap*   s_board_hexagon_bmp;
    static API::Bitmap*   s_board_grid3d_bmp;

    static API::Bitmap*   s_symb_flag_bmp;
    static API::Bitmap*   s_symb_quest_bmp;
    static API::Bitmap*   s_symb_mine_bmp;
    static API::Bitmap*   s_symb_cross_bmp;
    static API::Bitmap*   s_symb_zero_bmp;
    static API::Bitmap*   s_symb_digit_bmps[28];

    vector<API::Bitmap*>  m_cell_close_bmps;
    vector<API::Bitmap*>  m_cell_open_bmps;
    vector<API::Bitmap*>  m_cell_hintclose_bmps;
    vector<API::Bitmap*>  m_cell_hintopen_bmps;
    vector<API::Bitmap*>  m_cell_error_bmps;
    vector<API::Bitmap*>  m_frame_bmps;

    vector<BitmapCtrl*>  m_frame_ctrls;
    vector<BitmapCtrl*>  m_cell_ctrls;
    vector<BitmapCtrl*>  m_symbol_ctrls;

    // elementfunctionen
    void    actCell (CellNr k);
    CellNr  getCellAtPoint (const Point& p) const;
    void    actCursorCells();

//    void changeLevel     (const Level& lvl);
};

} // namespace SplendidMines

#endif
