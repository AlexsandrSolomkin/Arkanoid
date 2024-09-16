#include "Application.h"
#include <cstdlib>

namespace Arkanoid
{
	Application::Application(const std::string& gameName) :
		window(sf::VideoMode(Arkanoid::SCREEN_WIDTH, Arkanoid::SCREEN_HEIGHT), GAME_NAME)
	{
		int seed = (int)time(nullptr);
		srand(seed);

		InitGame(game);
		DeserializeGame(game);
	}

    Application::~Application()
    {

    }

	void Application::Run()
	{
        sf::Clock gameClock;
        float lastTime = gameClock.getElapsedTime().asSeconds();

        while (window.isOpen())
        {
            sf::sleep(sf::milliseconds(16));

            float currentTime = gameClock.getElapsedTime().asSeconds();
            float deltaTime = currentTime - lastTime;
            lastTime = currentTime;

            sf::Event event;
            while (window.pollEvent(event))
            {
                if ((event.type == sf::Event::Closed) ||
                    ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)) ||
                    (game.uiMenu.selectedMenuItemPressed & UIMenuPressedEnum::IsGameExitPressed))
                {
                    window.close();
                }
            }

            UpdateGame(game, deltaTime);

            window.clear();

            DrawGame(game, window, deltaTime);
            window.display();

            PlayBackgroundSound(game);
        }
	}
}