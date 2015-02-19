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

#include "mainwindow.h"
#include "dialogs.h"
#include <iostream>

MainWindow::MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade):
		Gtk::Window(cobject), builder(refGlade)
{
	builder->get_widget("gtkDA",gtkDA);
	builder->get_widget("menuitemNew",gtkMenuitemNew);
	builder->get_widget("menuitemOpen",gtkMenuitemOpen);
	builder->get_widget("menuitemSave",gtkMenuitemSave);
	builder->get_widget("menuitemExit",gtkMenuitemExit);
	builder->get_widget("menuitemBestTimes",gtkMenuitemBestTimes);
	builder->get_widget("menuitemOriginal",gtkMenuitemOriginal);
	builder->get_widget("menuitemHint",gtkMenuitemHint);
	builder->get_widget("menuitemLucky",gtkMenuitemLucky);
	builder->get_widget("menuitemImmune",gtkMenuitemImmune);
	builder->get_widget("menuitemStartup",gtkMenuitemStartup);
	builder->get_widget("menuitemMurph",gtkMenuitemMurph);
	builder->get_widget("menuitemBeginner",gtkMenuitemBeginner);
	builder->get_widget("menuitemIntermediate",gtkMenuitemIntermediate);
	builder->get_widget("menuitemExpert",gtkMenuitemExpert);
	builder->get_widget("menuitemSelfDefined",gtkMenuitemSelfDefined);
	builder->get_widget("menuitemSquare",gtkMenuitemSquare);
	builder->get_widget("menuitemHexagon",gtkMenuitemHexagon);
	builder->get_widget("menuitemTriangle",gtkMenuitemTriangle);
	builder->get_widget("menuitem3Dgrid",gtkMenuitem3Dgrid);
	builder->get_widget("menuitemGiveHint",gtkMenuitemGiveHint);
	builder->get_widget("menuitemSolveOne",gtkMenuitemSolveOne);
	builder->get_widget("menuitemSolveAll1",gtkMenuitemSolveAll1);
	builder->get_widget("menuitemSolveAll2",gtkMenuitemSolveAll2);
	builder->get_widget("menuitemSolveAll3",gtkMenuitemSolveAll3);
	builder->get_widget("menuitemSolveAuto0",gtkMenuitemSolveAuto0);
	builder->get_widget("menuitemSolveAuto1",gtkMenuitemSolveAuto1);
	builder->get_widget("menuitemSolveAuto2",gtkMenuitemSolveAuto2);
	builder->get_widget("menuitemSolveAuto3",gtkMenuitemSolveAuto3);
	builder->get_widget("menuitemMaxStage",gtkMenuitemMaxStage);
	builder->get_widget("menuitemMaxStage1",gtkMenuitemMaxStage1);
	builder->get_widget("menuitemMaxStage2",gtkMenuitemMaxStage2);
	builder->get_widget("menuitemMaxStage3",gtkMenuitemMaxStage3);
	builder->get_widget("menuitemShowMines",gtkMenuitemShowMines);
	builder->get_widget("menuitemUndo",gtkMenuitemUndo);
	builder->get_widget("menuitemRedo",gtkMenuitemRedo);
	builder->get_widget("menuitemUndoAll",gtkMenuitemUndoAll);
	builder->get_widget("menuitemAbout",gtkMenuitemAbout);

	gtkMenuitemNew->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemNewClicked));
	gtkMenuitemOpen->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemOpenClicked));
	gtkMenuitemSave->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemSaveClicked));
	gtkMenuitemBestTimes->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemBestTimesClicked));
	gtkMenuitemExit->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemExitClicked));
	gtkMenuitemBeginner->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemBeginnerClicked));
	gtkMenuitemIntermediate->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemIntermediateClicked));
	gtkMenuitemExpert->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemExpertClicked));
	gtkMenuitemSelfDefined->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemSelfDefinedClicked));

	gtkMenuitemOriginal->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemOriginalClicked));
	gtkMenuitemLucky->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemLuckyClicked));
	gtkMenuitemImmune->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemImmuneClicked));
	gtkMenuitemHint->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemHintClicked));
	gtkMenuitemStartup->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemStartupClicked));
	gtkMenuitemMurph->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemMurphClicked));

	gtkMenuitemSquare->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemSquareClicked));
	gtkMenuitemHexagon->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemHexagonClicked));
	gtkMenuitemTriangle->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemTriangleClicked));
	gtkMenuitem3Dgrid->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitem3DgridClicked));

	gtkMenuitemGiveHint->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemGiveHintClicked));
	gtkMenuitemSolveOne->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemSolveOneClicked));
	gtkMenuitemSolveAll1->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemSolveAll1Clicked));
	gtkMenuitemSolveAll2->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemSolveAll2Clicked));
	gtkMenuitemSolveAll3->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemSolveAll3Clicked));
	gtkMenuitemSolveAuto0->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemSolveAuto0Clicked));
	gtkMenuitemSolveAuto1->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemSolveAuto1Clicked));
	gtkMenuitemSolveAuto2->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemSolveAuto2Clicked));
	gtkMenuitemSolveAuto3->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemSolveAuto3Clicked));
	gtkMenuitemMaxStage1->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemMaxStage1Clicked));
	gtkMenuitemMaxStage2->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemMaxStage2Clicked));
	gtkMenuitemMaxStage3->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemMaxStage3Clicked));
	gtkMenuitemShowMines->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemShowMinesClicked));

	gtkMenuitemUndo->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemUndoClicked));
	gtkMenuitemRedo->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemRedoClicked));
	gtkMenuitemUndoAll->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemUndoAllClicked));

	gtkMenuitemAbout->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemAboutClicked));

	crBackBufferSurface = Cairo::ImageSurface::create(Cairo::Format::FORMAT_ARGB32, 1500, 1500);
	crBackBufferContext = Cairo::Context::create(crBackBufferSurface);

	gtkDA->signal_draw().connect(sigc::mem_fun(*this,&MainWindow::OnGameAreaDraw));
	gtkDA->add_events(Gdk::EventMask::POINTER_MOTION_MASK | Gdk::EventMask::BUTTON_PRESS_MASK | Gdk::EventMask::BUTTON_RELEASE_MASK );
	gtkDA->signal_button_press_event().connect(sigc::mem_fun(*this, &MainWindow::OnGameAreaMousePress));
	gtkDA->signal_button_release_event().connect(sigc::mem_fun(*this, &MainWindow::OnGameAreaMouseRelase));
	gtkDA->signal_motion_notify_event().connect(sigc::mem_fun(*this, &MainWindow::OnGameAreaMouseMotion));

	signal_delete_event().connect(sigc::mem_fun(*this,&MainWindow::OnWindowDelete));
}

