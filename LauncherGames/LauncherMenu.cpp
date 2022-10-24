#include "LauncherMenu.h"
#include "Games.h"
#include "MorpionMenu.h"
#include "PuissanceMenu.h"
LauncherMenu::LauncherMenu() : Menu("Games", {
	new Games("Morpion", new MorpionMenu()),
	new Games("Puissance4", new PuissanceMenu())
		})
{

}
