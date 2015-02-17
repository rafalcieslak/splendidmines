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

MainWindow::MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade):
		Gtk::Window(cobject), builder(refGlade)
{
	builder->get_widget("gtkDA",gtkDA);
	builder->get_widget("menuitemExit",gtkMenuitemExit);
	builder->get_widget("menuitemBeginner",gtkMenuitemBeginner);
	builder->get_widget("menuitemIntermediate",gtkMenuitemIntermediate);
	builder->get_widget("menuitemExpert",gtkMenuitemExpert);
	builder->get_widget("menuitemSquare",gtkMenuitemSquare);
	builder->get_widget("menuitemHexagon",gtkMenuitemHexagon);
	builder->get_widget("menuitemTriangle",gtkMenuitemTriangle);
	builder->get_widget("menuitem3Dgrid",gtkMenuitem3Dgrid);

	gtkMenuitemExit->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemExitClicked));
	gtkMenuitemBeginner->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemBeginnerClicked));
	gtkMenuitemIntermediate->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemIntermediateClicked));
	gtkMenuitemExpert->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemExpertClicked));

	gtkMenuitemSquare->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemSquareClicked));
	gtkMenuitemHexagon->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemHexagonClicked));
	gtkMenuitemTriangle->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemTriangleClicked));
	gtkMenuitem3Dgrid->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitem3DgridClicked));

	crBackBufferSurface = Cairo::ImageSurface::create(Cairo::Format::FORMAT_ARGB32, 1500, 1500);
	crBackBufferContext = Cairo::Context::create(crBackBufferSurface);

	gtkDA->signal_draw().connect(sigc::mem_fun(*this,&MainWindow::OnGameAreaDraw));
	gtkDA->add_events(Gdk::EventMask::POINTER_MOTION_MASK | Gdk::EventMask::BUTTON_PRESS_MASK | Gdk::EventMask::BUTTON_RELEASE_MASK );
	gtkDA->signal_button_press_event().connect(sigc::mem_fun(*this, &MainWindow::OnGameAreaMousePress));
	gtkDA->signal_button_release_event().connect(sigc::mem_fun(*this, &MainWindow::OnGameAreaMouseRelase));
	gtkDA->signal_motion_notify_event().connect(sigc::mem_fun(*this, &MainWindow::OnGameAreaMouseMotion));
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


void MainWindow::OnMenuitemBeginnerClicked(){
  game->changeLevel (MinesPerfect::BEGINNER);
	game->show();
}
void MainWindow::OnMenuitemIntermediateClicked(){
  game->changeLevel (MinesPerfect::INTERMEDIATE);
	game->show();
}
void MainWindow::OnMenuitemExpertClicked(){
  game->changeLevel (MinesPerfect::EXPERT);
	game->show();
}
void MainWindow::OnMenuitemSquareClicked(){
  game->changeBoard (0);
	game->show();
}
void MainWindow::OnMenuitemTriangleClicked(){
  game->changeBoard (2);
	game->show();
}
void MainWindow::OnMenuitemHexagonClicked(){
  game->changeBoard (1);
	game->show();
}
void MainWindow::OnMenuitem3DgridClicked(){
  game->changeBoard (3);
	game->show();
}
