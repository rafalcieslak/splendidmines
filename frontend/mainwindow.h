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
private:
	Glib::RefPtr<Gtk::Builder> builder;

	Gtk::DrawingArea* gtkDA;
	Cairo::RefPtr<Cairo::ImageSurface> crBackBufferSurface;

	Gtk::MenuItem*    gtkMenuitemExit;

	void OnMenuitemExitClicked();
	bool OnGameAreaDraw(const Cairo::RefPtr<Cairo::Context>& cr);
	bool OnGameAreaMousePress(GdkEventButton*);
	bool OnGameAreaMouseRelase(GdkEventButton*);
	bool OnGameAreaMouseMotion(GdkEventMotion*);
	MinesPerfect::Point prev_mouse_position = MinesPerfect::Point(-1,-1);
	bool LMB_down = false;
	bool RMB_down = false;
};

#endif
