#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Game.h"

namespace Arkanoid
{
	class Application
	{
	public:
		Application(const std::string& gameName);
		~Application();

		void Run();

	private:
		Game game;
		sf::RenderWindow window;
	};
}