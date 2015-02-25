#include "Projectile.h"
#include <SDL.h>
#include <math.h>

struct SDL_Renderer;

Projectile::Projectile()
{

}

Projectile::~Projectile()
{
}

void Projectile::Initialize()
{
	_rect = new SDL_Rect;
	_rect->h = PROJECTILE_H;
	_rect->w = PROJECTILE_W;
	_speed = 10;
	//_angle = 90;
}

SDL_Rect& Projectile:: GetPosition()
{
	return *_rect;
}


void Projectile::SetPosition(float posX, float posY, float angle)
{
	_pos.x = posX + 8;
	_pos.y = posY;
	_angle = angle;
}
void Projectile::Update(float dt)
{

}


void Projectile::ResetBounces()
{
	_bounces = 0;
}
int Projectile::GetBounces()
{
	return _bounces;
}
void Projectile::Bounce()
{
	_speed *= -1;
	_bounces++;
}


void Projectile::ResetSpeed()
{
	if (_speed < 0)
	{
		_speed *= -1;
	};
}
void Projectile::Draw(SDL_Renderer *renderer, float dt)
{

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	_rect->x = _pos.x;
	_rect->y = _pos.y;

	if (_texture == NULL)
	{
		_texture = IMG_LoadTexture(renderer,"projectile.png");
	}

	SDL_RenderCopyEx(renderer,_texture,nullptr, _rect,_angle - 90,nullptr,SDL_FLIP_NONE);

}

void Projectile::Move(float dt)
{
	float walkingDist = _speed * dt * 50 ;
	float radiansAngle = MathUtils::ToRadians(_angle);

	_pos.y -= walkingDist * sinf(radiansAngle);
	_pos.x -= walkingDist * cosf(radiansAngle);

}