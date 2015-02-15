#include "mainwindow.h"

MainWindow::MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade):
		Gtk::Window(cobject), builder(refGlade)
{
	builder->get_widget("gtkDA",gtkDA);
	builder->get_widget("menuitemExit",gtkMenuitemExit);

	gtkMenuitemExit->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemExitClicked));
}

void MainWindow::OnMenuitemExitClicked(){
	Gtk::Main::quit();
}
