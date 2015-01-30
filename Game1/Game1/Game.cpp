#include "Game.h"
#include <SDL.h>
#include <math.h>

// Initializing our static member pointer.
GameEngine* GameEngine::_instance = nullptr;

struct Vector2;
Player player;

Asteroid asteroid;

GameEngine* GameEngine::CreateInstance()
{
	if (_instance == nullptr)
	{
		_instance = new Game();
	}
	return _instance;
}

Game::Game() : GameEngine()
{

}

void Game::InitializeImpl()
{
	// Using the default member-wise initializer for our new struct.
	pos.x = 100.0f;
	pos.y = 100.0f;

	endPointOffset.x = 10.0f;
	endPointOffset.y = 0.0f;

	speed = 10.0f;
	rotationSpeed = 360.0f;

	Player player;
	
	player.Initialize();
	asteroid.Initialize();
}

void Game::UpdateImpl(float dt)
{
	SDL_Event evt;
	SDL_PollEvent(&evt);

	// Check for user input.
	if (evt.type == SDL_KEYDOWN)
	{


		SDL_KeyboardEvent &keyboardEvt = evt.key;
		SDL_Keycode &keyCode = keyboardEvt.keysym.sym;
		switch (keyCode)
		{
		case SDLK_UP:
			player.Move(dt);
			break;
		case SDLK_DOWN:
		
			break;
		case SDLK_RIGHT:
			player.Rotate(RIGHT);
			break;
		case SDLK_LEFT:
			player.Rotate(LEFT);
			break;
		default:
			break;
		}
	}


	asteroid.Update(dt);
}

void Game::DrawImpl(SDL_Renderer *renderer, float dt)
{
	// Set the draw colour for our point.
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);



	// Draw the point.
	//SDL_RenderDrawPoint(renderer, posX, posY);


	player.Draw(renderer,dt);

	asteroid.Draw(renderer, dt);

	



}