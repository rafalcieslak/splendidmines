#include <gtkmm.h>
#include <iostream>
#include "mainwindow.h"

MainWindow* pMainWindow = nullptr;

int main(int argc, char** argv){
  Gtk::Main gtkmain(argc, argv);

  //Load the Glade file and instiate its widgets:
  Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create();
  try
  {
    refBuilder->add_from_file("frontend/splendidmines.glade");
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

  refBuilder->get_widget_derived("gtkWindowMain", pMainWindow);
  if(pMainWindow)
  {
    Gtk::Main::run(*pMainWindow);
  }

  delete pMainWindow;

  return 0;
}
