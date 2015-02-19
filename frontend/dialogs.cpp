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

#include "dialogs.h"
#include <iostream>

DialogSelfDefined::DialogSelfDefined(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade):
		Gtk::Dialog(cobject), builder(refGlade)
{
	builder->get_widget("buttonOK",gtkButtonOK);
	builder->get_widget("buttonCancel",gtkButtonCancel);
	builder->get_widget("entryRows",gtkEntryRows);
	builder->get_widget("entryColumns",gtkEntryColumns);
	builder->get_widget("entryPages",gtkEntryPages);
	builder->get_widget("labelPages",gtkLabelPages);
	builder->get_widget("entryMines",gtkEntryMines);
	gtkButtonOK->signal_clicked().connect(sigc::mem_fun(*this,&DialogSelfDefined::OnButtonOKClicked));
	gtkButtonCancel->signal_clicked().connect(sigc::mem_fun(*this,&DialogSelfDefined::OnButtonCancelClicked));
}

void DialogSelfDefined::OnButtonCancelClicked(){
	response(Gtk::RESPONSE_CANCEL);
}
void DialogSelfDefined::OnButtonOKClicked(){
	level->height    = std::stoi( gtkEntryRows   ->get_text() );
	level->width     = std::stoi( gtkEntryColumns->get_text() );
	level->deep      = std::stoi( gtkEntryPages  ->get_text() );
	level->num_mines = std::stoi( gtkEntryMines  ->get_text() );
	response(Gtk::RESPONSE_OK);
}


DialogSelfDefined* DialogSelfDefined::Create(MinesPerfect::Level* level){
	Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create();
  try
  {
    refBuilder->add_from_file("selfdefined.glade");
  }
  catch(const Glib::Error& ex)
  {
    std::cerr << "Error creating selfdefined dialog: " << ex.what() << std::endl;
    return nullptr;
  }

	DialogSelfDefined* pSelfDefined;
  refBuilder->get_widget_derived("dialogSelfDefined", pSelfDefined);
  if(!pSelfDefined) return nullptr;

  pSelfDefined->level = level;
	pSelfDefined->gtkEntryRows   ->set_text(std::to_string(level->height    ));
	pSelfDefined->gtkEntryColumns->set_text(std::to_string(level->width     ));
	pSelfDefined->gtkEntryPages  ->set_text(std::to_string(level->deep      ));
	pSelfDefined->gtkEntryMines  ->set_text(std::to_string(level->num_mines ));

	if(level->deep == 0){
		pSelfDefined->gtkLabelPages->set_visible(false);
		pSelfDefined->gtkEntryPages->set_visible(false);
	}

	return pSelfDefined;
}
