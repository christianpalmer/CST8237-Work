#include "Asteroid.h"
#include <SDL.h>
#include <math.h>


struct SDL_Renderer;

 
Asteroid::Asteroid() : GameObject()
{


}

Asteroid::~Asteroid()
{
	
}

void Asteroid::Initialize()
{
	speed = 200;
	_transform.position.x = 0;
	_transform.position.y = 0;



}

void Asteroid::Update(float dt)
{
	_transform.position.x +=  speed * dt ;
	_transform.position.y += speed * dt;

	if (_transform.position.x > 640)
	{
		_transform.position.x = 0;
	}
		if (_transform.position.y > 640)
	{
		_transform.position.y = 0;
	}




}
void Asteroid::Draw(SDL_Renderer *renderer, float dt)
{

	//SDL_RenderDrawRect(

	SDL_Rect rect = {  _transform.position.x,_transform.position.y, 20,20};

	SDL_RenderDrawRect(renderer, &rect);


}

