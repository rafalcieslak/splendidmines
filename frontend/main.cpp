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

#include <gtkmm.h>
#include <iostream>
#include "mainwindow.h"
#include "../core/options.h"
#include "../gui/gamectrl.h"
#include <cstdlib>

MainWindow* pMainWindow = nullptr;

int main(int argc, char** argv){
#ifdef __linux__
  // Workaround for disabling Ubuntu global menu.
  setenv("UBUNTU_MENUPROXY", "", 1);
#endif

  Gtk::Main gtkmain(argc, argv);

  //Load the Glade file and instiate its widgets:
  Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create();
  try
  {
    refBuilder->add_from_file("splendidmines.glade");
  }
  catch(const Glib::FileError& ex)
  {
    std::cerr << "FileError: " << ex.what() << std::endl;
    return 1;
  }
  catch(const Glib::MarkupError& ex)
  {
    std::cerr << "MarkupError: " << ex.what() << std::endl;
    return 1;
  }
  catch(const Gtk::BuilderError& ex)
  {
    std::cerr << "BuilderError: " << ex.what() << std::endl;
    return 1;
  }

  MinesPerfect::Options* options = new MinesPerfect::Options();

  refBuilder->get_widget_derived("gtkWindowMain", pMainWindow);
  if(pMainWindow)
  {
    pMainWindow->game = new MinesPerfect::GameCtrl(options);
    pMainWindow->game->show();
    Gtk::Main::run(*pMainWindow);
  }

  delete pMainWindow;

  return 0;
}
