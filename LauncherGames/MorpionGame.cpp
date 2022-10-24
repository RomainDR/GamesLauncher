#include "MorpionGame.h"
#include "Morpion.h"
#include "Utils.h"
#include <iostream>

MorpionGame::MorpionGame(bool _activeIA) : Menu("Morpion", {})
{
	Ia = _activeIA;
}

MorpionGame::MorpionGame(const MorpionGame& _copy)
{
	Ia = _copy.Ia;
}

void MorpionGame::Open()
{
	bool isEnded = false;
	bool activeIA = Ia;
	std::string namePlayer1 = Utils::UserChoice<std::string>("Select name player 1: ");
	std::string namePlayer2 = "IA";
	if (!activeIA)
		namePlayer2 = Utils::UserChoice<std::string>("Select name player 2: ");
	Morpion* morpion = new Morpion(namePlayer1, namePlayer2, activeIA);
	while (!morpion->IsEnded())
	{
		morpion->Game();
	}
	delete morpion;
	OpenOldMenu();
}

