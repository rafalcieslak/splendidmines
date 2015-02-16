#include "mainwindow.h"

MainWindow::MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade):
		Gtk::Window(cobject), builder(refGlade)
{
	builder->get_widget("gtkDA",gtkDA);
	builder->get_widget("menuitemExit",gtkMenuitemExit);

	gtkMenuitemExit->signal_activate().connect(sigc::mem_fun(*this, &MainWindow::OnMenuitemExitClicked));

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
