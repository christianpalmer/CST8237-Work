#include "GameEngine.h"
#include <SDL.h>
#include "MathUtils.h"
#include <string.h>

GameEngine::GameEngine()
{

}

GameEngine::~GameEngine()
{

}

void GameEngine::Initialize()
{

  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

  _windowTitle = new char[25];
  strcpy(_windowTitle, "Tank Combat - Player1 0 X 0 Player2");
  _window = SDL_CreateWindow(_windowTitle,
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    SCREEN_SIZE, SCREEN_SIZE,
    SDL_WINDOW_SHOWN);

 
  _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

  InitializeImpl();

  /* Get the time at the beginning of our game loop so that we can track the
  * elapsed difference. */
  _engineTimer.Start();
  

}

void GameEngine::Shutdown()
{
  _engineTimer.Stop();

  SDL_DestroyRenderer(_renderer);
  SDL_DestroyWindow(_window);
}

void GameEngine::Update()
{
  // Calculating the time difference since our last loop.
  _engineTimer.Update();
//  SDL_SetWindowTitle(_window, _windowTitle );

  UpdateImpl(_engineTimer.GetDeltaTime());
}

void GameEngine::Draw()
{
  // Set the draw colour for screen clearing.
  SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);

 
  //// Clear the renderer with the current draw colour.
 
  DrawImpl(_renderer, _engineTimer.GetDeltaTime());

}