#include "../core/api.h"
#include "mainwindow.h"

using namespace MinesPerfect;

extern MainWindow* pMainWindow;

Bitmap* MinesPerfect::CreateBitmap (const string& kind, const string& spec){
	return nullptr;
}
Bitmap* MinesPerfect::CreateBitmap (const Bitmap* from, const Rect& rect){
	return nullptr;
}

Timer* MinesPerfect::CreateTimer(){
	return nullptr;
}

Sound* MinesPerfect::CreateSound (const string& name){
	return nullptr;
}

void MinesPerfect::InitApi(){

}

void MinesPerfect::WinSetSize    (const Point& sz){

}
void MinesPerfect::WinDrawBitmap (const Bitmap* bmp, const Point& p){

}
void MinesPerfect::WinDrawBevel  (const Rect& rect, int thickness, bool raised){

}

void MinesPerfect::DlgNewRecord (Options* options, int num_msecs, bool certified_board){

}
void MinesPerfect::FindFiles (vector<string>& files, const string& pattern){

}
bool MinesPerfect::FileExist (const string& fname){

}
void MinesPerfect::ShowMessageDlg (const string& text, const string& title){

}
bool MinesPerfect::StartBrowser (const string& protokoll, const string& fname){

}
