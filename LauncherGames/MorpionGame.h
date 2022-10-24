#pragma once
#include "Menu.h"
#include <string>
class MorpionGame : public Menu
{
private:
	bool Ia = false;
public:
	MorpionGame() = default;
	MorpionGame(bool _activeIA = false);
	MorpionGame(const MorpionGame& _copy);


#pragma region methods
public:
	void Open() override;
#pragma endregion methods
};

