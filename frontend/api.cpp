#include "../core/api.h"
#include "mainwindow.h"

using namespace MinesPerfect;

extern MainWindow* pMainWindow;

class UnimplementedAPIException{
public:
	UnimplementedAPIException(){}
};

API::Bitmap* MinesPerfect::API::CreateBitmap (const string& kind, const string& spec){
	throw UnimplementedAPIException();
	return nullptr;
}
API::Bitmap* MinesPerfect::API::CreateBitmap (const API::Bitmap* from, const Rect& rect){
	throw UnimplementedAPIException();
	return nullptr;
}

API::Timer* MinesPerfect::API::CreateTimer(){
	throw UnimplementedAPIException();
	return nullptr;
}

API::Sound* MinesPerfect::API::CreateSound (const string& name){
	throw UnimplementedAPIException();
	return nullptr;
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
	throw UnimplementedAPIException();
}
bool MinesPerfect::API::FileExist (const string& fname){
	throw UnimplementedAPIException();
}
void MinesPerfect::API::ShowMessageDlg (const string& text, const string& title){
	throw UnimplementedAPIException();
}
