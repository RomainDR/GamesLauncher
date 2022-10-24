#pragma once
#include "Menu.h"
class Games : public Menu
{
private:
	std::string name = "";
	Menu* gamesMenu = nullptr;
public:
	Games() = default;
	Games(const std::string& _name, Menu* _games);
	~Games();

public:
	std::string GetName() const;
	void OnClick(Menu* _current);
};

