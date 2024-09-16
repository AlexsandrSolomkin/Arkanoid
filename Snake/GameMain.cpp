#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Application.h"

using namespace Arkanoid;

int main()
{
	Application app(GAME_NAME);
	app.Run();

	return 0;
}