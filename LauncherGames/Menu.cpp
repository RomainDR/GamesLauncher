#include "Menu.h"
#include "Utils.h"
#include "Games.h"


Menu::Menu(const std::string _name, std::initializer_list<Games*> _menus)
{
	name = _name;
	for (Games* _item : _menus)
		subMenus.push_back(_item);
}

Menu::Menu(const Menu& _copy)
{
	name = _copy.name;
}

Menu::~Menu()
{
	subMenus.clear();
}

void Menu::Open()
{
	isOpen = true;
	DisplayItems();
}

void Menu::Close()
{
	isOpen = false;

}

void Menu::DisplayItems()
{	
	Utils::ClearConsole();
	Utils::LogTitle(name);
	size_t _size = subMenus.size();
	for (int i = 0; i < _size; i++)
		Utils::Log(std::to_string(i + 1) + ": " + subMenus[i]->GetName());
	Utils::Log(std::to_string(_size+1) + ": return");
}

void Menu::UpdatePage()
{
	int _index = -1;
	while (isOpen)
	{
		_index = Utils::UserChoice<int>("Select: ") - 1;
		if (_index == subMenus.size()) break;
		Choose(_index);
	}
	OpenOldMenu();
}

void Menu::SetOldMenu(Menu* _menu)
{
	old = _menu;
}

void Menu::OpenOldMenu()
{
	this->Close();
	if (old == nullptr)
		exit(0);
	old->Open();
}

void Menu::Choose(const int& _index)
{
	try
	{
		if (_index < 0 || _index > subMenus.size()) {
			throw std::exception("[MainMenu] => index out of range !");
			UpdatePage();
		}
		subMenus[_index]->OnClick(this);
	}
	catch (const std::exception& _exception)
	{
		Utils::LogError(_exception.what());
		Utils::Pause();
		OpenOldMenu();
	}
}