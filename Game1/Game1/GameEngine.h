/**
 * \class GameEngine.h
 * \brief An class that represent the Game Engine
 * \author Christian Andrade
 * \date February 13, 2015
 */

#pragma once // Preprocessor directive to ensure that this header will only be included once. -- Generally used on Windows

// Preprocessor directive to ensure that this header will only be included once. -- Generally used for all environments.
/*#ifndef _GAME_ENGINE_H_
#define _GAME_ENGINE_H_

#endif // _GAME_ENGINE_H_*/

#include "GameConstants.h"
#include "MathUtils.h"
#include "Player.h"
#include "Timer.h"
#include "Block.h"




// Forward declaring our renderer and window.
// Because we're using them as pointers, we don't need to know their size
// at compile time to define this class.
struct SDL_Renderer;
struct SDL_Window;
struct SDL_Texture;


class GameEngine
{
public:
	static GameEngine* CreateInstance();

	void Initialize();
	void Shutdown();

	void Update();
	void Draw();

	~GameEngine();

protected:
	GameEngine();

	virtual void InitializeImpl() = 0;
	virtual void UpdateImpl(float dt) = 0;
	virtual void DrawImpl(SDL_Renderer *renderer, float dt) = 0;

	static GameEngine *_instance;

	SDL_Window *_window;
	char* _windowTitle;
	SDL_Renderer *_renderer;
	Timer _engineTimer;

	float _oldTime, _currentTime, _deltaTime;

};