#pragma once
#include <string>
#include <vector>

class Games;

class Menu
{
private:
	std::string name = "";
	bool isOpen = true;
	std::vector<Games*> subMenus = std::vector<Games*>();
	Menu* old = nullptr;
public:
	Menu() = default;
	Menu(const std::string _name, std::initializer_list<Games*>);
	Menu(const Menu& _copy);

	~Menu();

public:
	virtual void Open();
	virtual void Close();
	void DisplayItems();
	virtual void UpdatePage();
	void SetOldMenu(Menu* _menu);
	void OpenOldMenu();
	void Choose(const int& _index);
};

