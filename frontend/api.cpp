#include "../core/api.h"
#include "mainwindow.h"

#include <cstdio>
#include <string>
#include <iostream> // for debug output

#ifdef __linux__
	#include <glob.h>
#endif

#include <gdkmm/pixbuf.h>

using namespace MinesPerfect;

extern MainWindow* pMainWindow;

class UnimplementedAPIException{
public:
	UnimplementedAPIException(){}
};

class BitmapImplementation : public API::Bitmap{
public:
	Glib::RefPtr<Gdk::Pixbuf> pixbuf;
	std::string name;
	BitmapImplementation(){};
	BitmapImplementation(const std::string path){
		name = path;
		pixbuf = Gdk::Pixbuf::create_from_file(path);
	}
  virtual Point getSize() const{
		return Point(pixbuf->get_width(), pixbuf->get_height());
	}
  virtual bool pointIsTransparent (const Point& p) const{
		if(!pixbuf->get_has_alpha()) return false;
		if(pixbuf->get_n_channels()!=4) {std::cerr << "Unsupported n_channels in a pixbuf" << std::endl; throw UnimplementedAPIException();}
		if(pixbuf->get_bits_per_sample()!=8) {std::cerr << "Unsupported bpp in a pixbuf" << std::endl; throw UnimplementedAPIException();}
		if(p.x >= pixbuf->get_width() || p.y >= pixbuf->get_height()) return true;
		guchar* pixels = pixbuf->get_pixels();
		guchar* px = pixels + p.x * pixbuf->get_n_channels() + p.y * pixbuf->get_rowstride();
		if(px[4] < 200) return false;
		return true;
	}

};

API::Bitmap* MinesPerfect::API::CreateBitmap (const string& kind, const string& spec){
	std::string path = "../textures/" + kind + "/" + spec + ".png";
	try{
		BitmapImplementation* bi = new BitmapImplementation(path);
		return bi;
	}catch(Glib::Error fe){
		std::cerr << "Exception when opening bitmap" + path + ": " << fe.what() << std::endl;
		throw;
	}
}
API::Bitmap* MinesPerfect::API::CreateBitmap (const API::Bitmap* from, const Rect& rect){
	const BitmapImplementation* bi = dynamic_cast<const BitmapImplementation*>(from);
	BitmapImplementation* new_bi = new BitmapImplementation();
	new_bi->pixbuf = Gdk::Pixbuf::create( bi->pixbuf->get_colorspace(), true, bi->pixbuf->get_bits_per_sample(), rect.getWidth(), rect.getHeight());
	new_bi->pixbuf->fill(0x00000000);
	bi->pixbuf->composite( new_bi->pixbuf, 0,0, rect.getWidth(), rect.getHeight(), -rect.getLeft(), -rect.getTop(), 1.0, 1.0, Gdk::InterpType::INTERP_NEAREST, 255);
	new_bi->name = bi->name + " (" + std::to_string(rect.getLeft()) + " " + std::to_string(rect.getTop()) + ")";
	return new_bi;
}

class TimerImplementation : public API::Timer{
public:
  virtual int getMSecs() const{
		return 1000.0*timer.elapsed();
	}
  virtual bool isRunning() const{
		return running;
	}
  virtual clock_t start(){
		timer.start();
		running = true;
	}
  virtual void stop(){
		timer.stop();
		running = false;
	}
  virtual void reset(){
		timer.reset();
	}
	// TODO: notify?
private:
	Glib::Timer timer;
	bool running = false;
};

API::Timer* MinesPerfect::API::CreateTimer(){
	return new TimerImplementation();
}

class SoundImplementation : public API::Sound{
public:
	SoundImplementation(const std::string name){

	}
	virtual void play(){

	}
	virtual bool isOk(){
		return false;
	}
};

API::Sound* MinesPerfect::API::CreateSound (const std::string& name){
	return new SoundImplementation(name);
}

void MinesPerfect::API::WinSetSize    (const Point& sz){
	pMainWindow->SetGameAreaSize(sz.x,sz.y);
}
void MinesPerfect::API::WinDrawBitmap (const API::Bitmap* bmp, const Point& p){
	if(bmp == nullptr) return;
	const BitmapImplementation* bi = dynamic_cast<const BitmapImplementation*>(bmp);
	//std::cerr << "Will draw tex " << bi->name << " at " << p.x << " " << p.y;
	Cairo::RefPtr<Cairo::Context> cr = pMainWindow->crBackBufferContext;
	cr->save();
	Gdk::Cairo::set_source_pixbuf(cr,bi->pixbuf,p.x,p.y);
	cr->rectangle(p.x, p.y, bi->pixbuf->get_width(), bi->pixbuf->get_height() );
	cr->fill();
	cr->restore();
	pMainWindow->RedrawGameArea();//p.x,p.y, bi->pixbuf->get_width(), bi->pixbuf->get_height());
}
void MinesPerfect::API::WinDrawBevel  (const Rect& rect, int thickness, bool raised){
	double th = thickness/2.0;
  if (rect.getWidth()  < 2 * thickness || rect.getHeight() < 2 * thickness)
    return;
	//std::cerr << "Will draw bevel " << thickness << "." << (int)raised <<  " at " << rect.getLeft() << " " << rect.getTop() << " " << rect.getWidth() << " " << rect.getHeight() << std::endl;
	Cairo::RefPtr<Cairo::Context> cr = pMainWindow->crBackBufferContext;
	cr->save();
  cr->set_line_width(thickness);
	if(raised) cr->set_source_rgb(1.0,1.0,1.0);
	else       cr->set_source_rgb(0.5,0.5,0.5);
  cr->move_to( rect.getLeft()                ,  th+rect.getTop()                 );
	cr->line_to( rect.getLeft()+rect.getWidth(),  th+rect.getTop()                 );
  cr->move_to( th+rect.getLeft()                ,  rect.getTop()                 );
	cr->line_to( th+rect.getLeft()                ,  rect.getTop()+rect.getHeight());
	cr->stroke();
	cr->restore();
	cr->save();
  cr->set_line_width(thickness);
	if(raised) cr->set_source_rgb(0.5,0.5,0.5);
	else       cr->set_source_rgb(1.0,1.0,1.0);
	cr->move_to(-th+rect.getLeft()+rect.getWidth(), rect.getTop()                 );
	cr->line_to(-th+rect.getLeft()+rect.getWidth(), rect.getTop()+rect.getHeight());
	cr->move_to(rect.getLeft()                , -th+rect.getTop()+rect.getHeight());
	cr->line_to(rect.getLeft()+rect.getWidth(), -th+rect.getTop()+rect.getHeight());
	cr->stroke();
	cr->restore();
	pMainWindow->RedrawGameArea();
}

void MinesPerfect::API::DlgNewRecord (Options* options, int num_msecs, bool certified_board){
	throw UnimplementedAPIException();
}
void MinesPerfect::API::FindFiles (vector<string>& files, const string& pattern){
#ifdef __linux__
    glob_t glob_res;
    glob(pattern.c_str(),GLOB_TILDE,NULL,&glob_res);
    for(unsigned int i=0; i < glob_res.gl_pathc; i++)
        files.push_back(string(glob_res.gl_pathv[i]));
    globfree(&glob_res);
#else
	throw UnimplementedAPIException();
#endif
}
bool MinesPerfect::API::FileExist (const string& fname){
    std::ifstream infile(fname.c_str());
    return infile.good();
}
void MinesPerfect::API::ShowMessageDlg (const string& text, const string& title){
	throw UnimplementedAPIException();
}
