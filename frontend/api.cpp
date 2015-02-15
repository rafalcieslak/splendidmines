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
	BitmapImplementation(const std::string path){
		pixbuf = Gdk::Pixbuf::create_from_file(path);
	}
  virtual Point  getSize() const{

	}
  virtual bool   pointIsTransparent (const Point& p) const{

	}

};

API::Bitmap* MinesPerfect::API::CreateBitmap (const string& kind, const string& spec){
	std::string path = "../textures/" + kind + "/" + spec + ".png";
	try{
		BitmapImplementation* bi = new BitmapImplementation(path);
		return bi;
	}catch(Glib::FileError fe){
		std::cerr << "Exception when creating bitmap: " << fe.what() << std::endl;
		throw;
	}
}
API::Bitmap* MinesPerfect::API::CreateBitmap (const API::Bitmap* from, const Rect& rect){
	throw UnimplementedAPIException();
	return nullptr;
}

API::Timer* MinesPerfect::API::CreateTimer(){
	throw UnimplementedAPIException();
	return nullptr;
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

void MinesPerfect::API::Init(){
	throw UnimplementedAPIException();
}

void MinesPerfect::API::WinSetSize    (const Point& sz){
	throw UnimplementedAPIException();
}
void MinesPerfect::API::WinDrawBitmap (const API::Bitmap* bmp, const Point& p){
	throw UnimplementedAPIException();
}
void MinesPerfect::API::WinDrawBevel  (const Rect& rect, int thickness, bool raised){
	throw UnimplementedAPIException();
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
	throw UnimplementedAPIException();
}
void MinesPerfect::API::ShowMessageDlg (const string& text, const string& title){
	throw UnimplementedAPIException();
}
