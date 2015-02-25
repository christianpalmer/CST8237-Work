/**
 * \class GameObject.h
 * \brief An abstract class that represents a single object that can  
 * be placed and manipulated in the world.
 * \author Christian Andrade
 * \date February 13, 2015
 */

#pragma once 

#include "MathUtils.h"

struct SDL_Renderer;

class GameObject
{
public:
  virtual void Initialize() = 0;
  
  virtual void Update(float dt) = 0;
  virtual void Draw(SDL_Renderer *renderer, float dt) = 0;

  ~GameObject();

protected:
  GameObject();

  Transform _transform;
};