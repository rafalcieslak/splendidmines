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


DialogSelfDefined* DialogSelfDefined::Create(SplendidMines::Level* level){
	Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create();
  try
  {
    refBuilder->add_from_file("splendidmines.glade");
  }
  catch(const Glib::Error& ex)
  {
    std::cerr << "Error using glade file: " << ex.what() << std::endl;
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

// =============================================================================

DialogAbout::DialogAbout(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade):
		Gtk::Dialog(cobject)
{
}

DialogAbout* DialogAbout::Create(){
	Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create();
  try
  {
    refBuilder->add_from_file("splendidmines.glade");
  }
  catch(const Glib::Error& ex)
  {
    std::cerr << "Error using glade file: " << ex.what() << std::endl;
    return nullptr;
  }

	DialogAbout* pAbout;
  refBuilder->get_widget_derived("dialogAbout", pAbout);
  return pAbout;
}


// =============================================================================

DialogRecord::DialogRecord(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade):
		Gtk::Dialog(cobject), builder(refGlade)
{
		builder->get_widget("buttonRecordOK",gtkButtonOK);
		builder->get_widget("buttonRecordCancel",gtkButtonCancel);
		builder->get_widget("labelBoard",gtkLabelBoard);
		builder->get_widget("labelLevel",gtkLabelLevel);
		builder->get_widget("labelTime",gtkLabelTime);
		builder->get_widget("comboUsers",gtkComboUsers);
		gtkButtonOK->signal_clicked().connect([this](){this->response(Gtk::RESPONSE_OK);});
		gtkComboUsers->get_entry()->signal_activate().connect([this](){this->response(Gtk::RESPONSE_OK);});
		gtkButtonCancel->signal_clicked().connect([this](){this->response(Gtk::RESPONSE_CANCEL);});
}

std::string DialogRecord::GetUsername() const{
	return gtkComboUsers->get_active_text();
}

DialogRecord* DialogRecord::Create(std::string board_name, std::string level_name, std::string time, std::vector<std::string> usernames){
	Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create();
  try
  {
    refBuilder->add_from_file("splendidmines.glade");
  }
  catch(const Glib::Error& ex)
  {
    std::cerr << "Error using glade file: " << ex.what() << std::endl;
    return nullptr;
  }

	DialogRecord* pRecord;
  refBuilder->get_widget_derived("dialogRecord", pRecord);
  if(pRecord){
		pRecord->gtkLabelBoard->set_text(board_name);
		pRecord->gtkLabelLevel->set_text(level_name);
		pRecord->gtkLabelTime->set_text(time);
		for(std::string& u : usernames){
			pRecord->gtkComboUsers->append(u);
		}
	}
	return pRecord;
}
