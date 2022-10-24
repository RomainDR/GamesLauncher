#pragma once
#include "IGames.h"
class Morpion : public IGames
{
private:
	std::string name1 = "";
	std::string name2 = "";
	bool IA = false;
	bool isEnded = false;
	bool player1Turn = true;

	const int sizeX = 3;
	const int sizeY = 3;

	int grid[3][3] = {
		{ 0,0,0 },
		{ 0,0,0 },
		{ 0,0,0 }
	};

public:
	Morpion(const std::string& _name1, const std::string& _name2, const bool _ia);

#pragma region methods
private:
	void DisplayGrid();
	void SetChoicePlayer();
	void CheckWin();
	std::string GetSymbol(const int& _y, const int& _x);
	bool IsAvailableCase(const int& _y, const int& _x);
public:
	bool IsEnded() const override;
	void SetEnded();
	void Game();
#pragma endregion 
};

