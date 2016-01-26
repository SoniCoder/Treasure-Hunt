#include "initinfo.h"

namespace gameinit
{
	void queryInfo(int& width, int& height, bool& windowed)
	{
		std::string temp;
		width = 800; height = 600;
		windowed = true;
		std::cout << "BITS Pilani Production\n\nEnter Screen Width in Pixels(default " << width << "): ";
		getNonEmptyInt(width);
		std::cout << "Enter Screen Height in Pixels(default " << height << "): ";
		getNonEmptyInt(height);
		std::cout << "Start Windowed?(Y/N)(Default:Y): ";
		getline(std::cin, temp);
		if (temp == "N" || temp == "n") windowed = false;
	}

	void getNonEmptyInt(int& a) {
		std::string temp;
		getline(std::cin, temp);
		if (!temp.empty()) {
			a = atoi(temp.c_str());
		}
		return;
	}
}