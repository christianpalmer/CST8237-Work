#pragma once

#include "GameObject.h"




class Player : public GameObject
{

	Vector2 _pos1, _pos2;
	float _speedX, _speedY, _acceleration;

public:
	Player();
	~Player();

	void Initialize();

	void Update(float dt);
	void Draw(SDL_Renderer *renderer, float dt);
	void Rotate(Direction direction);
	void Move(float dt);
	
};