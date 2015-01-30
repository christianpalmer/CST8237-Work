#include "Player.h"
#include <SDL.h>
#include <math.h>


struct SDL_Renderer;


Player::Player() : GameObject()
{
	_transform.position.x =  100.0f; 
	_transform.position.y =  100.0f;
	_transform.position.z = 0.0f;
	_transform.rotation.x = 100.0f;
	_transform.rotation.y = 105.0f;
	_transform.rotation.z = 90;
	_pos1.x = 90;
	_pos1.y = 110;

	_pos2.x = 110;
	_pos2.y = 110;

}

Player::~Player()
{
}

void Player::Initialize()
{


}

void Player::Update(float dt)
{

}


//function to rotate the player ( rotate each line)
void Player::Rotate(Direction direction)
{
	
	float rotationDegrees = direction == RIGHT ? 10.0f : -10.0f;

	_transform.rotation.z += rotationDegrees;
	if(_transform.rotation.z < 0 ) { _transform.rotation.z = 350;}
	if(_transform.rotation.z > 360) { _transform.rotation.z = 10;}


	float rotationRadians = MathUtils::ToRadians(rotationDegrees);


	Vector2 rotatedOffset =
	{
		(_transform.position.x  - _transform.rotation.x)* cosf(rotationRadians) - (_transform.position.y - _transform.rotation.y)  * sinf(rotationRadians),
		(_transform.position.x  - _transform.rotation.x) * sinf(rotationRadians) + (_transform.position.y  - _transform.rotation.y) * cosf(rotationRadians)
	};


	rotatedOffset.x += _transform.rotation.x;
	rotatedOffset.y += _transform.rotation.y;

	_transform.position.x = rotatedOffset.x;
	_transform.position.y = rotatedOffset.y;



	rotatedOffset.x = (_pos1.x  - _transform.rotation.x)* cosf(rotationRadians) - (_pos1.y - _transform.rotation.y)  * sinf(rotationRadians);
	rotatedOffset.y = (_pos1.x  - _transform.rotation.x) * sinf(rotationRadians) + (_pos1.y  - _transform.rotation.y) * cosf(rotationRadians);

	rotatedOffset.x += _transform.rotation.x;
	rotatedOffset.y += _transform.rotation.y;

	_pos1.x = rotatedOffset.x;
	_pos1.y = rotatedOffset.y;

	rotatedOffset.x = (_pos2.x  - _transform.rotation.x)* cosf(rotationRadians) - (_pos2.y - _transform.rotation.y)  * sinf(rotationRadians);
	rotatedOffset.y = (_pos2.x  - _transform.rotation.x) * sinf(rotationRadians) + (_pos2.y  - _transform.rotation.y) * cosf(rotationRadians);

	rotatedOffset.x += _transform.rotation.x;
	rotatedOffset.y += _transform.rotation.y;

	_pos2.x = rotatedOffset.x;
	_pos2.y = rotatedOffset.y;



}
void Player::Draw(SDL_Renderer *renderer, float dt)
{


	SDL_RenderDrawLine(renderer,
		_transform.position.x,
		_transform.position.y,
		_pos1.x,
		_pos1.y);

	SDL_RenderDrawLine(renderer,
		_transform.position.x,
		_transform.position.y,
		_pos2.x,
		_pos2.y);


	SDL_RenderDrawLine(renderer,
		_pos1.x,
		_pos1.y,
		_pos2.x,
		_pos2.y);
}

void Player::Move(float dt)
{

	_transform.position.x++;
	_transform.position.y++;
	_pos1.x++;
	_pos1.y++;
	
	_pos2.x++;
	_pos2.y++;
}