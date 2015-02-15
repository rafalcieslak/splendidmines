#include "../core/api.h"
#include "mainwindow.h"

using namespace MinesPerfect;

extern MainWindow* pMainWindow;

API::Bitmap* MinesPerfect::API::CreateBitmap (const string& kind, const string& spec){
	return nullptr;
}
API::Bitmap* MinesPerfect::API::CreateBitmap (const API::Bitmap* from, const Rect& rect){
	return nullptr;
}

API::Timer* MinesPerfect::API::CreateTimer(){
	return nullptr;
}

API::Sound* MinesPerfect::API::CreateSound (const string& name){
	return nullptr;
}

void MinesPerfect::API::Init(){

}

void MinesPerfect::API::WinSetSize    (const Point& sz){

}
void MinesPerfect::API::WinDrawBitmap (const API::Bitmap* bmp, const Point& p){

}
void MinesPerfect::API::WinDrawBevel  (const Rect& rect, int thickness, bool raised){

}

void MinesPerfect::API::DlgNewRecord (Options* options, int num_msecs, bool certified_board){

}
void MinesPerfect::API::FindFiles (vector<string>& files, const string& pattern){

}
bool MinesPerfect::API::FileExist (const string& fname){

}
void MinesPerfect::API::ShowMessageDlg (const string& text, const string& title){

}
