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

#ifndef DIALOGS_H
#define DIALOGS_H

#include <vector>
#include <gtkmm.h>
#include "../gui/gamectrl.h"

class DialogSelfDefined : public Gtk::Dialog{
private:
	DialogSelfDefined() = delete;
	SplendidMines::Level* level;
	Glib::RefPtr<Gtk::Builder> builder;
	Gtk::Button* gtkButtonOK;
	Gtk::Button* gtkButtonCancel;
	Gtk::Entry* gtkEntryRows;
	Gtk::Entry* gtkEntryColumns;
	Gtk::Entry* gtkEntryPages;
	Gtk::Label* gtkLabelPages;
	Gtk::Entry* gtkEntryMines;
public:
	static DialogSelfDefined* Create(SplendidMines::Level* level);
	DialogSelfDefined(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);
	void OnButtonOKClicked();
	void OnButtonCancelClicked();
};

class DialogAbout : public Gtk::Dialog{
private:
	DialogAbout() = delete;
public:
	static DialogAbout* Create();
	DialogAbout(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);
};

class DialogRecord : public Gtk::Dialog{
private:
	DialogRecord() = delete;
	Gtk::Button* gtkButtonOK;
	Gtk::Button* gtkButtonCancel;
	Gtk::Label* gtkLabelBoard;
	Gtk::Label* gtkLabelLevel;
	Gtk::Label* gtkLabelTime;
	Gtk::ComboBoxText* gtkComboUsers;
	Glib::RefPtr<Gtk::Builder> builder;
public:
	static DialogRecord* Create(std::string board_name, std::string level_name, std::string time, std::vector<std::string> usernames);
	DialogRecord(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);
	std::string GetUsername() const;
};

#endif
