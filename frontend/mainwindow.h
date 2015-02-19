/*  This file is a part of Splendid Mines.
    Copyright (C) 2015 Rafał Cieślak

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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtkmm.h>
#include "../gui/gamectrl.h"
#include <cairommconfig.h>
#include <cairomm/context.h>
#include <cairomm/surface.h>

class MainWindow : public Gtk::Window{
public:
	MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);
	void SetGameAreaSize(int width, int height);

	MinesPerfect::GameCtrl* game;
	Cairo::RefPtr<Cairo::Context> crBackBufferContext;

	void RedrawGameArea();
	void RedrawGameArea(int x, int y, int w, int h);

	void UpdateMenuIndicators();
private:
	Glib::RefPtr<Gtk::Builder> builder;

	Gtk::DrawingArea* gtkDA;
	Cairo::RefPtr<Cairo::ImageSurface> crBackBufferSurface;

	Gtk::MenuItem*    gtkMenuitemNew;
	Gtk::MenuItem*    gtkMenuitemOpen;
	Gtk::MenuItem*    gtkMenuitemSave;
	Gtk::MenuItem*    gtkMenuitemBestTimes;
	Gtk::MenuItem*    gtkMenuitemExit;
	Gtk::RadioMenuItem*    gtkMenuitemOriginal;
	Gtk::RadioMenuItem*    gtkMenuitemHint;
	Gtk::RadioMenuItem*    gtkMenuitemLucky;
	Gtk::RadioMenuItem*    gtkMenuitemImmune;
	Gtk::RadioMenuItem*    gtkMenuitemStartup;
	Gtk::CheckMenuItem*    gtkMenuitemMurph;
	Gtk::RadioMenuItem*    gtkMenuitemBeginner;
	Gtk::RadioMenuItem*    gtkMenuitemIntermediate;
	Gtk::RadioMenuItem*    gtkMenuitemExpert;
  Gtk::RadioMenuItem*    gtkMenuitemSelfDefined;
	Gtk::RadioMenuItem*    gtkMenuitemSquare;
	Gtk::RadioMenuItem*    gtkMenuitemHexagon;
	Gtk::RadioMenuItem*    gtkMenuitemTriangle;
	Gtk::RadioMenuItem*    gtkMenuitem3Dgrid;
	Gtk::MenuItem*    gtkMenuitemGiveHint;
	Gtk::MenuItem*    gtkMenuitemSolveOne;
	Gtk::MenuItem*    gtkMenuitemSolveAll1;
	Gtk::MenuItem*    gtkMenuitemSolveAll2;
	Gtk::MenuItem*    gtkMenuitemSolveAll3;
	Gtk::CheckMenuItem*    gtkMenuitemShowMines;
	Gtk::MenuItem*    gtkMenuitemUndo;
	Gtk::MenuItem*    gtkMenuitemRedo;
	Gtk::MenuItem*    gtkMenuitemUndoAll;
	Gtk::MenuItem*    gtkMenuitemAbout;

	bool OnWindowDelete(GdkEventAny* event);

	bool OnGameAreaDraw(const Cairo::RefPtr<Cairo::Context>& cr);
	bool OnGameAreaMousePress(GdkEventButton*);
	bool OnGameAreaMouseRelase(GdkEventButton*);
	bool OnGameAreaMouseMotion(GdkEventMotion*);
	MinesPerfect::Point prev_mouse_position = MinesPerfect::Point(-1,-1);
	bool LMB_down = false;
	bool RMB_down = false;

	bool dismiss_menu_toggle_signals = false;
	void OnMenuitemBeginnerClicked();
	void OnMenuitemIntermediateClicked();
	void OnMenuitemExpertClicked();
	void OnMenuitemSelfDefinedClicked();
	void OnMenuitemSquareClicked();
	void OnMenuitemTriangleClicked();
	void OnMenuitemHexagonClicked();
	void OnMenuitem3DgridClicked();
	void OnMenuitemNewClicked();
	void OnMenuitemOpenClicked();
	void OnMenuitemSaveClicked();
	void OnMenuitemExitClicked();
	void OnMenuitemBestTimesClicked();
	void OnMenuitemOriginalClicked();
	void OnMenuitemHintClicked();
	void OnMenuitemLuckyClicked();
	void OnMenuitemImmuneClicked();
	void OnMenuitemStartupClicked();
	void OnMenuitemMurphClicked();
	void OnMenuitemGiveHintClicked();
	void OnMenuitemSolveOneClicked();
	void OnMenuitemSolveAll1Clicked();
	void OnMenuitemSolveAll2Clicked();
	void OnMenuitemSolveAll3Clicked();
	void OnMenuitemShowMinesClicked();
	void OnMenuitemUndoClicked();
	void OnMenuitemRedoClicked();
	void OnMenuitemUndoAllClicked();
	void OnMenuitemAboutClicked();
};

#endif