void MainWindow::UpdateMenuIndicators(){
	dismiss_menu_toggle_signals = true;

	gtkMenuitemBeginner->    set_active(game->m_options->getLevelNr() == MinesPerfect::BEGINNER);
	gtkMenuitemIntermediate->set_active(game->m_options->getLevelNr() == MinesPerfect::INTERMEDIATE);
	gtkMenuitemExpert->      set_active(game->m_options->getLevelNr() == MinesPerfect::EXPERT);
	gtkMenuitemSelfDefined->set_active(game->m_options->getLevelNr() == MinesPerfect::USER_DEFINED);
	gtkMenuitemOriginal->set_active(game->m_options->getModus() == MinesPerfect::ORIGINAL);
	gtkMenuitemLucky->   set_active(game->m_options->getModus() == MinesPerfect::LUCKY);
	gtkMenuitemImmune->  set_active(game->m_options->getModus() == MinesPerfect::IMMUNE);
	gtkMenuitemHint->    set_active(game->m_options->getModus() == MinesPerfect::HINTS);
	gtkMenuitemStartup-> set_active(game->m_options->getModus() == MinesPerfect::STARTUP);
	gtkMenuitemMurph->   set_active(game->m_options->getMurphysLaw());
	gtkMenuitemSolveAuto0->set_active(game->m_options->getAutoStage() == 0);
	gtkMenuitemSolveAuto1->set_active(game->m_options->getAutoStage() == 1);
	gtkMenuitemSolveAuto2->set_active(game->m_options->getAutoStage() == 2);
	gtkMenuitemSolveAuto3->set_active(game->m_options->getAutoStage() == 3);
	gtkMenuitemMaxStage1-> set_active(game->m_options->getMaxStage() == 1);
	gtkMenuitemMaxStage2-> set_active(game->m_options->getMaxStage() == 2);
	gtkMenuitemMaxStage3-> set_active(game->m_options->getMaxStage() == 3);
	gtkMenuitemShowMines->   set_active(game->m_options->getShowMines());

	gtkMenuitemLucky->set_sensitive(game->m_options->getMaxStage() == 3);
	gtkMenuitemMaxStage->set_sensitive(game->m_options->getModus() != MinesPerfect::LUCKY);

	dismiss_menu_toggle_signals = false;
}
void MainWindow::OnMenuitemExitClicked(){
	Gtk::Main::quit();
}

