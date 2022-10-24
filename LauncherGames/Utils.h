#pragma once
#include <string>
#include <iostream>

#define color_white 15
#define color_red 4
#define color_yellow 14

class Utils
{
public:
	static void Log(const std::string& _str);
	static void LogTitle(const std::string& _str);
	static void ClearConsole();
	static void LogError(const std::string& _error);
	static void Pause();

	template<typename T>
	static T UserChoice(const std::string _str);
};

template<typename T>
inline T Utils::UserChoice(const std::string _str)
{
	if (_str != "") Log(_str);
	T _result = T();
	std::cin >> _result;
	return _result;

}
