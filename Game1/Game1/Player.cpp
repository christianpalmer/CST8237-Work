#include "Player.h"
#include <SDL.h>
#include <math.h>

struct SDL_Renderer;

MathUtils mathUtils;
Player::Player(int posX, int posY) : GameObject()
{

	_pos.x = posX;
	_pos.y = posY;

}

Player::Player()
{
	_pos.x = 100.0f;
	_pos.y = 100.0f;
}

Player::~Player()
{

}


void Player::SetAngle(float angle)
{
	_angle  = angle;
}
void Player::Initialize()
{
	IMG_Init(IMG_INIT_PNG);
	_speed = 100;
	_angle = 90;
	_shotState = Idle;
	_lifeState = Alive;
	_score = 0;

	_rect = new SDL_Rect();
	_rect->h = TANK_SIZE;
	_rect->w = TANK_WIDTH;
	_rect->x = _pos.x;
	_rect->y = _pos.y;
	_projectile.Initialize();
}

int Player::GetScore()
{
	return _score;
}

void Player::SetLifeState(LifeState lifeState)
{
	_lifeState = lifeState;
	_texture = NULL;
}
void Player::Update(float dt)
{
	if (_lifeState == Dead )
	{

		if (_deathTime >= MAX_DEATH_TIME)
		{
			SetLifeState(Alive);
			_deathTime = 0;
		}
		else {
			_deathTime += dt;
		}
	}


	if ( _shotState == Shooting &&_projectile.GetBounces() >= MAX_BOUNCES)
	{
		_shotState = Idle;
	}

}

void Player:: Score()
{
	_score++;
}

//function to rotate the player ( rotate each line)
void Player::Rotate(Rotation rotation)
{

	int rotationDegrees = rotation == RIGHT ? 10.0f : -10.0f;

	_angle+=rotationDegrees;

	if (_angle>360)
	{
		_angle-=360;
	}

	if (_angle < 0)
	{
		_angle = 360 + _angle;
	}

}
void Player::Draw(SDL_Renderer *renderer, float dt)
{

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	_rect->x = _pos.x;
	_rect->y = _pos.y;

	if (_texture == NULL)
	{
		if (_lifeState == Alive)
		{
			_texture = IMG_LoadTexture(renderer,"tank.png");
		}
		else if (_lifeState == Dead)
		{
			_texture = IMG_LoadTexture(renderer,"dead_tank.png");
		}

	}

	SDL_RenderCopyEx(renderer,_texture,nullptr, _rect,_angle ,nullptr,SDL_FLIP_NONE);

	if (_shotState == Shooting)
	{
		_projectile.Move(dt);
		_projectile.Draw(renderer, dt);
	}

}



void Player::Shoot()
{
	if (_shotState != Shooting)
	{
		_projectile.ResetSpeed();
		_projectile.ResetBounces();
		_projectile.SetPosition(_pos.x +  PROJECTILE_W/2, _pos.y, _angle);
		_shotState = Shooting;
	}
}
void Player::UndoMove()
{

	float walkingDist = _speed * _lastDT * 50 ;
	float radiansAngle = MathUtils::ToRadians(_angle);
	//if (_pos.y + walkingDist <= SCREEN_SIZE > _pos.y + walkingDist > 0)
	_pos.y += walkingDist * sinf(radiansAngle);


	//if (_pos.x + walkingDist <= SCREEN_SIZE && _pos.x + walkingDist> 0 )
	_pos.x += walkingDist * cosf(radiansAngle);

}

SDL_Rect& Player:: GetPosition()
{

	//SDL_Rect* rect = new SDL_Rect();
	//rect->h = TANK_SIZE;
	//rect->w = TANK_WIDTH;
	//rect->x = _pos.x;
	//rect->y = _pos.y;
	return *_rect;
}

void Player::Move(float dt)
{

	_lastDT = dt;
	float walkingDist = _speed * dt * 50 ;
	float radiansAngle = MathUtils::ToRadians(_angle);

	_pos.y -= walkingDist * sinf(radiansAngle);

	_pos.x -= walkingDist * cosf(radiansAngle);

}


bool Player::CheckShootCollision(SDL_Rect* rect)
{
	SDL_Rect result;

	if (_shotState == Shooting)
	{
		if (SDL_IntersectRect(&_projectile.GetPosition(), rect, &result))
		{
			//_shotState = Idle;
			_projectile.Bounce();
			return true;
		}
	}

	return false;
}
bool Player::CheckCollision(SDL_Rect* rect)
{

	bool isCollision = false;
	SDL_Rect intersectResult;

	if (SDL_IntersectRect(_rect, rect, &intersectResult))
	{
		UndoMove();
		isCollision = true;

	}
	else {
		isCollision = false;
	}

	return isCollision;
}

bool Player::IsAlive()
{
	return _lifeState == Alive;
}