void MainWindow::SetGameAreaSize(int width, int height){
	gtkDA->set_size_request(width,height);
	crBackBufferContext->save();
	crBackBufferContext->set_source_rgb(0.75,0.75,0.75);
	crBackBufferContext->rectangle(0,0,width,height);
	crBackBufferContext->fill();
	crBackBufferContext->restore();
}

void MainWindow::RedrawGameArea(){
	gtkDA->queue_draw();
}
void MainWindow::RedrawGameArea(int x, int y, int w, int h){
	gtkDA->queue_draw_area(x,y,w,h);
}

bool MainWindow::OnGameAreaDraw(const Cairo::RefPtr<Cairo::Context>& cr){
	cr->save();
	cr->set_source(crBackBufferSurface,0,0);
	cr->rectangle(0,0,gtkDA->get_width(),gtkDA->get_height());
	cr->fill();
	cr->restore();
	return true;
}


bool MainWindow::OnGameAreaMousePress(GdkEventButton* ev){
	MinesPerfect::API::MouseEvent mp_event;
	if(ev->button == 1){
		mp_event.m_type = MinesPerfect::API::MouseEvent::LEFT_DOWN;
		LMB_down = true;
	}else if(ev->button == 3){
		mp_event.m_type = MinesPerfect::API::MouseEvent::RIGHT_DOWN;
		RMB_down = true;
	}else return false;
	mp_event.m_pos = MinesPerfect::Point(ev->x, ev->y);
	mp_event.m_prev_pos = prev_mouse_position;
  mp_event.m_left_is_down  = LMB_down;
  mp_event.m_right_is_down = RMB_down;
  prev_mouse_position = mp_event.m_pos;

  game->onMouseEvent(mp_event);
  game->show();
	return true;
}
bool MainWindow::OnGameAreaMouseRelase(GdkEventButton* ev){
	MinesPerfect::API::MouseEvent mp_event;
	if(ev->button == 1){
		mp_event.m_type = MinesPerfect::API::MouseEvent::LEFT_UP;
		LMB_down = false;
	}else if(ev->button == 3){
		mp_event.m_type = MinesPerfect::API::MouseEvent::RIGHT_UP;
		RMB_down = false;
	}else return false;
	mp_event.m_pos = MinesPerfect::Point(ev->x, ev->y);
	mp_event.m_prev_pos = prev_mouse_position;
  mp_event.m_left_is_down  = LMB_down;
  mp_event.m_right_is_down = RMB_down;
  prev_mouse_position = mp_event.m_pos;
  game->onMouseEvent(mp_event);
  game->show();
	return true;
}
bool MainWindow::OnGameAreaMouseMotion(GdkEventMotion* ev){
	MinesPerfect::API::MouseEvent mp_event;
	mp_event.m_type = MinesPerfect::API::MouseEvent::MOVE;
	mp_event.m_pos = MinesPerfect::Point(ev->x, ev->y);
	mp_event.m_prev_pos = prev_mouse_position;
  mp_event.m_left_is_down  = LMB_down;
  mp_event.m_right_is_down = RMB_down;
  prev_mouse_position = mp_event.m_pos;
  game->onMouseEvent(mp_event);
  game->show();
	return true;
}


