#include "PuissanceMenu.h"

PuissanceMenu::PuissanceMenu() : Menu("Puissance 4", { })
{
}

void PuissanceMenu::Open()
{
	Menu::Open();
	UpdatePage();
}
