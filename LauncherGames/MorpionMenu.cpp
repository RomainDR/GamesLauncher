#include "MorpionMenu.h"
#include "MorpionGame.h"
#include "Menu.h"
#include "Games.h"
MorpionMenu::MorpionMenu() : Menu("Morpion", {
	new Games("Player vs Player", new MorpionGame(false)),
	new Games("Player vs IA", new MorpionGame(true))
		})
{
}

void MorpionMenu::Open()
{
	Menu::Open();
	UpdatePage();
}

