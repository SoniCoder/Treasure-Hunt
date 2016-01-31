#include "Phoenix.h"	//Our Engine

#include "ascincludes.h"	//Accessory Includes

#include "prototypes.h"


int main(int argc, char* argv[]){
	bool isWindowed;
	int width, height;
	gameinit::queryInfo(width, height, isWindowed);
	Phoenix::Phoenix_Instance.initialize();
	Phoenix::Phoenix_Instance.createWindow(width, height, isWindowed);
	Phoenix::Phoenix_Instance.setDrawFunction(update);
	Phoenix::Phoenix_Instance.begin();
	Phoenix::Phoenix_Instance.shutdown();
	return 0;
	
}