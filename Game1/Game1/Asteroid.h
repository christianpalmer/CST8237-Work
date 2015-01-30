#pragma once

#include "GameObject.h"


class Asteroid : public GameObject
{


public:
	float speed;
	Asteroid();
	~Asteroid();

	void Initialize();

	void Update(float dt);
	void Draw(SDL_Renderer *renderer, float dt);
	
};