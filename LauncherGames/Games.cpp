#include "Games.h"

Games::Games(const std::string& _name, Menu* _gamesMenu)
{
	name = _name;
	gamesMenu = _gamesMenu;
}

Games::~Games()
{
	delete gamesMenu;
}

std::string Games::GetName() const
{
	return name;
}

void Games::OnClick(Menu* _current)
{
	if (gamesMenu == nullptr)
		throw std::exception("[GamesMenu] gamesMenu is null");
	gamesMenu->SetOldMenu(_current);
	_current->Close();
	gamesMenu->Open();
}
