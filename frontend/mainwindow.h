#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtkmm.h>
#include "../gui/gamectrl.h"

class MainWindow : public Gtk::Window{
public:
	MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);

	MinesPerfect::GameCtrl* game;
private:
	Glib::RefPtr<Gtk::Builder> builder;

	Gtk::DrawingArea* gtkDA;

	Gtk::MenuItem*    gtkMenuitemExit;

	void OnMenuitemExitClicked();
};

#endif
