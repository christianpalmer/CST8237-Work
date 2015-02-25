/**
 * \class Game.h
 * \brief An class that represent the Game
 * \author Christian Andrade
 * \date February 13, 2015
 */
#pragma once

#include "GameEngine.h"

class SDL_Texture;


class Game: public GameEngine
{
  friend class GameEngine;

protected:
  Game();

  void InitializeImpl();
  void UpdateImpl(float dt);
  void DrawImpl(SDL_Renderer *renderer, float dt);

  //Player _player;

  // Using the default member-wise initializer for our new struct.
  Vector2 pos;
  Vector2 endPointOffset;
  float speed;
  float rotationSpeed;
  Block blocks[MAX_BLOCKS];
  Block walls[MAX_WALLS];

  
};