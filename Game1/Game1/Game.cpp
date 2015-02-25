#include "Game.h"
#include <SDL.h>
#include <math.h>

#include <sstream> 
#include <string.h>
// Initializing our static member pointer.
GameEngine* GameEngine::_instance = nullptr;

struct Vector2;
Player player1(SCREEN_SIZE/2,10);
Player player2(SCREEN_SIZE/2,SCREEN_SIZE - TANK_SIZE - WALL_HEIGHT);


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
	int blockIndex = 0, blockPosX = TANK_SIZE * 1.5, blockPosY = 250;
	player1.Initialize();
	player2.Initialize();
	player1.SetAngle(270); // setting the player 1 to "look down"


	// initializing the blocks in the game
	for (blockIndex = 0; blockIndex < MAX_BLOCKS; blockIndex++)
	{
		blocks[blockIndex].SetPosition(blockPosX, blockPosY);
		blocks[blockIndex].SetSize(BLOCK_SIZE,BLOCK_SIZE);
		blocks[blockIndex].Initialize();

		blockPosX+= BLOCK_SIZE + TANK_SIZE * 2;

		if (blockPosX+ BLOCK_SIZE  >= SCREEN_SIZE)
		{
			blockPosY +=BLOCK_SIZE * 2;
			blockPosX = TANK_SIZE * 1.5 ;
		}
		if (blockPosY + BLOCK_SIZE >= SCREEN_SIZE)
		{
			break;
		}

	}


	walls[0].SetSize(WALL_HEIGHT, WALL_WIDTH);
	walls[0].SetPosition(0, 0);
	walls[1].SetSize(WALL_WIDTH, WALL_HEIGHT);
	walls[1].SetPosition(0, 0);
	walls[2].SetSize(WALL_HEIGHT, WALL_WIDTH);
	walls[2].SetPosition(0, SCREEN_SIZE - WALL_HEIGHT);
	walls[3].SetSize(WALL_WIDTH, WALL_HEIGHT);
	walls[3].SetPosition(SCREEN_SIZE - WALL_HEIGHT, 0);

	for (blockIndex = 0; blockIndex < MAX_WALLS; blockIndex ++)
	{
		walls[blockIndex].Initialize();
	}

	speed = 10.0f;
	rotationSpeed = 360.0f;
}

void Game::UpdateImpl(float dt)
{
	SDL_Event evt;
	SDL_PollEvent(&evt);

	// Check for user input.

	SDL_Rect player1Position = player1.GetPosition();
	SDL_Rect player2Position = player2.GetPosition();
	SDL_Rect intersectResult;



	//checking players collisions
	if (player1.CheckShootCollision(&player2Position) && player2.IsAlive())
	{
		player2.SetLifeState(Dead);
		player1.Score();

		std::string title = "Tank Combat - Player1 " +  std::to_string(player1.GetScore())
			+ " X " + std::to_string(player2.GetScore()) + " Player2";
		strcpy(_windowTitle,  title.c_str());
		SDL_SetWindowTitle(_window, _windowTitle );
	}

	if (player2.CheckShootCollision(&player1Position) && player1.IsAlive())
	{
		player1.SetLifeState(Dead);
		player2.Score();

		std::string title = "Tank Combat - Player1 " +  std::to_string(player1.GetScore())
			+ " X " + std::to_string(player2.GetScore()) + " Player2";
		strcpy(_windowTitle,  title.c_str());
		SDL_SetWindowTitle(_window, _windowTitle );
	}


	//checking if  players collid to each other
	if (SDL_IntersectRect(&player1Position, &player2Position, &intersectResult))
	{
		player1.UndoMove();
		player2.UndoMove();
	}

	

	for(int blockIndex = 0; blockIndex < MAX_BLOCKS; blockIndex++)
	{

		player1.CheckCollision(&blocks[blockIndex].GetPosition());
		player2.CheckCollision(&blocks[blockIndex].GetPosition());

		player1.CheckShootCollision(&blocks[blockIndex].GetPosition());
		player2.CheckShootCollision(&blocks[blockIndex].GetPosition());

	}

	// checking collision of each player and projectiles with the walls around the world
	for (int wallIndex = 0; wallIndex  < MAX_WALLS; wallIndex++)
	{
		player1.CheckCollision(&walls[wallIndex].GetPosition());
		player2.CheckCollision(&walls[wallIndex].GetPosition());

		player1.CheckShootCollision(&walls[wallIndex].GetPosition());
		player2.CheckShootCollision(&walls[wallIndex].GetPosition());
	}

	if (evt.type == SDL_KEYDOWN)
	{
		SDL_KeyboardEvent &keyboardEvt = evt.key;
		SDL_Keycode &keyCode = keyboardEvt.keysym.sym;


		if (player1.IsAlive())
		{

			switch (evt.key.keysym.sym)
			{
			case SDLK_UP:
				player1.Move(dt);
				break;
			case SDLK_DOWN:
				break;
			case SDLK_RIGHT:
				player1.Rotate(RIGHT);
				break;
			case SDLK_LEFT:
				player1.Rotate(LEFT);
				break;
			case SDLK_RCTRL:
				player1.Shoot();
				break;

			default:
				break;

			}
		}

		if (player2.IsAlive())
		{
			switch (evt.key.keysym.sym)
			{
			case SDLK_w:
				player2.Move(dt);
				break;
			case SDLK_s:
				break;
			case SDLK_d:
				player2.Rotate(RIGHT);
				break;
			case SDLK_a:
				player2.Rotate(LEFT);
				break;
			case SDLK_SPACE:
				player2.Shoot();
				break;
			default:
				break;
			}
		}

	}


	player1.Update(dt);
	player2.Update(dt);
}

void Game::DrawImpl(SDL_Renderer *renderer, float dt)
{
	SDL_RenderClear(renderer);
	// Set the draw colour for our point.
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

	player1.Draw(renderer,dt);
	player2.Draw(renderer,dt);

	for (int blockIndex = 0; blockIndex < MAX_BLOCKS; blockIndex++)
	{
		blocks[blockIndex].Draw(renderer, dt);
	}

	for(int wallIndex = 0; wallIndex < MAX_WALLS; wallIndex++)
	{
		walls[wallIndex].Draw(renderer, dt);
	}

	SDL_RenderPresent(renderer);

}