void MainWindow::OnMenuitemNewClicked(){
	game->newGame();
	game->show();
}
void MainWindow::OnMenuitemOpenClicked(){
  Gtk::FileChooserDialog dialog("Choose a file to open", Gtk::FILE_CHOOSER_ACTION_OPEN);
  dialog.set_transient_for(*this);

	auto filter = Gtk::FileFilter::create();
	filter->add_pattern("*.log");
	filter->set_name(".log files");
	dialog.add_filter(filter);

  dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
  dialog.add_button("Select", Gtk::RESPONSE_OK);

  int result = dialog.run();
	std::string file = dialog.get_filename();
	switch(result)
  {
    case(Gtk::RESPONSE_OK):
			game->load(file.c_str());
			std::cout << "Game loaded" << std::endl;
      break;
    case(Gtk::RESPONSE_CANCEL):
      break;
  }
	UpdateMenuIndicators();
	game->show();
}
void MainWindow::OnMenuitemSaveClicked(){
  Gtk::FileChooserDialog dialog("Choose a save file", Gtk::FILE_CHOOSER_ACTION_SAVE);
  dialog.set_transient_for(*this);

	auto filter = Gtk::FileFilter::create();
	filter->add_pattern("*.log");
	filter->set_name(".log files");
	dialog.add_filter(filter);

  dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
  dialog.add_button("Select", Gtk::RESPONSE_OK);

  int result = dialog.run();
	std::string file = dialog.get_filename();
	switch(result)
  {
    case(Gtk::RESPONSE_OK):
			if(file.length() < 5 || file.substr(file.length() - 4) != ".log") file += ".log";
			game->save(file.c_str());
      break;
    case(Gtk::RESPONSE_CANCEL):
      break;
  }
	game->show();
}
void MainWindow::OnMenuitemOriginalClicked(){
	if(dismiss_menu_toggle_signals) return;
  game->changeModus (MinesPerfect::ORIGINAL);
	UpdateMenuIndicators();
	game->show();
}
void MainWindow::OnMenuitemLuckyClicked(){
	if(dismiss_menu_toggle_signals) return;
  game->changeModus (MinesPerfect::LUCKY);
	UpdateMenuIndicators();
	game->show();
}
void MainWindow::OnMenuitemHintClicked(){
	if(dismiss_menu_toggle_signals) return;
  game->changeModus (MinesPerfect::HINTS);
	UpdateMenuIndicators();
	game->show();
}
void MainWindow::OnMenuitemImmuneClicked(){
	if(dismiss_menu_toggle_signals) return;
  game->changeModus (MinesPerfect::IMMUNE);
	UpdateMenuIndicators();
	game->show();
}
void MainWindow::OnMenuitemStartupClicked(){
	if(dismiss_menu_toggle_signals) return;
  game->changeModus (MinesPerfect::STARTUP);
	UpdateMenuIndicators();
	game->show();
}
void MainWindow::OnMenuitemMurphClicked(){
	if(dismiss_menu_toggle_signals) return;
  game->setMurphysLaw (gtkMenuitemMurph->get_active());
	game->show();
}
void MainWindow::OnMenuitemShowMinesClicked(){
	if(dismiss_menu_toggle_signals) return;
  game->setShowMines (gtkMenuitemShowMines->get_active());
	game->show();
}
void MainWindow::OnMenuitemGiveHintClicked(){
	game->giveHint();
	game->show();
}
void MainWindow::OnMenuitemSolveOneClicked(){
  game->solveOne();
	game->show();
}
void MainWindow::OnMenuitemSolveAll1Clicked(){
	game->solveAll(1);
	game->show();
}
void MainWindow::OnMenuitemSolveAll2Clicked(){
	game->solveAll(2);
	game->show();
}
void MainWindow::OnMenuitemSolveAll3Clicked(){
	game->solveAll(3);
	game->show();
}
void MainWindow::OnMenuitemSolveAuto0Clicked(){
	if(dismiss_menu_toggle_signals) return;
	game->changeSolveAuto(0);
	game->show();
}
void MainWindow::OnMenuitemSolveAuto1Clicked(){
	if(dismiss_menu_toggle_signals) return;
	game->changeSolveAuto(1);
	game->show();
}
void MainWindow::OnMenuitemSolveAuto2Clicked(){
	if(dismiss_menu_toggle_signals) return;
	game->changeSolveAuto(2);
	game->show();
}
void MainWindow::OnMenuitemSolveAuto3Clicked(){
	if(dismiss_menu_toggle_signals) return;
	game->changeSolveAuto(3);
	game->show();
}
void MainWindow::OnMenuitemMaxStage1Clicked(){
	if(dismiss_menu_toggle_signals) return;
	game->changeMaxStage(1);
	UpdateMenuIndicators();
	game->show();
}
void MainWindow::OnMenuitemMaxStage2Clicked(){
	if(dismiss_menu_toggle_signals) return;
	game->changeMaxStage(2);
	UpdateMenuIndicators();
	game->show();
}
void MainWindow::OnMenuitemMaxStage3Clicked(){
	if(dismiss_menu_toggle_signals) return;
	game->changeMaxStage(3);
	UpdateMenuIndicators();
	game->show();
}
void MainWindow::OnMenuitemBeginnerClicked(){
	if(dismiss_menu_toggle_signals) return;
  game->changeLevel (MinesPerfect::BEGINNER);
	game->show();
}
void MainWindow::OnMenuitemIntermediateClicked(){
	if(dismiss_menu_toggle_signals) return;
  game->changeLevel (MinesPerfect::INTERMEDIATE);
	game->show();
}
void MainWindow::OnMenuitemExpertClicked(){
	if(dismiss_menu_toggle_signals) return;
  game->changeLevel (MinesPerfect::EXPERT);
	game->show();
}
void MainWindow::OnMenuitemSelfDefinedClicked(){
	if(dismiss_menu_toggle_signals) return;
	if(!gtkMenuitemSelfDefined->get_active()) return;

  MinesPerfect::Level level = game->m_options->getLevel();
  level.nr = MinesPerfect::USER_DEFINED;

	DialogSelfDefined* selfdef = DialogSelfDefined::Create(&level);
	selfdef->set_transient_for(*this);
	int result = selfdef->run();
	switch(result)
  {
    case(Gtk::RESPONSE_OK):
			game->changeLevel(level);
    case(Gtk::RESPONSE_CANCEL):
      break;
  }
	delete selfdef;

	game->show();
}
void MainWindow::OnMenuitemBestTimesClicked(){

	// TODO
}
void MainWindow::OnMenuitemSquareClicked(){
	if(dismiss_menu_toggle_signals) return;
  game->changeBoard (0);
	game->show();
}
void MainWindow::OnMenuitemTriangleClicked(){
	if(dismiss_menu_toggle_signals) return;
  game->changeBoard (2);
	game->show();
}
void MainWindow::OnMenuitemHexagonClicked(){
	if(dismiss_menu_toggle_signals) return;
  game->changeBoard (1);
	game->show();
}
void MainWindow::OnMenuitem3DgridClicked(){
	if(dismiss_menu_toggle_signals) return;
  game->changeBoard (3);
	game->show();
}
void MainWindow::OnMenuitemUndoClicked(){
  game->undo(false);
	game->show();
}
void MainWindow::OnMenuitemUndoAllClicked(){
  game->undo(true);
	game->show();
}
void MainWindow::OnMenuitemRedoClicked(){
  game->redo();
	game->show();
}
void MainWindow::OnMenuitemAboutClicked(){
	DialogAbout* about = DialogAbout::Create();
	about->set_transient_for(*this);
	about->run();
	delete about;
}
bool MainWindow::OnWindowDelete(GdkEventAny* event){
	int x, y;
	get_position(x,y);
	game->m_options->setXPos(x);
	game->m_options->setYPos(y);
	game->m_options->saveIni();
}
