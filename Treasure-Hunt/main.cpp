#include "Phoenix.h"	//Our Engine

#include "ascincludes.h"	//Accessory Includes

#include "prototypes.h"

int main(int argc, char* argv[]){
	bool isWindowed;
	int width, height;
	gameinit::queryInfo(width, height, isWindowed);
	Phoenix engineInst;
	engineInst.initialize();
	engineInst.createWindow(width, height, isWindowed);
	engineInst.setDrawFunction(draw);
	engineInst.begin();
	engineInst.shutdown();
	return 0;
}