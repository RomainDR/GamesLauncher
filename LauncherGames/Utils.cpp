#include "Utils.h"
#include <Windows.h>

void Utils::Log(const std::string& _str)
{
	std::cout << _str << std::endl;
}

void Utils::LogTitle(const std::string& _str)
{
	std::cout << "\t" + _str << std::endl;
}

void Utils::ClearConsole()
{
	system("cls");
}

void Utils::LogError(const std::string& _error)
{
	const HANDLE _handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_handle, color_red);
	std::cout << "[ERROR] => " << _error << std::endl;
	SetConsoleTextAttribute(_handle, color_white);
}

void Utils::Pause()
{
	system("pause");
}
