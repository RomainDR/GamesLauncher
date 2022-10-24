#include "Morpion.h"
#include <iostream>
#include "Utils.h"

Morpion::Morpion(const std::string& _name1, const std::string& _name2, const bool _ia)
{
	name1 = _name1;
	name2 = _name2;
	IA = _ia;
	std::cout << "test" << std::endl;
	Game();
}


bool Morpion::IsEnded() const
{
	return isEnded;
}

void Morpion::SetEnded()
{
	isEnded = true;
}

void Morpion::Game()
{
	Utils::ClearConsole();
	DisplayGrid();
	SetChoicePlayer();
	CheckWin();
}

void Morpion::DisplayGrid()
{
	std::string grid = "";
	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			grid += "[" + GetSymbol(y, x) + "] ";
		}
		grid += "\n";
	}
	std::cout <<  grid << std::endl;
}

void Morpion::SetChoicePlayer()
{
	int _input = Utils::UserChoice<int>("Tour de " + (player1Turn ? name1 : name2) + ".\nSelection de case (0-9): ") -1;
	if (_input < 0 || _input > 9) throw std::exception("Invalid input");
	int _y = 0;
	int _x = 0;
	while (_input >= 3)
	{
		_y++;
		_input -= 3;
	}
	_x = _input;
	grid[_y][_x] = player1Turn ? 1 : 2;
}

std::string Morpion::GetSymbol(const int& _y, const int& _x)
{
	return grid[_y][_x] == 0 ? " " : grid[_y][_x] == 1 ? "X" : "O";
}

void Morpion::CheckWin()
{
	int _y = 0;
	while (_y < 2) {
		if ((grid[_y][0] == 1 && grid[_y][1] == 1 && grid[_y][2] == 1) || (grid[_y][0] == 2 && grid[_y][1] == 2 && grid[_y][2] == 2))
			SetEnded();
		else
			_y++;
	}
	_y = 0;
	int _x = 0;
	while (_x < 2) {
		if ((grid[0][_x] == 1 && grid[1][_x] == 1 && grid[2][_x] == 1) || (grid[0][_x] == 2 && grid[1][_x] == 2 && grid[2][_x] == 2))
			SetEnded();
		else
			_x++;
	}
	if ((grid[0][0] == 1 && grid[1][1] == 1 && grid[2][2] == 1) || (grid[0][0] == 2 && grid[1][1] == 2 && grid[2][2] == 2))
		SetEnded();
	if ((grid[0][2] == 1 && grid[1][1] == 1 && grid[2][0] == 1) || (grid[0][2] == 2 && grid[1][1] == 2 && grid[2][0] == 2))
		SetEnded();
	if (IsEnded()) {
		Utils::Log("[MORPION] => " + (player1Turn ? name1 : name2) + " viens de gagner");
		system("pause");
	}
	else
		player1Turn = !player1Turn;
}


